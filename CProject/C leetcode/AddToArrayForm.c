#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
    int* res = malloc(sizeof(int) * fmax(10,numSize + 1));
    *returnSize = 0;
    int sum = 0;
    int carry = 0;
    int i = numSize - 1;
    while (i >= 0 || k != 0)
    {
        int x = i >= 0? num[i] : 0;
        int y = k != 0? k % 10 : 0;
        sum  = x + y + carry;
        //下一轮的进位
        carry = sum / 10;
        k = k / 10;
        i --;
        res[(*returnSize) ++] = sum % 10;
    }
    if(carry > 0){
        res[(*returnSize) ++] = carry;
    }
    for(int i = 0;i < (*returnSize) / 2;i ++){
        int tmp = res[i];
        res[i] = res[(*returnSize) -1 - i];
        res[(*returnSize) - 1 - i] = tmp;
    }
    return res;
}
int main(){
    int x = 0;
    int y = 0;
    printf("Hello world\n");
    return 0;
}