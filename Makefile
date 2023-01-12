remove:
	rm -f c.tab.c c.tab.h ex lex.yy.c

compile:
	lex c.l
	bison -d c.y
	gcc lex.yy.c c.tab.c -ll -o ex

run:
	rm -f symbol_table_functions.txt symbol_table.txt
	./ex test.txt


good:
	rm -f symbol_table_functions.txt symbol_table.txt
	./ex good.txt

bad:
	rm -f symbol_table_functions.txt symbol_table.txt
	./ex bad.txt