remove:
	rm -f c.tab.c c.tab.h ex lex.yy.c

compile:
	lex c.l
	bison -d c.y
	gcc lex.yy.c c.tab.c -ll -o ex

run:
	./ex test.txt