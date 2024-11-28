#include <limits.h>
#define min(a,b) ((a)>(b) ? (b):(a))
int dp[10001];


int jump(int* nums, int numsSize) {
    for (int i=0; i<10001;i++){
        dp[i]=INT_MAX;
    }
    
    dp[0]=0;
    
    for (int i=1; i<numsSize; i++){
        for (int j=0; j<i; j++){
            if (j+nums[j] >= i){
                dp[i]=min(dp[j]+1,dp[i]);
            }
        }
    }
    
    return dp[numsSize-1];
    
    
    
}
