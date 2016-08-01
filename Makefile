CC = gcc
CFLAGS = -std=c99 `pkg-config --libs check`

clean:
	rm -f *.o *.a calc_test
	
build: src/calculate.c src/convert.c
	$(CC) $(CFLAGS) -c src/calculate.c src/convert.c

test:
	$(CC) -o calc_test src/calculate.c src/convert.c tests/check_all.c -lcheck $(CFLAGS)

check: test
	./calc_test

