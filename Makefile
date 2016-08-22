CC = gcc
CFLAGS = -g -Wall -Werror -std=c99 
LIBS=`pkg-config --cflags --libs check`

clean:
	rm -f *.o *.a calc_test
	
build: src/calculate.c src/convert.c
	$(CC) $(CFLAGS) -c src/calculate.c src/convert.c

test:
	$(CC) $(CFLAGS) -o calc_test src/calculate.c src/convert.c tests/check_all.c $(LIBS)

check: test
	./calc_test