#ifndef __PROCESS_H
#define __PROCESS_H

typedef struct {
    char    *name;
    int     confirm;
} Data;

typedef struct Option{
    Data            data;
    struct Option   *next;
} Option;

void createOption(Option **opt, char *name);
void freeOption(Option *opt);
void printTasks(Option *opt, int select);

#endif
