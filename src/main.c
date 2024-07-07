#include <stdio.h>
#include <string.h>
#include "main.h"

const char HELP[] = "\nThis is C CLI App\n\nIt has two commands:\n\tcommandA\t\tDisplays command A output\n\tcommandB [Name]\t\tSays hello to the Name"; 

int main(int argc, char *argv[]) {
    printArguments(argc, argv);
    processCommands(argc, argv);
    return 0;
}

void printArguments(int argc, char *argv[])
{
    printf("Running C CLI app\n\nArguments passed:\n");

    for (int i = 0; i < argc; i++)
    {
        printf("%i : %s\n", i, argv[i]);
    }

    printf("\n");
}

void processCommands(int argc, char *argv[])
{
    if (argc == 1) {
        printf("%s\n", HELP);
    }

    if (strcmp(argv[1], "-h") == 0) {
        printf("%s\n", HELP);
    }
    else if (strcmp(argv[1], "commandA") == 0) {
        printf("Command A output\n");
    } else if (strcmp(argv[1], "commandB") == 0) {
        runCommandB(argc, argv);
    } else {
        printf("Unrecognized command\n");
    }

}

void runCommandB(int argc, char *argv[])
{
    printf("Command B ouptut\n");

    if (argc < 3) {
        printf("Command B takes 1 argument: name\n");
        return;
    }

    printf("Hello, %s!\n", argv[2]);
}
