/* Generated by re2c */
#line 1 "unicode_group_Sk.8--encoding-policy(substitute).re"
#include <stdio.h>
#include "utf8.h"
#define YYCTYPE unsigned char
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Sk:
	
#line 13 "unicode_group_Sk.8--encoding-policy(substitute).c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	switch (yych) {
	case '^':
	case '`':	goto yy4;
	case 0xC2:	goto yy6;
	case 0xCB:	goto yy7;
	case 0xCD:	goto yy8;
	case 0xCE:	goto yy9;
	case 0xE1:	goto yy10;
	case 0xE3:	goto yy11;
	case 0xEA:	goto yy12;
	case 0xEF:	goto yy13;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
yy3:
#line 13 "unicode_group_Sk.8--encoding-policy(substitute).re"
	{ return YYCURSOR == limit; }
#line 35 "unicode_group_Sk.8--encoding-policy(substitute).c"
yy4:
	++YYCURSOR;
#line 12 "unicode_group_Sk.8--encoding-policy(substitute).re"
	{ goto Sk; }
#line 40 "unicode_group_Sk.8--encoding-policy(substitute).c"
yy6:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xA8:
	case 0xAF:
	case 0xB4:
	case 0xB8:	goto yy4;
	default:	goto yy3;
	}
yy7:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x82:
	case 0x83:
	case 0x84:
	case 0x85:
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
	case 0xA5:
	case 0xA6:
	case 0xA7:
	case 0xA8:
	case 0xA9:
	case 0xAA:
	case 0xAB:
	case 0xAD:
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
	case 0xBF:	goto yy4;
	default:	goto yy3;
	}
yy8:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xB5:	goto yy4;
	default:	goto yy3;
	}
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x84:
	case 0x85:	goto yy4;
	default:	goto yy3;
	}
yy10:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0xBE:	goto yy14;
	case 0xBF:	goto yy16;
	default:	goto yy3;
	}
yy11:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x82:	goto yy17;
	default:	goto yy3;
	}
yy12:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0x9C:	goto yy18;
	case 0x9E:	goto yy19;
	default:	goto yy3;
	}
yy13:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 0xAE:	goto yy20;
	case 0xAF:	goto yy21;
	case 0xBC:	goto yy22;
	case 0xBD:	goto yy23;
	case 0xBF:	goto yy24;
	default:	goto yy3;
	}
yy14:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xBD:
	case 0xBF:	goto yy4;
	default:	goto yy15;
	}
yy15:
	YYCURSOR = YYMARKER;
	goto yy3;
yy16:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x80:
	case 0x81:
	case 0x8D:
	case 0x8E:
	case 0x8F:
	case 0x9D:
	case 0x9E:
	case 0x9F:
	case 0xAD:
	case 0xAE:
	case 0xAF:
	case 0xBD:
	case 0xBE:	goto yy4;
	default:	goto yy15;
	}
yy17:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x9B:
	case 0x9C:	goto yy4;
	default:	goto yy15;
	}
yy18:
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
	case 0xA0:
	case 0xA1:	goto yy4;
	default:	goto yy15;
	}
yy19:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x89:
	case 0x8A:	goto yy4;
	default:	goto yy15;
	}
yy20:
	yych = *++YYCURSOR;
	switch (yych) {
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
	case 0xBF:	goto yy4;
	default:	goto yy15;
	}
yy21:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x80:
	case 0x81:	goto yy4;
	default:	goto yy15;
	}
yy22:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xBE:	goto yy4;
	default:	goto yy15;
	}
yy23:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x80:	goto yy4;
	default:	goto yy15;
	}
yy24:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0xA3:	goto yy4;
	default:	goto yy15;
	}
}
#line 14 "unicode_group_Sk.8--encoding-policy(substitute).re"

}
static const unsigned int chars_Sk [] = {0x5e,0x5e,  0x60,0x60,  0xa8,0xa8,  0xaf,0xaf,  0xb4,0xb4,  0xb8,0xb8,  0x2c2,0x2c5,  0x2d2,0x2df,  0x2e5,0x2eb,  0x2ed,0x2ed,  0x2ef,0x2ff,  0x375,0x375,  0x384,0x385,  0x1fbd,0x1fbd,  0x1fbf,0x1fc1,  0x1fcd,0x1fcf,  0x1fdd,0x1fdf,  0x1fed,0x1fef,  0x1ffd,0x1ffe,  0x309b,0x309c,  0xa700,0xa716,  0xa720,0xa721,  0xa789,0xa78a,  0xfbb2,0xfbc1,  0xff3e,0xff3e,  0xff40,0xff40,  0xffe3,0xffe3,  0x0,0x0};
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
	YYCTYPE * buffer_Sk = new YYCTYPE [464];
	unsigned int buffer_len = encode_utf8 (chars_Sk, sizeof (chars_Sk) / sizeof (unsigned int), buffer_Sk);
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_Sk), reinterpret_cast<const YYCTYPE *> (buffer_Sk + buffer_len)))
		printf("test 'Sk' failed\n");
	delete [] buffer_Sk;
	return 0;
}
