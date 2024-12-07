#define max(a,b) ((a)>(b) ? (a):(b))
int dp[2501]; // i-1번째 원소를 사용했을 때, 가장 긴 증가 수열의 길이
int lengthOfLIS(int* nums, int numsSize) {
    for (int i=0; i<2501; i++){
        dp[i]=1;
    }
    
    
    
    
    for (int i=0; i<numsSize; i++){
        int max = 1;
        for (int j=0; j<i; j++){
            if (nums[j] < nums[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    
    int ans = 1;
    for (int i=0; i<numsSize; i++){
        printf("%d ",dp[i]);
        ans = max(ans, dp[i]);
    }
    
    return ans;
    
}