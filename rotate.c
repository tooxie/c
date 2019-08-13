#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void slicestr(const char* str, char* dest, int start, int end) {
    size_t j = 0;
    for (int i = start; i < end; i++) {
        dest[j++] = str[i];
    }

    dest[j] = '\0';
}

void rotatestr(char* str) {
    int len = strlen(str);
    char head = str[0];

    memmove(str, str + 1, len - 1);
    str[len - 1] = head;
}

void rotate(char* ns, int i) {
    int len = strlen(ns);
    char slice[len];
    char newn[len + 1];  // len + '\0'

    slicestr(ns, newn, 0, i);  // Cut the head
    slicestr(ns, slice, i, len);  // Cut the tail
    rotatestr(slice);  // Rotate the tail
    strcat(newn, slice);  // Re-join
    newn[len+1] = '\0';

    strcpy(ns, newn);
}

long long maxRot(long long n) {
    char ns[32];
    sprintf(ns, "%lld", n);

    int nlen = strlen(ns);
    ns[nlen] = '\0';

    char max[nlen+1];
    strcpy(max, ns);

    for (int i = 0; i < nlen - 1; i++) {
        rotate(ns, i);
        if (strtoll(ns, NULL, 10) > strtoll(max, NULL, 10)) {
            strcpy(max, ns);
        }
    }

    return strtoll(max, NULL, 10);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Invalid arguments\n");
        return 1;
    }

    long long n = strtoll(argv[1], NULL, 10);

    printf("[%llu] %s -> %llu\n", n, argv[1], maxRot(n));
    return 0;
}
