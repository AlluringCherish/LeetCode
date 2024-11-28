#include <string.h>

bool isSubsequence(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);
    
    int i=0, j=0;
    
    while(i<lenS && j<lenT){
        if (s[i]==t[j]){
            i++;
        }
            
        j++;
    }
    
    if (i==lenS){
        return 1;
    }
    else{
        return 0;
    }
}