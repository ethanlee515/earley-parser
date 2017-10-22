CPPFLAGS = -std=c++14 -O2

main: main.cpp parser.o rule.o entry.o column.o

entry.o: entry.cpp entry.h rule.h

rule.o: rule.cpp rule.h

column.o: column.cpp column.h rule.h

parser.o: parser.cpp parser.h rule.h column.h

test: test.cpp rule.o parser.o entry.o column.o

clean:
	rm -f *.o main test
