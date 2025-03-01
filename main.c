#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // 异常判断
    if (argc != 2) {
        fprintf(stderr, "%s, invalid number of arguments\n", argv[0]);
        return 1;
    }

    printf("    .global main\n");
    printf("main:\n");
    printf("    li a0, %d\n", atoi(argv[1]));
    printf("    ret\n");

    return 0;
}
