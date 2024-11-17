int hIndex(int* citations, int citationsSize) {
    int i=citationsSize-1;
    int j=1;
    for(;i>=0;i--,j++){
        if (citations[i]<j){
            break;
        }
    }
    
    return j-1;
}