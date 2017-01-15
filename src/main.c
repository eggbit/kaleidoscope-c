#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <llvm-c/Core.h>

#include "lexer.h"

int main(__unused int argc, __unused const char *argv[]) {
    int x = get_tok();

    printf("TOKEN: %d\n", x);

    return 0;
}
