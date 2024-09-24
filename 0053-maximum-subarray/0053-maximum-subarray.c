#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
    int max_sum=INT_MIN, sum=0; //INT_MIN이 필요하다. 음수만 있는 경우 때문이다.
    for (int i=0; i<numsSize; i++){
        if (sum>0) sum+=nums[i];
        else sum=nums[i];
        if (sum>max_sum) max_sum = sum;
    }
    return max_sum;
}