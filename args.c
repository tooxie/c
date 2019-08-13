#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%i arguments supplied\n", argc);
    printf("Arguments: ");
    for (int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
}
