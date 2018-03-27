%{
#include "lexico.h"
%}

%option yylineno
%%
 /* Ignorar */
[ \n\r\t]+                                  ;
 /* Palabras clave */
solid	                                    return SOLID;
facet	                                    return FACET;
normal										return NORMAL;
outer										return OUTER;
loop										return LOOP;
vertex										return VERTEX;
endloop										return ENDLOOP;
endfacet									return ENDFACET;
endsolid									return ENDSOLID;
[a-zA-Z0-9]+				                return NAME;
[\-]?[0-9]\.[0-9]+[eE][+\-][0-9]+			return FLOAT;
.											printf("Lexical error in line %d: %s\n",yylineno,yytext);
%%



