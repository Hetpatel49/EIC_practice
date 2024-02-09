TARGET: exe
exe: application.o libfun.a
	gcc application.o -o exe -L . libfun.a
application.o:application.c
	gcc -c application.c -o application.o
libfun.a:source.o
	ar rs libfun.a source.o
source.o:source.c
	gcc -c -I header source.c -o source.o
clean:
	rm -rf exe source.o application.o libfun.a
