int rangeBitwiseAnd(int left, int right){
    int res = 0;
    while(left != right){
        left >>= 1;
        right >>= 1;
        res += 1;
    }
    return left << res;
}

// left -> right do bitwise AND of all numbers

//   00000000 00000000 00000000 00000010  reset = 0
//   00000000 00000000 00000000 00000111

//   00000000 00000000 00000000 00000001  reset = 1
//   00000000 00000000 00000000 00000011

//   00000000 00000000 00000000 00000000  reset = 2
//   00000000 00000000 00000000 00000001

//   00000000 00000000 00000000 00000000  reset = 3
//   00000000 00000000 00000000 00000000

//  return left << reset -> = 0
