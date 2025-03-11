TARGET = MyString

all : ${TARGET}

MyString: main.o MyString.o
	cc -o MyString main.o MyString.o

main.o : main.c MyString.h
	cc -c main.c

MyString.o : MyString.c
	cc -c MyString.c

clean :
	rm ${TARGET} main.o MyString.o
