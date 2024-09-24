#include <string.h>

int strStr(char* haystack, char* needle) {
    int n=strlen(haystack), m=strlen(needle);
    int i=0;
    for (; i<n; i++){
        int j=0;
        for (; j<m; j++){
            if (haystack[i+j]!=needle[j]){
                break;
            }
        }
        if (j==m){
            return i;
        }
    }
    
    return -1;
}