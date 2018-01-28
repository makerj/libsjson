#ifndef __JSON_PRIVATE_H__
#define __JSON_PRIVATE_H__

// Scanner Result
#define SR_NOMEM -2
#define SR_EOF -1
#define SR_BADCHAR 0

#define SR_NUMBER		1
#define SR_STRING		2
#define SR_NULL			3
#define SR_BOOL_TRUE	4
#define SR_BOOL_FALSE	5
#define SR_COLON		6
#define SR_COMMA		7
#define SR_LBRACKET		8
#define SR_RBRACKET		9
#define SR_LBRACE		10
#define SR_RBRACE		11
#define SR_ESC_DQUOTE	12

#endif
