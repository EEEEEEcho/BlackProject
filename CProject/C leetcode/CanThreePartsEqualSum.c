#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
bool canThreePartsEqualSum(int* arr, int arrSize){
    int total = 0;
    for(int i = 0;i < arrSize;i ++){
        total += *(arr + i);
    }
    if(total % 3 != 0){
        return false;
    }
    int target = total / 3;
    int i = 0;
    int current = 0;
    while(i < arrSize){
        current += *(arr + i);
        if(current == target){
            break;
        }
        i ++;
    }
    if(i < arrSize - 1){
        int j = i + 1;
        while (j < arrSize)
        {
            current += *(arr + j);
            if (current == target * 2 && j != arrSize - 1)
            {
                return true;
            }
            j ++;
        }
    }
    
    return false;
}
int main(){
    int arr[11] = {0,2,1,-6,6,-7,9,1,2,0,1};
    canThreePartsEqualSum(arr,11);
}

