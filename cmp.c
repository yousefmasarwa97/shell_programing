#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int cmp(char* firstFileName, char* secondFileName, char mode) {
    // Reading the two files that will be retrieved from argv.
    FILE* firstFile = fopen(firstFileName, "r");
    FILE* secondFile = fopen(secondFileName, "r");
    
    // Initializing two chars for each file to read their streams.
    char FF_ch, SF_ch;

    // In case -i command was chosen:
    if (mode == 'i') {
        // As long as the two files didn't reach their end, we keep reading their streams as lowercase.
        while (FF_ch != EOF && SF_ch != EOF) {
            FF_ch = fgetc(firstFile);
            SF_ch = fgetc(secondFile);

            if (tolower(FF_ch) != tolower(SF_ch)) {
                return 1;
            }
        }
    }
    // In case -v command was chosen:
    else if (mode == 'v') {
        // As long as the two files didn't reach their end, we keep reading their streams.
        while (FF_ch != EOF && SF_ch != EOF) {
            FF_ch = fgetc(firstFile);
            SF_ch = fgetc(secondFile);

            if (FF_ch != SF_ch ) {
                return 1;
            }
        }
    }

    // Closing both files once finishing reading them.
    fclose(firstFile);
    fclose(secondFile);

    if (FF_ch != SF_ch) {
        return 1;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    // Initializing flags for -i and -v commands.
    int v = 0, i = 0, option;
    extern int optind;

    // Commands recognition, either -v or -i.
    while ((option = getopt(argc, argv, "vi")) != -1) {
        if (option == 'v') {
            v = 1;
        }
        else if (option == 'i') {
            i = 1;
        }
        else {
            printf("Unsupported command was chosen. Choose -v or -i ONLY.");
        }
    }

    int res;

    // Performing cmp tool according to the chosen command.
    if (v == 1) {
        if ((res = cmp(argv[optind], argv[optind + 1], 'v')) == 0)
            printf("equal\n");
        else
            printf("distinct\n");
    }
    else if (i == 1) {
        if ((res = cmp(argv[optind], argv[optind + 1], 'i')) == 0)
            printf("equal\n");
        else
            printf("distinct\n");
    }

    return 2;
}