#include <limits.h>

int dp[201][10001]; // i번째까지 사용했을 때, 합이 j인게 가능한가?



bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i=0; i<numsSize; i++){
        sum+=nums[i];
        
    }
    
    for (int i=0; i<=numsSize; i++){
        for (int j=0; j<10001 ; j++){
            dp[i][j]=0;
        }
    }
    
    
    
    
    
    
    if (sum%2!=0){
        return 0;
    }
    
    int target = sum/2;
  
    dp[0][0]=1;
    for (int j=1; j<=target; j++){
        dp[0][j] = 0;
    }
    
    
    
    for (int i=1; i<=numsSize; i++){
        for (int j=0; j<=target ; j++){
            if (nums[i-1] > j){
                dp[i][j]= dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
             
        }
    }
    
    return dp[numsSize][target];
    
    
    
    
    
    
    
    
    
    
}