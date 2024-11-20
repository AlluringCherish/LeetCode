int adj[1000][1000];
int visited[1000];
int queue[4000];
int front, rear;

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    
    
    for (int i=0; i<1000; i++){
        visited[i]=0;
        for (int j=0; j<1000; j++){
            adj[i][j]=0;
        }
    }
    
    
    for (int i=0; i<4000;i++){
        queue[i]=0;
    }
    
    front=0, rear=0;
    
    
    for (int i=0; i<roomsSize; i++){
        for (int j=0; j<roomsColSize[i]; j++){
            adj[i][rooms[i][j]] = 1;
        }
    }
    
    queue[rear++]=0;
    visited[0]=1;
    
    while(front<rear){
        int v = queue[front++];
        
        for (int i = 0; i<roomsSize; i++){
            if(!visited[i] && adj[v][i]){
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
    
    
    for (int i=0; i<roomsSize; i++){
        if (!visited[i]){
            return 0;
        }
    }
    
    return 1;
}