int longestMountain(int* arr, int arrSize) {
    if (arrSize < 3){
        return 0;
    }
    int a=0, b=0, temp=0, ans=0;
    
    
    while(a<arrSize-1){
        printf("%d %d\n",a,b);
        b=a;
        while(b<arrSize-1 && arr[b]<arr[b+1]){
            b++;
        }
        if (a==b){
            a=b+1;
            continue;
        }
        
        
        else if (b==arrSize-1){
            break;
        }
        
        else{
            temp=b;
            while(b<arrSize-1 && arr[b]>arr[b+1]  ){
                b++;
            }
            
            if (temp == b){
                a=b+1;
                continue;
            }
            
            else if (b==arrSize-1){
                if(b-a+1>ans){
                    ans = b-a+1;
                    
                }
                break;
            }
            else{
                if(b-a+1>ans){
                    ans = b-a+1;
                    
                }
                a=b;
                if (b==arrSize-1){
                    break;
                }
                continue;
            }
          
        }
    }
    
    return ans;
}