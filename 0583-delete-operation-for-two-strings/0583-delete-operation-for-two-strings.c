#include <string.h>
#define max(a,b) ((a)>(b) ? (a):(b))
int dp[501][501]; // word1의 i번쨰까지, word2의 j번째까지 subsequence의 길이

int minDistance(char* word1, char* word2) {
    int a= strlen(word1), b= strlen(word2);
    
    for (int i=0; i<=a; i++){
        for (int j=0; j<=b ; j++){
            dp[i][j]=0;
        }
    }
    
    for (int i=1; i<=a; i++){
        for (int j=1; j<=b; j++){
            if (word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    
    int ans = a+b-2*dp[a][b];
    for (int i=0; i<=a; i++){
        for (int j=0; j<=b; j++){
            printf("%d ", dp[i][j]);
        }
        
        printf("\n");
    }
    return ans;
}