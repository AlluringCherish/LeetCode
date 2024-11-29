#include <string.h>

int dp[101][101];

bool isInterleave(char* s1, char* s2, char* s3) {
    for (int i=0; i<101; i++){
        for (int j=0; j<101; j++){
            dp[i][j]=0;
        }
    }
    
    dp[0][0]=1;
    int m=strlen(s1), n=strlen(s2), k=strlen(s3);
    
    if (m+n!=k){
        return 0;
    }
    
    for (int i=1; i<=m;i++){
        if (s3[i-1]==s1[i-1] && dp[0][i-1]){
            dp[0][i]=1;
        }
        else{
            dp[0][i]=0;
        }
        
    }
    
    for (int i=1; i<=n;i++){
        if (s3[i-1]==s2[i-1] && dp[i-1][0]){
            dp[i][0]=1;
        }
        else{
            dp[i][0]=0;
        }
        
    }
    
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int t1 = 0, t2 = 0;
            if (dp[i-1][j] && s2[i-1]==s3[i+j-1]){
                t1 = 1;
            }
            
            if (dp[i][j-1]&& s1[j-1]==s3[i+j-1]){
                t2 = 1;
            }
            dp[i][j] = t1 || t2 ;
        }
    }
    
    return dp[n][m];
    
    
    
    
    
    
    
}