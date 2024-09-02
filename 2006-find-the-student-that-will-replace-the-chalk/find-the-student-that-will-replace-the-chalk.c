int chalkReplacer(int* chalk, int chalkSize, int k) {
    long  result = 0;

    for(int i=0;i<chalkSize;i++){
        result+=chalk[i];
    }
    k%=result;
    
    for(int i=0;i<chalkSize;i++){
        if(k<chalk[i]){
            return i;
        }
        k-=chalk[i];
    }
    return -1;
}