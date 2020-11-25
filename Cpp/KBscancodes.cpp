#include "H/KBscancodes.h"

bool ShiftPressed = false;
uint_8 LastScancode;

void StandardKeyboardHandler(uint8 scancodes, uint8 chr){
    if (chr != 0){
        switch (ShiftPressed) {
        
        case true:
            switch (scancodes){
                case 0x32:
                    printf("?");
                    break;
                case 0x33:
                    printf(".");
                    break;
                case 0x34:
                    printf("/");
                    break;
                case 0x35:
                    printf("!");
                    break;
                case 0x2B:
                    printf("µ");
                    break;
                case 0x1B:
                    printf("£");
                    break;
                case 0x1A:
                    printf("¨");
                    break;
                case 0x02:
                    printf("1");
                    break;
                case 0x03:
                    printf("2");
                    break;
                case 0x04:
                    printf("3");
                    break;
                case 0x05:
                    printf("4");
                    break;
                case 0x06:
                    printf("5");
                    break;
                case 0x07:
                    printf("6");
                    break;
                case 0x08:
                    printf("7");
                    break;
                case 0x09:
                    printf("8");
                    break;
                case 0x0A:
                    printf("9");
                    break;
                case 0x0B:
                    printf("0");
                    break;
                case 0x0C:
                    printf("°");
                    break;
                case 0x0D:
                    printf("+");
                    break;
                default:
                    printchar(chr - 32);
            }
            break;
        case false:
            printchar(chr);
            break;
        }
    }else{
        switch (scancodes) {
            if (ProtectedPos[CursorPosition] != 1){
                case 0x0E: //backspace
                    SetCursorPosition(CursorPosition - 1);
	    		    printchar(' ');
	    		    SetCursorPosition(CursorPosition - 1);
                 break;
	          	case 0x2A: //Left Shift
	        		ShiftPressed = true;
	    	    	break;
	    	    case 0xAA: //Left Shift Released
          			ShiftPressed = false;
                    break;
          		case 0x36: //Right Shift
          			ShiftPressed = true;
          			break;
         		case 0xB6: //Right Shift Released
         			ShiftPressed = false;
         			break;
                case 0x1C: //enter
                    printf("\n");
                    break;
                 // numpad
                 case 0x52:
                     printf(IntToStr(0));
                     break;
                 case 0x4F:
                     printf(IntToStr(1));
                     break;
                 case 0x50:
                     printf(IntToStr(2));
                     break;
                 case 0x51:
                     printf(IntToStr(3));
                     break;
                 case 0x4B:
                     printf(IntToStr(4));
                     break;
                 case 0x4C:
                     printf(IntToStr(5));
                     break;
                 case 0x4D:
                     printf(IntToStr(6));
                     break;
                 case 0x47:
                     printf(IntToStr(7));
                     break;
                 case 0x48:
                     printf(IntToStr(8));
                     break;
                 case 0x49:
                     printf(IntToStr(9));
                     break;
                case 0x4A:
                      printf("-");
                      break;
                case 0x4E:
                      printf("+");
                      break;
                case 0x53:
                      printf(".");
                      break;
                case 0x2B:
                      printf("/");
                      break;
                case 0x66:
                      Rect(0,0,320,200,6464);
                      break;
            }
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
        SetCursorPosition(CursorPosition -1);
        break;
    case 0x4D:
        SetCursorPosition(CursorPosition +1);
        break;
    case 0x35:
        printf("/");
        break;
    case 0x5E:
        cls();
        SetCursorPosition(PositionFromCoords(0, 0));
        //outb(0xB004, 0x2000);
        //outb(0x604, 0x2000);
        //outb(0x4004, 0x3400);
        break;
    case 0x1C: //enter
        printf("\n");
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
