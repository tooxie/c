/*
 * Write a function that takes a positive integer and returns the next smaller
 * positive integer containing the same digits.
 *
 * For example:
 *   nextSmaller(21) == 12
 *   nextSmaller(531) == 513
 *   nextSmaller(2071) == 2017
 *
 * Return -1 when there is no smaller number that contains the same digits.
 * Also return -1 when the next smaller number with the same digits would
 * require the leading digit to be zero:
 *   nextSmaller(9) == -1
 *   nextSmaller(111) == -1
 *   nextSmaller(135) == -1
 *   nextSmaller(1027) == -1  // we don't write numbers with leading zeros
 *
 * > Some tests will include very large numbers.
 * > Test data only employs positive integers.
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void append(char* dest, char s) {
    int pos = 0;
    int found = 0;
    while(dest[pos]) {
        if (dest[pos] == s) return;
        if (dest[pos] > s) {
            if (!found++) dest[pos] = s;
            dest[pos + 1] = dest[pos];
        }
        pos++;
    }
}

void unique(char* dest, char* s)
{
    while(*s) {
        append(dest, *s);
        s++;
    }
}

char getsmaller(char* ss, char s)
{
    char prev = ss[0];

    while(*++ss) {
        if (s >= *ss) return prev;
        prev = *ss;
    }

    return s;
}

void swap(char* s, int x, int y)
{
    char c = s[y];
    s[y] = s[x];
    s[x] = c;
}

unsigned long long next_smaller_number(unsigned long long n)
{
    char ns[32];
    sprintf(ns, "%llu", n);
    int l = strlen(ns);
    char set[l];
    set[0] = '\0';
    unique(set, ns);

    while(l--) {
        char s[strlen(ns)]; strcpy(s, ns);
        for (int i = l - 1; i >= 0; i--) {
            if (ns[i] != '0' && ns[i] > ns[l]) {
                swap(s, i, l);
                unsigned long long ll = atoll(s);
                if (ll < n) return ll;
            }
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    long long s = next_smaller_number(atoll(argv[1]));
    printf("%llu\n", s);
}
