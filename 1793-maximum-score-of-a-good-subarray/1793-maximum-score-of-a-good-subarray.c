int maximumScore(int* nums, int numsSize, int k) {
    int max = nums[k];
    int min = nums[k];
    int left = k, right = k;
    while (min>0){
        int left_num = 0, right_num =0;
        if (left>0){
            left_num = nums[left-1];
        }
        
        if (right < numsSize-1){
            right_num = nums[right+1];
        }
        
        
        if (left_num < right_num){
            if (min > right_num){
                min = right_num;
            }
            right++;
        }
        
        
        else{
            if (min > left_num){
                min = left_num;
            }
            left--;
        }
        
        if (max < min*(right-left+1)){
            max = min*(right-left+1);
        }
        
        
    }
    
    return max;
}