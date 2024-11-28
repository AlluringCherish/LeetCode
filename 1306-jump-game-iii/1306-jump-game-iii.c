int stack[100001], top;
int visited[100001];
int flag=0;


bool canReach(int* arr, int arrSize, int start) {
    for (int i=0; i<100001; i++){
        stack[i]=-1;
        visited[i] = 0;
    }
    top = 0;
    flag=0;
    
    visited[start]=1;
    stack[top++]=start;
    
    while(top){
        int v = stack[--top];
        visited[v] = 1;
        if (arr[v]==0){
            flag = 1;
        }
        
        if (v+arr[v] < arrSize && !visited[v+arr[v]]){
            stack[top++]=v+arr[v];
        }
        
        if (v-arr[v] >= 0 && !visited[v-arr[v]]){
            stack[top++] = v-arr[v];
        }
    }
    
    if (flag == 1){
        return 1;
    }
    else{
        return 0;
    }
    
    
}