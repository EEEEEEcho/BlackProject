#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct Point{
    int x;
    int y;
};
char a;
short b;
int c;
struct Point p;
void main(){
    char x;
    char* p1;
    char** p2;
    char*** p3;
    char**** p4;
    p1 = &x;
    p2 = &p1;
    p3 = &p2;
    p4 = &p3;
    system("pause");
    return;
}