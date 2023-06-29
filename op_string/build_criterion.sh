gcc -o unit_test -lcriterion ./criterion/*_t.c src/*.c -I. -Wall -Wextra
./unit_test
#rm unit_test
