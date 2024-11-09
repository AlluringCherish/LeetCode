#include <stdlib.h>

//sol1: Qsort
/*
int compare(const void *a, const void *b){
    return (*(int*)b-*(int*)a);
}


int findKthLargest(int* nums, int numsSize, int k) {
    
    qsort(nums, numsSize,sizeof(int),compare);
    
    return nums[k-1];
    
}
*/

//sol2: counting

int findKthLargest(int* nums, int numsSize, int k) {
    int arr[20002];
    for (int i=0; i<20002; i++){
        arr[i]=0;
    }
    
    for (int i=0; i<numsSize;i++){
        arr[nums[i]+10001]++;
    }
    
    int i=20001;
    while(1){
        while(arr[i]){
            if (k>1){
                
                k--;
                arr[i]-=1;
            }
            else if (k==1){
                return (i-10001);
                
            }
        }
        i--;
    }
    return 0;    

     
}