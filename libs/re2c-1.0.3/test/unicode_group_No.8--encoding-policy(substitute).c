/* Generated by re2c */
#line 1 "unicode_group_No.8--encoding-policy(substitute).re"
#include <stdio.h>
#include "utf8.h"
#define YYCTYPE unsigned char
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
No:
	
#line 13 "unicode_group_No.8--encoding-policy(substitute).c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	switch (yych) {
	case 0xC2:	goto yy4;
	case 0xE0:	goto yy5;
	case 0xE1:	goto yy6;
	case 0xE2:	goto yy7;
	case 0xE3:	goto yy8;
	case 0xEA:	goto yy9;
	case 0xF0:	goto yy10;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
yy3:
#line 13 "unicode_group_No.8--encoding-policy(substitute).re"
	{ return YYCURSOR == limit; }
#line 32 "unicode_group_No.8--encoding-policy(substitute).c"
yy4:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB2:
	case 0xB3:
	case 0xB9:
	case 0xBC:
	case 0xBD:
	case 0xBE:	goto yy11;
	default:	goto yy3;
	}
yy5:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0xA7:	goto yy13;
	case 0xAD:	goto yy15;
	case 0xAF:	goto yy16;
	case 0xB1:	goto yy17;
	case 0xB5:	goto yy18;
	case 0xBC:	goto yy19;
	default:	goto yy3;
	}
yy6:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x8D:	goto yy20;
	case 0x9F:	goto yy21;
	case 0xA7:	goto yy22;
	default:	goto yy3;
	}
yy7:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x81:	goto yy23;
	case 0x82:	goto yy24;
	case 0x85:	goto yy25;
	case 0x86:	goto yy26;
	case 0x91:	goto yy27;
	case 0x92:	goto yy28;
	case 0x93:	goto yy29;
	case 0x9D:	goto yy30;
	case 0x9E:	goto yy31;
	case 0xB3:	goto yy32;
	default:	goto yy3;
	}
yy8:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x86:	goto yy33;
	case 0x88:	goto yy34;
	case 0x89:	goto yy35;
	case 0x8A:	goto yy36;
	default:	goto yy3;
	}
yy9:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0xA0:	goto yy18;
	default:	goto yy3;
	}
yy10:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x90:	goto yy37;
	case 0x91:	goto yy38;
	case 0x9D:	goto yy39;
	case 0x9F:	goto yy40;
	default:	goto yy3;
	}
yy11:
	++YYCURSOR;
#line 12 "unicode_group_No.8--encoding-policy(substitute).re"
	{ goto No; }
#line 106 "unicode_group_No.8--encoding-policy(substitute).c"
yy13:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB4:
	case 0xB5:
	case 0xB6:
	case 0xB7:
	case 0xB8:
	case 0xB9:	goto yy11;
	default:	goto yy14;
	}
yy14:
	YYCURSOR = YYMARKER;
	goto yy3;
yy15:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB2:
	case 0xB3:
	case 0xB4:
	case 0xB5:
	case 0xB6:
	case 0xB7:	goto yy11;
	default:	goto yy14;
	}
yy16:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB0:
	case 0xB1:
	case 0xB2:	goto yy11;
	default:	goto yy14;
	}
yy17:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB8:
	case 0xB9:
	case 0xBA:
	case 0xBB:
	case 0xBC:
	case 0xBD:
	case 0xBE:	goto yy11;
	default:	goto yy14;
	}
yy18:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB0:
	case 0xB1:
	case 0xB2:
	case 0xB3:
	case 0xB4:
	case 0xB5:	goto yy11;
	default:	goto yy14;
	}
yy19:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xAA:
	case 0xAB:
	case 0xAC:
	case 0xAD:
	case 0xAE:
	case 0xAF:
	case 0xB0:
	case 0xB1:
	case 0xB2:
	case 0xB3:	goto yy11;
	default:	goto yy14;
	}
yy20:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xA9:
	case 0xAA:
	case 0xAB:
	case 0xAC:
	case 0xAD:
	case 0xAE:
	case 0xAF:
	case 0xB0:
	case 0xB1:
	case 0xB2:
	case 0xB3:
	case 0xB4:
	case 0xB5:
	case 0xB6:
	case 0xB7:
	case 0xB8:
	case 0xB9:
	case 0xBA:
	case 0xBB:
	case 0xBC:	goto yy11;
	default:	goto yy14;
	}
yy21:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB0:
	case 0xB1:
	case 0xB2:
	case 0xB3:
	case 0xB4:
	case 0xB5:
	case 0xB6:
	case 0xB7:
	case 0xB8:
	case 0xB9:	goto yy11;
	default:	goto yy14;
	}
yy22:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x9A:	goto yy11;
	default:	goto yy14;
	}
yy23:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB0:
	case 0xB4:
	case 0xB5:
	case 0xB6:
	case 0xB7:
	case 0xB8:
	case 0xB9:	goto yy11;
	default:	goto yy14;
	}
yy24:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x80:
	case 0x81:
	case 0x82:
	case 0x83:
	case 0x84:
	case 0x85:
	case 0x86:
	case 0x87:
	case 0x88:
	case 0x89:	goto yy11;
	default:	goto yy14;
	}
yy25:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x90:
	case 0x91:
	case 0x92:
	case 0x93:
	case 0x94:
	case 0x95:
	case 0x96:
	case 0x97:
	case 0x98:
	case 0x99:
	case 0x9A:
	case 0x9B:
	case 0x9C:
	case 0x9D:
	case 0x9E:
	case 0x9F:	goto yy11;
	default:	goto yy14;
	}
yy26:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x89:	goto yy11;
	default:	goto yy14;
	}
yy27:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xA0:
	case 0xA1:
	case 0xA2:
	case 0xA3:
	case 0xA4:
	case 0xA5:
	case 0xA6:
	case 0xA7:
	case 0xA8:
	case 0xA9:
	case 0xAA:
	case 0xAB:
	case 0xAC:
	case 0xAD:
	case 0xAE:
	case 0xAF:
	case 0xB0:
	case 0xB1:
	case 0xB2:
	case 0xB3:
	case 0xB4:
	case 0xB5:
	case 0xB6:
	case 0xB7:
	case 0xB8:
	case 0xB9:
	case 0xBA:
	case 0xBB:
	case 0xBC:
	case 0xBD:
	case 0xBE:
	case 0xBF:	goto yy11;
	default:	goto yy14;
	}
yy28:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x80:
	case 0x81:
	case 0x82:
	case 0x83:
	case 0x84:
	case 0x85:
	case 0x86:
	case 0x87:
	case 0x88:
	case 0x89:
	case 0x8A:
	case 0x8B:
	case 0x8C:
	case 0x8D:
	case 0x8E:
	case 0x8F:
	case 0x90:
	case 0x91:
	case 0x92:
	case 0x93:
	case 0x94:
	case 0x95:
	case 0x96:
	case 0x97:
	case 0x98:
	case 0x99:
	case 0x9A:
	case 0x9B:	goto yy11;
	default:	goto yy14;
	}
yy29:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xAA:
	case 0xAB:
	case 0xAC:
	case 0xAD:
	case 0xAE:
	case 0xAF:
	case 0xB0:
	case 0xB1:
	case 0xB2:
	case 0xB3:
	case 0xB4:
	case 0xB5:
	case 0xB6:
	case 0xB7:
	case 0xB8:
	case 0xB9:
	case 0xBA:
	case 0xBB:
	case 0xBC:
	case 0xBD:
	case 0xBE:
	case 0xBF:	goto yy11;
	default:	goto yy14;
	}
yy30:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB6:
	case 0xB7:
	case 0xB8:
	case 0xB9:
	case 0xBA:
	case 0xBB:
	case 0xBC:
	case 0xBD:
	case 0xBE:
	case 0xBF:	goto yy11;
	default:	goto yy14;
	}
yy31:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x80:
	case 0x81:
	case 0x82:
	case 0x83:
	case 0x84:
	case 0x85:
	case 0x86:
	case 0x87:
	case 0x88:
	case 0x89:
	case 0x8A:
	case 0x8B:
	case 0x8C:
	case 0x8D:
	case 0x8E:
	case 0x8F:
	case 0x90:
	case 0x91:
	case 0x92:
	case 0x93:	goto yy11;
	default:	goto yy14;
	}
yy32:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xBD:	goto yy11;
	default:	goto yy14;
	}
yy33:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x92:
	case 0x93:
	case 0x94:
	case 0x95:	goto yy11;
	default:	goto yy14;
	}
yy34:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xA0:
	case 0xA1:
	case 0xA2:
	case 0xA3:
	case 0xA4:
	case 0xA5:
	case 0xA6:
	case 0xA7:
	case 0xA8:
	case 0xA9:	goto yy11;
	default:	goto yy14;
	}
yy35:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x91:
	case 0x92:
	case 0x93:
	case 0x94:
	case 0x95:
	case 0x96:
	case 0x97:
	case 0x98:
	case 0x99:
	case 0x9A:
	case 0x9B:
	case 0x9C:
	case 0x9D:
	case 0x9E:
	case 0x9F:	goto yy11;
	default:	goto yy14;
	}
yy36:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x80:
	case 0x81:
	case 0x82:
	case 0x83:
	case 0x84:
	case 0x85:
	case 0x86:
	case 0x87:
	case 0x88:
	case 0x89:
	case 0xB1:
	case 0xB2:
	case 0xB3:
	case 0xB4:
	case 0xB5:
	case 0xB6:
	case 0xB7:
	case 0xB8:
	case 0xB9:
	case 0xBA:
	case 0xBB:
	case 0xBC:
	case 0xBD:
	case 0xBE:
	case 0xBF:	goto yy11;
	default:	goto yy14;
	}
yy37:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x84:	goto yy41;
	case 0x85:	goto yy42;
	case 0x86:	goto yy43;
	case 0x8C:	goto yy44;
	case 0xA1:	goto yy45;
	case 0xA4:	goto yy46;
	case 0xA9:	goto yy47;
	case 0xAD:	goto yy48;
	case 0xB9:	goto yy49;
	default:	goto yy14;
	}
yy38:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x81:	goto yy50;
	default:	goto yy14;
	}
yy39:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x8D:	goto yy51;
	default:	goto yy14;
	}
yy40:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x84:	goto yy52;
	default:	goto yy14;
	}
yy41:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x87:
	case 0x88:
	case 0x89:
	case 0x8A:
	case 0x8B:
	case 0x8C:
	case 0x8D:
	case 0x8E:
	case 0x8F:
	case 0x90:
	case 0x91:
	case 0x92:
	case 0x93:
	case 0x94:
	case 0x95:
	case 0x96:
	case 0x97:
	case 0x98:
	case 0x99:
	case 0x9A:
	case 0x9B:
	case 0x9C:
	case 0x9D:
	case 0x9E:
	case 0x9F:
	case 0xA0:
	case 0xA1:
	case 0xA2:
	case 0xA3:
	case 0xA4:
	case 0xA5:
	case 0xA6:
	case 0xA7:
	case 0xA8:
	case 0xA9:
	case 0xAA:
	case 0xAB:
	case 0xAC:
	case 0xAD:
	case 0xAE:
	case 0xAF:
	case 0xB0:
	case 0xB1:
	case 0xB2:
	case 0xB3:	goto yy11;
	default:	goto yy14;
	}
yy42:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB5:
	case 0xB6:
	case 0xB7:
	case 0xB8:	goto yy11;
	default:	goto yy14;
	}
yy43:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x8A:	goto yy11;
	default:	goto yy14;
	}
yy44:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xA0:
	case 0xA1:
	case 0xA2:
	case 0xA3:	goto yy11;
	default:	goto yy14;
	}
yy45:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x98:
	case 0x99:
	case 0x9A:
	case 0x9B:
	case 0x9C:
	case 0x9D:
	case 0x9E:
	case 0x9F:	goto yy11;
	default:	goto yy14;
	}
yy46:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x96:
	case 0x97:
	case 0x98:
	case 0x99:
	case 0x9A:
	case 0x9B:	goto yy11;
	default:	goto yy14;
	}
yy47:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x80:
	case 0x81:
	case 0x82:
	case 0x83:
	case 0x84:
	case 0x85:
	case 0x86:
	case 0x87:
	case 0xBD:
	case 0xBE:	goto yy11;
	default:	goto yy14;
	}
yy48:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x98:
	case 0x99:
	case 0x9A:
	case 0x9B:
	case 0x9C:
	case 0x9D:
	case 0x9E:
	case 0x9F:
	case 0xB8:
	case 0xB9:
	case 0xBA:
	case 0xBB:
	case 0xBC:
	case 0xBD:
	case 0xBE:
	case 0xBF:	goto yy11;
	default:	goto yy14;
	}
yy49:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xA0:
	case 0xA1:
	case 0xA2:
	case 0xA3:
	case 0xA4:
	case 0xA5:
	case 0xA6:
	case 0xA7:
	case 0xA8:
	case 0xA9:
	case 0xAA:
	case 0xAB:
	case 0xAC:
	case 0xAD:
	case 0xAE:
	case 0xAF:
	case 0xB0:
	case 0xB1:
	case 0xB2:
	case 0xB3:
	case 0xB4:
	case 0xB5:
	case 0xB6:
	case 0xB7:
	case 0xB8:
	case 0xB9:
	case 0xBA:
	case 0xBB:
	case 0xBC:
	case 0xBD:
	case 0xBE:	goto yy11;
	default:	goto yy14;
	}
yy50:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x92:
	case 0x93:
	case 0x94:
	case 0x95:
	case 0x96:
	case 0x97:
	case 0x98:
	case 0x99:
	case 0x9A:
	case 0x9B:
	case 0x9C:
	case 0x9D:
	case 0x9E:
	case 0x9F:
	case 0xA0:
	case 0xA1:
	case 0xA2:
	case 0xA3:
	case 0xA4:
	case 0xA5:	goto yy11;
	default:	goto yy14;
	}
yy51:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xA0:
	case 0xA1:
	case 0xA2:
	case 0xA3:
	case 0xA4:
	case 0xA5:
	case 0xA6:
	case 0xA7:
	case 0xA8:
	case 0xA9:
	case 0xAA:
	case 0xAB:
	case 0xAC:
	case 0xAD:
	case 0xAE:
	case 0xAF:
	case 0xB0:
	case 0xB1:	goto yy11;
	default:	goto yy14;
	}
yy52:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x80:
	case 0x81:
	case 0x82:
	case 0x83:
	case 0x84:
	case 0x85:
	case 0x86:
	case 0x87:
	case 0x88:
	case 0x89:
	case 0x8A:	goto yy11;
	default:	goto yy14;
	}
}
#line 14 "unicode_group_No.8--encoding-policy(substitute).re"

}
static const unsigned int chars_No [] = {0xb2,0xb3,  0xb9,0xb9,  0xbc,0xbe,  0x9f4,0x9f9,  0xb72,0xb77,  0xbf0,0xbf2,  0xc78,0xc7e,  0xd70,0xd75,  0xf2a,0xf33,  0x1369,0x137c,  0x17f0,0x17f9,  0x19da,0x19da,  0x2070,0x2070,  0x2074,0x2079,  0x2080,0x2089,  0x2150,0x215f,  0x2189,0x2189,  0x2460,0x249b,  0x24ea,0x24ff,  0x2776,0x2793,  0x2cfd,0x2cfd,  0x3192,0x3195,  0x3220,0x3229,  0x3251,0x325f,  0x3280,0x3289,  0x32b1,0x32bf,  0xa830,0xa835,  0x10107,0x10133,  0x10175,0x10178,  0x1018a,0x1018a,  0x10320,0x10323,  0x10858,0x1085f,  0x10916,0x1091b,  0x10a40,0x10a47,  0x10a7d,0x10a7e,  0x10b58,0x10b5f,  0x10b78,0x10b7f,  0x10e60,0x10e7e,  0x11052,0x11065,  0x1d360,0x1d371,  0x1f100,0x1f10a,  0x0,0x0};
static unsigned int encode_utf8 (const unsigned int * ranges, unsigned int ranges_count, unsigned char * s)
{
	unsigned char * const s_start = s;
	for (unsigned int i = 0; i < ranges_count - 2; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
			s += re2c::utf8::rune_to_bytes (s, j);
	re2c::utf8::rune_to_bytes (s, ranges[ranges_count - 1]);
	return s - s_start + 1;
}

int main ()
{
	YYCTYPE * buffer_No = new YYCTYPE [1828];
	unsigned int buffer_len = encode_utf8 (chars_No, sizeof (chars_No) / sizeof (unsigned int), buffer_No);
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_No), reinterpret_cast<const YYCTYPE *> (buffer_No + buffer_len)))
		printf("test 'No' failed\n");
	delete [] buffer_No;
	return 0;
}
