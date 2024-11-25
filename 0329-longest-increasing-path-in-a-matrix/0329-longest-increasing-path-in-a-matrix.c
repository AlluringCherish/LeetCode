#define max(a,b) ((a)<(b) ? (b):(a))


int mem[201][201];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n, m;

int dfs (int** matrix, int x,int y){
    
    if (mem[x][y]){
        return mem[x][y];
    }
    
    mem[x][y]=1;
    
    for (int i=0; i<4; i++){
        int a=x+dx[i], b=y+dy[i];
        if (a>=0 && a<n && b>=0 && b<m && matrix[a][b]>matrix[x][y]){
            int num = 1 + dfs(matrix,a,b);
            if (mem[x][y] < num){
                mem[x][y]=num;
            }
            
        }
    }
    
    
    return mem[x][y];
    
    
}


        
//행 matrixSize 열 matrixColsize

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    
    m=*matrixColSize;
    n = matrixSize;
    
    for (int i=0; i<201; i++){
        for (int j=0; j<201; j++){
            mem[i][j]=0;
        }
    }
    
    
    
    int max = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!mem[i][j]){
                int len = dfs(matrix,i,j);
                if (len>max){
                    max = len;
                }
            }
            
        }
    }
    
   
    
    return max;
}


