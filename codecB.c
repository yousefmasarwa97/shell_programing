#include <string.h>
#include <stdio.h>
#include <ctype.h>

// This method converts each char to the 3rd next char according to ASCII table.
void encode_codecB(char* str) {
    for (size_t i = 0; i < strlen(str); i++) {
        str[i] = str[i] + 3;
    }
    
    printf("%s\n", str);
}

// This method converts each char to the 3rd former char according to ASCII table.
void decode_codecB(char* str) {
    for (size_t i = 0; i < strlen(str); i++) {
        str[i] = str[i] - 3;
    }
    
    printf("%s\n", str);
}