#define max(a,b) ((a)>(b) ? (a):(b))
#define min(a,b) ((a)<(b) ? (a):(b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size){
        int* temp=nums1;
        int temp1=nums1Size;
        nums1 = nums2;
        nums2 = temp;
        nums1Size = nums2Size;
        nums2Size = temp1;
    }
        
    
    int l = 0, r=nums1Size;
    while(l<=r){
        int i = l+(r-l)/2;
        int j = (nums1Size+nums2Size+1)/2-i;
        if (j>nums2Size){
            l=i+1;
            continue;
        }
        
        if ((i<nums1Size && j>0)&& nums1[i]<nums2[j-1]){
            l=i+1;
            continue;
        }
        
        
        if ((i>0 && j<nums2Size)&& nums1[i-1]>nums2[j]){
            r=i-1;
            continue;
        }
        
        int max_num = -1000001, min_num = 1000001;
        
        if (i>0){
            max_num = max(max_num,nums1[i-1]);
        }
        
        if (j>0){
            max_num = max(max_num,nums2[j-1]);
        }
        
        if ((nums1Size+nums2Size)%2!=0){
            return max_num;
        }
        
        if (i<nums1Size){
            min_num = min(min_num,nums1[i]);
        }
        
        if (j<nums2Size){
            min_num = min(min_num,nums2[j]);
        }
        
        return (double)(max_num+min_num)/2;
    }
    return 0;
}