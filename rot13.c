/*
 * ROT13 is a simple letter substitution cipher that replaces a letter with the
 * letter 13 letters after it in the alphabet. ROT13 is an example of the
 * Caesar cipher.
 *
 * Create a function that takes a string and returns the string ciphered with
 * Rot13. If there are numbers or special characters included in the string,
 * they should be returned as they are. Only letters from the latin/english
 * alphabet should be shifted, like in the original Rot13 "implementation".
 */
#include <stdlib.h>
#include <string.h>

int rotate (int i, int r)
{
    return (((i + 13) - r) % 26) + r;
}

int itor13(int i)
{
    if (i > 64 && i < 91) return rotate(i, 65);
    if (i > 96 && i < 123) return rotate(i, 97);

    return i;
}

char* rot13(const char *s)
{
    char* rot = (char*) malloc(sizeof(char) * (strlen(s) + 1));
    rot[0] = '\0';
    for (;*s;s++) {
        char c[2] = {itor13((int)*s), '\0'};
        strncat(rot, c, 2);
    }

    return rot;
}

#include <stdio.h>
int main(int argc, char* argv[])
{
    if (argc != 2) { printf("Invalid argument\n"); return 1; }
    printf("%s\n", rot13(argv[1]));
}
