#include <string.h>
#define min(a,b) ((a)<(b)? (a):(b))
int dp[501][501]; // base 1-index, i번째 글자로 j번째 글자를 만드는 최소 비용

int minDistance(char* word1, char* word2) {
    for (int i=0; i<501; i++){
        for (int j=0; j<501; j++){
            dp[i][j]=0;
        }
    }
    
    
    dp[0][0]=0;
    for (int j=0; j<=strlen(word2); j++){
        dp[0][j]=j;
    }
    
    for (int i=0; i<=strlen(word1); i++){
        dp[i][0]=i;
    }
    
    for (int i=1; i<=strlen(word1); i++){
        for (int j=1 ; j<=strlen(word2); j++){
            if (word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            }
            
        }
    }
    
    return dp[strlen(word1)][strlen(word2)];
    
}