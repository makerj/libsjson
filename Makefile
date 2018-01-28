.PHONY: all clean

BASE := $(PWD)
LEMON := $(BASE)/libs/lemon/build/lemon
RE2C := $(BASE)/libs/re2c/build/bin/re2c

CC := gcc

all: $(RE2C) $(LEMON)
	@echo 'libraries built'

$(RE2C):
	$(shell mkdir -p ./libs/re2c/build/)
	rm -rf /tmp/re2c && cp -Lr $(BASE)/libs/re2c /tmp
	cd /tmp/re2c/ && ./autogen.sh && ./configure --prefix=$(BASE)/libs/re2c/build && make install
	rm -rf /tmp/re2c

$(LEMON):
	$(shell mkdir -p ./libs/lemon/build/)
	cd $(BASE)/libs/lemon/ && $(CC) -std=gnu11 -O3 -o build/lemon lemon.c
	cp $(BASE)/libs/lemon/lempar.c $(BASE)/libs/lemon/build/lempar.c

clean:
	rm -rf build
