CPPFLAGS = -std=c++14 -O2

main: main.cpp parser.o rule.o

rule.o: rule.cpp rule.h

parser.o: parser.cpp parser.h rule.h

clean:
	rm -f *.o main
