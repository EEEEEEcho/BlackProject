#include<string.h>
#include<stdio.h>
int main(){
    char str[50];
    strcpy(str,"This is my dream");
    puts(str);
    //Arrays.fill()
    memset(str,'$',7);
    puts(str);
    return 0;
}