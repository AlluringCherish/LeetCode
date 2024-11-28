int dp[101][101];

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            dp[i][j]=0;
        }
    }
    
    if (!obstacleGrid[0][0]){
        dp[0][0]=1;
    }
    else{
        dp[0][0]=0;
        return 0;
    }
    
    for (int i=1; i<m; i++){
        if (!obstacleGrid[i][0]){
            dp[i][0]=dp[i-1][0];
        }
        else{
            dp[i][0]=0;
        }
        
    }
    
    for (int i=1; i<n; i++){
        if (!obstacleGrid[0][i]){
            dp[0][i]=dp[0][i-1];
        }
        else{
            dp[0][i]=0;
        }
       
    }
    
    for (int i=1; i<m; i++){
        for (int j=1; j<n; j++){
            if (!obstacleGrid[i][j]){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    
    
    
    return dp[m-1][n-1];
    
    
    
}