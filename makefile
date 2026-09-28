exe:main.o macro.o comment.o headerfile.o
	cc main.o macro.o comment.o headerfile.o -o exe

main.o:main.c
	cc -c main.c

macro.o:macro.c
	cc -c macro.c

comment.o:comment.c
	cc -c comment.c

headerfile.o:headerfile.c
	cc -c headerfile.c

clear:
	@echo"cleaningup"
	@rm -r *.o
