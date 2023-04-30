#include <string.h>
#include <stdio.h>
#include <ctype.h>

// This method converts upper case letters into lower case letters.
void encode_codecA(char* str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = tolower(str[i]);
        }
        else if (str[i] >= 97 && str[i] <= 122) {
            str[i] = toupper(str[i]);
        }
    }

    printf("%s\n", str);
}

// This method converts upper case letters into lower case letters.
void decode_codecA(char* str) {
    encode_codecA(str);
}