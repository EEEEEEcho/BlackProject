#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
bool hasGroupsSizeX(int* deck, int deckSize);
int gcd(int x,int y);
int main(){
    int array[6] = {1,2,3,3,2,1};
    bool result = hasGroupsSizeX(array,6);
    printf("%d",result);
    return 0;
}
int gcd(int x,int y){
    if(x < y){
        int temp = x;
        x = y;
        y = temp;
    }
    
    while (x % y != 0){
        int temp = y;
        y = x % y;
        x = temp;
    }    
    return y;
}
bool hasGroupsSizeX(int* deck, int deckSize){
    if(deckSize <=1){
        return false;
    }
    int array[10000] = {0};
    int i;
    for(i = 0;i < deckSize;i ++){
        array[deck[i]] ++;
    }
    i = 0;
    int start = array[deck[i]];
    for (; i < 10000; i++)
    {
        if(array[i] > 0){
            printf("%d %d \n",i,array[i]);
            start = gcd(start,array[i]);
            if (start == 1)
            {
                return false;
            }
            
        }
    }
    return true;
}