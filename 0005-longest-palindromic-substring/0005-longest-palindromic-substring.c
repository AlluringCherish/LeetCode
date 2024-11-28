#include <string.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b) ? (a):(b))

char* longestPalindrome(char* s) {
    int lenS = strlen(s);
    
    
    int max_ans = 1;
    int max_i=0;
    int flag = 0;
    
    for (int i=0; i<lenS; i++){
        
        int j=i, k=i, max_odd=1, max_even=0;
        while(0<j && k<lenS-1){ // len = odd
            if (s[j-1]==s[k+1]){
                j--;
                k++;
                max_odd+=2;
            }
            else{
                break;
            }
        }
        
        j=i, k=i;
        while(0<=j && k<lenS-1){ // len = even
            if (s[j]==s[k+1]){
                j--;
                k++;
                max_even+=2;
            }
            else{
      
                break;
            }
        }
        if (max_ans < max(max_odd,max_even)){
            max_i = i;
            max_ans = max(max_ans,max(max_odd,max_even));
            if (max_odd > max_even){
                flag = 1;
            }
            else{
                flag = 2;
            }
            
            
        }
        
    }
    
    char* result = (char*)malloc((max_ans + 1) * sizeof(char));
    printf("max_i : %d\nmax_len: %d\nflag:%d\n",max_i,max_ans,flag);
    if (flag == 1){
        strncpy(result, s+max_i - max_ans/2, max_ans);
        result[max_ans] = '\0';
       
    }
    else if (flag == 2){
        strncpy(result, s+max_i - (max_ans-1)/2, max_ans);
        result[max_ans] = '\0';
    
    }
    else{
        result[0]=s[max_i];
        result[1] = '\0';
    }
    
    return result;
    
    
    
    
}