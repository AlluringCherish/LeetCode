int trailingZeroes(int n) {
    int sum=0;
    for (int i=5; n/i>0; i=5*i) {
         sum+=n/i;
    }
    return sum;
}