#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // 异常判断
    if (argc != 2) {
        fprintf(stderr, "%s, invalid number of arguments\n", argv[0]);
        return 1;
    }

    char *P = argv[1];

    printf("    .global main\n");
    printf("main:\n");

    // 转换字符串
    printf("    li a0, %ld\n", strtol(P, &P, 10));

    while(*P) {
        if (*P == '+') {
            ++P;
            printf("    addi a0, a0, %ld\n", strtol(P, &P, 10));
            continue;
        }

        if (*P == '-') {
            ++P;
            printf("    addi a0, a0, -%ld\n", strtol(P, &P, 10));
            continue;
        }

        fprintf(stderr, "Unexpected character: '%c'\n", *P);
        return 1;
    }

    printf("    ret\n");

    return 0;
}
