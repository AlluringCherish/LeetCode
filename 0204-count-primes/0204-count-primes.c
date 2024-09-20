int IsPrime[5000001];

int countPrimes(int n) {
    int count=0;
    for (int i=2; i*i<=n ; i++){
        for (int j=i ; i*j<=n; j+=1){
            IsPrime[i*j]=1; // Number i*j is Not Prime
        }
    }
    
    for (int z=2; z<n ; z++){
        if (!IsPrime[z]){
            count++;
        }
    }
    return count;
}