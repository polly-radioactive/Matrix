CC=gcc 
CFLAGS=-Wall -Wextra -Werror
CHECKFLAGS=-lcheck
GCOVFLAGS=-fprofile-arcs -ftest-coverage
MATRIXFILES = s21_matrix_funcs/*.c
OUT=exec
TESTFILES= s21_test_matrix.c test_cases/*.c

all: s21_matrix.a

tests: test gcov_report

gcov_report:
	$(CC) -o $(OUT) $(GCOVFLAGS) $(MATRIXFILES) $(TESTFILES) $(CHECKFLAGS)
	./$(OUT)
	lcov -capture --directory . --output-file main_coverage.info
	genhtml *.info -o ./gcov_report
	rm -rf *.gcda *.gcno *.info exec a.out

test:
	$(CC) $(MATRIXFILES) $(TESTFILES) $(CHECKFLAGS)

s21_matrix.a:
	$(CC) -c $(MATRIXFILES)
	clang-format -i *.[ch]
	ar -rc s21_matrix.a *.o
	rm -rf *.o
	
check:
	clang-format -style=Google -n $(MATRIXFILES) $(TESTFILES)

style:
	clang-format -style=Google -i $(MATRIXFILES) $(TESTFILES)
 
clean:
	rm -rf gcov_report tests/*.o ./a.out *.o *.gcda *.gcno *.info exec s21_matrix.a