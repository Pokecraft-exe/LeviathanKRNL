#include "typedefs.cpp"
#include "printf.cpp"

bool LeftShiftPressed = false;
bool RightShiftPressed = false;
uint_8 LastScancode;

void StandardKeyboardHandler(uint8 scancodes, uint8 chr){
    if (chr != 0){
        printchar(chr);
    }else{
        switch (scancodes) {
            case 0x0E: //backspace
                SetCursorPosition(CursorPosition - 1);
			    printchar(' ');
			    SetCursorPosition(CursorPosition - 1);
                break;
	      	case 0x2A: //Left Shift
	    		LeftShiftPressed = true;
		    	break;
		    case 0xAA: //Left Shift Released
    			LeftShiftPressed = false;
    		case 0x36: //Right Shift
    			RightShiftPressed = true;
    			break;
    		case 0xB6: //Right Shift Released
    			RightShiftPressed = false;
    			break;
            case 0x1C: //enter
                printf("\n");
                break;
        }        
    }
}

void KeyboardHandler0xE0(uint_8 scanCode) {
	switch (scanCode)
	{
	case 0x50:
		SetCursorPosition(CursorPosition + VGA_WIDTH);
		break;
	case 0x48:
		SetCursorPosition(CursorPosition - VGA_WIDTH);
		break;
    case 0x4B:
        SetCursorPosition((CursorPosition + 1) * VGA_WIDTH);
        break;
    case 0x4D:
        SetCursorPosition((CursorPosition + 1) % VGA_WIDTH);
        break;
	default:
		break;
	}
}

void Keyboardhandler(uint8 scancodes, uint8 chr){
    	switch (LastScancode) {
        	case 0xE0:
		        KeyboardHandler0xE0(scancodes);
		        break;
          	default:
	        	StandardKeyboardHandler(scancodes, chr);
	}

	LastScancode = scancodes;
}
