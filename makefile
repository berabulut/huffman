LIBCDIR = /usr/lib/
COMPILER = cc
OBJS = main.o io.o data.o
EXE = proje
${EXE} : ${OBJS} ${LIBCDIR}libc.a
${COMPILER} -o ${EXE} ${OBJS} ${LIBCDIR}libc.a
@echo == Derleme islemi basari ile tamamlandi!.. ==
main.o : main.c data.h io.h
${COMPILER} -c main.c
@echo main.o dosyasi basari ile olusturulmustur.
io.o : io.h io.c
${COMPILER} -c io.c
@echo io.o dosyasi basari ile olusturulmustur.
data.o : data.h data.c
${COMPILER} -c data.c
@echo data.o dosyasi basari ile olusturulmustur.
clean :
${LIBCDIR}rm *.o
@echo Obje dosyalar basari ile temizlenmistir.