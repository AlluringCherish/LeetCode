#include <limits.h>
#define min(a,b) ((a)>(b) ? (b):(a))
int dp[201][201];

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    
    for (int i=0; i<201; i++){
        for (int j=0; j<201; j++){
            dp[i][j]=0;
        }
    }
    
    
    
    dp[1][1]=triangle[0][0];
    
    for (int i=2; i<=triangleSize; i++){
        dp[i][1]=dp[i-1][1]+triangle[i-1][0];
        dp[i][i]=dp[i-1][i-1]+triangle[i-1][i-1];
        for (int j=2; j<i; j++){
            dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i-1][j-1];
        }
    }
    
    
    int ans = INT_MAX;
    for (int i=1; i<=triangleSize; i++){
        ans = min(ans,dp[triangleSize][i]);
    }
    
    
    return ans;
    
    
}