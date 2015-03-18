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
