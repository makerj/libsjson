/* Generated by re2c */
char scan(const unsigned char *s)
{

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 0x60) {
		if (yych == 0x07) goto yy4;
	} else {
		if (yych <= 0x61) goto yy6;
		if (yych == 0x7F) goto yy8;
	}
	++YYCURSOR;
	{
		return '\0';
	}
yy4:
	++YYCURSOR;
	{
		return '\x7F';
	}
yy6:
	++YYCURSOR;
	{
		return '\x2F';
	}
yy8:
	++YYCURSOR;
	{
		return '"';
	}
}

}
