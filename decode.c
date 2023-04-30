#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <dlfcn.h>

int main(int argc, char* argv[]) {
    // Initialization setup.
    void* library;
    void (*decode)(char*);

    // Recognizing the 2nd passed parameter and loading the correct library it needs.
    if (strcmp(argv[1], "codecA") == 0) {
        library = dlopen("./libcodecA.so", RTLD_LAZY);
        decode = dlsym(library, "decode_codecA");
    }
    else if (strcmp(argv[1], "codecB") == 0) {
        library = dlopen("./libcodecB.so", RTLD_LAZY);
        decode = dlsym(library, "decode_codecB");
    }
    else {
        printf("The argument %s is unsupported.\n", argv[1]);
    }

    // Performing the requested method of the library we loaded and then closing it.
    decode(argv[2]);
    dlclose(library);
    
    return 0;
}