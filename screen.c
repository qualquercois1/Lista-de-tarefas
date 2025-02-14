#include "screen.h"
#include "process.h"
#include <string.h>
#include <stdio.h>
#include <windows.h>

void printOptions() {
    printf(" (1) - Criar Tarefa ||");
    printf(" (2) - Alterar Tarefa ||");
    printf(" (3) - Excluir Tarefa ||");
    printf(" (0) - Sair");
    printf("\n");
}

void divisor(int width) {
    for(int i=0; i<width; i++) {
        printf("-");
    }
}

void getTerminalSize(int *width, int *height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void createScreen(Option *opt) {
    int option_select = 1;
    system("chcp 65001");
    system("cls");
    int width, height;
    getTerminalSize(&width, &height);

    //titulo
    char *title = "Lista de Tarefas";
    int title_size = strlen(title);
    for(int i=0; i<width-title_size+1; i++) {
        if(i == (width-title_size)/2) printf("%s", title);
        else printf(" ");
    }
    printf("\n");

    divisor(width);

    printOptions();

    divisor(width);

    printf("\n");
    printTasks(opt, option_select);

    divisor(width);

    printOptions();

    for(int i=0; i<width; i++) {
        printf("-");
    }
}