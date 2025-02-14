#include <stdio.h>
#include "screen.h"
#include "process.h"

int main() {
    Option *options = NULL;
    createOption(&options, "dar a bunda");
    createOption(&options, "comer viado");
    createOption(&options, "lamber viado");
    createOption(&options, "bapihomet");
    createOption(&options, "passoa");
    createOption(&options, "vixi");


    createScreen(options);
    freeOption (options);
    return 0;
}
