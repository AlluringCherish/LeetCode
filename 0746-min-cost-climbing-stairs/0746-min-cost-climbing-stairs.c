int dp[1001]; //dp[i] means minimum costs to ith stair
#define min(a,b) ((a)>(b) ? (b):(a))

int minCostClimbingStairs(int* cost, int costSize) {
    for (int i=0; i<1001;i++){
        dp[i]=0;
    }
    
    dp[0]=0;
    dp[1]=0;
    
    for (int i=2; i<=costSize; i++){
        dp[i]=min(dp[i-2]+cost[i-2],dp[i-1]+cost[i-1]);
    }
    
    
    return dp[costSize];
    
    
    
    
    
    
    
    
    
}