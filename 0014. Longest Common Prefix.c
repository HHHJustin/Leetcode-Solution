char * longestCommonPrefix(char ** strs, int strsSize){
    char current;
    int count = 0, s = 0;
    while(strs[0][count] != '\0' && s == 0){
        current = strs[0][count];
        for(int i=1; i<strsSize; i++){
            if(strs[i][count] != current){s = -1; count--; break;}
        }
        count++;
    }
    char *output = (char *)malloc(count + 1);
    for(int i=0;i<count;i++){
        output[i] = strs[0][i];
    }
    output[count] = '\0';
    return output;
}

// give an string matrix strs.
// find the longest common prefix amongst an array of strings.
// if no common prefix : return empty.
// 1 <= strs.length <= 200
// 0 <= strs[]i.length <= 200
// strs[i] consists of only lowercase English letters.

// [f, l, o, w, e, r]    use a int "count" to record the common letter number
// [f, l, o ,w]
// [f, l, i, g, h, t]
//  ^                    if all same in column : count++

// [f, l, o, w, e, r]    
// [f, l, o ,w]
// [f, l, i, g, h, t]
//     ^                 if all same in column : count++

// [f, l, o, w, e, r]    
// [f, l, o ,w]
// [f, l, i, g, h, t]
//        ^              if is not same: break

// and then push in output array 
