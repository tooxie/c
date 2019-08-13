#include <stdio.h>
#include <memory.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Invalid arguments\n");
        return 1;
    }

    char* arg = argv[1];
    char head = arg[0];
    printf("arg: %s\n", arg);
    printf("head: %c\n", head);
    printf("strlen: %i\n", strlen(arg));

    memmove(arg, arg + 1, strlen(arg) - 1);
    arg[strlen(arg) - 1] = head;
    printf("new: %s\n", arg);

    return 0;
}
