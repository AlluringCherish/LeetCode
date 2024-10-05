#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int min = INT_MAX, sum = 0, i=0, j = 0;
    
    for (;j<numsSize;j++){
        sum+=nums[j];
        while (sum >= target){

            if (min > j-i+1){
                min = j-i+1;
            }
            
            sum -=nums[i];
            i++;
            
        }
    }
        
    
    if (min == INT_MAX){
        return 0;
    }
    else{
        return min;
    }
}