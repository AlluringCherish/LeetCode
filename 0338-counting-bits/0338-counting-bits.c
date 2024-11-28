/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int dp[1000001];


int* countBits(int n, int* returnSize) {
    for (int i=0; i<1000001;i++){
        dp[i]=0;
    }
    
    
    
    dp[0]=0;
    dp[1]=1;
    
    for (int i=2; i<1000001; i++){
        dp[i]=dp[i>>1]+i%2;
    }
    
    *returnSize = n+1;
    return dp;
    
    
    
    
}