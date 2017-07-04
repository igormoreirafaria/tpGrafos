MAINFILE :=	main
HIPER:=	hipergrafoTAD
HEURISTICA:=	heuristica
MAINGRAFO:=	grafo
COMPFLAGS := 	-Wall -O9 -c
LINKFLAGS := 	-o

geral:
	gcc	$(COMPFLAGS) 	*.c 	-g
hiper:	geral
	gcc	$(LINKFLAGS)	$(MAINFILE)	$(MAINFILE).o 	$(HIPER).o 	-g
	rm -f	*.o
heuristica:	geral
	gcc	$(LINKFLAGS)	$(MAINFILE)	$(MAINFILE).o	$(HEURISTICA).o 	-g
	rm -f	*.o
clear:
	rm -f	*.o	$(MAINFILE)	$(MAINGRAFO)
run:
	./$(MAINGRAFO)
