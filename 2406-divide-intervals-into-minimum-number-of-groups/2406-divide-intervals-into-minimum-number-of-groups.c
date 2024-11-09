#include <stdlib.h>
/* Solution1: minheap
int heap[100001];
int size;
int compare(const void *a, const void *b){
    
    int *m=*(int **)a;
    int *n=*(int **)b;
    
    if (m[0]==n[0]){
        return m[1]-n[1];
    }
    
    return m[0]-n[0];
    
}

void heap_insert(int value){
    
    int i = ++size;
    while (i>1 && value<heap[i/2]){
        
        heap[i]=heap[i/2];
        i/=2;
    }
    heap[i]=value;
    
}


int heap_pop(){
    if (size==0){
        return -1;
    }
    
    int parent = 1, child = 2;
    int value=heap[1];
    int temp= heap[size--];
    while(child <= size){
        if (child < size && heap[child]>heap[child+1]){
            child++;
        }
        
        if (temp<=heap[child]){
            break;
        }
        
        heap[parent]=heap[child];
        parent = child;
        child*=2;
    }
    
    heap[parent]=temp;
    return value;
}



int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
    
    for (int i=0; i<100001;i++){
        heap[i]=0;
    }
    size=0;
    
    
    int col = *intervalsColSize;
    qsort(intervals,intervalsSize,sizeof(int*),compare);

    
    
    for (int i=0; i<intervalsSize; i++){
        int temp = heap_pop();
        if (temp==-1){
            heap_insert(intervals[i][1]);
        }
        
        else{
            if ( temp >= intervals[i][0]){
                heap_insert(temp);
                
            }
            heap_insert(intervals[i][1]);
        }
    }
    
    
    return size;
}
*/

//solution2 : mapping
int map[1000002];
int minGroups(int** intervals, int intervalsSize, int* intervalsColSize) {
    for (int i=0; i<1000002; i++){
        map[i]=0;
    }
    
    for (int i=0; i<intervalsSize; i++){
        map[intervals[i][0]]++;
        map[intervals[i][1]+1]--;
    }
    
    int cur = 0, max=0;
    
    for (int i=0; i<1000002; i++){
        if (map[i]){
            cur+=map[i];
            if (max < cur){
                max = cur;
            }
        }
        
    }
    
    return max;
}