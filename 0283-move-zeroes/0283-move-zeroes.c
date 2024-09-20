int findZero(int* nums, int n, int numsSize){
    for (int i=n; i<numsSize; i++){
        if(nums[i]==0){
            return i;
        }
    }
    
    return -1;
}

void moveZeroes(int* nums, int numsSize) {
    int a=findZero(nums,0,numsSize);
    int b=a+1;
    while (b<numsSize && a!=-1){
        if (nums[b]!=0 && nums[a]==0){
            nums[a]=nums[b];
            nums[b]=0;
            a=findZero(nums,a,numsSize);
        }
        b++;
    }
}

