/*
 * Given a list of digits, return the smallest number that could be formed from
 * these digits, using the digits only once (ignore duplicates).
 *
 * Example: minValue ({1, 3, 1})  ==> return (13)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void join(char* dest, const int* values, const size_t len)
{
    for (int i = 0; i < len; i++) {
        char s[2];
        snprintf(s, 2, "%d", values[i]);
        dest[i] = s[0];
    }
    dest[len] = '\0';
}

unsigned long long minValue(const int* values, const size_t len)
{
    int num[len];
    int num_len = 0;

    for (int i = 0; i < len; i++) {
        int pos = 0;
        int v = values[i];
        bool dupe = false;
        bool found = false;

        for (int j = 0; j < num_len; j++) {
            pos = found ? pos : j;

            // Ignore duplicates
            if (num[j] == v) {
                dupe = true;
                break;
            }
            if (num[j] > v) {
                found = true;
                // Make room for `v` by moving the right-most element one
                // position to the right
                int h = (num_len + pos) - j;
                num[h] = num[h - 1];
            }
        }

        if (!dupe) {
            // Increment the size of num
            num[pos] = v;
            num_len++;
        }
    }

    char s[num_len];
    join(s, num, num_len);
    return atoll(s);
}

int main (int argc, char* argv[]) {
    if (argc == 1) {
        printf("Invalid arguments\n");
        return 1;
    }

    int values[argc];
    for (int i = 1; i < argc; i++) {
        values[i-1] = atoi(argv[i]);
    }

    printf("%llu\n", minValue(values, argc-1));
}
