// Created from bdf2c Version 3, (c) 2009, 2010 by Lutz Sammer
//	License AGPLv3: GNU Affero General Public License version 3

#include "font.h"
	/// character bitmap for each encoding
const unsigned char __font_bitmap__[] = {
//   0 $00 'uni0000.dup1'
//	width 8, bbx 0, bby 0, bbw 1, bbh 1
	________,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
//   1 $01 'uni0001'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_XXXXXX_,
	X______X,
	X_X__X_X,
	X______X,
	X_XXXX_X,
	X__XX__X,
	X______X,
	_XXXXXX_,
//   2 $02 'uni0002'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_XXXXXX_,
	XXXXXXXX,
	XX_XX_XX,
	XXXXXXXX,
	XX____XX,
	XXX__XXX,
	XXXXXXXX,
	_XXXXXX_,
//   3 $03 'uni0003'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XX_XX__,
	XXXXXXX_,
	XXXXXXX_,
	XXXXXXX_,
	_XXXXX__,
	__XXX___,
	___X____,
	________,
//   4 $04 'uni0004'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___X____,
	__XXX___,
	_XXXXX__,
	XXXXXXX_,
	_XXXXX__,
	__XXX___,
	___X____,
	________,
//   5 $05 'uni0005'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	__XXX___,
	_XXXXX__,
	__XXX___,
	XXXXXXX_,
	XXXXXXX_,
	_XXXXX__,
	__XXX___,
	_XXXXX__,
//   6 $06 'uni0006'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	___X____,
	___X____,
	__XXX___,
	_XXXXX__,
	XXXXXXX_,
	_XXXXX__,
	__XXX___,
	_XXXXX__,
//   7 $07 'uni0007'
//	width 8, bbx 2, bby 1, bbw 4, bbh 4
	___XX___,
	__XXXX__,
	__XXXX__,
	___XX___,
	________,
	________,
	________,
	________,
//   8 $08 'uni0008'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXXXXXXX,
	XXXXXXXX,
	XXX__XXX,
	XX____XX,
	XX____XX,
	XXX__XXX,
	XXXXXXXX,
	XXXXXXXX,
//   9 $09 'uni0009'
//	width 8, bbx 1, bby 0, bbw 6, bbh 6
	__XXXX__,
	_XX__XX_,
	_X____X_,
	_X____X_,
	_XX__XX_,
	__XXXX__,
	________,
	________,
//  10 $0a 'uni000A'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXXXXXXX,
	XX____XX,
	X__XX__X,
	X_XXXX_X,
	X_XXXX_X,
	X__XX__X,
	XX____XX,
	XXXXXXXX,
//  11 $0b 'uni000B'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	____XXXX,
	_____XXX,
	____XXXX,
	_XXXXX_X,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
//  12 $0c 'uni000C'
//	width 8, bbx 1, bby -1, bbw 6, bbh 8
	__XXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXX__,
	___XX___,
	_XXXXXX_,
	___XX___,
//  13 $0d 'uni000D'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	__XXXXXX,
	__XX__XX,
	__XXXXXX,
	__XX____,
	__XX____,
	_XXX____,
	XXXX____,
	XXX_____,
//  14 $0e 'uni000E'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_XXXXXXX,
	_XX___XX,
	_XXXXXXX,
	_XX___XX,
	_XX___XX,
	_XX__XXX,
	XXX__XX_,
	XX______,
//  15 $0f 'uni000F'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	X__XX__X,
	_X_XX_X_,
	__XXXX__,
	XXX__XXX,
	XXX__XXX,
	__XXXX__,
	_X_XX_X_,
	X__XX__X,
//  16 $10 'uni0010'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	X_______,
	XXX_____,
	XXXXX___,
	XXXXXXX_,
	XXXXX___,
	XXX_____,
	X_______,
	________,
//  17 $11 'uni0011'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	______X_,
	____XXX_,
	__XXXXX_,
	XXXXXXX_,
	__XXXXX_,
	____XXX_,
	______X_,
	________,
//  18 $12 'uni0012'
//	width 8, bbx 1, bby -1, bbw 6, bbh 8
	___XX___,
	__XXXX__,
	_XXXXXX_,
	___XX___,
	___XX___,
	_XXXXXX_,
	__XXXX__,
	___XX___,
//  19 $13 'uni0013'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	________,
	_XX__XX_,
	________,
//  20 $14 'uni0014'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_XXXXXXX,
	XX_XX_XX,
	XX_XX_XX,
	_XXXX_XX,
	___XX_XX,
	___XX_XX,
	___XX_XX,
	________,
//  21 $15 'uni0015'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	__XXXXX_,
	_XX___XX,
	__XXX___,
	_XX_XX__,
	_XX_XX__,
	__XXX___,
	XX__XX__,
	_XXXX___,
//  22 $16 'uni0016'
//	width 8, bbx 1, bby 0, bbw 6, bbh 3
	_XXXXXX_,
	_XXXXXX_,
	_XXXXXX_,
	________,
	________,
	________,
	________,
	________,
//  23 $17 'uni0017'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	___XX___,
	__XXXX__,
	_XXXXXX_,
	___XX___,
	_XXXXXX_,
	__XXXX__,
	___XX___,
	XXXXXXXX,
//  24 $18 'uni0018'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	___XX___,
	__XXXX__,
	_XXXXXX_,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	________,
//  25 $19 'uni0019'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	_XXXXXX_,
	__XXXX__,
	___XX___,
	________,
//  26 $1a 'uni001A'
//	width 8, bbx 0, bby 1, bbw 7, bbh 5
	___XX___,
	____XX__,
	XXXXXXX_,
	____XX__,
	___XX___,
	________,
	________,
	________,
//  27 $1b 'uni001B'
//	width 8, bbx 0, bby 1, bbw 7, bbh 5
	__XX____,
	_XX_____,
	XXXXXXX_,
	_XX_____,
	__XX____,
	________,
	________,
	________,
//  28 $1c 'uni001C'
//	width 8, bbx 0, bby 1, bbw 7, bbh 4
	XX______,
	XX______,
	XX______,
	XXXXXXX_,
	________,
	________,
	________,
	________,
//  29 $1d 'uni001D'
//	width 8, bbx 0, bby 1, bbw 8, bbh 5
	__X__X__,
	_XX__XX_,
	XXXXXXXX,
	_XX__XX_,
	__X__X__,
	________,
	________,
	________,
//  30 $1e 'uni001E'
//	width 8, bbx 0, bby 1, bbw 8, bbh 5
	___XX___,
	__XXXX__,
	_XXXXXX_,
	XXXXXXXX,
	XXXXXXXX,
	________,
	________,
	________,
//  31 $1f 'uni001F'
//	width 8, bbx 0, bby 1, bbw 8, bbh 5
	XXXXXXXX,
	XXXXXXXX,
	_XXXXXX_,
	__XXXX__,
	___XX___,
	________,
	________,
	________,
//  32 $20 'space'
//	width 8, bbx 0, bby 0, bbw 1, bbh 1
	________,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
//  33 $21 'exclam'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	__XX____,
	_XXXX___,
	_XXXX___,
	__XX____,
	__XX____,
	________,
	__XX____,
	________,
//  34 $22 'quotedbl'
//	width 8, bbx 1, bby 4, bbw 5, bbh 3
	_XX_XX__,
	_XX_XX__,
	_XX_XX__,
	________,
	________,
	________,
	________,
	________,
//  35 $23 'numbersign'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XX_XX__,
	_XX_XX__,
	XXXXXXX_,
	_XX_XX__,
	XXXXXXX_,
	_XX_XX__,
	_XX_XX__,
	________,
//  36 $24 'dollar'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	_XXXXX__,
	XX______,
	_XXXX___,
	____XX__,
	XXXXX___,
	__XX____,
	________,
//  37 $25 'percent'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XX___XX_,
	XX__XX__,
	___XX___,
	__XX____,
	_XX__XX_,
	XX___XX_,
	________,
	________,
//  38 $26 'ampersand'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	__XXX___,
	_XXX_XX_,
	XX_XXX__,
	XX__XX__,
	_XXX_XX_,
	________,
//  39 $27 'quotesingle'
//	width 8, bbx 0, bby 4, bbw 3, bbh 3
	_XX_____,
	_XX_____,
	XX______,
	________,
	________,
	________,
	________,
	________,
//  40 $28 'parenleft'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	___XX___,
	__XX____,
	_XX_____,
	_XX_____,
	_XX_____,
	__XX____,
	___XX___,
	________,
//  41 $29 'parenright'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	_XX_____,
	__XX____,
	___XX___,
	___XX___,
	___XX___,
	__XX____,
	_XX_____,
	________,
//  42 $2a 'asterisk'
//	width 8, bbx 0, bby 1, bbw 8, bbh 5
	_XX__XX_,
	__XXXX__,
	XXXXXXXX,
	__XXXX__,
	_XX__XX_,
	________,
	________,
	________,
//  43 $2b 'plus'
//	width 8, bbx 0, bby 1, bbw 6, bbh 5
	__XX____,
	__XX____,
	XXXXXX__,
	__XX____,
	__XX____,
	________,
	________,
	________,
//  44 $2c 'comma'
//	width 8, bbx 1, bby -1, bbw 3, bbh 3
	________,
	________,
	________,
	________,
	________,
	__XX____,
	__XX____,
	_XX_____,
//  45 $2d 'hyphen'
//	width 8, bbx 0, bby 3, bbw 6, bbh 1
	________,
	________,
	________,
	________,
	XXXXXX__,
	________,
	________,
	________,
//  46 $2e 'period'
//	width 8, bbx 2, bby 0, bbw 2, bbh 2
	________,
	________,
	________,
	________,
	________,
	________,
	__XX____,
	__XX____,
//  47 $2f 'slash'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_____XX_,
	____XX__,
	___XX___,
	__XX____,
	_XX_____,
	XX______,
	X_______,
	________,
//  48 $30 'zero'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX___XX_,
	XX__XXX_,
	XX_XXXX_,
	XXXX_XX_,
	XXX__XX_,
	_XXXXX__,
	________,
//  49 $31 'one'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	XXXXXX__,
	________,
//  50 $32 'two'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	____XX__,
	__XXX___,
	_XX_____,
	XX___X__,
	XXXXXX__,
	________,
//  51 $33 'three'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	____XX__,
	__XXX___,
	____XX__,
	XX__XX__,
	_XXXX___,
	________,
//  52 $34 'four'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XXX__,
	__XXXX__,
	_XX_XX__,
	XX__XX__,
	XXXXXXX_,
	____XX__,
	___XXXX_,
	________,
//  53 $35 'five'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	XX______,
	XXXXX___,
	____XX__,
	____XX__,
	XX__XX__,
	_XXXX___,
	________,
//  54 $36 'six'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XXX___,
	_XX_____,
	XX______,
	XXXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
//  55 $37 'seven'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	XX__XX__,
	____XX__,
	___XX___,
	__XX____,
	__XX____,
	__XX____,
	________,
//  56 $38 'eight'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
//  57 $39 'nine'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	___XX___,
	_XXX____,
	________,
//  58 $3a 'colon'
//	width 8, bbx 2, bby 0, bbw 2, bbh 6
	________,
	________,
	__XX____,
	__XX____,
	________,
	________,
	__XX____,
	__XX____,
//  59 $3b 'semicolon'
//	width 8, bbx 1, bby 0, bbw 3, bbh 6
	________,
	________,
	__XX____,
	__XX____,
	________,
	__XX____,
	__XX____,
	_XX_____,
	
	
//  60 $3c 'less'
//	width 8, bbx 0, bby 0, bbw 5, bbh 7
	___XX___,
	__XX____,
	_XX_____,
	XX______,
	_XX_____,
	__XX____,
	___XX___,
	________,
//  61 $3d 'equal'
//	width 8, bbx 0, bby 1, bbw 6, bbh 4
	________,
	________,
	XXXXXX__,
	________,
	________,
	XXXXXX__,
	________,
	________,
//  62 $3e 'greater'
//	width 8, bbx 1, bby 0, bbw 5, bbh 7
	_XX_____,
	__XX____,
	___XX___,
	____XX__,
	___XX___,
	__XX____,
	_XX_____,
	________,
//  63 $3f 'question'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	____XX__,
	___XX___,
	__XX____,
	________,
	__XX____,
	________,
//  64 $40 'at'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX___XX_,
	XX_XXXX_,
	XX_XXXX_,
	XX_XXXX_,
	XX______,
	_XXXX___,
	________,
//  65 $41 'A'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	XX__XX__,
	________,
//  66 $42 'B'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	XXXXXX__,
	________,
//  67 $43 'C'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXXX__,
	_XX__XX_,
	XX______,
	XX______,
	XX______,
	_XX__XX_,
	__XXXX__,
	________,
//  68 $44 'D'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXX___,
	_XX_XX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX_XX__,
	XXXXX___,
	________,
//  69 $45 'E'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	_XX___X_,
	_XX_X___,
	_XXXX___,
	_XX_X___,
	_XX___X_,
	XXXXXXX_,
	________,
//  70 $46 'F'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	_XX___X_,
	_XX_X___,
	_XXXX___,
	_XX_X___,
	_XX_____,
	XXXX____,
	________,
//  71 $47 'G'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXXX__,
	_XX__XX_,
	XX______,
	XX______,
	XX__XXX_,
	_XX__XX_,
	__XXXXX_,
	________,
//  72 $48 'H'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
//  73 $49 'I'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	_XXXX___,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
//  74 $4a 'J'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XXXX_,
	____XX__,
	____XX__,
	____XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
//  75 $4b 'K'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX__XX_,
	_XX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	_XX__XX_,
	XXX__XX_,
	________,
//  76 $4c 'L'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXX____,
	_XX_____,
	_XX_____,
	_XX_____,
	_XX___X_,
	_XX__XX_,
	XXXXXXX_,
	________,
//  77 $4d 'M'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XXX_XXX_,
	XXXXXXX_,
	XXXXXXX_,
	XX_X_XX_,
	XX___XX_,
	XX___XX_,
	________,
//  78 $4e 'N'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XXX__XX_,
	XXXX_XX_,
	XX_XXXX_,
	XX__XXX_,
	XX___XX_,
	XX___XX_,
	________,
//  79 $4f 'O'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
//  80 $50 'P'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_____,
	_XX_____,
	XXXX____,
	________,
//  81 $51 'Q'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX_XXX__,
	_XXXX___,
	___XXX__,
	________,
//  82 $52 'R'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_XX__,
	_XX__XX_,
	XXX__XX_,
	________,
//  83 $53 'S'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	XXX_____,
	_XXX____,
	___XXX__,
	XX__XX__,
	_XXXX___,
	________,
//  84 $54 'T'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	X_XX_X__,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
//  85 $55 'U'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XXXXXX__,
	________,
//  86 $56 'V'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	________,
//  87 $57 'W'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX_X_XX_,
	XXXXXXX_,
	XXX_XXX_,
	XX___XX_,
	________,
//  88 $58 'X'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	________,
//  89 $59 'Y'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	__XX____,
	_XXXX___,
	________,
//  90 $5a 'Z'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	XX___XX_,
	X___XX__,
	___XX___,
	__XX__X_,
	_XX__XX_,
	XXXXXXX_,
	________,
//  91 $5b 'bracketleft'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	_XXXX___,
	_XX_____,
	_XX_____,
	_XX_____,
	_XX_____,
	_XX_____,
	_XXXX___,
	________,
//  92 $5c 'backslash'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX______,
	_XX_____,
	__XX____,
	___XX___,
	____XX__,
	_____XX_,
	______X_,
	________,
//  93 $5d 'bracketright'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	_XXXX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	_XXXX___,
	________,
//  94 $5e 'asciicircum'
//	width 8, bbx 0, bby 3, bbw 7, bbh 4
	___X____,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	________,
	________,
	________,
	________,
//  95 $5f 'underscore'
//	width 8, bbx 0, bby -1, bbw 8, bbh 1
	________,
	________,
	________,
	________,
	________,
	________,
	________,
	XXXXXXXX,
//  96 $60 'grave'
//	width 8, bbx 2, bby 4, bbw 3, bbh 3
	__XX____,
	__XX____,
	___XX___,
	________,
	________,
	________,
	________,
	________,
//  97 $61 'a'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	________,
	________,
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXX_XX_,
	________,
	
//  98 $62 'b'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX_____,
	_XX_____,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	XX_XXX__,
	________,
//  99 $63 'c'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	________,
	________,
	_XXXX___,
	XX__XX__,
	XX______,
	XX__XX__,
	_XXXX___,
	________,
	
// 100 $64 'd'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XXX__,
	____XX__,
	____XX__,
	_XXXXX__,
	XX__XX__,
	XX__XX__,
	_XXX_XX_,
	________,
// 101 $65 'e'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	________,
	________,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXX___,
	________,
	
// 102 $66 'f'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XXX___,
	_XX_XX__,
	_XX_____,
	XXXX____,
	_XX_____,
	_XX_____,
	XXXX____,
	________,
// 103 $67 'g'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	________,
	_XXX_XX_,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	XXXXX___,
	________,
	
// 104 $68 'h'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX_____,
	_XX_____,
	_XX_XX__,
	_XXX_XX_,
	_XX__XX_,
	_XX__XX_,
	XXX__XX_,
	________,
// 105 $69 'i'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	__XX____,
	________,
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 106 $6a 'j'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	____XX__,
	________,
	____XX__,
	____XX__,
	____XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
// 107 $6b 'k'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX_____,
	_XX_____,
	_XX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	XXX__XX_,
	________,
// 108 $6c 'l'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 109 $6d 'm'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	________,
	________,
	XX__XX__,
	XXXXXXX_,
	XXXXXXX_,
	XX_X_XX_,
	XX___XX_,
	________,
	
// 110 $6e 'n'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	________,
	________,
	XXXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
	
// 111 $6f 'o'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	________,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
	
// 112 $70 'p'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	________,
	XX_XXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_____,
	XXXX____,
	________,
	
// 113 $71 'q'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	________,
	_XXX_XX_,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	___XXXX_,
	________,
	
// 114 $72 'r'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	________,
	________,
	XX_XXX__,
	_XXX_XX_,
	_XX__XX_,
	_XX_____,
	XXXX____,
	________,
	
// 115 $73 's'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	________,
	________,
	_XXXXX__,
	XX______,
	_XXXX___,
	____XX__,
	XXXXX___,
	________,
	
// 116 $74 't'
//	width 8, bbx 1, bby 0, bbw 5, bbh 7
	___X____,
	__XX____,
	_XXXXX__,
	__XX____,
	__XX____,
	__XX_X__,
	___XX___,
	________,
// 117 $75 'u'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	________,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXX_XX_,
	________,
	
// 118 $76 'v'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	________,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	________,
	
// 119 $77 'w'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	________,
	________,
	XX___XX_,
	XX_X_XX_,
	XXXXXXX_,
	XXXXXXX_,
	_XX_XX__,
	________,
	
// 120 $78 'x'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	________,
	________,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	________,
	
// 121 $79 'y'
//	width 8, bbx 0, bby -1, bbw 6, bbh 6
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	XXXXX___,
	________,
	
// 122 $7a 'z'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	________,
	________,
	XXXXXX__,
	X__XX___,
	__XX____,
	_XX__X__,
	XXXXXX__,
	________,
	
// 123 $7b 'braceleft'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	__XX____,
	__XX____,
	XXX_____,
	__XX____,
	__XX____,
	___XXX__,
	________,
// 124 $7c 'bar'
//	width 8, bbx 3, bby 0, bbw 2, bbh 7
	___XX___,
	___XX___,
	___XX___,
	________,
	___XX___,
	___XX___,
	___XX___,
	________,
// 125 $7d 'braceright'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXX_____,
	__XX____,
	__XX____,
	___XXX__,
	__XX____,
	__XX____,
	XXX_____,
	________,
// 126 $7e 'asciitilde'
//	width 8, bbx 0, bby 5, bbw 7, bbh 2
	_XXX_XX_,
	XX_XXX__,
	________,
	________,
	________,
	________,
	________,
	________,
// 127 $7f 'uni007F'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	___X____,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XXXXXXX_,
	________,
	________,
// 160 $a0 'uni00A0'
//	width 8, bbx 0, bby 0, bbw 1, bbh 1
	________,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 161 $a1 'exclamdown'
//	width 8, bbx 3, bby 0, bbw 2, bbh 7
	___XX___,
	___XX___,
	________,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	________,
// 162 $a2 'cent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	___XX___,
	___XX___,
	_XXXXXX_,
	XX______,
	XX______,
	_XXXXXX_,
	___XX___,
	___XX___,
// 163 $a3 'sterling'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	_XX__X__,
	XXXX____,
	_XX_____,
	XXX__XX_,
	XXXXXX__,
	________,
// 164 $a4 'currency'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XX___XX_,
	_XXXXX__,
	XX___XX_,
	XX___XX_,
	_XXXXX__,
	XX___XX_,
	________,
	________,
// 165 $a5 'yen'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	XX__XX__,
	XX__XX__,
	_XXXX___,
	XXXXXX__,
	__XX____,
	XXXXXX__,
	__XX____,
	__XX____,
// 166 $a6 'brokenbar'
//	width 8, bbx 3, bby 0, bbw 2, bbh 7
	___XX___,
	___XX___,
	___XX___,
	________,
	___XX___,
	___XX___,
	___XX___,
	________,
// 167 $a7 'section'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	__XXXXX_,
	_XX___XX,
	__XXX___,
	_XX_XX__,
	_XX_XX__,
	__XXX___,
	XX__XX__,
	_XXXX___,
// 168 $a8 'dieresis'
//	width 8, bbx 0, bby 6, bbw 7, bbh 1
	XX___XX_,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 169 $a9 'copyright'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_XXXXXX_,
	X______X,
	X__XXX_X,
	X_X____X,
	X_X____X,
	X__XXX_X,
	X______X,
	_XXXXXX_,
// 170 $aa 'ordfeminine'
//	width 8, bbx 1, bby 1, bbw 6, bbh 6
	__XXXX__,
	_XX_XX__,
	_XX_XX__,
	__XXXXX_,
	________,
	_XXXXXX_,
	________,
	________,
// 171 $ab 'guillemotleft'
//	width 8, bbx 0, bby 1, bbw 8, bbh 5
	__XX__XX,
	_XX__XX_,
	XX__XX__,
	_XX__XX_,
	__XX__XX,
	________,
	________,
	________,
// 172 $ac 'logicalnot'
//	width 8, bbx 0, bby 1, bbw 6, bbh 3
	XXXXXX__,
	____XX__,
	____XX__,
	________,
	________,
	________,
	________,
	________,
// 173 $ad 'uni00AD'
//	width 8, bbx 1, bby 3, bbw 6, bbh 1
	_XXXXXX_,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 174 $ae 'registered'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_XXXXXX_,
	X______X,
	X_XXX__X,
	X_X__X_X,
	X_XXX__X,
	X_X__X_X,
	X______X,
	_XXXXXX_,
// 175 $af 'macron'
//	width 8, bbx 0, bby 6, bbw 8, bbh 1
	XXXXXXXX,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 176 $b0 'degree'
//	width 8, bbx 1, bby 3, bbw 5, bbh 4
	__XXX___,
	_XX_XX__,
	_XX_XX__,
	__XXX___,
	________,
	________,
	________,
	________,
// 177 $b1 'plusminus'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	__XX____,
	XXXXXX__,
	__XX____,
	__XX____,
	________,
	XXXXXX__,
	________,
// 178 $b2 'uni00B2'
//	width 8, bbx 1, bby 2, bbw 4, bbh 5
	_XXX____,
	___XX___,
	__XX____,
	_XX_____,
	_XXXX___,
	________,
	________,
	________,
// 179 $b3 'uni00B3'
//	width 8, bbx 1, bby 2, bbw 4, bbh 5
	_XXX____,
	___XX___,
	__XX____,
	___XX___,
	_XXX____,
	________,
	________,
	________,
// 180 $b4 'acute'
//	width 8, bbx 2, bby 4, bbw 4, bbh 3
	____XX__,
	___XX___,
	__XX____,
	________,
	________,
	________,
	________,
	________,
// 181 $b5 'mu'
//	width 8, bbx 0, bby -1, bbw 7, bbh 7
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_____,
	XX______,
	________,
// 182 $b6 'paragraph'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_XXXXXXX,
	XX_XX_XX,
	XX_XX_XX,
	_XXXX_XX,
	___XX_XX,
	___XX_XX,
	___XX_XX,
	________,
// 183 $b7 'periodcentered'
//	width 8, bbx 3, bby 2, bbw 2, bbh 1
	___XX___,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 184 $b8 'cedilla'
//	width 8, bbx 2, bby -1, bbw 4, bbh 3
	___XX___,
	____XX__,
	__XXX___,
	________,
	________,
	________,
	________,
	________,
// 185 $b9 'uni00B9'
//	width 8, bbx 1, bby 2, bbw 4, bbh 5
	__XX____,
	_XXX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
	________,
	________,
// 186 $ba 'ordmasculine'
//	width 8, bbx 1, bby 1, bbw 5, bbh 6
	__XXX___,
	_XX_XX__,
	_XX_XX__,
	__XXX___,
	________,
	_XXXXX__,
	________,
	________,
// 187 $bb 'guillemotright'
//	width 8, bbx 0, bby 1, bbw 8, bbh 5
	XX__XX__,
	_XX__XX_,
	__XX__XX,
	_XX__XX_,
	XX__XX__,
	________,
	________,
	________,
// 188 $bc 'onequarter'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	XX___XX_,
	XX__XX__,
	XX_XX_XX,
	__XX_XXX,
	_XX_XXXX,
	XX__XXXX,
	______XX,
// 189 $bd 'onehalf'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	XX___XX_,
	XX__XX__,
	XX_XXXX_,
	__XX__XX,
	_XX__XX_,
	XX__XX__,
	____XXXX,
// 190 $be 'threequarters'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXX_____,
	__XX__XX,
	_XX__XX_,
	__XXXX__,
	XXXXX_XX,
	__XX_XXX,
	_XX_XXXX,
	XX____XX,
// 191 $bf 'questiondown'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	________,
	__XX____,
	_XX_____,
	XX______,
	XX__XX__,
	_XXXX___,
	________,
// 192 $c0 'Agrave'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX______,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XXXXXXX_,
	XX___XX_,
	XX___XX_,
	________,
// 193 $c1 'Aacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_____XX_,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XXXXXXX_,
	XX___XX_,
	XX___XX_,
	________,
// 194 $c2 'Acircumflex'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX___XX_,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XXXXXXX_,
	XX___XX_,
	________,
// 195 $c3 'Atilde'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX_XX_,
	XX_XXX__,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XXXXXXX_,
	XX___XX_,
	________,
// 196 $c4 'Adieresis'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XXXXXXX_,
	XX___XX_,
	XX___XX_,
	________,
// 197 $c5 'Aring'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	__XX____,
	________,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	________,
// 198 $c6 'AE'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXXXX_,
	_XX_XX__,
	XX__XX__,
	XXXXXXX_,
	XX__XX__,
	XX__XX__,
	XX__XXX_,
	________,
// 199 $c7 'Ccedilla'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	_XXXX___,
	XX__XX__,
	XX______,
	XX__XX__,
	_XXXX___,
	___XX___,
	____XX__,
	_XXXX___,
// 200 $c8 'Egrave'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXX_____,
	________,
	XXXXXX__,
	_XX_____,
	_XXXX___,
	_XX_____,
	XXXXXX__,
	________,
// 201 $c9 'Eacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	________,
	XXXXXX__,
	_XX_____,
	_XXXX___,
	_XX_____,
	XXXXXX__,
	________,
// 202 $ca 'Ecircumflex'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	_XX_____,
	_XXXX___,
	_XX_____,
	XXXXXX__,
	________,
// 203 $cb 'Edieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	XXXXXX__,
	_XX_____,
	_XXXX___,
	_XX_____,
	XXXXXX__,
	________,
// 204 $cc 'Igrave'
//	width 8, bbx 0, bby 0, bbw 5, bbh 7
	XXX_____,
	________,
	_XXXX___,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 205 $cd 'Iacute'
//	width 8, bbx 1, bby 0, bbw 5, bbh 7
	___XXX__,
	________,
	_XXXX___,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 206 $ce 'Icircumflex'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_XXXXXX_,
	XX____XX,
	__XXXX__,
	___XX___,
	___XX___,
	___XX___,
	__XXXX__,
	________,
// 207 $cf 'Idieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	_XXXX___,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 208 $d0 'Eth'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXX___,
	_XX_XX__,
	_XX__XX_,
	XXXX_XX_,
	_XX__XX_,
	_XX_XX__,
	XXXXX___,
	________,
// 209 $d1 'Ntilde'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	________,
	XX__XX__,
	XXX_XX__,
	XXXXXX__,
	XX_XXX__,
	XX__XX__,
	________,
// 210 $d2 'Ograve'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX______,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 211 $d3 'Oacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_____XX_,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 212 $d4 'Ocircumflex'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX___XX_,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 213 $d5 'Otilde'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX_XX_,
	XX_XXX__,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 214 $d6 'Odieresis'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	XX____XX,
	___XX___,
	__XXXX__,
	_XX__XX_,
	_XX__XX_,
	__XXXX__,
	___XX___,
	________,
// 215 $d7 'multiply'
//	width 8, bbx 0, bby 1, bbw 7, bbh 5
	XX___XX_,
	_XX_XX__,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	________,
	________,
	________,
// 216 $d8 'Oslash'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX_X_,
	_XX_XX__,
	XX__XXX_,
	XX_X_XX_,
	XXX__XX_,
	_XX_XX__,
	X_XXX___,
	________,
// 217 $d9 'Ugrave'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXX_____,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 218 $da 'Uacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 219 $db 'Ucircumflex'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX___XX_,
	________,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	_XXXXX__,
	________,
// 220 $dc 'Udieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 221 $dd 'Yacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	________,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	_XXXX___,
	________,
// 222 $de 'Thorn'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXX____,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	_XXXXX__,
	_XX_____,
	XXXX____,
	________,
// 223 $df 'germandbls'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XX_XX___,
	XX__XX__,
	XX___XX_,
	XX__XX__,
	________,
// 224 $e0 'agrave'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX_____,
	________,
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 225 $e1 'aacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XXX__,
	________,
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 226 $e2 'acircumflex'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_XXXXXX_,
	XX____XX,
	__XXXX__,
	_____XX_,
	__XXXXX_,
	_XX__XX_,
	__XXXXXX,
	________,
// 227 $e3 'atilde'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX_XX_,
	XX_XXX__,
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 228 $e4 'adieresis'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX__XX__,
	________,
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 229 $e5 'aring'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XX____,
	__XX____,
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 230 $e6 'ae'
//	width 8, bbx 0, bby 0, bbw 8, bbh 5
	_XXXXXXX,
	____XX__,
	_XXXXXXX,
	XX__XX__,
	_XXXXXXX,
	________,
	________,
	________,
// 231 $e7 'ccedilla'
//	width 8, bbx 0, bby -1, bbw 6, bbh 6
	_XXXX___,
	XX______,
	XX______,
	_XXXX___,
	____XX__,
	__XXX___,
	________,
	________,
// 232 $e8 'egrave'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXX_____,
	________,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXX___,
	________,
// 233 $e9 'eacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	________,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXX___,
	________,
// 234 $ea 'ecircumflex'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_XXXXXX_,
	XX____XX,
	__XXXX__,
	_XX__XX_,
	_XXXXXX_,
	_XX_____,
	__XXXX__,
	________,
// 235 $eb 'edieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXX___,
	________,
// 236 $ec 'igrave'
//	width 8, bbx 0, bby 0, bbw 5, bbh 7
	XXX_____,
	________,
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 237 $ed 'iacute'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	__XXX___,
	________,
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 238 $ee 'icircumflex'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX___XX_,
	__XXX___,
	___XX___,
	___XX___,
	___XX___,
	__XXXX__,
	________,
// 239 $ef 'idieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 240 $f0 'eth'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XX____,
	_XXXXXX_,
	____XX__,
	_XXXXX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 241 $f1 'ntilde'
//	width 8, bbx 0, bby 0, bbw 6, bbh 6
	XXXXX___,
	________,
	XXXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
	________,
// 242 $f2 'ograve'
//	width 8, bbx 0, bby 0, bbw 6, bbh 6
	XXX_____,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
	________,
// 243 $f3 'oacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 6
	___XXX__,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
	________,
// 244 $f4 'ocircumflex'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 245 $f5 'otilde'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX_XX_,
	XX_XXX__,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 246 $f6 'odieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 6
	XX__XX__,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
	________,
// 247 $f7 'divide'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	__XX____,
	________,
	XXXXXX__,
	________,
	__XX____,
	__XX____,
	________,
// 248 $f8 'oslash'
//	width 8, bbx 0, bby -1, bbw 7, bbh 7
	______X_,
	_XXXXX__,
	XX__XXX_,
	XX_X_XX_,
	XXX__XX_,
	_XXXXX__,
	X_______,
	________,
// 249 $f9 'ugrave'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXX_____,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXXX_,
	________,
	________,
// 250 $fa 'uacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	___XXX__,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXXX_,
	________,
	________,
// 251 $fb 'ucircumflex'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXX___,
	XX__XX__,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 252 $fc 'udieresis'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XX__XX__,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXXX_,
	________,
	________,
// 253 $fd 'yacute'
//	width 8, bbx 0, bby -1, bbw 6, bbh 7
	___XXX__,
	________,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	_XXXX___,
	________,
// 254 $fe 'thorn'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XXX_____,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_____,
	XXXX____,
// 255 $ff 'ydieresis'
//	width 8, bbx 0, bby -1, bbw 6, bbh 7
	XX__XX__,
	________,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	XXXXX___,
	________,
// 256 $100 'Amacron'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	________,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XXXXXXX_,
	XX___XX_,
	________,
// 257 $101 'amacron'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	________,
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 258 $102 'Abreve'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	_XXXXX__,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XXXXXXX_,
	XX___XX_,
	________,
// 259 $103 'abreve'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX__XX__,
	_XXXX___,
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 260 $104 'Aogonek'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	__XX____,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	XX_XXX__,
	____XXX_,
// 261 $105 'aogonek'
//	width 8, bbx 0, bby -1, bbw 8, bbh 6
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXXXXX_,
	_____XXX,
	________,
	________,
// 262 $106 'Cacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	____XXX_,
	__XXXX__,
	_XX__XX_,
	XX______,
	XX______,
	_XX__XX_,
	__XXXX__,
	________,
// 263 $107 'cacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	________,
	_XXXX___,
	XX__XX__,
	XX______,
	XX__XX__,
	_XXXX___,
	________,
// 264 $108 'Ccircumflex'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_XXXXXX_,
	XX____XX,
	__XXXX__,
	_XX__XX_,
	XX______,
	_XX__XX_,
	__XXXX__,
	________,
// 265 $109 'ccircumflex'
//	width 8, bbx 1, bby 0, bbw 5, bbh 7
	__XXX___,
	_XX_XX__,
	________,
	__XXXX__,
	_XX_____,
	_XX_____,
	__XXXX__,
	________,
// 266 $10a 'Cdotaccent'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XX___,
	________,
	__XXXX__,
	_XX__XX_,
	XX______,
	_XX__XX_,
	__XXXX__,
	________,
// 267 $10b 'cdotaccent'
//	width 8, bbx 1, bby 0, bbw 5, bbh 6
	___XX___,
	________,
	__XXXX__,
	_XX_____,
	_XX_____,
	__XXXX__,
	________,
	________,
// 268 $10c 'Ccaron'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	XX____XX,
	_XXXXXX_,
	__XXXX__,
	_XX__XX_,
	XX______,
	_XX__XX_,
	__XXXX__,
	________,
// 269 $10d 'ccaron'
//	width 8, bbx 1, bby 0, bbw 5, bbh 7
	_XX_XX__,
	__XXX___,
	________,
	__XXXX__,
	_XX_____,
	_XX_____,
	__XXXX__,
	________,
// 270 $10e 'Dcaron'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX__XX__,
	_XXXX___,
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	XXXXXX__,
	________,
// 271 $10f 'dcaron'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	XX_XXXX_,
	_XXX_XX_,
	_____XX_,
	__XXXXX_,
	_XX__XX_,
	_XX__XX_,
	__XXX_XX,
	________,
// 272 $110 'Dcroat'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXX___,
	_XX_XX__,
	_XX__XX_,
	XXXX_XX_,
	_XX__XX_,
	_XX_XX__,
	XXXXX___,
	________,
// 273 $111 'dcroat'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	____XX__,
	__XXXXX_,
	____XX__,
	_XXXXX__,
	XX__XX__,
	XX__XX__,
	_XXX_XX_,
	________,
// 274 $112 'Emacron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	________,
	XXXXXX__,
	_XX_____,
	_XXXX___,
	_XX_____,
	XXXXXX__,
	________,
// 275 $113 'emacron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	________,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXX___,
	________,
// 276 $114 'Ebreve'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	XXXXXX__,
	_XX_____,
	_XXXX___,
	_XX_____,
	XXXXXX__,
	________,
// 277 $115 'ebreve'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXX___,
	________,
// 278 $116 'Edotaccent'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	________,
	XXXXXX__,
	_XX_____,
	_XXXX___,
	_XX_____,
	XXXXXX__,
	________,
// 279 $117 'edotaccent'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	________,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXX___,
	________,
// 280 $118 'Eogonek'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XXXXXXX_,
	_XX___X_,
	_XX_X___,
	_XXXX___,
	_XX_X___,
	_XX___X_,
	XXXXXXX_,
	____XX__,
// 281 $119 'eogonek'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXXX__,
	____XXX_,
	________,
	________,
// 282 $11a 'Ecaron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XX_XX__,
	__XXX___,
	XXXXXX__,
	_XX_____,
	_XXXX___,
	_XX_____,
	XXXXXX__,
	________,
// 283 $11b 'ecaron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XX_XX__,
	__XXX___,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXX___,
	________,
// 284 $11c 'Gcircumflex'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_XXXXXX_,
	XX____XX,
	__XXXXX_,
	_XX_____,
	XX__XXX_,
	_XX__XX_,
	__XXXXX_,
	________,
// 285 $11d 'gcircumflex'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	__XXX___,
	_XX_XX__,
	________,
	_XXX_XX_,
	XX__XX__,
	_XXXXX__,
	____XX__,
	XXXXX___,
// 286 $11e 'Gbreve'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XX_XX_,
	___XXX__,
	__XXXXX_,
	_XX_____,
	XX__XXX_,
	_XX__XX_,
	__XXXXX_,
	________,
// 287 $11f 'gbreve'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	_XX__XX_,
	__XXXX__,
	________,
	_XXX_XX_,
	XX__XX__,
	_XXXXX__,
	____XX__,
	XXXXX___,
// 288 $120 'Gdotaccent'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XX___,
	________,
	__XXXXX_,
	_XX_____,
	XX__XXX_,
	_XX__XX_,
	__XXXXX_,
	________,
// 289 $121 'gdotaccent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	___XX___,
	________,
	_XXX_XX_,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	XXXXX___,
// 290 $122 'Gcommaaccent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	__XXXX__,
	_XX__XX_,
	XX______,
	XX__XXX_,
	_XX__XX_,
	__XXXXX_,
	____XX__,
	__XXX___,
// 291 $123 'gcommaaccent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	____XXX_,
	___XX___,
	_XXX_XX_,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	XXXXX___,
// 292 $124 'Hcircumflex'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	________,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	XX__XX__,
	________,
// 293 $125 'hcircumflex'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	XXX_XXX_,
	_XXXX_XX,
	_XX_____,
	_XX_XX__,
	_XXX_XX_,
	_XX__XX_,
	XXX__XX_,
	________,
// 294 $126 'Hbar'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_XX__XX_,
	XXXXXXXX,
	_XX__XX_,
	_XXXXXX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	________,
// 295 $127 'hbar'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX_____,
	_XX_____,
	XXXX____,
	_XX_XX__,
	_XXX_XX_,
	_XX__XX_,
	XXX__XX_,
	________,
// 296 $128 'Itilde'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX_XX_,
	XX_XXX__,
	________,
	_XXXX___,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 297 $129 'itilde'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX_XX_,
	XX_XXX__,
	________,
	_XXX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 298 $12a 'Imacron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	________,
	_XXXX___,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 299 $12b 'imacron'
//	width 8, bbx 0, bby 0, bbw 5, bbh 7
	XXXXX___,
	________,
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 300 $12c 'Ibreve'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	________,
	_XXXX___,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 301 $12d 'ibreve'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	________,
	_XXX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 302 $12e 'Iogonek'
//	width 8, bbx 1, bby -1, bbw 5, bbh 8
	_XXXX___,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	___XXX__,
// 303 $12f 'iogonek'
//	width 8, bbx 1, bby -1, bbw 5, bbh 8
	__XX____,
	________,
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	___XXX__,
// 304 $130 'Idotaccent'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	__XX____,
	________,
	_XXXX___,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 305 $131 'dotlessi'
//	width 8, bbx 1, bby 0, bbw 4, bbh 5
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
	________,
	________,
// 306 $132 'IJ'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_XXX__,
	________,
// 307 $133 'ij'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XX___XX_,
	________,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX_X_XX_,
	XX_X_XX_,
	___XXX__,
// 308 $134 'Jcircumflex'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	__XXXXX_,
	_XX___XX,
	___XXX__,
	____XX__,
	____XX__,
	XX__XX__,
	_XXXX___,
	________,
// 309 $135 'jcircumflex'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	___XXXX_,
	__XX__XX,
	________,
	____XX__,
	____XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
// 310 $136 'Kcommaaccent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XXX__XX_,
	_XX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	_XX__XX_,
	XXX__XX_,
	___XXX__,
// 311 $137 'kcommaaccent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XXX_____,
	_XX_____,
	_XX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	XXX__XX_,
	___XXX__,
// 312 $138 'kgreenlandic'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XXX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	_XX__XX_,
	________,
	________,
	________,
// 313 $139 'Lacute'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	XXXX__XX,
	_XX__XX_,
	_XX_____,
	_XX_____,
	_XX___X_,
	_XX__XX_,
	XXXXXXX_,
	________,
// 314 $13a 'lacute'
//	width 8, bbx 1, bby 0, bbw 7, bbh 7
	_XXX__XX,
	__XX_XX_,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 315 $13b 'Lcommaaccent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XXXX____,
	_XX_____,
	_XX_____,
	_XX___X_,
	_XX__XX_,
	XXXXXXX_,
	___XX___,
	_XXX____,
// 316 $13c 'lcommaaccent'
//	width 8, bbx 1, bby -1, bbw 4, bbh 8
	_XXX____,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	___XX___,
	_XXX____,
// 317 $13d 'Lcaron'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	XXXXX_XX,
	_XX_XXX_,
	_XX__X__,
	_XX_____,
	_XX___X_,
	_XX__XX_,
	XXXXXXX_,
	________,
// 318 $13e 'lcaron'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	XX_XX_XX,
	XX__XXX_,
	XX___X__,
	XX______,
	XX______,
	XX______,
	XXX_____,
	________,
// 319 $13f 'Ldot'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXX____,
	_XX_____,
	_XX__XX_,
	_XX_____,
	_XX___X_,
	_XX__XX_,
	XXXXXXX_,
	________,
// 320 $140 'ldot'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XXX____,
	__XX____,
	__XX_XX_,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 321 $141 'Lslash'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXX____,
	_XX_____,
	_XXXX___,
	_XXX____,
	XXX___X_,
	_XX__XX_,
	XXXXXXX_,
	________,
// 322 $142 'lslash'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX____,
	__XX_XX_,
	__XXXX__,
	__XXX___,
	__XX____,
	_XXX____,
	XX_XX___,
	________,
// 323 $143 'Nacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	____XXX_,
	________,
	XXX__XX_,
	XXXX_XX_,
	XX_XXXX_,
	XX__XXX_,
	XX___XX_,
	________,
// 324 $144 'nacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	________,
	XXXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
// 325 $145 'Ncommaaccent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XX___XX_,
	XXX__XX_,
	XXXX_XX_,
	XX_XXXX_,
	XX__XXX_,
	XX___XX_,
	___XX___,
	_XXX____,
// 326 $146 'ncommaaccent'
//	width 8, bbx 0, bby -1, bbw 6, bbh 6
	XXXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	__XX____,
	XXX_____,
	________,
	________,
// 327 $147 'Ncaron'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XX_XX__,
	__XXX___,
	XXX__XX_,
	XXXX_XX_,
	XX_XXXX_,
	XX__XXX_,
	XX___XX_,
	________,
// 328 $148 'ncaron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	________,
	XXXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
// 329 $149 'napostrophe'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XX_____,
	XX______,
	________,
	XXXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
// 330 $14a 'Eng'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XX___XX_,
	XXX__XX_,
	XXXX_XX_,
	XX_XXXX_,
	XX__XXX_,
	XX___XX_,
	XX___XX_,
	___XXX__,
// 331 $14b 'eng'
//	width 8, bbx 0, bby -1, bbw 6, bbh 6
	XXXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	___XX___,
	________,
	________,
// 332 $14c 'Omacron'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	________,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 333 $14d 'omacron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 6
	XXXXXX__,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
	________,
// 334 $14e 'Obreve'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	_XXXXX__,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 335 $14f 'obreve'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 336 $150 'Ohungarumlaut'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XX_XX_,
	________,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 337 $151 'ohungarumlaut'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	__XX_XX_,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
	________,
// 338 $152 'OE'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXXXX_,
	_XX_XX__,
	XX__XX__,
	XX__XXX_,
	XX__XX__,
	_XX_XX__,
	__XXXXX_,
	________,
// 339 $153 'oe'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	_XXXXXX_,
	XX_XX___,
	XX_XXXX_,
	XX_XX___,
	_XXXXXX_,
	________,
	________,
	________,
// 340 $154 'Racute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	____XXX_,
	________,
	XXXXXX__,
	_XX__XX_,
	_XXXXX__,
	_XX_XX__,
	XXX__XX_,
	________,
// 341 $155 'racute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	____XXX_,
	________,
	XX_XXX__,
	_XXX_XX_,
	_XX__XX_,
	_XX_____,
	XXXX____,
	________,
// 342 $156 'Rcommaaccent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_XX__,
	XXX__XX_,
	___XX___,
	_XXX____,
// 343 $157 'rcommaaccent'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	XX_XXX__,
	_XXX_XX_,
	_XX_____,
	XXXX____,
	___XX___,
	_XXX____,
	________,
	________,
// 344 $158 'Rcaron'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XX_XX__,
	__XXX___,
	XXXXXX__,
	_XX__XX_,
	_XXXXX__,
	_XX_XX__,
	XXX__XX_,
	________,
// 345 $159 'rcaron'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XX_XX__,
	__XXX___,
	XX_XXX__,
	_XXX_XX_,
	_XX__XX_,
	_XX_____,
	XXXX____,
	________,
// 346 $15a 'Sacute'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_XXXX_XX,
	XX__XX__,
	XXX_____,
	_XXX____,
	___XXX__,
	XX__XX__,
	_XXXX___,
	________,
// 347 $15b 'sacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	________,
	_XXXXX__,
	XX______,
	_XXXX___,
	____XX__,
	XXXXX___,
	________,
// 348 $15c 'Scircumflex'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XXX___,
	_XX_XX__,
	_XXXXX__,
	XXX_____,
	_XXXX___,
	___XXX__,
	XXXXX___,
	________,
// 349 $15d 'scircumflex'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XXX___,
	_XX_XX__,
	________,
	_XXXX___,
	XXX_____,
	___XXX__,
	_XXXX___,
	________,
// 350 $15e 'Scedilla'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	_XXXX___,
	XX__XX__,
	XXX_____,
	_XXX____,
	___XXX__,
	XX__XX__,
	_XXXX___,
	XXX_____,
// 351 $15f 'scedilla'
//	width 8, bbx 0, bby -1, bbw 6, bbh 6
	_XXXXX__,
	XX______,
	_XXXX___,
	____XX__,
	XXXXX___,
	XXX_____,
	________,
	________,
// 352 $160 'Scaron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	XX__XX__,
	_XX_____,
	___XX___,
	XX__XX__,
	_XXXX___,
	________,
// 353 $161 'scaron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XX_XX__,
	__XXX___,
	_XXXXX__,
	XX______,
	_XXXX___,
	____XX__,
	XXXXX___,
	________,
// 354 $162 'Tcommaaccent'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	XXXXXX__,
	X_XX_X__,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	___XX___,
	XXXX____,
// 355 $163 'tcommaaccent'
//	width 8, bbx 1, bby -1, bbw 5, bbh 8
	___X____,
	__XX____,
	_XXXXX__,
	__XX____,
	__XX____,
	__XX_X__,
	___XX___,
	_XXX____,
// 356 $164 'Tcaron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	XXXXXX__,
	X_XX_X__,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 357 $165 'tcaron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	__XX____,
	_XXXXX__,
	__XX____,
	__XX_X__,
	___XX___,
	________,
// 358 $166 'Tbar'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	X_XX_X__,
	__XX____,
	XXXXXX__,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 359 $167 'tbar'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	___X____,
	__XX____,
	_XXXXX__,
	__XX____,
	_XXXX___,
	__XX__X_,
	___XXX__,
	________,
// 360 $168 'Utilde'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX_XX_,
	XX_XXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXX__,
	________,
// 361 $169 'utilde'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX_XX_,
	XX_XXX__,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 362 $16a 'Umacron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 363 $16b 'umacron'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXX__,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXXX_,
	________,
	________,
// 364 $16c 'Ubreve'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 365 $16d 'ubreve'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX__XX__,
	_XXXX___,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 366 $16e 'Uring'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 367 $16f 'uring'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XX____,
	__XX____,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 368 $170 'Uhungarumlaut'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XX_XX_,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 369 $171 'uhungarumlaut'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	__XX_XX_,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXXX_,
	________,
	________,
// 370 $172 'Uogonek'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	____XXX_,
// 371 $173 'uogonek'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XXX_,
	________,
	________,
// 372 $174 'Wcircumflex'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	________,
	XX_X_XX_,
	XXXXXXX_,
	XXX_XXX_,
	XX___XX_,
	________,
// 373 $175 'wcircumflex'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	________,
	XX___XX_,
	XX_X_XX_,
	XXXXXXX_,
	_XX_XX__,
	________,
// 374 $176 'Ycircumflex'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	________,
	XX__XX__,
	_XXXX___,
	__XX____,
	_XXXX___,
	________,
// 375 $177 'ycircumflex'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	_XXXX___,
	XX__XX__,
	________,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	_XXXX___,
// 376 $178 'Ydieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	_XXXX___,
	________,
// 377 $179 'Zacute'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	______XX,
	XXXXXXX_,
	XX__XX__,
	X__XX___,
	__XX__X_,
	_XX__XX_,
	XXXXXXX_,
	________,
// 378 $17a 'zacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	________,
	XXXXXX__,
	X__XX___,
	__XX____,
	_XX__X__,
	XXXXXX__,
	________,
// 379 $17b 'Zdotaccent'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XX____,
	XXXXXXX_,
	XX__XX__,
	X__XX___,
	__XX__X_,
	_XX__XX_,
	XXXXXXX_,
	________,
// 380 $17c 'zdotaccent'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	________,
	XXXXXX__,
	X__XX___,
	__XX____,
	_XX__X__,
	XXXXXX__,
	________,
// 381 $17d 'Zcaron'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	XX____XX,
	_XXXXXX_,
	_XX__XX_,
	_X__XX__,
	___XX___,
	__XX__X_,
	_XXXXXX_,
	________,
// 382 $17e 'zcaron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	_XXXX___,
	XXXXXX__,
	X__XX___,
	__XX____,
	_XX__X__,
	XXXXXX__,
	________,
// 383 $17f 'longs'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XXX___,
	_XX_XX__,
	_XX_____,
	_XX_____,
	_XX_____,
	_XX_____,
	XXXX____,
	________,
// 402 $192 'florin'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	____XXX_,
	___XX_XX,
	___XX___,
	__XXXX__,
	___XX___,
	___XX___,
	XX_XX___,
	_XXX____,
// 417 $1a1 'ohorn'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	_XXXXXX_,
	XX_XX___,
	XX_XX___,
	XX_XX___,
	_XXX____,
	________,
	________,
	________,
// 439 $1b7 'uni01B7'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	XX__XX__,
	___XX___,
	__XXX___,
	____XX__,
	XX__XX__,
	_XXXX___,
	________,
// 506 $1fa 'Aringacute'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XXXX__,
	__XX____,
	________,
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	________,
// 507 $1fb 'aringacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXXX__,
	__XX____,
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXXXXX_,
	________,
// 508 $1fc 'AEacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	____XXX_,
	________,
	__XXXXX_,
	_XX_XX__,
	XXXXXXX_,
	XX__XX__,
	XX__XXX_,
	________,
// 509 $1fd 'aeacute'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	____XXX_,
	________,
	_XXXXXXX,
	____XX__,
	_XXXXXXX,
	XX__XX__,
	_XXXXXXX,
	________,
// 510 $1fe 'Oslashacute'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	_____XXX,
	__XXX_X_,
	_XX_XX__,
	XX_X_XX_,
	XX_X_XX_,
	_XX_XX__,
	X_XXX___,
	________,
// 511 $1ff 'oslashacute'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	___XXX__,
	______X_,
	_XXXXX__,
	XX__XXX_,
	XX_X_XX_,
	XXX__XX_,
	_XXXXX__,
	X_______,
// 536 $218 'Scommaaccent'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	_XXXX___,
	XX__XX__,
	XXX_____,
	_XXX____,
	___XXX__,
	XX__XX__,
	_XXXX___,
	__XX____,
// 537 $219 'scommaaccent'
//	width 8, bbx 0, bby -1, bbw 6, bbh 6
	_XXXXX__,
	XX______,
	_XXXX___,
	____XX__,
	XXXXX___,
	__XX____,
	________,
	________,
// 538 $21a 'uni021A'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	XXXXXX__,
	X_XX_X__,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	__XX____,
// 539 $21b 'uni021B'
//	width 8, bbx 1, bby -1, bbw 5, bbh 8
	___X____,
	__XX____,
	_XXXXX__,
	__XX____,
	__XX____,
	__XX_X__,
	___XX___,
	__XX____,
// 593 $251 'uni0251'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	_XXX_XX_,
	XX_XXX__,
	XX__X___,
	XX_XXX__,
	_XXX_XX_,
	________,
	________,
	________,
// 632 $278 'uni0278'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	XXXXXX__,
	__XX____,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	XXXXXX__,
// 710 $2c6 'circumflex'
//	width 8, bbx 1, bby 4, bbw 5, bbh 3
	___X____,
	__XXX___,
	_XX_XX__,
	________,
	________,
	________,
	________,
	________,
// 711 $2c7 'caron'
//	width 8, bbx 0, bby 5, bbw 5, bbh 2
	XX_XX___,
	_XXX____,
	________,
	________,
	________,
	________,
	________,
	________,
// 713 $2c9 'uni02C9'
//	width 8, bbx 1, bby 6, bbw 5, bbh 1
	_XXXXX__,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 728 $2d8 'breve'
//	width 8, bbx 0, bby 5, bbw 7, bbh 2
	XX___XX_,
	_XXXXX__,
	________,
	________,
	________,
	________,
	________,
	________,
// 729 $2d9 'dotaccent'
//	width 8, bbx 2, bby 6, bbw 2, bbh 1
	__XX____,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 730 $2da 'ring'
//	width 8, bbx 1, bby 3, bbw 5, bbh 4
	__XXX___,
	_XX_XX__,
	_XX_XX__,
	__XXX___,
	________,
	________,
	________,
	________,
// 731 $2db 'ogonek'
//	width 8, bbx 3, bby -1, bbw 3, bbh 2
	___XX___,
	___XXX__,
	________,
	________,
	________,
	________,
	________,
	________,
// 732 $2dc 'tilde'
//	width 8, bbx 0, bby 5, bbw 7, bbh 2
	_XXX_XX_,
	XX_XXX__,
	________,
	________,
	________,
	________,
	________,
	________,
// 733 $2dd 'hungarumlaut'
//	width 8, bbx 2, bby 6, bbw 5, bbh 1
	__XX_XX_,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 894 $37e 'uni037E'
//	width 8, bbx 1, bby 0, bbw 3, bbh 6
	__XX____,
	__XX____,
	________,
	__XX____,
	__XX____,
	_XX_____,
	________,
	________,
// 900 $384 'tonos'
//	width 8, bbx 2, bby 4, bbw 3, bbh 3
	___XX___,
	__XX____,
	__X_____,
	________,
	________,
	________,
	________,
	________,
// 901 $385 'dieresistonos'
//	width 8, bbx 0, bby 5, bbw 8, bbh 2
	____X___,
	XX____XX,
	________,
	________,
	________,
	________,
	________,
	________,
// 902 $386 'Alphatonos'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	X__XX___,
	X_XXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXXX_,
	_XX__XX_,
	_XX__XX_,
	________,
// 903 $387 'anoteleia'
//	width 8, bbx 3, bby 3, bbw 2, bbh 2
	___XX___,
	___XX___,
	________,
	________,
	________,
	________,
	________,
	________,
// 904 $388 'Epsilontonos'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	X_XXXXX_,
	X_XX__X_,
	__XX____,
	__XXXX__,
	__XX____,
	__XX__X_,
	__XXXXX_,
	________,
// 905 $389 'Etatonos'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	X_XX_XX_,
	X_XX_XX_,
	__XX_XX_,
	__XXXXX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	________,
// 906 $38a 'Iotatonos'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	X_XXXX__,
	X__XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	__XXXX__,
	________,
// 908 $38c 'Omicrontonos'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	X_XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 910 $38e 'Upsilontonos'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	X_XX_XX_,
	X_XX_XX_,
	__XX_XX_,
	___XXX__,
	____X___,
	____X___,
	___XXX__,
	________,
// 911 $38f 'Omegatonos'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	X_XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	XXX_XXX_,
	________,
// 912 $390 'iotadieresistonos'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	____X___,
	XX____XX,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	____XX__,
	________,
// 913 $391 'Alpha'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	XX__XX__,
	________,
// 914 $392 'Beta'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	XXXXXX__,
	________,
// 915 $393 'Gamma'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	XX__XX__,
	XX______,
	XX______,
	XX______,
	XX______,
	XX______,
	________,
// 916 $394 'uni0394'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___X____,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XXXXXXX_,
	________,
// 917 $395 'Epsilon'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	_XX___X_,
	_XX_X___,
	_XXXX___,
	_XX_X___,
	_XX___X_,
	XXXXXXX_,
	________,
// 918 $396 'Zeta'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	XX___XX_,
	X___XX__,
	___XX___,
	__XX__X_,
	_XX__XX_,
	XXXXXXX_,
	________,
// 919 $397 'Eta'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
// 920 $398 'Theta'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XXXXXXX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 921 $399 'Iota'
//	width 8, bbx 1, bby 0, bbw 4, bbh 7
	_XXXX___,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 922 $39a 'Kappa'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX__XX_,
	_XX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	_XX__XX_,
	XXX__XX_,
	________,
// 923 $39b 'Lambda'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___X____,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	________,
// 924 $39c 'Mu'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XXX_XXX_,
	XXXXXXX_,
	XXXXXXX_,
	XX_X_XX_,
	XX___XX_,
	XX___XX_,
	________,
// 925 $39d 'Nu'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XXX__XX_,
	XXXX_XX_,
	XX_XXXX_,
	XX__XXX_,
	XX___XX_,
	XX___XX_,
	________,
// 926 $39e 'Xi'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	XX___XX_,
	________,
	_XXXXX__,
	________,
	XX___XX_,
	XXXXXXX_,
	________,
// 927 $39f 'Omicron'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 928 $3a0 'Pi'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
// 929 $3a1 'Rho'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_____,
	_XX_____,
	XXXX____,
	________,
// 931 $3a3 'Sigma'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	_XX__XX_,
	__XX____,
	___XX___,
	__XX____,
	_XX__XX_,
	XXXXXXX_,
	________,
// 932 $3a4 'Tau'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	X_XX_X__,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 933 $3a5 'Upsilon'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 934 $3a6 'Phi'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___X____,
	_XXXXX__,
	XX_X_XX_,
	XX_X_XX_,
	_XXXXX__,
	___X____,
	___X____,
	________,
// 935 $3a7 'Chi'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	________,
// 936 $3a8 'Psi'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XX_X_XX_,
	XX_X_XX_,
	_XXXXX__,
	___X____,
	___X____,
	___X____,
	________,
// 937 $3a9 'uni03A9'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	XXX_XXX_,
	________,
// 938 $3aa 'Iotadieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	_XXXX___,
	__XX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
// 939 $3ab 'Upsilondieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	_XXXX___,
	________,
// 940 $3ac 'alphatonos'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XX___,
	________,
	_XXX_XX_,
	XX_XXX__,
	XX__XX__,
	XX_XXX__,
	_XXX_XX_,
	________,
// 941 $3ad 'epsilontonos'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	________,
	_XXXXX__,
	XX______,
	_XXX____,
	XX______,
	_XXXXX__,
	________,
// 942 $3ae 'etatonos'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	________,
	X_XXX___,
	XXX_XX__,
	_XX_XX__,
	_XX_XX__,
	_XX_XX__,
	________,
// 943 $3af 'iotatonos'
//	width 8, bbx 2, bby 0, bbw 3, bbh 7
	__XX____,
	________,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	___XX___,
	________,
// 944 $3b0 'upsilondieresistonos'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	____X___,
	XX____XX,
	________,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXX__,
	________,
// 945 $3b1 'alpha'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	_XXX_XX_,
	XX_XXX__,
	XX__XX__,
	XX_XXX__,
	_XXX_XX_,
	________,
	________,
	________,
// 946 $3b2 'beta'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XXXXX___,
	XX__XX__,
	XXXXX___,
	XX______,
	XX______,
// 947 $3b3 'gamma'
//	width 8, bbx 0, bby -1, bbw 6, bbh 6
	XX__XX__,
	_XXXX___,
	__XX____,
	_XXXX___,
	XX__XX__,
	_XXXX___,
	________,
	________,
// 948 $3b4 'delta'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	_XX_____,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 949 $3b5 'epsilon'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	_XXXXX__,
	XX______,
	_XXX____,
	XX______,
	_XXXXX__,
	________,
	________,
	________,
// 950 $3b6 'zeta'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	XXXXXX__,
	__XX____,
	_XX_____,
	XX______,
	XX______,
	_XXXX___,
	____XX__,
	__XXX___,
// 951 $3b7 'eta'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	X_XXX___,
	XXX_XX__,
	_XX_XX__,
	_XX_XX__,
	_XX_XX__,
	________,
	________,
	________,
// 952 $3b8 'theta'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 953 $3b9 'iota'
//	width 8, bbx 2, bby 0, bbw 3, bbh 5
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	___XX___,
	________,
	________,
	________,
// 954 $3ba 'kappa'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	XX__XX__,
	XX_XX___,
	XXXX____,
	XX_XX___,
	XX__XX__,
	________,
	________,
	________,
// 955 $3bb 'lambda'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXX____,
	XX_XX___,
	____XX__,
	__XXXX__,
	_XX_XX__,
	XX__XX__,
	XX__XX__,
	________,
// 956 $3bc 'uni03BC'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XXXXXXX_,
	XX______,
	XX______,
	________,
	________,
// 957 $3bd 'nu'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	________,
	________,
	________,
// 958 $3be 'xi'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	XXXXXX__,
	__XX____,
	_XX_____,
	__XXX___,
	_XX_____,
	__XXX___,
	____XX__,
	__XXX___,
// 959 $3bf 'omicron'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
	________,
	________,
// 960 $3c0 'pi'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	XXXXXX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
	________,
	________,
// 961 $3c1 'rho'
//	width 8, bbx 0, bby -1, bbw 6, bbh 6
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XXXXX___,
	XX______,
	XX______,
	________,
	________,
// 962 $3c2 'sigma1'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	_XXXXX__,
	XX___XX_,
	XX______,
	_XXXXX__,
	_____XX_,
	___XXX__,
	________,
	________,
// 963 $3c3 'sigma'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	_XXXXX__,
	XX_XX___,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
	________,
	________,
// 964 $3c4 'tau'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	XXXXXX__,
	__XX____,
	__XX____,
	__XX____,
	___XX___,
	________,
	________,
	________,
// 965 $3c5 'upsilon'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
	________,
	________,
// 966 $3c6 'phi'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	XX_XXX__,
	XX_X_XX_,
	XX_X_XX_,
	_XXXXX__,
	___X____,
	___X____,
	________,
	________,
// 967 $3c7 'chi'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	XX__XX__,
	_XXXX___,
	__XX____,
	_XXXX___,
	XX__XX__,
	________,
	________,
	________,
// 968 $3c8 'psi'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	_XXXXX__,
	___X____,
	___X____,
	________,
	________,
// 969 $3c9 'omega'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XX___XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	_XX_XX__,
	________,
	________,
	________,
// 970 $3ca 'iotadieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	___XX___,
	________,
// 971 $3cb 'upsilondieresis'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XX__XX__,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 972 $3cc 'omicrontonos'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	________,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 973 $3cd 'upsilontonos'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	________,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 974 $3ce 'omegatonos'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XX___,
	________,
	XX___XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	_XX_XX__,
	________,
// 976 $3d0 'uni03D0'
//	width 8, bbx 0, bby -1, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	XXXXX___,
	XX__XX__,
	XXXXX___,
	XX______,
	XX______,
	________,
// 1012 $3f4 'uni03F4'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XXXXXXX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 1024 $400 'uni0400'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX_____,
	________,
	XXXXXXX_,
	_XX___X_,
	_XXXX___,
	_XX___X_,
	XXXXXXX_,
	________,
// 1025 $401 'afii10023'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XX_XX__,
	XXXXXXX_,
	_XX___X_,
	_XXXX___,
	_XX_____,
	_XX___X_,
	XXXXXXX_,
	________,
// 1026 $402 'afii10051'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXX__,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX_XX__,
	________,
// 1027 $403 'afii10052'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	__X_____,
	XXXXXXX_,
	XX___XX_,
	XX______,
	XX______,
	XX______,
	________,
// 1028 $404 'afii10053'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXXX__,
	_XX__XX_,
	XX______,
	XXXXX___,
	XX______,
	_XX__XX_,
	__XXXX__,
	________,
// 1029 $405 'afii10054'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	__XXXX__,
	_XX__XX_,
	_XXX____,
	__XXX___,
	____XXX_,
	_XX__XX_,
	__XXXX__,
	________,
// 1030 $406 'afii10055'
//	width 8, bbx 2, bby 0, bbw 4, bbh 7
	__XXXX__,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	__XXXX__,
	________,
// 1031 $407 'afii10056'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XX__XX_,
	________,
	__XXXX__,
	___XX___,
	___XX___,
	___XX___,
	__XXXX__,
	________,
// 1032 $408 'afii10057'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XXXX_,
	____XX__,
	____XX__,
	____XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 1033 $409 'afii10058'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXX___,
	_X_XX___,
	_X_XXX__,
	_X_XX_X_,
	_X_XX_X_,
	_X_XX_X_,
	XX_XXX__,
	________,
// 1034 $40a 'afii10059'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX_XX___,
	XX_XX___,
	XX_XX___,
	XXXXXX__,
	XX_XX_X_,
	XX_XX_X_,
	XX_XXX__,
	________,
// 1035 $40b 'afii10060'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXX___,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	________,
// 1036 $40c 'afii10061'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XX___,
	XXX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	_XX__XX_,
	XXX__XX_,
	________,
// 1037 $40d 'uni040D'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXX____,
	___X____,
	XX___XX_,
	XX__XXX_,
	XX_XXXX_,
	XXXX_XX_,
	XXX__XX_,
	________,
// 1038 $40e 'afii10062'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	________,
	XX___XX_,
	XX___XX_,
	_XXXXXX_,
	_____XX_,
	_XXXXX__,
	________,
// 1039 $40f 'afii10145'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XXXXXXX_,
	___X____,
// 1040 $410 'afii10017'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XX____,
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XXXXXX__,
	XX__XX__,
	XX__XX__,
	________,
// 1041 $411 'afii10018'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	_XX__XX_,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	XXXXXX__,
	________,
// 1042 $412 'afii10019'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	XXXXXX__,
	________,
// 1043 $413 'afii10020'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	_XX__XX_,
	_XX___X_,
	_XX_____,
	_XX_____,
	_XX_____,
	XXXX____,
	________,
// 1044 $414 'afii10021'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	___XXXX_,
	__XX_XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	XXXXXXXX,
	XX____XX,
// 1045 $415 'afii10022'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXXX_,
	_XX___X_,
	_XX_X___,
	_XXXX___,
	_XX_X___,
	_XX___X_,
	XXXXXXX_,
	________,
// 1046 $416 'afii10024'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX_X_XX_,
	XX_X_XX_,
	_XXXXX__,
	__XXX___,
	_XXXXX__,
	XX_X_XX_,
	XX_X_XX_,
	________,
// 1047 $417 'afii10025'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX___XX_,
	_____XX_,
	__XXXX__,
	_____XX_,
	XX___XX_,
	_XXXXX__,
	________,
// 1048 $418 'afii10026'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XX___XX_,
	XX__XXX_,
	XX_XXXX_,
	XXXX_XX_,
	XXX__XX_,
	XX___XX_,
	________,
// 1049 $419 'afii10027'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	XX___XX_,
	XX__XXX_,
	XX_XXXX_,
	XXXX_XX_,
	XXX__XX_,
	XX___XX_,
	________,
// 1050 $41a 'afii10028'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX__XX_,
	_XX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	_XX__XX_,
	XXX__XX_,
	________,
// 1051 $41b 'afii10029'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XXXX_,
	__XX_XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	XX___XX_,
	________,
// 1052 $41c 'afii10030'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XXX_XXX_,
	XXXXXXX_,
	XXXXXXX_,
	XX_X_XX_,
	XX___XX_,
	XX___XX_,
	________,
// 1053 $41d 'afii10031'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XXXXXX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	________,
// 1054 $41e 'afii10032'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	________,
// 1055 $41f 'afii10033'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XXXXXX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	________,
// 1056 $420 'afii10034'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_____,
	XXXX____,
	________,
// 1057 $421 'afii10035'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXXX__,
	_XX__XX_,
	XX______,
	XX______,
	XX______,
	_XX__XX_,
	__XXXX__,
	________,
// 1058 $422 'afii10036'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XXXXXX_,
	_X_XX_X_,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	__XXXX__,
	________,
// 1059 $423 'afii10037'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXXX_,
	_____XX_,
	_XX__XX_,
	__XXXX__,
	________,
// 1060 $424 'afii10038'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	_XXXXX__,
	___X____,
	__XXX___,
	________,
// 1061 $425 'afii10039'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	________,
// 1062 $426 'afii10040'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XXXXXXX_,
	_____XX_,
// 1063 $427 'afii10041'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXXX_,
	_____XX_,
	_____XX_,
	_____XX_,
	________,
// 1064 $428 'afii10042'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XXXXXXX_,
	________,
// 1065 $429 'afii10043'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XXXXXXXX,
	______XX,
// 1066 $42a 'afii10044'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXX____,
	X_XX____,
	X_XX____,
	__XXXX__,
	__XX_XX_,
	__XX_XX_,
	__XXXX__,
	________,
// 1067 $42b 'afii10045'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XXXX_XX_,
	XX_XXXX_,
	XX_XXXX_,
	XXXX_XX_,
	________,
// 1068 $42c 'afii10046'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXXX____,
	_XX_____,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	________,
// 1069 $42d 'afii10047'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXX___,
	X___XX__,
	_____XX_,
	__XXXXX_,
	_____XX_,
	X___XX__,
	_XXXX___,
	________,
// 1070 $42e 'afii10048'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX__XX__,
	XX_X_XX_,
	XX_X_XX_,
	XXXX_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX__XX__,
	________,
// 1071 $42f 'afii10049'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	__XXXXX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXXX_,
	__XX_XX_,
	_XX__XX_,
	________,
// 1072 $430 'afii10065'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	_XXXX___,
	____XX__,
	_XXXXX__,
	XX__XX__,
	_XXX_XX_,
	________,
	________,
	________,
// 1073 $431 'afii10066'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_____XX_,
	__XXXX__,
	_XX_____,
	__XXXX__,
	_XX__XX_,
	_XX__XX_,
	__XXXX__,
	________,
// 1074 $432 'afii10067'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XXXXXX__,
	_XX__XX_,
	_XXXXX__,
	_XX__XX_,
	XXXXXX__,
	________,
	________,
	________,
// 1075 $433 'afii10068'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XXXXXXX_,
	_XX__XX_,
	_XX_____,
	_XX_____,
	XXXX____,
	________,
	________,
	________,
// 1076 $434 'afii10069'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	__XXXX__,
	_XX_XX__,
	_XX_XX__,
	_XX_XX__,
	XXXXXXX_,
	XX___XX_,
	________,
	________,
// 1077 $435 'afii10070'
//	width 8, bbx 1, bby 0, bbw 6, bbh 5
	__XXXX__,
	_XX__XX_,
	_XXXXXX_,
	_XX_____,
	__XXXX__,
	________,
	________,
	________,
// 1078 $436 'afii10072'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XX_X_XX_,
	_XXXXX__,
	__XXX___,
	_XXXXX__,
	XX_X_XX_,
	________,
	________,
	________,
// 1079 $437 'afii10073'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	_XXXXX__,
	XX___XX_,
	___XXX__,
	XX___XX_,
	_XXXXX__,
	________,
	________,
	________,
// 1080 $438 'afii10074'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XX___XX_,
	XX__XXX_,
	XX_XXXX_,
	XXXX_XX_,
	XXX__XX_,
	________,
	________,
	________,
// 1081 $439 'afii10075'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XX_XX__,
	__XXX___,
	XX___XX_,
	XX__XXX_,
	XX_XXXX_,
	XXXX_XX_,
	XXX__XX_,
	________,
// 1082 $43a 'afii10076'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XXX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	XXX__XX_,
	________,
	________,
	________,
// 1083 $43b 'afii10077'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	__XXXXX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	XXX__XX_,
	________,
	________,
	________,
// 1084 $43c 'afii10078'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XX___XX_,
	XXXXXXX_,
	XXXXXXX_,
	XX_X_XX_,
	XX___XX_,
	________,
	________,
	________,
// 1085 $43d 'afii10079'
//	width 8, bbx 1, bby 0, bbw 6, bbh 5
	_XX__XX_,
	_XX__XX_,
	_XXXXXX_,
	_XX__XX_,
	_XX__XX_,
	________,
	________,
	________,
// 1086 $43e 'afii10080'
//	width 8, bbx 1, bby 0, bbw 6, bbh 5
	__XXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXX__,
	________,
	________,
	________,
// 1087 $43f 'afii10081'
//	width 8, bbx 1, bby 0, bbw 6, bbh 5
	_XXXXXX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	________,
	________,
	________,
// 1088 $440 'afii10082'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_____,
	XXXX____,
	________,
	________,
// 1089 $441 'afii10083'
//	width 8, bbx 1, bby 0, bbw 6, bbh 5
	__XXXX__,
	_XX__XX_,
	_XX_____,
	_XX__XX_,
	__XXXX__,
	________,
	________,
	________,
// 1090 $442 'afii10084'
//	width 8, bbx 1, bby 0, bbw 6, bbh 5
	_XXXXXX_,
	_X_XX_X_,
	___XX___,
	___XX___,
	__XXXX__,
	________,
	________,
	________,
// 1091 $443 'afii10085'
//	width 8, bbx 1, bby -1, bbw 6, bbh 6
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXXX_,
	_____XX_,
	_XXXXX__,
	________,
	________,
// 1092 $444 'afii10086'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	_XXXXX__,
	XX_X_XX_,
	XX_X_XX_,
	_XXXXX__,
	___X____,
	__XXX___,
	________,
	________,
// 1093 $445 'afii10087'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XX___XX_,
	_XX_XX__,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	________,
	________,
	________,
// 1094 $446 'afii10088'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XXXXXXX_,
	_____XX_,
	________,
	________,
// 1095 $447 'afii10089'
//	width 8, bbx 1, bby 0, bbw 6, bbh 5
	_XX__XX_,
	_XX__XX_,
	__XXXXX_,
	_____XX_,
	_____XX_,
	________,
	________,
	________,
// 1096 $448 'afii10090'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XXXXXXX_,
	________,
	________,
	________,
// 1097 $449 'afii10091'
//	width 8, bbx 0, bby -1, bbw 8, bbh 6
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XXXXXXXX,
	______XX,
	________,
	________,
// 1098 $44a 'afii10092'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XXXX____,
	X_XX____,
	__XXXX__,
	__XX_XX_,
	__XXXX__,
	________,
	________,
	________,
// 1099 $44b 'afii10093'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XX___XX_,
	XX___XX_,
	XXXX_XX_,
	XX_XXXX_,
	XXXX_XX_,
	________,
	________,
	________,
// 1100 $44c 'afii10094'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XXXX____,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	XXXXXX__,
	________,
	________,
	________,
// 1101 $44d 'afii10095'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	_XXXXX__,
	XX___XX_,
	___XXXX_,
	XX___XX_,
	_XXXXX__,
	________,
	________,
	________,
// 1102 $44e 'afii10096'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XX__XX__,
	XX_X_XX_,
	XXXX_XX_,
	XX_X_XX_,
	XX__XX__,
	________,
	________,
	________,
// 1103 $44f 'afii10097'
//	width 8, bbx 1, bby 0, bbw 6, bbh 5
	__XXXXX_,
	_XX__XX_,
	__XXXXX_,
	__XX_XX_,
	_XX__XX_,
	________,
	________,
	________,
// 1104 $450 'uni0450'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XXX____,
	________,
	__XXXX__,
	_XX__XX_,
	_XXXXXX_,
	_XX_____,
	__XXXX__,
	________,
// 1105 $451 'afii10071'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XX__XX_,
	________,
	__XXXX__,
	_XX__XX_,
	_XXXXXX_,
	_XX_____,
	__XXXX__,
	________,
// 1106 $452 'afii10099'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	_XX_____,
	XXXX____,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	____XX__,
// 1107 $453 'afii10100'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	___XXX__,
	___X____,
	________,
	_XXXXXX_,
	_XX_____,
	_XX_____,
	_XX_____,
	________,
// 1108 $454 'afii10101'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	_XXXXX__,
	XX___XX_,
	XXXX____,
	XX___XX_,
	_XXXXX__,
	________,
	________,
	________,
// 1109 $455 'afii10102'
//	width 8, bbx 1, bby 0, bbw 6, bbh 5
	__XXXXX_,
	_XX_____,
	__XXXX__,
	_____XX_,
	_XXXXX__,
	________,
	________,
	________,
// 1110 $456 'afii10103'
//	width 8, bbx 2, bby 0, bbw 4, bbh 7
	___XX___,
	________,
	__XXX___,
	___XX___,
	___XX___,
	___XX___,
	__XXXX__,
	________,
// 1111 $457 'afii10104'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XX__XX_,
	________,
	__XXX___,
	___XX___,
	___XX___,
	___XX___,
	__XXXX__,
	________,
// 1112 $458 'afii10105'
//	width 8, bbx 1, bby -1, bbw 6, bbh 8
	_____XX_,
	________,
	_____XX_,
	_____XX_,
	_____XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXX__,
// 1113 $459 'afii10106'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XXXXX___,
	_X_XX___,
	_X_XXX__,
	_X_XX_X_,
	XX_XXX__,
	________,
	________,
	________,
// 1114 $45a 'afii10107'
//	width 8, bbx 0, bby 0, bbw 7, bbh 5
	XX_XX___,
	XX_XX___,
	XXXXXX__,
	XX_XX_X_,
	XX_XXX__,
	________,
	________,
	________,
// 1115 $45b 'afii10108'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XX_____,
	XXXX____,
	_XX_____,
	_XXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	________,
// 1116 $45c 'afii10109'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___XXX__,
	___X____,
	XXX__XX_,
	_XX_XX__,
	_XXXX___,
	_XX_XX__,
	XXX__XX_,
	________,
// 1117 $45d 'uni045D'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	__XXX___,
	____X___,
	________,
	_XX__XX_,
	_XX_XXX_,
	_XXXXXX_,
	_XXX_XX_,
	________,
// 1118 $45e 'afii10110'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	_XX_XX__,
	__XXX___,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	_XXXXXX_,
	_____XX_,
	_XXXXX__,
// 1119 $45f 'afii10193'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XXXXXXX_,
	___X____,
	________,
	________,
// 1168 $490 'afii10050'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_____XX_,
	XXXXXXX_,
	_XX_____,
	_XX_____,
	_XX_____,
	_XX_____,
	XXXX____,
	________,
// 1169 $491 'afii10098'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	_____XX_,
	XXXXXXX_,
	_XX_____,
	_XX_____,
	_XX_____,
	XXXX____,
	________,
	________,
// 1470 $5be 'afii57645'
//	width 8, bbx 1, bby 5, bbw 6, bbh 1
	_XXXXXX_,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 1488 $5d0 'afii57664'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XX___XX_,
	_XX__XX_,
	_XXX_XX_,
	XX_XXX__,
	XX__XX__,
	XX___XX_,
	________,
	________,
// 1489 $5d1 'afii57665'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXX___,
	____XX__,
	____XX__,
	____XX__,
	____XX__,
	XXXXXXX_,
	________,
	________,
// 1490 $5d2 'afii57666'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	__XXX___,
	____XX__,
	____XX__,
	___XXX__,
	__XX_X__,
	XXX__XX_,
	________,
	________,
// 1491 $5d3 'afii57667'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXXX_,
	____XX__,
	____XX__,
	____XX__,
	____XX__,
	____XX__,
	________,
	________,
// 1492 $5d4 'afii57668'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXX__,
	_____XX_,
	_____XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	________,
	________,
// 1493 $5d5 'afii57669'
//	width 8, bbx 1, bby 0, bbw 4, bbh 6
	_XXX____,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	________,
	________,
// 1494 $5d6 'afii57670'
//	width 8, bbx 2, bby 0, bbw 4, bbh 6
	__XXXX__,
	___XX___,
	___XX___,
	____XX__,
	___XX___,
	__XX____,
	________,
	________,
// 1495 $5d7 'afii57671'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXX__,
	_XX__XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	________,
	________,
// 1496 $5d8 'afii57672'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XX__XX__,
	XX_X_XX_,
	XX_X_XX_,
	XX___XX_,
	XX__XX__,
	_XXXX___,
	________,
	________,
// 1497 $5d9 'afii57673'
//	width 8, bbx 2, bby 2, bbw 4, bbh 4
	__XXX___,
	____XX__,
	____XX__,
	___XX___,
	________,
	________,
	________,
	________,
// 1498 $5da 'afii57674'
//	width 8, bbx 0, bby -1, bbw 7, bbh 7
	XXXXXX__,
	_____XX_,
	_____XX_,
	____XX__,
	____XX__,
	____XX__,
	____XXX_,
	________,
// 1499 $5db 'afii57675'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXX__,
	_____XX_,
	_____XX_,
	_____XX_,
	_____XX_,
	XXXXXX__,
	________,
	________,
// 1500 $5dc 'afii57676'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX______,
	XXXXXX__,
	_____XX_,
	_____XX_,
	____XX__,
	___XX___,
	___XX___,
	________,
// 1501 $5dd 'afii57677'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXX__,
	_XX__XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XXXXXXX_,
	________,
	________,
// 1502 $5de 'afii57678'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XX_XXX__,
	_XXX_XX_,
	_XX__XX_,
	XX___XX_,
	XX___XX_,
	XX_XXXX_,
	________,
	________,
// 1503 $5df 'afii57679'
//	width 8, bbx 2, bby -1, bbw 4, bbh 7
	__XXX___,
	____XX__,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XXX__,
	________,
// 1504 $5e0 'afii57680'
//	width 8, bbx 1, bby 0, bbw 5, bbh 6
	__XXX___,
	____XX__,
	____XX__,
	____XX__,
	____XX__,
	_XXXXX__,
	________,
	________,
// 1505 $5e1 'afii57681'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXX__,
	_XX__XX_,
	XX___XX_,
	XX___XX_,
	XX__XX__,
	_XXXX___,
	________,
	________,
// 1506 $5e2 'afii57682'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XX_XX_,
	XXXXXX__,
	________,
	________,
// 1507 $5e3 'afii57683'
//	width 8, bbx 0, bby -1, bbw 7, bbh 7
	XXXXX___,
	_X__XX__,
	XX__XX__,
	XXX_XX__,
	____XX__,
	____XX__,
	____XXX_,
	________,
// 1508 $5e4 'afii57684'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXX__,
	_X___XX_,
	XX___XX_,
	XXX__XX_,
	_____XX_,
	XXXXXXX_,
	________,
	________,
// 1509 $5e5 'afii57685'
//	width 8, bbx 1, bby -1, bbw 6, bbh 7
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XXXXX__,
	_XX_____,
	_XX_____,
	_XXX____,
	________,
// 1510 $5e6 'afii57686'
//	width 8, bbx 1, bby 0, bbw 6, bbh 6
	_XX__XX_,
	__XX_XX_,
	___XXX__,
	____XX__,
	_____XX_,
	_XXXXXX_,
	________,
	________,
// 1511 $5e7 'afii57687'
//	width 8, bbx 0, bby -1, bbw 7, bbh 7
	XXXXXX__,
	_____XX_,
	_XX__XX_,
	_XX_XX__,
	_XX_XXX_,
	_XX_____,
	_XX_____,
	________,
// 1512 $5e8 'afii57688'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXX__,
	_____XX_,
	_____XX_,
	_____XX_,
	_____XX_,
	_____XX_,
	________,
	________,
// 1513 $5e9 'afii57689'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XX_X_XX_,
	XX_X_XX_,
	XX_X_XX_,
	XXXX_XX_,
	XX___XX_,
	_XXXXX__,
	________,
	________,
// 1514 $5ea 'afii57690'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	XXX__XX_,
	XXX__XX_,
	________,
	________,
// 1520 $5f0 'afii57716'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XX__XX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	________,
	________,
// 1521 $5f1 'afii57717'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XX__XX__,
	_XX__XX_,
	_XX__XX_,
	_____XX_,
	_____XX_,
	_____XX_,
	________,
	________,
// 1522 $5f2 'afii57718'
//	width 8, bbx 0, bby 3, bbw 7, bbh 3
	XX__XX__,
	_XX__XX_,
	_XX__XX_,
	________,
	________,
	________,
	________,
	________,
// 1523 $5f3 'uni05F3'
//	width 8, bbx 2, bby 4, bbw 3, bbh 3
	___XX___,
	___XX___,
	__XX____,
	________,
	________,
	________,
	________,
	________,
// 1524 $5f4 'uni05F4'
//	width 8, bbx 0, bby 4, bbw 7, bbh 3
	_XX__XX_,
	_XX__XX_,
	XX__XX__,
	________,
	________,
	________,
	________,
	________,
// 7451 $1d1b 'uni1D1B'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	_XXX_XX_,
	XX_XXX__,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	________,
	________,
// 7462 $1d26 'uni1D26'
//	width 8, bbx 0, bby 0, bbw 6, bbh 6
	XXXXXX__,
	XX__XX__,
	XX______,
	XX______,
	XX______,
	XX______,
	________,
	________,
// 7464 $1d28 'uni1D28'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXXXX_,
	_XX_XX__,
	_XX_XX__,
	_XX_XX__,
	_XX_XX__,
	_XX_XX__,
	________,
	________,
// 7808 $1e80 'Wgrave'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX_____,
	________,
	XX___XX_,
	XX_X_XX_,
	XXXXXXX_,
	XXX_XXX_,
	XX___XX_,
	________,
// 7809 $1e81 'wgrave'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XXX_____,
	________,
	XX___XX_,
	XX_X_XX_,
	XXXXXXX_,
	XXXXXXX_,
	_XX_XX__,
	________,
// 7810 $1e82 'Wacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	____XXX_,
	________,
	XX___XX_,
	XX_X_XX_,
	XXXXXXX_,
	XXX_XXX_,
	XX___XX_,
	________,
// 7811 $1e83 'wacute'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	____XXX_,
	________,
	XX___XX_,
	XX_X_XX_,
	XXXXXXX_,
	XXXXXXX_,
	_XX_XX__,
	________,
// 7812 $1e84 'Wdieresis'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	________,
	XX___XX_,
	XX_X_XX_,
	XXXXXXX_,
	XXX_XXX_,
	XX___XX_,
	________,
// 7813 $1e85 'wdieresis'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	XX___XX_,
	________,
	XX___XX_,
	XX_X_XX_,
	XXXXXXX_,
	XXXXXXX_,
	_XX_XX__,
	________,
// 7839 $1e9f 'uni1E9F'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XXX__,
	__XX____,
	___XX___,
	_XXXXX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 7922 $1ef2 'Ygrave'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXX_____,
	________,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	__XX____,
	_XXXX___,
	________,
// 7923 $1ef3 'ygrave'
//	width 8, bbx 0, bby -1, bbw 6, bbh 7
	XXX_____,
	________,
	XX__XX__,
	XX__XX__,
	_XXXXX__,
	____XX__,
	XXXXX___,
	________,
// 8208 $2010 'uni2010'
//	width 8, bbx 0, bby 3, bbw 6, bbh 1
	XXXXXX__,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 8210 $2012 'figuredash'
//	width 8, bbx 1, bby 3, bbw 5, bbh 1
	_XXXXX__,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 8211 $2013 'endash'
//	width 8, bbx 1, bby 3, bbw 5, bbh 1
	_XXXXX__,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 8212 $2014 'emdash'
//	width 8, bbx 0, bby 3, bbw 8, bbh 1
	XXXXXXXX,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 8213 $2015 'afii00208'
//	width 8, bbx 0, bby 3, bbw 8, bbh 1
	XXXXXXXX,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 8215 $2017 'underscoredbl'
//	width 8, bbx 0, bby -1, bbw 8, bbh 3
	XXXXXXXX,
	________,
	XXXXXXXX,
	________,
	________,
	________,
	________,
	________,
// 8216 $2018 'quoteleft'
//	width 8, bbx 2, bby 4, bbw 3, bbh 3
	___XX___,
	__XX____,
	__XX____,
	________,
	________,
	________,
	________,
	________,
// 8217 $2019 'quoteright'
//	width 8, bbx 1, bby 4, bbw 3, bbh 3
	__XX____,
	__XX____,
	_XX_____,
	________,
	________,
	________,
	________,
	________,
// 8218 $201a 'quotesinglbase'
//	width 8, bbx 1, bby -1, bbw 3, bbh 3
	__XX____,
	__XX____,
	_XX_____,
	________,
	________,
	________,
	________,
	________,
// 8219 $201b 'quotereversed'
//	width 8, bbx 2, bby 4, bbw 3, bbh 3
	__XX____,
	__XX____,
	___XX___,
	________,
	________,
	________,
	________,
	________,
// 8220 $201c 'quotedblleft'
//	width 8, bbx 0, bby 4, bbw 7, bbh 3
	_XX__XX_,
	XX__XX__,
	XX__XX__,
	________,
	________,
	________,
	________,
	________,
// 8221 $201d 'quotedblright'
//	width 8, bbx 0, bby 4, bbw 7, bbh 3
	_XX__XX_,
	_XX__XX_,
	XX__XX__,
	________,
	________,
	________,
	________,
	________,
// 8222 $201e 'quotedblbase'
//	width 8, bbx 0, bby -1, bbw 7, bbh 3
	_XX__XX_,
	_XX__XX_,
	XX__XX__,
	________,
	________,
	________,
	________,
	________,
// 8223 $201f 'uni201F'
//	width 8, bbx 0, bby 4, bbw 7, bbh 3
	XX__XX__,
	XX__XX__,
	_XX__XX_,
	________,
	________,
	________,
	________,
	________,
// 8224 $2020 'dagger'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	__XX____,
	__XX____,
	XXXXXX__,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
	__XX____,
// 8225 $2021 'daggerdbl'
//	width 8, bbx 0, bby -1, bbw 6, bbh 8
	__XX____,
	__XX____,
	XXXXXX__,
	__XX____,
	__XX____,
	XXXXXX__,
	__XX____,
	__XX____,
// 8226 $2022 'bullet'
//	width 8, bbx 2, bby 1, bbw 4, bbh 4
	___XX___,
	__XXXX__,
	__XXXX__,
	___XX___,
	________,
	________,
	________,
	________,
// 8230 $2026 'ellipsis'
//	width 8, bbx 0, bby 0, bbw 8, bbh 2
	XX_XX_XX,
	XX_XX_XX,
	________,
	________,
	________,
	________,
	________,
	________,
// 8231 $2027 'uni2027'
//	width 8, bbx 3, bby 2, bbw 2, bbh 2
	___XX___,
	___XX___,
	________,
	________,
	________,
	________,
	________,
	________,
// 8240 $2030 'perthousand'
//	width 8, bbx 0, bby 0, bbw 8, bbh 6
	XX__XX__,
	XX_XX___,
	__XX____,
	_XX_____,
	XX_XX_XX,
	X__XX_XX,
	________,
	________,
// 8242 $2032 'minute'
//	width 8, bbx 1, bby 4, bbw 4, bbh 3
	___XX___,
	__XX____,
	_XX_____,
	________,
	________,
	________,
	________,
	________,
// 8243 $2033 'second'
//	width 8, bbx 0, bby 4, bbw 7, bbh 3
	__XX_XX_,
	_XX_XX__,
	XX_XX___,
	________,
	________,
	________,
	________,
	________,
// 8245 $2035 'uni2035'
//	width 8, bbx 1, bby 4, bbw 4, bbh 3
	_XX_____,
	__XX____,
	___XX___,
	________,
	________,
	________,
	________,
	________,
// 8249 $2039 'guilsinglleft'
//	width 8, bbx 1, bby 1, bbw 4, bbh 5
	___XX___,
	__XX____,
	_XX_____,
	__XX____,
	___XX___,
	________,
	________,
	________,
// 8250 $203a 'guilsinglright'
//	width 8, bbx 1, bby 1, bbw 4, bbh 5
	_XX_____,
	__XX____,
	___XX___,
	__XX____,
	_XX_____,
	________,
	________,
	________,
// 8252 $203c 'exclamdbl'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	________,
	_XX__XX_,
	________,
// 8254 $203e 'uni203E'
//	width 8, bbx 0, bby 6, bbw 8, bbh 1
	XXXXXXXX,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 8255 $203f 'uni203F'
//	width 8, bbx 0, bby -1, bbw 7, bbh 2
	XX___XX_,
	_XXXXX__,
	________,
	________,
	________,
	________,
	________,
	________,
// 8256 $2040 'uni2040'
//	width 8, bbx 0, bby 5, bbw 7, bbh 2
	_XXXXX__,
	XX___XX_,
	________,
	________,
	________,
	________,
	________,
	________,
// 8260 $2044 'fraction'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_____XX_,
	____XX__,
	___XX___,
	__XX____,
	_XX_____,
	XX______,
	X_______,
	________,
// 8276 $2054 'uni2054'
//	width 8, bbx 0, bby -1, bbw 7, bbh 2
	_XXXXX__,
	XX___XX_,
	________,
	________,
	________,
	________,
	________,
	________,
// 8308 $2074 'uni2074'
//	width 8, bbx 1, bby 2, bbw 5, bbh 5
	___XX___,
	__XXX___,
	_XXXX___,
	_XXXXX__,
	___XX___,
	________,
	________,
	________,
// 8309 $2075 'uni2075'
//	width 8, bbx 1, bby 2, bbw 4, bbh 5
	_XXXX___,
	_XX_____,
	_XXX____,
	___XX___,
	_XXX____,
	________,
	________,
	________,
// 8310 $2076 'uni2076'
//	width 8, bbx 1, bby 2, bbw 5, bbh 5
	__XXX___,
	_XX_____,
	_XXXX___,
	_XX_XX__,
	__XXX___,
	________,
	________,
	________,
// 8311 $2077 'uni2077'
//	width 8, bbx 1, bby 2, bbw 5, bbh 5
	_XXXXX__,
	____XX__,
	___XX___,
	__XX____,
	__XX____,
	________,
	________,
	________,
// 8312 $2078 'uni2078'
//	width 8, bbx 1, bby 2, bbw 5, bbh 5
	__XXX___,
	_XX_XX__,
	__XXX___,
	_XX_XX__,
	__XXX___,
	________,
	________,
	________,
// 8313 $2079 'uni2079'
//	width 8, bbx 1, bby 2, bbw 5, bbh 5
	__XXX___,
	_XX_XX__,
	__XXXX__,
	____XX__,
	__XXX___,
	________,
	________,
	________,
// 8314 $207a 'uni207A'
//	width 8, bbx 0, bby 2, bbw 6, bbh 5
	__XX____,
	__XX____,
	XXXXXX__,
	__XX____,
	__XX____,
	________,
	________,
	________,
// 8315 $207b 'uni207B'
//	width 8, bbx 1, bby 4, bbw 4, bbh 1
	_XXXX___,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 8319 $207f 'uni207F'
//	width 8, bbx 1, bby 2, bbw 5, bbh 5
	_XXXX___,
	_XX_XX__,
	_XX_XX__,
	_XX_XX__,
	_XX_XX__,
	________,
	________,
	________,
// 8321 $2081 'uni2081'
//	width 8, bbx 1, bby -1, bbw 4, bbh 5
	__XX____,
	_XXX____,
	__XX____,
	__XX____,
	_XXXX___,
	________,
	________,
	________,
// 8322 $2082 'uni2082'
//	width 8, bbx 1, bby -1, bbw 4, bbh 5
	_XXX____,
	___XX___,
	__XX____,
	_XX_____,
	_XXXX___,
	________,
	________,
	________,
// 8323 $2083 'uni2083'
//	width 8, bbx 1, bby -1, bbw 4, bbh 5
	_XXX____,
	___XX___,
	__XX____,
	___XX___,
	_XXX____,
	________,
	________,
	________,
// 8324 $2084 'uni2084'
//	width 8, bbx 1, bby -1, bbw 5, bbh 5
	___XX___,
	__XXX___,
	_XXXX___,
	_XXXXX__,
	___XX___,
	________,
	________,
	________,
// 8325 $2085 'uni2085'
//	width 8, bbx 1, bby -1, bbw 4, bbh 5
	_XXXX___,
	_XX_____,
	_XXX____,
	___XX___,
	_XXX____,
	________,
	________,
	________,
// 8326 $2086 'uni2086'
//	width 8, bbx 1, bby -1, bbw 5, bbh 5
	__XXX___,
	_XX_____,
	_XXXX___,
	_XX_XX__,
	__XXX___,
	________,
	________,
	________,
// 8327 $2087 'uni2087'
//	width 8, bbx 1, bby -1, bbw 5, bbh 5
	_XXXXX__,
	____XX__,
	___XX___,
	__XX____,
	__XX____,
	________,
	________,
	________,
// 8328 $2088 'uni2088'
//	width 8, bbx 1, bby -1, bbw 5, bbh 5
	__XXX___,
	_XX_XX__,
	__XXX___,
	_XX_XX__,
	__XXX___,
	________,
	________,
	________,
// 8329 $2089 'uni2089'
//	width 8, bbx 1, bby -1, bbw 5, bbh 5
	__XXX___,
	_XX_XX__,
	__XXXX__,
	____XX__,
	__XXX___,
	________,
	________,
	________,
// 8330 $208a 'uni208A'
//	width 8, bbx 0, bby -1, bbw 6, bbh 5
	__XX____,
	__XX____,
	XXXXXX__,
	__XX____,
	__XX____,
	________,
	________,
	________,
// 8331 $208b 'uni208B'
//	width 8, bbx 1, bby 1, bbw 4, bbh 1
	_XXXX___,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 8355 $20a3 'franc'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XXXXXXX_,
	_XX___X_,
	_XX_X___,
	_XXXX___,
	_XX_X___,
	_XX_____,
	XXXX____,
	_XX_____,
// 8356 $20a4 'lira'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXXX__,
	_XX__XX_,
	XXXX__X_,
	_XX_____,
	XXXX____,
	_XX__XX_,
	XXXXXX__,
	________,
// 8359 $20a7 'peseta'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXXXX___,
	XX__XX__,
	XX__XX__,
	XXXXX_X_,
	XX___XX_,
	XX__XXXX,
	XX___XX_,
	XX___XXX,
// 8362 $20aa 'afii57636'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	XXXXX_X_,
	X___X_X_,
	X_X_X_X_,
	X_X_X_X_,
	X_X___X_,
	X_XXXXX_,
	________,
	________,
// 8364 $20ac 'Euro'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXXX__,
	_XX___X_,
	XXXXX___,
	_XX_____,
	XXXXX___,
	_XX___X_,
	__XXXX__,
	________,
// 8453 $2105 'afii61248'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_XXX__XX,
	XX___XX_,
	XX__XX__,
	_XXXX___,
	__XXXXX_,
	_XXXX_XX,
	XX_XX_XX,
	____XXX_,
// 8467 $2113 'afii61289'
//	width 8, bbx 1, bby 0, bbw 5, bbh 7
	___X____,
	__XXX___,
	_XX_XX__,
	_XX_XX__,
	__XXX___,
	__XX_X__,
	_X_XX___,
	________,
// 8470 $2116 'afii61352'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	XX__XXXX,
	XXX_XX_X,
	XXXXXXXX,
	XX_XXX__,
	XX__XXXX,
	XX__XX__,
	XX__XX__,
	________,
// 8482 $2122 'trademark'
//	width 8, bbx 0, bby 3, bbw 8, bbh 4
	XXXX___X,
	_X_XX_XX,
	_X_X_X_X,
	_X_X___X,
	________,
	________,
	________,
	________,
// 8486 $2126 'Omega'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	_XX_XX__,
	_XX_XX__,
	XXX_XXX_,
	________,
// 8494 $212e 'estimated'
//	width 8, bbx 0, bby 0, bbw 6, bbh 5
	_XXXX___,
	XX__XX__,
	XXXXXX__,
	XX______,
	_XXXX___,
	________,
	________,
	________,
// 8528 $2150 'uni2150'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	XX___XX_,
	XX__XX__,
	XX_XX___,
	__XXXXXX,
	_XX___XX,
	XX___XX_,
	_____XX_,
// 8529 $2151 'uni2151'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	XX___XX_,
	XX__XX__,
	XX_XXXX_,
	__XXX_XX,
	_XX_XXXX,
	XX____XX,
	____XXX_,
// 8531 $2153 'onethird'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	XX___XX_,
	XX__XX__,
	XX_XXXX_,
	__XX__XX,
	_XX__XX_,
	XX____XX,
	____XXX_,
// 8532 $2154 'twothirds'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	_XX__XX_,
	XX__XX__,
	XXXXXXX_,
	__XX__XX,
	_XX__XX_,
	XX____XX,
	____XXX_,
// 8533 $2155 'uni2155'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	XX___XX_,
	XX__XX__,
	XX_XXXXX,
	__XXXX__,
	_XX_XXX_,
	XX____XX,
	____XXX_,
// 8534 $2156 'uni2156'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	_XX__XX_,
	XX__XX__,
	XXXXXXXX,
	__XXXX__,
	_XX_XXX_,
	XX____XX,
	____XXX_,
// 8535 $2157 'uni2157'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXX___XX,
	__XX_XX_,
	_XX_XX__,
	__XXXXXX,
	XXXXXX__,
	_XX_XXX_,
	XX____XX,
	____XXX_,
// 8536 $2158 'uni2158'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	__XX__XX,
	_XXX_XX_,
	XXXXXX__,
	__XXXXXX,
	__XXXX__,
	_XX_XXX_,
	XX____XX,
	____XXX_,
// 8537 $2159 'uni2159'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	XX___XX_,
	XX__XX__,
	XX_XXXX_,
	__XXX___,
	_XXXXXX_,
	XX_XX_XX,
	____XXX_,
// 8538 $215a 'uni215A'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXXX__XX,
	XX___XX_,
	XXX_XX__,
	__XXXXX_,
	XXXXX___,
	_XXXXXX_,
	XX_XX_XX,
	____XXX_,
// 8539 $215b 'oneeighth'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	XX___XX_,
	XX__XX__,
	XX_XXXX_,
	__XXX_XX,
	_XX_XXX_,
	XX_XX_XX,
	____XXX_,
// 8540 $215c 'threeeighths'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXX___XX,
	__XX_XX_,
	_XX_XX__,
	__XXXXX_,
	XXXXX_XX,
	_XX_XXX_,
	XX_XX_XX,
	____XXX_,
// 8541 $215d 'fiveeighths'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXXX__XX,
	XX___XX_,
	XXX_XX__,
	__XXXXX_,
	XXXXX_XX,
	_XX_XXX_,
	XX_XX_XX,
	____XXX_,
// 8542 $215e 'seveneighths'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXXX__XX,
	__XX_XX_,
	_XX_XX__,
	XX_XXXX_,
	__XXX_XX,
	_XX_XXX_,
	XX_XX_XX,
	____XXX_,
// 8592 $2190 'arrowleft'
//	width 8, bbx 0, bby 1, bbw 7, bbh 5
	__XX____,
	_XX_____,
	XXXXXXX_,
	_XX_____,
	__XX____,
	________,
	________,
	________,
// 8593 $2191 'arrowup'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	___XX___,
	__XXXX__,
	_XXXXXX_,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	________,
// 8594 $2192 'arrowright'
//	width 8, bbx 0, bby 1, bbw 7, bbh 5
	___XX___,
	____XX__,
	XXXXXXX_,
	____XX__,
	___XX___,
	________,
	________,
	________,
// 8595 $2193 'arrowdown'
//	width 8, bbx 1, bby 0, bbw 6, bbh 7
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	_XXXXXX_,
	__XXXX__,
	___XX___,
	________,
// 8596 $2194 'arrowboth'
//	width 8, bbx 0, bby 1, bbw 8, bbh 5
	__X__X__,
	_XX__XX_,
	XXXXXXXX,
	_XX__XX_,
	__X__X__,
	________,
	________,
	________,
// 8597 $2195 'arrowupdn'
//	width 8, bbx 1, bby -1, bbw 6, bbh 8
	___XX___,
	__XXXX__,
	_XXXXXX_,
	___XX___,
	___XX___,
	_XXXXXX_,
	__XXXX__,
	___XX___,
// 8616 $21a8 'arrowupdnbse'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	___XX___,
	__XXXX__,
	_XXXXXX_,
	___XX___,
	_XXXXXX_,
	__XXXX__,
	___XX___,
	XXXXXXXX,
// 8706 $2202 'partialdiff'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	__XXX___,
	_XX_XX__,
	____XX__,
	_XXXXX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
	________,
// 8709 $2205 'emptyset'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_____XX_,
	____XX__,
	_XXXXXX_,
	XX_XX_XX,
	XX_XX_XX,
	_XXXXXX_,
	__XX____,
	_XX_____,
// 8710 $2206 'Delta'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___X____,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XXXXXXX_,
	________,
// 8712 $2208 'element'
//	width 8, bbx 0, bby 0, bbw 5, bbh 7
	__XXX___,
	_XX_____,
	XX______,
	XXXXX___,
	XX______,
	_XX_____,
	__XXX___,
	________,
// 8719 $220f 'product'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	XXXXXXX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
	XX___XX_,
// 8721 $2211 'summation'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	XXXXXX__,
	XX__XX__,
	_XX_____,
	__XX____,
	_XX_____,
	XX__XX__,
	XXXXXX__,
	________,
// 8722 $2212 'minus'
//	width 8, bbx 0, bby 3, bbw 6, bbh 1
	XXXXXX__,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 8725 $2215 'uni2215'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_____XX_,
	____XX__,
	___XX___,
	__XX____,
	_XX_____,
	XX______,
	X_______,
	________,
// 8729 $2219 'uni2219'
//	width 8, bbx 3, bby 2, bbw 2, bbh 2
	___XX___,
	___XX___,
	________,
	________,
	________,
	________,
	________,
	________,
// 8730 $221a 'radical'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	____XXXX,
	____XX__,
	____XX__,
	____XX__,
	XXX_XX__,
	_XX_XX__,
	__XXXX__,
	___XXX__,
// 8734 $221e 'infinity'
//	width 8, bbx 0, bby 1, bbw 8, bbh 4
	_XXXXXX_,
	XX_XX_XX,
	XX_XX_XX,
	_XXXXXX_,
	________,
	________,
	________,
	________,
// 8735 $221f 'orthogonal'
//	width 8, bbx 0, bby 1, bbw 7, bbh 4
	XX______,
	XX______,
	XX______,
	XXXXXXX_,
	________,
	________,
	________,
	________,
// 8745 $2229 'intersection'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XXXX___,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	________,
// 8747 $222b 'integral'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	____XXX_,
	___XX_XX,
	___XX_XX,
	___XX___,
	___XX___,
	XX_XX___,
	XX_XX___,
	_XXX____,
// 8776 $2248 'approxequal'
//	width 8, bbx 0, bby 1, bbw 7, bbh 5
	_XXX_XX_,
	XX_XXX__,
	________,
	_XXX_XX_,
	XX_XXX__,
	________,
	________,
	________,
// 8800 $2260 'notequal'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	____XX__,
	XXXXXXX_,
	___XX___,
	__XX____,
	XXXXXXX_,
	_XX_____,
	________,
	________,
// 8801 $2261 'equivalence'
//	width 8, bbx 0, bby 1, bbw 6, bbh 5
	XXXXXX__,
	________,
	XXXXXX__,
	________,
	XXXXXX__,
	________,
	________,
	________,
// 8804 $2264 'lessequal'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	___XX___,
	__XX____,
	_XX_____,
	__XX____,
	___XX___,
	________,
	XXXXXX__,
	________,
// 8805 $2265 'greaterequal'
//	width 8, bbx 0, bby 0, bbw 6, bbh 7
	_XX_____,
	__XX____,
	___XX___,
	__XX____,
	_XX_____,
	________,
	XXXXXX__,
	________,
// 8857 $2299 'uni2299'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX___XX_,
	XX___XX_,
	XX_X_XX_,
	XX___XX_,
	XX___XX_,
	_XXXXX__,
	________,
// 8960 $2300 'uni2300'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XXXXX__,
	XX___XX_,
	XX__XXX_,
	XX_X_XX_,
	XXX__XX_,
	XX___XX_,
	_XXXXX__,
	________,
// 8962 $2302 'house'
//	width 8, bbx 0, bby 0, bbw 7, bbh 6
	___X____,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	XX___XX_,
	XXXXXXX_,
	________,
	________,
// 8976 $2310 'revlogicalnot'
//	width 8, bbx 0, bby 1, bbw 6, bbh 3
	XXXXXX__,
	XX______,
	XX______,
	________,
	________,
	________,
	________,
	________,
// 8992 $2320 'integraltp'
//	width 8, bbx 3, bby -1, bbw 5, bbh 8
	____XXX_,
	___XX_XX,
	___XX_XX,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
// 8993 $2321 'integralbt'
//	width 8, bbx 0, bby -1, bbw 5, bbh 8
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	XX_XX___,
	XX_XX___,
	_XXX____,
// 9472 $2500 'SF100000'
//	width 8, bbx 0, bby 2, bbw 8, bbh 1
	XXXXXXXX,
	________,
	________,
	________,
	________,
	________,
	________,
	________,
// 9474 $2502 'SF110000'
//	width 8, bbx 3, bby -1, bbw 2, bbh 8
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XX___,
// 9484 $250c 'SF010000'
//	width 8, bbx 3, bby -1, bbw 5, bbh 4
	___XXXXX,
	___XX___,
	___XX___,
	___XX___,
	________,
	________,
	________,
	________,
// 9488 $2510 'SF030000'
//	width 8, bbx 0, bby -1, bbw 5, bbh 4
	XXXXX___,
	___XX___,
	___XX___,
	___XX___,
	________,
	________,
	________,
	________,
// 9492 $2514 'SF020000'
//	width 8, bbx 3, bby 2, bbw 5, bbh 5
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XXXXX,
	________,
	________,
	________,
// 9496 $2518 'SF040000'
//	width 8, bbx 0, bby 2, bbw 5, bbh 5
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	XXXXX___,
	________,
	________,
	________,
// 9500 $251c 'SF080000'
//	width 8, bbx 3, bby -1, bbw 5, bbh 8
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	___XXXXX,
	___XX___,
	___XX___,
	___XX___,
// 9508 $2524 'SF090000'
//	width 8, bbx 0, bby -1, bbw 5, bbh 8
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	XXXXX___,
	___XX___,
	___XX___,
	___XX___,
// 9516 $252c 'SF060000'
//	width 8, bbx 0, bby -1, bbw 8, bbh 4
	XXXXXXXX,
	___XX___,
	___XX___,
	___XX___,
	________,
	________,
	________,
	________,
// 9524 $2534 'SF070000'
//	width 8, bbx 0, bby 2, bbw 8, bbh 5
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	XXXXXXXX,
	________,
	________,
	________,
// 9532 $253c 'SF050000'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	___XX___,
	___XX___,
	___XX___,
	___XX___,
	XXXXXXXX,
	___XX___,
	___XX___,
	___XX___,
// 9552 $2550 'SF430000'
//	width 8, bbx 0, bby 2, bbw 8, bbh 3
	XXXXXXXX,
	________,
	XXXXXXXX,
	________,
	________,
	________,
	________,
	________,
// 9553 $2551 'SF240000'
//	width 8, bbx 2, bby -1, bbw 5, bbh 8
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
// 9554 $2552 'SF510000'
//	width 8, bbx 3, bby -1, bbw 5, bbh 6
	___XXXXX,
	___XX___,
	___XXXXX,
	___XX___,
	___XX___,
	___XX___,
	________,
	________,
// 9555 $2553 'SF520000'
//	width 8, bbx 2, bby -1, bbw 6, bbh 4
	__XXXXXX,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	________,
	________,
	________,
	________,
// 9556 $2554 'SF390000'
//	width 8, bbx 2, bby -1, bbw 6, bbh 6
	__XXXXXX,
	__XX____,
	__XX_XXX,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	________,
	________,
// 9557 $2555 'SF220000'
//	width 8, bbx 0, bby -1, bbw 5, bbh 6
	XXXXX___,
	___XX___,
	XXXXX___,
	___XX___,
	___XX___,
	___XX___,
	________,
	________,
// 9558 $2556 'SF210000'
//	width 8, bbx 0, bby -1, bbw 7, bbh 4
	XXXXXXX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	________,
	________,
	________,
	________,
// 9559 $2557 'SF250000'
//	width 8, bbx 0, bby -1, bbw 7, bbh 6
	XXXXXXX_,
	_____XX_,
	XXXX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	________,
	________,
// 9560 $2558 'SF500000'
//	width 8, bbx 3, bby 2, bbw 5, bbh 5
	___XX___,
	___XX___,
	___XXXXX,
	___XX___,
	___XXXXX,
	________,
	________,
	________,
// 9561 $2559 'SF490000'
//	width 8, bbx 2, bby 2, bbw 6, bbh 5
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XXXXXX,
	________,
	________,
	________,
// 9562 $255a 'SF380000'
//	width 8, bbx 2, bby 2, bbw 6, bbh 5
	__XX_XX_,
	__XX_XX_,
	__XX_XXX,
	__XX____,
	__XXXXXX,
	________,
	________,
	________,
// 9563 $255b 'SF280000'
//	width 8, bbx 0, bby 2, bbw 5, bbh 5
	___XX___,
	___XX___,
	XXXXX___,
	___XX___,
	XXXXX___,
	________,
	________,
	________,
// 9564 $255c 'SF270000'
//	width 8, bbx 0, bby 2, bbw 7, bbh 5
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	XXXXXXX_,
	________,
	________,
	________,
// 9565 $255d 'SF260000'
//	width 8, bbx 0, bby 2, bbw 7, bbh 5
	__XX_XX_,
	__XX_XX_,
	XXXX_XX_,
	_____XX_,
	XXXXXXX_,
	________,
	________,
	________,
// 9566 $255e 'SF360000'
//	width 8, bbx 3, bby -1, bbw 5, bbh 8
	___XX___,
	___XX___,
	___XXXXX,
	___XX___,
	___XXXXX,
	___XX___,
	___XX___,
	___XX___,
// 9567 $255f 'SF370000'
//	width 8, bbx 2, bby -1, bbw 6, bbh 8
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XXX,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
// 9568 $2560 'SF420000'
//	width 8, bbx 2, bby -1, bbw 6, bbh 8
	__XX_XX_,
	__XX_XX_,
	__XX_XXX,
	__XX____,
	__XX_XXX,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
// 9569 $2561 'SF190000'
//	width 8, bbx 0, bby -1, bbw 5, bbh 8
	___XX___,
	___XX___,
	XXXXX___,
	___XX___,
	XXXXX___,
	___XX___,
	___XX___,
	___XX___,
// 9570 $2562 'SF200000'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	XXXX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
// 9571 $2563 'SF230000'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	__XX_XX_,
	__XX_XX_,
	XXXX_XX_,
	_____XX_,
	XXXX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
// 9572 $2564 'SF470000'
//	width 8, bbx 0, bby -1, bbw 8, bbh 6
	XXXXXXXX,
	________,
	XXXXXXXX,
	___XX___,
	___XX___,
	___XX___,
	________,
	________,
// 9573 $2565 'SF480000'
//	width 8, bbx 0, bby -1, bbw 8, bbh 4
	XXXXXXXX,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	________,
	________,
	________,
	________,
// 9574 $2566 'SF410000'
//	width 8, bbx 0, bby -1, bbw 8, bbh 6
	XXXXXXXX,
	________,
	XXXX_XXX,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	________,
	________,
// 9575 $2567 'SF450000'
//	width 8, bbx 0, bby 2, bbw 8, bbh 5
	___XX___,
	___XX___,
	XXXXXXXX,
	________,
	XXXXXXXX,
	________,
	________,
	________,
// 9576 $2568 'SF460000'
//	width 8, bbx 0, bby 2, bbw 8, bbh 5
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	XXXXXXXX,
	________,
	________,
	________,
// 9577 $2569 'SF400000'
//	width 8, bbx 0, bby 2, bbw 8, bbh 5
	__XX_XX_,
	__XX_XX_,
	XXXX_XXX,
	________,
	XXXXXXXX,
	________,
	________,
	________,
// 9578 $256a 'SF540000'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	___XX___,
	___XX___,
	XXXXXXXX,
	___XX___,
	XXXXXXXX,
	___XX___,
	___XX___,
	___XX___,
// 9579 $256b 'SF530000'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
	XXXXXXXX,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
// 9580 $256c 'SF440000'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	__XX_XX_,
	__XX_XX_,
	XXXX_XXX,
	________,
	XXXX_XXX,
	__XX_XX_,
	__XX_XX_,
	__XX_XX_,
// 9600 $2580 'upblock'
//	width 8, bbx 0, bby 3, bbw 8, bbh 4
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
	________,
	________,
	________,
	________,
// 9601 $2581 'uni2581'
//	width 8, bbx 0, bby -1, bbw 8, bbh 2
	XXXXXXXX,
	XXXXXXXX,
	________,
	________,
	________,
	________,
	________,
	________,
// 9604 $2584 'dnblock'
//	width 8, bbx 0, bby -1, bbw 8, bbh 4
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
	________,
	________,
	________,
	________,
// 9608 $2588 'block'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
	XXXXXXXX,
// 9612 $258c 'lfblock'
//	width 8, bbx 0, bby -1, bbw 4, bbh 8
	XXXX____,
	XXXX____,
	XXXX____,
	XXXX____,
	XXXX____,
	XXXX____,
	XXXX____,
	XXXX____,
// 9616 $2590 'rtblock'
//	width 8, bbx 4, bby -1, bbw 4, bbh 8
	____XXXX,
	____XXXX,
	____XXXX,
	____XXXX,
	____XXXX,
	____XXXX,
	____XXXX,
	____XXXX,
// 9617 $2591 'ltshade'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	__X___X_,
	X___X___,
	__X___X_,
	X___X___,
	__X___X_,
	X___X___,
	__X___X_,
	X___X___,
// 9618 $2592 'shade'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_X_X_X_X,
	X_X_X_X_,
	_X_X_X_X,
	X_X_X_X_,
	_X_X_X_X,
	X_X_X_X_,
	_X_X_X_X,
	X_X_X_X_,
// 9619 $2593 'dkshade'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX_XX_XX,
	_XXX_XXX,
	XX_XX_XX,
	XXX_XXX_,
	XX_XX_XX,
	_XXX_XXX,
	XX_XX_XX,
	XXX_XXX_,
// 9632 $25a0 'filledbox'
//	width 8, bbx 2, bby 1, bbw 4, bbh 4
	__XXXX__,
	__XXXX__,
	__XXXX__,
	__XXXX__,
	________,
	________,
	________,
	________,
// 9633 $25a1 'H22073'
//	width 8, bbx 1, bby 1, bbw 5, bbh 4
	_XXXXX__,
	_XX_XX__,
	_XX_XX__,
	_XXXXX__,
	________,
	________,
	________,
	________,
// 9642 $25aa 'H18543'
//	width 8, bbx 2, bby 1, bbw 4, bbh 3
	__XXXX__,
	__XXXX__,
	__XXXX__,
	________,
	________,
	________,
	________,
	________,
// 9643 $25ab 'H18551'
//	width 8, bbx 1, bby 1, bbw 5, bbh 3
	_XXXXX__,
	_XX_XX__,
	_XXXXX__,
	________,
	________,
	________,
	________,
	________,
// 9644 $25ac 'filledrect'
//	width 8, bbx 1, bby 0, bbw 6, bbh 3
	_XXXXXX_,
	_XXXXXX_,
	_XXXXXX_,
	________,
	________,
	________,
	________,
	________,
// 9650 $25b2 'triagup'
//	width 8, bbx 0, bby 1, bbw 8, bbh 5
	___XX___,
	__XXXX__,
	_XXXXXX_,
	XXXXXXXX,
	XXXXXXXX,
	________,
	________,
	________,
// 9658 $25ba 'triagrt'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	X_______,
	XXX_____,
	XXXXX___,
	XXXXXXX_,
	XXXXX___,
	XXX_____,
	X_______,
	________,
// 9660 $25bc 'triagdn'
//	width 8, bbx 0, bby 1, bbw 8, bbh 5
	XXXXXXXX,
	XXXXXXXX,
	_XXXXXX_,
	__XXXX__,
	___XX___,
	________,
	________,
	________,
// 9668 $25c4 'triaglf'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	______X_,
	____XXX_,
	__XXXXX_,
	XXXXXXX_,
	__XXXXX_,
	____XXX_,
	______X_,
	________,
// 9674 $25ca 'lozenge'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___X____,
	__XXX___,
	_XX_XX__,
	XX___XX_,
	_XX_XX__,
	__XXX___,
	___X____,
	________,
// 9675 $25cb 'circle'
//	width 8, bbx 1, bby 0, bbw 6, bbh 6
	__XXXX__,
	_XX__XX_,
	_X____X_,
	_X____X_,
	_XX__XX_,
	__XXXX__,
	________,
	________,
// 9679 $25cf 'H18533'
//	width 8, bbx 1, bby 0, bbw 6, bbh 6
	__XXXX__,
	_XXXXXX_,
	_XXXXXX_,
	_XXXXXX_,
	_XXXXXX_,
	__XXXX__,
	________,
	________,
// 9688 $25d8 'invbullet'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXXXXXXX,
	XXXXXXXX,
	XXX__XXX,
	XX____XX,
	XX____XX,
	XXX__XXX,
	XXXXXXXX,
	XXXXXXXX,
// 9689 $25d9 'invcircle'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XXXXXXXX,
	XX____XX,
	X__XX__X,
	X_XXXX_X,
	X_XXXX_X,
	X__XX__X,
	XX____XX,
	XXXXXXXX,
// 9702 $25e6 'openbullet'
//	width 8, bbx 1, bby 1, bbw 5, bbh 4
	__XXX___,
	_XX_XX__,
	_XX_XX__,
	__XXX___,
	________,
	________,
	________,
	________,
// 9786 $263a 'smileface'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_XXXXXX_,
	X______X,
	X_X__X_X,
	X______X,
	X_XXXX_X,
	X__XX__X,
	X______X,
	_XXXXXX_,
// 9787 $263b 'invsmileface'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_XXXXXX_,
	XXXXXXXX,
	XX_XX_XX,
	XXXXXXXX,
	XX____XX,
	XXX__XXX,
	XXXXXXXX,
	_XXXXXX_,
// 9788 $263c 'sun'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	X__XX__X,
	_X_XX_X_,
	__XXXX__,
	XXX__XXX,
	XXX__XXX,
	__XXXX__,
	_X_XX_X_,
	X__XX__X,
// 9792 $2640 'female'
//	width 8, bbx 1, bby -1, bbw 6, bbh 8
	__XXXX__,
	_XX__XX_,
	_XX__XX_,
	_XX__XX_,
	__XXXX__,
	___XX___,
	_XXXXXX_,
	___XX___,
// 9794 $2642 'male'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	____XXXX,
	_____XXX,
	____XXXX,
	_XXXXX_X,
	XX__XX__,
	XX__XX__,
	XX__XX__,
	_XXXX___,
// 9824 $2660 'spade'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	___X____,
	___X____,
	__XXX___,
	_XXXXX__,
	XXXXXXX_,
	_XXXXX__,
	__XXX___,
	_XXXXX__,
// 9827 $2663 'club'
//	width 8, bbx 0, bby -1, bbw 7, bbh 8
	__XXX___,
	_XXXXX__,
	__XXX___,
	XXXXXXX_,
	XXXXXXX_,
	_XXXXX__,
	__XXX___,
	_XXXXX__,
// 9829 $2665 'heart'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	_XX_XX__,
	XXXXXXX_,
	XXXXXXX_,
	XXXXXXX_,
	_XXXXX__,
	__XXX___,
	___X____,
	________,
// 9830 $2666 'diamond'
//	width 8, bbx 0, bby 0, bbw 7, bbh 7
	___X____,
	__XXX___,
	_XXXXX__,
	XXXXXXX_,
	_XXXXX__,
	__XXX___,
	___X____,
	________,
// 9834 $266a 'musicalnote'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	__XXXXXX,
	__XX__XX,
	__XXXXXX,
	__XX____,
	__XX____,
	_XXX____,
	XXXX____,
	XXX_____,
// 9835 $266b 'musicalnotedbl'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	_XXXXXXX,
	_XX___XX,
	_XXXXXXX,
	_XX___XX,
	_XX___XX,
	_XX__XXX,
	XXX__XX_,
	XX______,
// 10003 $2713 'uni2713'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	______XX,
	______XX,
	_____XX_,
	_____XX_,
	XX___XX_,
	_XX_XX__,
	__XXXX__,
	___XX___,
// 64257 $fb01 'uniFB01'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	__XXXXX_,
	_XX_XXX_,
	_XX_____,
	XXXXXXX_,
	_XX__XX_,
	_XX__XX_,
	XXXX_XXX,
	________,
// 64258 $fb02 'uniFB02'
//	width 8, bbx 0, bby 0, bbw 8, bbh 7
	__XXXXX_,
	_XX__XX_,
	_XX__XX_,
	XXXX_XX_,
	_XX__XX_,
	_XX__XX_,
	XXXX_XXX,
	________,
// 65533 $fffd 'uniFFFD'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	X__XX__X,
	XXXXX__X,
	XXXX__XX,
	XXX__XXX,
	XXXXXXXX,
	XXX__XXX,
	XXXXXXXX,
//  -1 $ffffffff '.notdef'
//	width 8, bbx 0, bby -1, bbw 8, bbh 8
	XX____XX,
	X__XX__X,
	XXXXX__X,
	XXXX__XX,
	XXX__XXX,
	XXXXXXXX,
	XXX__XXX,
	XXXXXXXX,
};

unsigned char reverse_byte(unsigned char x)
{
    static const unsigned char table[] = {
        0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0,
        0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0,
        0x08, 0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8,
        0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8,
        0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4,
        0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
        0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec,
        0x1c, 0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc,
        0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2,
        0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2,
        0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea,
        0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa,
        0x06, 0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6,
        0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6,
        0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee,
        0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe,
        0x01, 0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1,
        0x11, 0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1,
        0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9,
        0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9,
        0x05, 0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5,
        0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5,
        0x0d, 0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed,
        0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd,
        0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3,
        0x13, 0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3,
        0x0b, 0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb,
        0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb,
        0x07, 0x87, 0x47, 0xc7, 0x27, 0xa7, 0x67, 0xe7,
        0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,
        0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef,
        0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff,
    };
    return table[x];
}

	/// bitmap font structure
const struct bitmap_font font = {
	.Width = 8, .Height = 8,
	.Chars = 782,
	.Bitmap = __font_bitmap__,
};

struct limine_framebuffer *Fontframebuffer;

int fontInitFrameBuffer(struct limine_framebuffer* fb) {
    Fontframebuffer = fb;
    if (Fontframebuffer != fb) return 0;
    return 1;
}

const char set[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

void DrawSquare(int x, int y, int size_x, int size_y, uint32_t color) {
    uint32_t *fb_ptr = Fontframebuffer->address;
    int i,j;
    for (j=0; j<size_y; j++) {
        for (i=0; i<size_x; i++) {
    		fb_ptr[Fontframebuffer->width*(y+j)+(x+i)] = color;
    	}
    }
}

void DrawCharBackground(char c, uint16_t x, uint16_t y, uint32_t color, uint32_t back_color, uint8_t size) {
    uint8_t i,j;
    // Draw pixels
    for (j=0; j<8; j++) {
        for (i=0; i<8; i++) {
            if (reverse_byte(__font_bitmap__[c*8+j]) & (1<<i)) {
        		DrawSquare(x+(i*size), y+(j*size), size, size, color);
            }else {
            	DrawSquare(x+(i*size), y+(j*size), size, size, back_color);
            }
        }
    }
}

void DrawChar(char c, uint16_t x, uint16_t y, uint32_t color, uint8_t size) {
    uint8_t i,j;
    // Draw pixels
    for (j=0; j<8; j++) {
        for (i=0; i<8; i++) {
            if (reverse_byte(__font_bitmap__[c*8+j]) & (1<<i)) {
        		DrawSquare(x+(i*size), y+(j*size), size, size, color);
            }
        }
    }
}

void DrawString(const char* str, uint16_t x, uint16_t y, uint32_t color, uint8_t size) {
    while (*str) {
        DrawChar(*str++, x, y, color, size);
        x += (8*size);
    }
}

void DrawStringBackground(const char* str, uint16_t x, uint16_t y, uint8_t size, uint32_t color, uint32_t bg_color, bool background) {
    if (background){
    	while (*str) {
        	DrawCharBackground(*str++, x, y, color, bg_color, size);
        	x += (8*size);
    	}
    	return;
    }
    while (*str) {
        DrawChar(*str++, x, y, color, size);
        x += (8*size);
    }
}
