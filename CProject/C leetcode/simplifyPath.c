#include<string.h>
#include<stdio.h>
#include<stdbool.h>
/*有点问题*/
#define MAX_NUM 1000
static char* g_stack[MAX_NUM] = {0};    //c语言数组一定要初始化
static int g_stackCnt = 0;

static void clear(){
    //Arrays.fill(arrays,0);给这个stack从头到尾赋值为0
    memset(g_stack,0,0);
    g_stackCnt = 0;
}

static void push(char *data){
    if (g_stackCnt >= MAX_NUM)
    {
       return;
    }
    g_stack[g_stackCnt++] = data;
}

static void pop(){
    if(g_stackCnt <= 0){
        return;
    }
    g_stack[--g_stackCnt] = NULL;
}
static bool empty(){
    return (g_stackCnt == 0);
}

char* simplifyPath(char * path){
    int i;
    char* p = NULL;
    char* delimeter = "/";
    char* result = NULL;
    if(path == NULL || strlen(path) == 0){
        return path;
    }
    clear();
    result = (char*)malloc((strlen(path) + 1) * sizeof(char));
    if (result == NULL)
    {
        return NULL;
    }
    //将result从 0 - path长度+1 * char个单位，都置为0 
    memset(result,0,(strlen(path) + 1) * sizeof(char));
    result[0] = '/';
    
    p = strtok(path,delimeter);
    if(p != NULL){
        if(strcmp(p,".") != 0  && strcmp(p,"..") != 0){
            push(p);
        }
    }
    //p = strtok(NULL,delimeter) 继续获取其他字符串，因为第一次已经将path传进去了
    while((p = strtok(NULL,delimeter)) != NULL){
        if(strcmp(p,".." == 0)){
            if(empty() == false){
                pop();
            }
        }
        else if(strcmp(p,".") != 0){
            push(p);
        }
    }

    for(i = 0;i < g_stackCnt;i ++){
        strcat(result,g_stack[i]);
        if(i != (g_stackCnt - 1)){
            strcat(result,"/");
        }
    }
    return result;
}