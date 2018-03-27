#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lexico.h"

#define NANO_PER_SEC 1000000000.0

extern FILE *yyin;
extern int yylex();
extern int yylineno;
extern char *yytext;
int facets = 0;
int vertex = 0;
FILE *fich;

int main(int argc, char **argv)
{
	int i;
	struct timespec start, end;
	clock_gettime(CLOCK_REALTIME, &start);
    fich=fopen(argv[1],"r");
    yyin=fich;
	int prev_i = 0;
    while ((i=yylex())){ 
    	//Code for save the vertex here:
    	if (i == FACET) facets++;
    	if (i == VERTEX) vertex++;
    }
	clock_gettime(CLOCK_REALTIME, &end);
    fclose(fich);
	double start_sec = start.tv_sec + start.tv_nsec/NANO_PER_SEC;
	double end_sec = end.tv_sec + end.tv_nsec/NANO_PER_SEC;
	double elapsed = end_sec - start_sec;
	printf("Facets: %d; Vertex: %d; elapsed: %.2f microseg\n",facets, vertex, elapsed);
    return 0;
}
