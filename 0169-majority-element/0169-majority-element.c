int majorityElement(int* nums, int numsSize) { //Boyer-Moore Majority vote algorithm
    int count=0;
    int temp=nums[0];
    for (int i=1; i<numsSize;i++){
        if (count<0){
            temp=nums[i];
            count=0;
        }
        else if (nums[i]==temp) count++;
        else count--;
    }
    
    return temp;
}