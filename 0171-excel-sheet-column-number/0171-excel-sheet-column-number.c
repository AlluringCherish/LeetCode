#include <string.h>

int titleToNumber(char* columnTitle) {
    int len=strlen(columnTitle);
    int result=0;
    for (int i=0; i<len; i++){
        result = 26*result+(columnTitle[i]-'A'+1);
    }
    return result;
}