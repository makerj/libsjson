/* Generated by re2c */

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 0x00:	goto yy2;
	case 'c':
		yyt1 = YYCURSOR;
		goto yy6;
	default:
		yyt1 = YYCURSOR;
		goto yy3;
	}
yy2:
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy5;
	case 'c':	goto yy6;
	default:	goto yy3;
	}
yy5:
	YYCURSOR = YYMARKER;
	goto yy2;
yy6:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:
		yyt2 = YYCURSOR;
		goto yy8;
	case 'c':	goto yy6;
	default:
		yyt2 = YYCURSOR;
		goto yy9;
	}
yy8:
	yynmatch = 3;
	yypmatch[2] = yyt1;
	yypmatch[4] = yyt2;
	yypmatch[0] = yyt1;
	yypmatch[1] = YYCURSOR;
	yypmatch[3] = yyt2 - 1;
	yypmatch[5] = YYCURSOR;
	{}
yy9:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy8;
	case 'c':	goto yy6;
	default:	goto yy9;
	}
}

re2c: warning: line 6: rule matches empty string [-Wmatch-empty-string]
