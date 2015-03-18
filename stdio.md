# <stdio.h>

### File Operation 
#### open and close
```c
// return NULL if fails
FILE * fopen(const char* filename, const char * flag);

FILE * freopen(const char* filename, const char * mode, FILE * stream);

// redirect stdin, stdout to file
freopen("log", "a", stderr);

// returns EOF if writting error, 0 otherwise;
int fflush(FILE* stream);

// returns EOF if any error happens, 0 otherwise;
int fclose(FILE* stream);
```

Mode

```c
"r"  : open, reading
"w"	 : create or open and discard previous contents if any
"a"  : open or create, append

"r+" : open, read and write(update)
"w+" : create and update
"a+" : append and update
"b"
```


#### delete file and rename file

```c
// rm file 
// returns non-zero if any error happens
int remove(const char* filename);

// non-zero for errors
int rename(const char* oldname, const char* newname);
```

#### Temp files

```c
// NULL if fail
FILE * tmpfile(void)

char *tmpnam(char s[L_tmpnam])
L_tmpnam -- the max char for a name
TMP_MAX  -- max number of different tmp files
```

#### buffer
- should be called before any read write,


```c
// return non-zero for errors
int setvbuf(FILE * stream, char * buf, int mode, size_t size);
int setbuf(FIEL * stream, char * buf);

setbuf(stream, NULL); // = no buffer

//mode
_IOFBF		// full buffer
_IOLBF		// line buffer
_IONBF		// no buffer

```

### Formatted Output

```c
// return number of chars written
// negative if errors
int printf(const char * format, ...);
int fprintf(FILE * stream, const char *format, ...);
int sprintf(char *s, const char * format, ...);


int vprintf(const char * format, va_list arg);
int vfprintf(FILE *stream, const char * format, va_list arg);
int vsprintf(char *s, const char * format, va_list arg);
```


| specifier |	Output	| Example |
| --------- | ------|---------|
| d or i	| Signed decimal integer |	392|
|u	|Unsigned decimal integer|	7235|
|o	|Unsigned octal	|610|
|x	|Unsigned hexadecimal integer|	7fa|
|X	|Unsigned hexadecimal integer (uppercase)|	7FA|
|f	|Decimal floating point, lowercase	|392.65|
|F	|Decimal floating point, uppercase	|392.65|
|e	|Scientific notation (mantissa/exponent), |lowercase	3.9265e+2|
|E	|Scientific notation (mantissa/exponent), uppercase|	3.9265E+2|
|**g**	|Use the shortest representation: %e or %f	|392.65|
|**G**	|Use the shortest representation: %E or %F	|392.65|
|a	|Hexadecimal floating point, lowercase	|-0xc.90fep-2|
|A	|Hexadecimal floating point, uppercase	-0XC.90FEP-2|
|c	|Character	|a|
|s	|String of characters	|sample|
|p	|Pointer address	| b8000000 |
|n	|-> a pointer to a signed int. The number of characters written so far is stored in the pointed location.	| - |
|%	|A % followed by another % character will write a single % to the stream.	| %|


```c
#include <stdio.h>
int main(){

    //% [flag][width][.precision][length]specifier

    // flag
    // - : left justify, if width is specified
    // + : force sign
    printf("left %-+6d\n", 12);
    printf("right%+6d\n", 12);

    // # : hex or oct, force 0x 0
    printf("#hex : %#X\n", 0xABC);
    printf("#oct : %#o\n", 0765);

    // 0: left padding with 0
    printf("left pad 0: %0+6d\n", 12);     // +00012
    printf("left pad 0: %06d\n", 12);      // 000012
    printf("left pad 0: %0#6x\n", 0xABC);  // 0x0abc

    // width (number) or *
    // min chars to be printed, padding with leading space by default
    printf("hello( 10): %10s\n", "hello");
    printf("hello(010): %010s\n", "hello");
    printf("helloworld(5): %5s\n", "helloworld");

    // precision (number) or *
    // int: min number of digits to be printed, 
    // (padding with leading 0s)
    printf("   1: %4.3d\n", 1);      // 001
    printf("1234: %4.3d\n", 1234);   //1234

    // float
    // min digits after decimal point(default 6)
    printf("f: %f\n", 12345.6);    //12345.600000
    printf("f: %.2f\n", 12345.6);  //12345.60
    printf("f: %.4f\n", 12345.6);  //12345.6000
    printf("f: %.8f\n", 12345.6);  //12345.600000

    // g,G
    // max significant digits to be printed
    printf("gG: %G\n", 12345.6);    //12345.6
    printf("gG: %.2G\n", 12345.6);  //1.2E+4
    printf("gG: %.4G\n", 12345.6);  //1.235E+4
    printf("gG: %.8G\n", 12345.6);  //12345.6

    // string : max chars to be printed
    printf("string: %.5s\n", "hello world");

    // *
    printf("string: %.*s\n", 5, "helloworld");
}
```

#### format input

```c
int scanf(const char * format, ...);
int sscanf(const char * s, const char * format, ...);
int fscanf(FILE * stream, const char * format, ...);

```

```c
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
    sscanf(str, "%*d , %s", &buffer);
    printf("read '%s', get string '%s'\n", str, buffer);
    
    // [width], read max chars
    str = "hello, world";
    sscanf(str, "%5s", &buffer);
    printf("read '%s' within 5 chars, get string '%s'\n", str, buffer);

    str = "hello, world";
    memset(buffer, '0', 256);
    sscanf(str, "%5c", &buffer); // read 5 char, no null char '\0' append.
    printf("read '%s' within 5 chars, get string '%s'\n", str, buffer);

    // [] scan set
    // only accept a-z and space
    str = "HELLE world HELLO";
    sscanf(str, "%*[A-Z]%[a-z ]", &buffer);
    printf("read lowercase and space from '%s', get '%s'\n", str, buffer);

    // [] get a whole line;
    str = "Hello World 123 \n";
    sscanf(str, "%[^\n]", &buffer);
    printf("read line from '%s', get '%s'\n", str, buffer);

    // n get number of char that have been read
    sscanf(str, "%[^1-9] %n", &buffer, &integer);
    printf("read from '%s', get %d chars '%s'\n", str, integer, buffer);
}
```

#### char input and output

```c
// error, EOF -> returns EOF
int fgetc(FILE * stream);
char* fgets(char *s, int n, FILE * stream);

// error -> EOF
int fputc(int c, FILE * stream);
int fputs(const char *s, FILE * stream);

// = fgetc, 
// in some lib, may implemented as macro
int getc(FILE * stream);

int getchar(void); // = getc(stdin);

// reads next input line from stdin
// ends when meets newline, EOF, error
// returns s or NULL;
char *gets(char *s);

// = fputc
// in some lib, may implemented as macro
int putc(int c, FILE * stream);

int putchar(int c); // = putc(c, stdout);

// write s and newline to stdout
// returns EOF if error, 
int puts(const char *s)

```



### <stdarg.h> variable arg lists

> a list of function args of unknown number and type.

```c
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
```






