#include "process.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void createOption(Option **opt, char *name) {
    Option *new_option = malloc(sizeof(Option));
    new_option->data.name = strdup(name);
    new_option->data.confirm = 0;
    new_option->next = NULL;

    if(*opt == NULL) {
        *opt = new_option;
    } else {
        Option *temp = *opt;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_option;
    }

}

void freeOption(Option *opt) {
    Option *temp;
    while (opt) {
        temp = opt;
        opt = opt->next;
        free(temp->data.name);
        free(temp);
    }
}

void printTasks(Option *opt, int select) {
    int counter = 1;
    while (opt) {
        printf("%d\t ", counter);
        if(opt->data.confirm == 0) {
            printf("| | ");
        } else {
            printf("|X| ");
        }
        printf("%s\n", opt->data.name);
        opt = opt->next;
        counter++;
    }
}