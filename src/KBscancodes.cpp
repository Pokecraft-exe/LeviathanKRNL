#include "KBscancodes.hpp"

bool ShiftPressed = false;
uint8_t LastScancode;
char KEY;
const char ScanCodeLookupTable[] ={
    0, 0, '&', '2',
    34, 39, '(', '-',
    0, '_', '9', '0',
    ')', '=', 0, 0,
    'a', 'z', 'e', 'r',
    't', 'y', 'u', 'i',
    'o', 'p', '^', '$',
    0, 0, 'q', 's',
    'd', 'f', 'g', 'h',
    'j', 'k', 'l', 'm',
    '0', 0, 0, '*',
    'w', 'x', 'c', 'v',
    'b', 'n', ',', ';',
    ':', '!', 0, '*',
    0, ' '
  };
  
void StandardKeyboardHandler(uint8_t scancodes, uint8_t chr){
    if (chr != 0){
        switch (ShiftPressed) {
        
        case true:
            switch (scancodes){
                case 0x32:
                    KEY = '?';
                    break;
                case 0x33:
                    KEY = '.';
                    break;
                case 0x34:
                    KEY = '/';
                    break;
                case 0x35:
                    KEY = '!';
                    break;
                /*case 0x2B:
                    KEY = 'µ';
                    break;
                case 0x1B:
                    KEY = '£';
                    break;
                case 0x1A:
                    KEY = '¨';
                    break;*/
                case 0x02:
                    KEY = '1';
                    break;
                case 0x03:
                    KEY = '2';
                    break;
                case 0x04:
                    KEY = '3';
                    break;
                case 0x05:
                    KEY = '4';
                    break;
                case 0x06:
                    KEY = '5';
                    break;
                case 0x07:
                    KEY = '6';
                    break;
                case 0x08:
                    KEY = '7';
                    break;
                case 0x09:
                    KEY = '8';
                    break;
                case 0x0A:
                    KEY = '9';
                    break;
                case 0x0B:
                    KEY = '0';
                    break;
                case 0x0C:
                    //KEY = '°';
                    break;
                case 0x0D:
                    KEY = '+';
                    break;
                default:
                    KEY = chr - 32;
            }
            break;
        case false:
            KEY = chr;
            break;
        }
    }else{
        switch (scancodes) {
                case 0x0E: //backspace
                    KEY = 255;
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
                    KEY = 10;
                    break;
                 // numpad
                 case 0x52:
                     KEY = '0';
                 case 0xD2:
                     break;
                 case 0x4F:
                     KEY = '1';
                     break;
                 case 0x50:
                     KEY = '2';
                     break;
                 case 0x51:
                     KEY = '3';
                     break;
                 case 0x4B:
                     KEY = '4';
                     break;
                 case 0x4C:
                     KEY = '5';
                     break;
                 case 0xCC:
                     break;
                 case 0x4D:
                     KEY = '6';
                     break;
                 case 0x47:
                     KEY = '7';
                     break;
                 case 0x48:
                     KEY = '8';
                     break;
                 case 0x49:
                     KEY = '9';
                     break;
                case 0x4A:
                      KEY = '-';
                      break;
                case 0x4E:
                      KEY = '+';
                      break;
                case 0x53:
                      KEY = '.';
                      break;
                case 0x2B:
                      KEY = '/';
                      break;
                case 0x3B:
                      break;
        }
    }
}

void KeyboardHandler0xE0(uint8_t scanCode) {
	switch (scanCode)
	{
	case 0x50:
		//SetCursorPosition(CursorPosition + VGA_WIDTH);
		break;
	case 0x48:
		//SetCursorPosition(CursorPosition - VGA_WIDTH);
		break;
    case 0x4B:
        //SetCursorPosition(CursorPosition -1);
        break;
    case 0x4D:
        //SetCursorPosition(CursorPosition +1);
        break;
    case 0x35:
        KEY = '/';
        break;
    case 0x5E:
        
        //outb(0xB004, 0x2000);
        //outb(0x604, 0x2000);
        //outb(0x4004, 0x3400);
        break;
    case 0x1C: //enter
        KEY = 10;
        break;
    case 0x2E:
        break;
    case 0x30:
        break;
    case 0x20:
        break;
	}
}

void Keyboardhandler(uint8_t scancodes){
	if (scancodes < 0x3A){
		KEY = ScanCodeLookupTable[scancodes];
	} else {
    	switch (LastScancode) {
        	case 0xE0:
		        KeyboardHandler0xE0(scancodes);
		        break;
          	default:
	        	StandardKeyboardHandler(scancodes, 0);
		}
	}
	LastScancode = scancodes;
}
