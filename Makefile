all:
	mkdir -p bin
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	@echo "--- Test 1 (Domyślny) ---"
	bin/gauss dane/A dane/b
	@echo "--- Test 2 (Pivoting - Zero na przekątnej) ---"
	bin/gauss dane/C dane/d
