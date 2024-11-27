
int dp[46];

int climbStairs(int n) {
    for (int i=0; i<46; i++){
        dp[i]=0;
    }
    
    
    dp[1]=1;
    dp[2]=2;
    
    if (n<=2){
        return dp[n];
    }
    
    for (int i=3; i<=n;i++){
        dp[i]=dp[i-2]+dp[i-1];
    }
    
    return dp[n];
    
    
    
    
}