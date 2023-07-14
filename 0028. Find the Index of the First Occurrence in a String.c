int strStr(char * haystack, char * needle){
    int i = 0, j = 0, count = strlen(needle); 
    while((i < count) && j < strlen(haystack)){
        printf("%c %c\n",needle[i], haystack[j]);
        if(needle[i] == haystack[j]){i++;}
        else{
            j -= i;
            i = 0;
            }
        j++;
    }
    if(i == count){return j - count;}
    else{return -1;}
}

// give 2 string "needle", "haystack"
// if the string of needle in haystack, return the start index. else return -1.
// let count = strlen(needle)
// needle   = [s, a, d]
//             ^ i
// haystack = [s, a, d, b, u, t, s, a, d]
//             ^ j 

// if (needle[i] == haystack[j]){i++}
// j -= i; back to the position that start check.
// else i = 0; 
// j++
// if i == count break return j - count + 1
// else return -1 
