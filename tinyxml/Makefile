CC=g++ -g -fpic -c
GCC=g++ -g -shared
OBJ=libxml.so

OBJ:tinystr.o tinyxml.o tinyxmlerror.o tinyxmlparser.o
	$(GCC) tinystr.o tinyxml.o tinyxmlerror.o tinyxmlparser.o -shared -o $(OBJ)

tinystr.o:
	$(CC) tinystr.cpp -o $@
tinyxml.o:
	$(CC) tinyxml.cpp -o $@
tinyxmlerror.o:
	$(CC) tinyxmlerror.cpp -o $@
tinyxmlparser.o:
	$(CC) tinyxmlparser.cpp -o $@


