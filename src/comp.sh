cd src 
lex c.l
bison -d c.y
cd ..
gcc src/lex.yy.c src/c.tab.c -ll -o ex