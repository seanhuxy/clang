#include <stdio.h>
#include <stdarg.h>

// used -std=c99
void func(int n, ...){

    char* str;
    int i;
    va_list vl;
    va_start(vl, n);
    for(i=0; i<n; i++){

        str = va_arg(vl, char*);
        printf("%s\n", str);
    }
    va_end(vl);
}

int main(){
    func(4,"hello","world","hello","byebye");
    return 0;
}


    
