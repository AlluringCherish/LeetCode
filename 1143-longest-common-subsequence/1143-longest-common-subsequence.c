#include <string.h>
#define max(a,b) ((a)>(b) ? (a):(b))
int dp[1001][1001]; // word1의 i번쨰까지, word2의 j번째까지 subsequence의 길이

int longestCommonSubsequence(char* text1, char* text2) {
    int a= strlen(text1), b= strlen(text2);
    
    for (int i=0; i<=a; i++){
        for (int j=0; j<=b ; j++){
            dp[i][j]=0;
        }
    }
    
    for (int i=1; i<=a; i++){
        for (int j=1; j<=b; j++){
            if (text1[i-1]==text2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[a][b];
}