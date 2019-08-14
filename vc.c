/*
 * Return the number (count) of vowels in the given string. We will consider a,
 * e, i, o, and u as vowels for this Kata. The input string will only consist
 * of lower case letters and/or spaces.
 */
#include <stddef.h>

size_t get_count(const char *s)
{
    int c = 0;
    while(*s) {
        switch(*s++) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                c++;
                break;
        }
    }

    return c;
}

#include <stdio.h>
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Invalid argument\n");
        return 1;
    }

    printf("%i\n", get_count(argv[1]));
}
