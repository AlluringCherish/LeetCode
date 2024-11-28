#include <string.h>
int dp[101]; // i번째

int numDecodings(char* s) {
    for (int i=0; i<101; i++){
        dp[i]=0;
    }
    
    int n = strlen(s);
    dp[0]=1;
    
    if (s[0]=='0'){
        return 0;
    }
    
    else{
        dp[1]=1;
    }
    
    
    for (int i=2; i<=strlen(s);i++){
        int twoDigits = 10*(s[i-2]-'0')+(s[i-1]-'0');
        if (10<=twoDigits && twoDigits<=26){
            dp[i] += dp[i-2];
        }
        
        if (s[i-1]!='0'){
            dp[i] += dp[i-1];
        }
        
    }
    
    return dp[n];
    
    
    
    
}