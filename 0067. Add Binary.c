#define MAX(i, j) ((i) > (j) ? (i) : (j));

char * addBinary(char * a, char * b){
    int carry=0;
    int a_l= strlen(a);
    int b_l= strlen(b);
    int max_l = MAX(a_l, b_l);
    char* out = (char *)malloc(sizeof(char) * (max_l + 2));
    out[max_l + 1] = '\0';

    for(int i = max_l ; i >= 0;i--){
        if(a_l){carry+=a[--a_l]-'0';}  // '1' - '0' = 1 , '0' - '0' = 0 
        if(b_l){carry+=b[--b_l]-'0';}  // i.e. get the a[i] + b[i] + carry → 0 or 1 or 2 or 3 (a[i]=b[i]=carry)
        out[i] = (carry&1) + '0'; // if 0 or 2 out[i] = 0 else 1 out[i] = 1
                        //  ^  translate to char
                        //  note: the priority of '+' is higher than '&'
        carry >>= 1;   // i.e. if 2 >> 1 (0010 -> 0001) = 1 else if 3 >> 1 (0011 -> 0001) = 1 else 1 or 0 >> 1 = 0000 = 0
    }

    if(out[0]=='0'){
        for(int i=0;i<max_l+1;i++){
            out[i] = out[i+1];
        }
    }
    
    return out;
}

// ex: 11111100  a_l = 8   max_length
//           11  b_l = 2 → 00000011 ,b[max_l] = '\0', b[max_l-1] = b[1], b[max_l-2] = b[0]
//                                                      max_l-1-i  b[b_l-1-i] 

// give 2 binary strings a, b.
// return the sum as a binary string.
// ex : a = 11, b = 1.
/*
       if(strlen(a) > strlen(b)){fill '0' to b}
       else{fill '1' to a}

        11
    +   01
    ------
       010   → need 1 integer record if carry, need at most max(strlen(a),strlen(b)) length string
       
       if a[i] + b[i] + c[i] > 2 , carry = 1, else = 0
       o[i] = a[i] ^ b[i] ^ c[i]
*/
