/*
 * Write a function, persistence, that takes in a positive parameter num and
 * returns its multiplicative persistence, which is the number of times you
 * must multiply the digits in num until you reach a single digit.
 *
 * For example:
 *
 *   persistence(for: 39) === 3 // because 3*9 = 27, 2*7 = 14, 1*4=4
 *                              // and 4 has only one digit
 *
 *   persistence(for: 999) === 4 // because 9*9*9 = 729, 7*2*9 = 126,
 *                               // 1*2*6 = 12, and finally 1*2 = 2
 *
 *   persistence(for: 4) === 0 // because 4 is already a one-digit number
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Turn a string into a list of int
void decomp(int* dest, char* s) {
    int l = strlen(s);

    for (int i = 0; i < l; i++) {
        dest[i] = s[i] - '0';  // cast to int
    }
}

int multiply(int size, int* nn) {
    int res = 1;

    for (int i = 0; i < size; i++) {
        res *= nn[i];
    }

    return res;
}

int calc(int size, int* nn, int count) {
    if (size == 1) { return count; }

    int res = multiply(size, nn);
    char s[6];
    sprintf(s, "%d", res);
    int l = strlen(s);
    int sl[l];
    decomp(sl, s);

    return calc(l, sl, ++count);
}

int persistence(int n) {
    char s[6];
    sprintf(s, "%d", n);
    int l = strlen(s);
    int nn[l];
    decomp(nn, s);

    return calc(l, nn, 0);
}

int main(int argc, char* argv[]) {
    if (argc != 2) { printf("Invalid arguments"); return 1; }

    char* i = argv[1];
    int n = atoi(i);
    int p = persistence(n);

    printf("%i\n", p);
}
