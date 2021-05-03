all: compile run


compile:
	gcc -I ./include/ -o ./lib/fields.o -c ./src/fields.c
	gcc -I ./include/ -o ./lib/jval.o -c ./src/jval.c
	gcc -I ./include/ -o ./lib/jrb.o -c ./src/jrb.c
	gcc -I ./include/ -o ./bin/Test ./lib/fields.o ./lib/jval.o ./lib/jrb.o ./src/main.c

run:
	./bin/Test	
