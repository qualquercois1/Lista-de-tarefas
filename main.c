#include <stdio.h>
#include "screen.h"
#include "process.h"

int main() {
    Option *options = NULL;
    createOption(&options, "chari viado");
    createOption(&options, "mauro viado");
    createOption(&options, "lacerda viado");
    createOption(&options, "chari viado");
    createOption(&options, "mauro viado");
    createOption(&options, "lacerda viado");

    createScreen(options);
    freeOption (options);
    return 0;
}
