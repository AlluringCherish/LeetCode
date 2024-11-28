
#include <limits.h>
#define min(a,b) ((a)>(b) ? (b):(a))
int dp[10001];
int numSquares(int n) {
    for (int i=0; i<10001;i++){
        dp[i]=INT_MAX;
    }
    
    
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=1;
    
    
    for (int i=5; i<=n; i++){
        for (int j=1; i-j*j>=0;j++){
            dp[i]=min(dp[i-j*j]+1,dp[i]);
        }
    }
    
    
    return dp[n];
    
}