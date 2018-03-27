# Makefile para compilar lexico
lexico : lexico.c lexico.h main.c
	gcc lexico.c main.c -lfl -o lexico

lexico.c : lexico.l lexico.h
	flex -o lexico.c lexico.l

clean :
	rm -f lexico.c lexico

prueba1 : lexico prueba1.mc
	./lexico prueba1.mc

prueba2 : lexico prueba2.mc
	./lexico prueba2.mc