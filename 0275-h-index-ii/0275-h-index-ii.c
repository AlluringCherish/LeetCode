/* Sol1: Time Complexity is O(n)
int hIndex(int* citations, int citationsSize) {
    // Time Complexity is O(n)
    int i=citationsSize-1;
    int j=1;
    for(;i>=0;i--,j++){
        if (citations[i]<j){
            break;
        }
    }
    
    return j-1;
}
*/




int hIndex(int* citations, int citationsSize) {
    int l=0, r=citationsSize-1,ans=0;
    while(l<=r){
        int mid = l+(r-l)/2;
        if ((citationsSize-mid)<=citations[mid]){
            ans = (citationsSize-mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    
    
    return ans;
}