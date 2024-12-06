#include <string.h>
#define min(a,b) ((a)>(b) ? (b):(a))

int findMinimumOperations(char* s1, char* s2, char* s3) {
    int a=strlen(s1), b=strlen(s2), c=strlen(s3);
    int sum = 0;
    
    int n = min(min(a,b),c);
    
    for (int i=1; i<=n; i++){
        if (s1[i-1]==s2[i-1] && s2[i-1]==s3[i-1]){
            sum++;
        }
        else{
            break;
        }
    }
    
    if (sum == 0){
        return -1;
    }
    
    else{
        return (a+b+c-3*sum);
    }
}