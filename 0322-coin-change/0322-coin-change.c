#include <limits.h>
#define min(a,b) ((a)>(b) ? (b):(a))

int dp[10001];


int coinChange(int* coins, int coinsSize, int amount) {
    
    if (amount ==0){
        return 0;
    }
    
    for (int i=0; i<10001; i++){
        dp[i]=INT_MAX;
    }
    
    
    dp[0]=0;
    
    
    for (int i=1; i<=amount; i++){
        for (int j=0; j<coinsSize ; j++){
            if (i>=coins[j]){
                dp[i]=min(dp[i-coins[j]]+1,dp[i]);
            }
            
        }
    }
    
    
    if (dp[amount]==INT_MAX){
        return -1;
    }
    
    return dp[amount];
}