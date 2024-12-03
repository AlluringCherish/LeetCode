#define max(a,b) ((a)>(b) ?  (a):(b))
#include <string.h>
int dp[1000][1000];

int longestPalindromeSubseq(char* s) {
    int n = strlen(s);
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==j){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    
    
    for (int i = n-1 ; i>=0; i--){
        for (int j=i+1; j<n; j++){
            if(s[i]==s[j]){
                dp[i][j] = dp[i+1][j-1]+2;
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    
    return dp[0][n-1];
    
    
    
}