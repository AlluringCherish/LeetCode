int cur_min[100001];
int dp[100001];
#define min(a,b) ((a)>(b) ? (b):(a))

int maxProfit(int* prices, int pricesSize) {
    for (int i=0; i<100001;i++){
        cur_min[i]=0;
        dp[i]=0;
    }
    
    
    cur_min[0]=prices[0];
    
    for (int i=1; i<pricesSize; i++){
        cur_min[i]=min(cur_min[i-1],prices[i]);
    }
    
    
    dp[0]=0;
    int ans=0;
    for (int i=1; i<pricesSize; i++){
        if (cur_min[i-1] < prices[i]){
            dp[i]=prices[i]-cur_min[i-1];
            if (ans < dp[i]){
                ans = dp[i];
            }
        }
        
    }
    
    
    return ans;
    
}