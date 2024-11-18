/* Sol1 : Binary search // Time complexity = O(logn)
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
*/
int search(int* nums, int numsSize, int target) {
    int result= -1;
    if (nums[0]==target){
        result = 0;
    }
    
    else if (nums[numsSize-1]==target){
        result = (numsSize-1);
    }
    
    else if (nums[0] > target){
        for (int i=numsSize-1; i>0; i--){
            if (nums[i]==target){
                result = i;
            }
            
            else if ((nums[i-1]>nums[i]) || (target > nums[i])){
                break;
            }
        }
    }
    
    else {
        for (int i=1; i<(numsSize-1); i++){
            if (nums[i]==target){
                result = i;
            }
            
            else if (nums[i+1]<nums[i] || target < nums[i]){
                break;
            }
        }
    }
    return result;
}