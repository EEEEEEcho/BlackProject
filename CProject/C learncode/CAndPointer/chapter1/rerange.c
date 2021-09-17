/**
 * 这个程序从标准输入中读取输入行并在标准输出中打印这些输出行
 * 每个输出行的后面一行是该行内容的一部分
 * 
 * 输入的第一行是一串标号，串的最后以一个负数结尾
 * 这些列标号成对出现，说明需要打印的输入行的列的范围
 * 例如：0 3 10 12 -1 表示第0列到第3列，第10列到第12列的内容将被打印
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20     /*所能处理的最大列号*/
#define MAX_INPUT 1000
int read_column_numbers(int columns[],int max);
void rearrange(char* output,char const* input,int n_columns,int const columns[]);
int main(){
    int n_columns;  //进行处理的列标号
    int columns[MAX_COLS];  //需要处理的列数
    char input[MAX_INPUT];  //容纳输入行的数组
    char output[MAX_INPUT]; //容纳输出行的数组

    n_columns = read_column_numbers(columns,MAX_COLS);
    while (gets(input) != NULL)
    {
        printf("Original input : %s \n",input);
        rearrange(output,input,n_columns,columns);
        printf("Rearrange lines: %s \n",output);
    }
    return EXIT_SUCCESS;
}

/**
 * 读取列标号，超出给定范围不予理会
*/
int read_column_numbers(int columns[],int max){
    int num = 0;
    int ch;
    /**
     * 输入max次，每次输入给columns[num] 赋值 num:0 - max
     * 并且输入的值大于0
     * */
    while (num < max && scanf("%d",&columns[num]) == 1 && columns[num] >= 0){}
    {
        num += 1;
    }
    
    /**
     * 确认已经读取的标号为偶数个，因为它们是成对出现的
     * */
    if(num % 2 != 0){
        puts("Last column number is not paired");
        exit(EXIT_FAILURE);
    }

    /**
     * 丢弃该行中包含最后一个数字的那部分内容
    */
    while( (ch=getchar()) != EOF && ch != '\n' );

    return num;
}

void rearrange(char* output,char const* input,int n_columns,int const columns[]){
    int col;    //colmn数组的下标
    int output_col; //输出列计数器
    int len;    //输入行的长度

    len = strlen(input);
    output_col = 0;

    for(col = 0;col < n_columns; col += 2){
        int nchars = columns[col + 1] - columns[col] + 1;
        //如果输入行结束或者输出行数组已满，就结束任务
        if(columns[col] >= len || output_col == MAX_INPUT - 1) break;
        //如果输出行数据空间不够，只复制可以容纳的数据
        if(output_col + nchars > MAX_INPUT - 1){
            nchars = MAX_INPUT - output_col - 1;
        }
        //复制相关数据
        strncpy(output + output_col,input + columns[col],nchars);
        output_col += nchars;
    }

    output[output_col] = '\0';
}