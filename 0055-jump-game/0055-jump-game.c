int dp[10001];


bool canJump(int* nums, int numsSize) {
    for (int i=0; i<numsSize; i++){
        dp[i]=0;
    }
    
    
    dp[0]=1;
    
    for (int i=0; i<numsSize; i++){
        if (dp[i]){
            for (int j=i; j<numsSize && j<=i+nums[i]; j++){
                dp[j]=1;
            }
        }
    }
    
    return dp[numsSize-1];
    
    
    
}