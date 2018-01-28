#include <stdio.h>
#include <assert.h>

extern void* scanner_create(FILE* stream);
extern void scanner_destroy(void* a_scanner);
extern int scanner_scan(void* a_scanner, char** out, size_t* outlen);

int main(int argc, char** argv) {
	char buf[] =
		"\\\" 1234 0x1234 0b10 0100 \"hello \\\" world\" 'error123' 22 true false null"
		"[1,2,3,4,\"hello\",\"hello \\\" \\\" again\",null,true,false,{}]"
		"{ \"key\": \"value\", \"key2\": null }";
	FILE* json = fmemopen(buf, sizeof(buf), "r");
	void* scanner = scanner_create(json);

	int token;
	char* token_val;
	size_t token_valsize;
	while((token = scanner_scan(scanner, &token_val, &token_valsize)) >= 0) {
		printf("token[%d]\ttoken_val[%.*s]\n", token, (int)token_valsize, token_val);
	}
	assert(token != -2);

	scanner_destroy(scanner);
	fclose(json);

	return 0;
}
