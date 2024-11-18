int search(int* nums, int numsSize, int target) {
    int l=0, r=numsSize-1;
    
    while(l<=r){
        int mid = l+(r-l)/2;
        //printf("%d %d %d\n",l,mid,r);
        if (nums[mid]==target){
            return mid;
        }
        
        else if (nums[mid] < nums[l]){
            
            if (target >= nums[l]){
                r=mid-1;
            }
            else if ((target < nums[l]) && (target > nums[mid])){
                l=mid+1;
            }
            else {
                r=mid-1;
            }
            
        }
        
        else{
            if ((target >= nums[l]) && (target < nums[mid])){
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
    }
    
    return -1;
    
}