#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int copy(char* srcFileName, char* destFileName, char mode) {
    FILE* srcFile = fopen(srcFileName, "r");
    FILE* destFile;
    char srcFileTracker = fgetc(srcFile);

    // Checking whether the destination file exists or not.
    // Then, we open it by matching the wanted mode.
    if ((access(destFileName, F_OK) != -1 || access(destFileName, F_OK) == -1) && mode == 'f') {
        destFile = fopen(destFileName, "w");
    }
    else if (access(destFileName, F_OK) != -1 && mode == 'v') {
        printf("target file exist");
        return 0;
    }
    else if (access(destFileName, F_OK) == -1 && mode == 'v') {
        destFile = fopen(destFileName, "w");
    }

    // Transferring a copy of each char of the source file into the destination file.
    do {
        fputc(srcFileTracker, destFile);
        srcFileTracker = fgetc(srcFile);
    } while (srcFileTracker != EOF);

    // Closing both files after finishing handling them.
    fclose(srcFile);
    fclose(destFile);

    return 0;
}

int main(int argc, char* argv[]) {
    // Initializing flags for -f and -v commands.
    int v = 0, f = 0, option;
    extern int optind;
    int res;

    // Commands recognition, either -v or -f.
    while ((option = getopt(argc, argv, "vf")) != -1) {
        if (option == 'v') {
            v = 1;
        }
        else if (option == 'f') {
            f = 1;
        }
        else {
            printf("The inserted command is not supported. Choose -v or -f ONLY.\n");
            return -1;
        }
    }

    // Performing cmp tool according to the chosen command.
    if (v == 1) {
        if ((res = copy(argv[optind], argv[optind + 1], 'v')) == 0 && (access(argv[optind + 1], F_OK) == 0))
            printf("\n");
        else if ((res = copy(argv[optind], argv[optind + 1], 'v')) == 0 && access(argv[optind + 1], F_OK) == -1)
            printf("success\n");
        else
            printf("general failure\n");
    }
    else if (f == 1) {
        copy(argv[optind], argv[optind + 1], 'f');
        printf("success");
    }

    return 2;
}
