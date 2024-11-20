///Solution: This problem is equlvalent to determine whether exists cycle in directed graph.


int adj[2001][2001];
int visited[2001];
int finish[2001];

int result = 0;


void dfs(int v,int num){
    if (result==1){
        return;
    }
    
    
    visited[v]=1;
    
    for (int i=0; i<num; i++){
        if (adj[v][i]){
            if(!visited[i]){
                dfs(i,num);
            }
            
            else if (!finish[i]){
                result=1;
                return;
            }
            
        }
    }
    
    finish[v]=1;
    
    
}





bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    result=0;
    if (prerequisitesSize == 0){
        return 1;
    }
    
    for (int i=0; i<numCourses; i++){
        visited[i]=0;
        finish[i]=0;
        for (int j=0; j<numCourses; j++){
            adj[i][j]=0;
        }
    }
    
    for (int i=0; i<prerequisitesSize; i++){
        adj[prerequisites[i][1]][prerequisites[i][0]]=1;
    }
    
    
    for (int i=0; i<numCourses;i++){
        dfs(i,numCourses);
        if (result==1){
            return 0;
        }
    }
    
    return 1;
    
}