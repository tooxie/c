/*
 * You are given an odd-length array of integers, in which all of them are the
 * same, except for one single number.
 *
 * Complete the method which accepts such an array, and returns that single
 * different number.
 *
 * The input array will always be valid! (odd-length >= 3)
 *
 * Examples
 * stray(3, {1, 1, 2}) == 2
 * stray(7, {17, 17, 3, 17, 17, 17, 17}) == 3
 */
#include <stddef.h>

int stray(size_t n, int arr[]) {
    int a = arr[0], b, c = 1;

    while (--n) {
        if (arr[n] == a) c++;
        else b = arr[n];
    }

    return c == 1 ? a : b;
}

#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("Invalid arguments\n");
        return 1;
    }

    int values[argc-1];
    for (int i = 1; i < argc; i++) {
        values[i-1] = atoi(argv[i]);
    }

    printf("%i\n", stray(argc-1, values));
}
