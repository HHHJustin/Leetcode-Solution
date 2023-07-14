int hammingWeight(uint32_t n) {
    int count=0;
    while(n!=0){
        if(n%2==1){count++;}
        n>>=1;
    }
    return count;
}

// write a function that takes the binary representation of an unsigned integer.
// and returns the number of '1' bits it has.
// let count to record the '1' appear times.
// while(n!=0){if(n%2 == 1){count++;}n>>=1;}
// finally return count;
