.PHONY: all clean

BASE := $(PWD)
LEMON := $(BASE)/libs/lemon/build/lemon
RE2C := $(BASE)/libs/re2c/build/bin/re2c

CC := gcc
CFLAGS := -std=gnu11 -O3
# CFLAGS := -std=gnu11 -O0 -g

all: $(RE2C) $(LEMON) build/json
	build/json


$(RE2C):
	$(shell mkdir -p ./libs/re2c/build/)
	rm -rf /tmp/re2c && cp -Lr $(BASE)/libs/re2c /tmp
	cd /tmp/re2c/ && ./autogen.sh && ./configure --prefix=$(BASE)/libs/re2c/build && make install
	rm -rf /tmp/re2c

$(LEMON):
	$(shell mkdir -p ./libs/lemon/build/)
	cd $(BASE)/libs/lemon/ && $(CC) $(CFLAGS) -o build/lemon lemon.c
	cp $(BASE)/libs/lemon/lempar.c $(BASE)/libs/lemon/build/lempar.c

build/json: json.c json_scan.gen.c json_gram.gen.c ./libs/ds/hmap.c ./libs/ds/vec.c
	@(mkdir -p build/)
	$(CC) $(CFLAGS) -o $@ $^

json_scan.gen.c: json_scan.re.c
	$(RE2C) -W --tags -i -o $@ $<

json_gram.gen.c: json_gram.gen.yy
	$(LEMON) $<

clean:
	rm -rf build
