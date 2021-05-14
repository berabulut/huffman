INCLUDE = -I ./include
CC = gcc
LIBS = ./lib/libfdr.a
CFLAGS = $(INCLUDE)
ALL = proje

all: $(ALL)

encrypt:
	./kripto -e ornek_metin encripted

decrypt:
	./kripto -d encripted decripted

clean:
	rm -f kripto 

cleanall:clean
	rm -f .kilit encripted decripted *.txt

run: clean proje encrypt decrypt

proje:
	$(CC) $(CFLAGS) -o kripto ./src/main.c $(LIBS)
	