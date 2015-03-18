#include <stdio.h>

int main(){

    char buffer[256];
    char* ptr = buffer;

    /*
    FILE* tmp = tmpfile();


    fputs("abcdef\n", tmp);
    fflush(tmp);
    */

    //fprintf(tmp, "abcdef");

    fgets(buffer, 256, stdin);

    printf("get string of size 3, get '%s'\n", buffer);
    printf("ptr is '%s'\n", ptr);



}


