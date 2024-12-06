#include <string.h>
#define min(a,b) ((a)>(b) ? (b):(a))


int dp[501][501]; // dp[i][j].. a의 i번째글자에서 b의 j번째글자까지 최소회수

int minDistance(char* word1, char* word2) {
    for (int i=0; i<501; i++){
        for (int j=0; j<501; j++){
            dp[i][j]=0;
        }
    }
    
    int a = strlen(word1), b = strlen(word2);
    dp[0][0]=0;
    for (int i=1; i<=a; i++){
        dp[i][0]=i;
    }
    for (int i=1; i<=b; i++){
        dp[0][i]=i;
    }
    
    for (int i=1; i<=a; i++){
        for (int j=1; j<=b; j++){
            if (word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
    }
    
    for (int i=0; i<=a; i++){
        for (int j=0; j<=b; j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    
    return dp[a][b];
    
}