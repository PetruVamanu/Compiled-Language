remove:
	rm -f src/c.tab.c src/c.tab.h ex src/lex.yy.c

compile:
	./src/comp.sh

run:
	rm -f symbol_tables/symbol_table_functions.txt symbol_tables/symbol_table.txt
	./ex test_cases/test.txt

good:
	rm -f symbol_tables/symbol_table_functions.txt symbol_tables/symbol_table.txt
	./ex test_cases/good.txt

bad:
	rm -f symbol_tables/symbol_table_functions.txt symbol_tables/symbol_table.txt
	./ex test_cases/bad.txt