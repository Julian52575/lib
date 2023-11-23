gcc -o unit_test -lcriterion ./criterion/*_t.c src/*.c src/set/*.c src/get/*.c -I. -Wall -Wextra
./unit_test
#rm unit_test
