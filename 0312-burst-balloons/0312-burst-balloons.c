

int dp[502][502]; // nums의 i번째 원소부터 j번째 원소까지 사용했을 때, 얻을 수 있는 코인의 최댓값

#define max(a,b) ((a)>(b) ? (a):(b))
#define max3(a,b,c) (max(a,max(b,c)))


int maxCoins(int* nums, int numsSize) {
    int renums[502];
    renums[0]=1;
    renums[numsSize+1]=1;
    
    for (int i=1; i<=numsSize; i++){
        renums[i]=nums[i-1];
    }
    
    
    for (int i=0; i<502; i++){
        for (int j=0; j<502; j++){
            dp[i][j]=0;
        }
    }
    
    
    for (int i=numsSize; i>=1; i--){
        for (int j=i; j<=numsSize; j++){
            for (int k=i;  k<=j ; k++){
              
                dp[i][j] = max(dp[i][j],max3(dp[i+1][j]+renums[i]*renums[i-1]*renums[j+1], dp[i][j-1]+renums[j]*renums[j+1]*renums[i-1], dp[i][k-1]+dp[k+1][j]+renums[i-1]*renums[k]*renums[j+1]));
            }
        }
    }
    
    return dp[1][numsSize];
    
    
    
}