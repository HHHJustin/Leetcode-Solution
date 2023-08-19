bool isPowerOfTwo(int n){
    int sum = 0;
    if(n <= 0){return false;}
    for(int i = 0; i < 32; i++){
        sum += (n & 1);
        n >>= 1;
    }
    if(sum == 1){return true;}
    else{return false;}
}

// 00000000 00000000 00000000 00000100, int sum = 0
//                                      n >>= 1

bool isPowerOfTwo(int n){
    return (n > 0) && (!(n & (n - 1)));
}

// 00000000 00000000 00000000 00000110
// 00000000 00000000 00000000 00000101
//                                    -> 1
// 00000000 00000000 00000000 00000100
// 00000000 00000000 00000000 00000011
//                                    -> 0
