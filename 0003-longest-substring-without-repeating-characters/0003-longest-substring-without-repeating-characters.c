#include <string.h> 
int check[128];

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    for (int i=0; i<128; i++) check[i]=0; //In leetcode, global variable must be init.
    int result=0;
    int max=0;
    int left=0,right=0;
    
    for (int i=0; i<len; i++){
        if(check[s[i]]==0){
            check[s[i]]=1;
            right++;
            result++;
        }
        else{
            while(s[left]!=s[i]){
                check[s[left]]=0;
                left++;
                result--;
            }
            check[s[i]]=0;
            i--;
            result--;
            left++;
        }
        if (result>max) max=result;
    }
    return max;
}