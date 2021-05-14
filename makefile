INCLUDE = -I ./include
CC = gcc
LIBS = ./lib/libfdr.a
CFLAGS = $(INCLUDE)
ALL = proje

all: $(ALL)

encripted:
	./kripto -e ornek_metin encripted

decripted:
	./kripto -d ornek_metin decripted

clean:
	rm -f kripto 

cleanall:clean
	rm -f .kilit encripted decripted *.txt

run:clean proje encripted decripted

proje:
	$(CC) $(CFLAGS) -o kripto ./src/main.c $(LIBS)
	