/* Generated by re2c */

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 'a':
		yyt1 = YYCURSOR;
		goto yy3;
	case 'c':
		yyt1 = YYCURSOR;
		goto yy5;
	default:	goto yy2;
	}
yy2:
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':
		yyt2 = YYCURSOR;
		goto yy6;
	case 'e':
		yyt6 = YYCURSOR;
		goto yy8;
	default:	goto yy4;
	}
yy4:
	YYCURSOR = YYMARKER;
	goto yy2;
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'd':
		yyt4 = YYCURSOR;
		goto yy9;
	default:	goto yy4;
	}
yy6:
	++YYCURSOR;
	yyt4 = yyt5 = yyt6 = yyt7 = NULL;
	yyt3 = YYCURSOR;
yy7:
	yynmatch = 4;
	yypmatch[0] = yyt1;
	yypmatch[2] = yyt2;
	yypmatch[3] = yyt3;
	yypmatch[4] = yyt4;
	yypmatch[5] = yyt5;
	yypmatch[6] = yyt6;
	yypmatch[7] = yyt7;
	yypmatch[1] = YYCURSOR;
	{}
yy8:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':
		yyt7 = YYCURSOR;
		goto yy10;
	default:	goto yy4;
	}
yy9:
	++YYCURSOR;
	yyt2 = yyt3 = yyt6 = yyt7 = NULL;
	yyt5 = YYCURSOR;
	goto yy7;
yy10:
	++YYCURSOR;
	yyt2 = yyt3 = yyt4 = yyt5 = NULL;
	goto yy7;
}

re2c: warning: line 6: rule matches empty string [-Wmatch-empty-string]
