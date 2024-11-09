#include <stdlib.h>
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


int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    for (int i=0; i<100001;i++){
        heap[i]=0;
    }
    size=0;
    qsort(events,eventsSize,sizeof(int*),compare);
    
    int answer = 0;
    int check=0;
    
    int maxDay=0;
    for (int i = 0; i < eventsSize; i++) {
        if (events[i][1] > maxDay) {
            maxDay = events[i][1];
        }
    }
    
    int index=0;
    for (int j=1 ; j<=maxDay; j++){
        while(index < eventsSize && events[index][0]==j){
            heap_insert(events[index][1]);
            index++;
        }
        while(size>0 && heap[1]<j){
            heap_pop();
        }
        
        if (size>0){
            heap_pop();
            answer++;
        }
        
    }
    return answer;
    
}