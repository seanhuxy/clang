#include <stdio.h>
#include <string.h>
int main(){
    
    char buffer[256];
    char * str = " 123";
    int integer;

    // %[*][width][length]specifier
    // whitespace : ignore all ws
    sscanf(str, " %d ", &integer);
    printf("read ' 123' get%d\n", integer);

    sscanf(str, "%d", &integer);            // no difference
    printf("read ' 123' get %d\n", integer);    
    
    str = "123";
    sscanf(str, "%d", &integer);            // no difference
    printf("read  '123' get %d\n", integer);    
    
    // non ws, should be match

    // *, read, but ignored,
    str = "123  ,  hello";
    sscanf(str, "%*d , %s", buffer);
    printf("read '%s', get string '%s'\n", str, buffer);
    
    // [width], read max chars
    str = "hello, world";
    sscanf(str, "%5s", buffer);
    printf("read '%s' within 5 chars, get string '%s'\n", str, buffer);

    str = "hello, world";
    memset(buffer, '0', 256);
    sscanf(str, "%5c", buffer); // read 5 char, no null char '\0' append.
    printf("read '%s' within 5 chars, get string '%s'\n", str, buffer);

    // [] scan set
    // only accept a-z and space
    str = "HELLE world HELLO";
    sscanf(str, "%*[A-Z]%[a-z ]", buffer);
    printf("read lowercase and space from '%s', get '%s'\n", str, buffer);

    // [] get a whole line;
    str = "Hello World 123 \n";
    sscanf(str, "%[^\n]", buffer);
    printf("read line from '%s', get '%s'\n", str, buffer);

    // n get number of char that have been read
    sscanf(str, "%[^1-9] %n", buffer, &integer);
    printf("read from '%s', get %d chars '%s'\n", str, integer, buffer);
}
