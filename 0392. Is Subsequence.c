bool isSubsequence(char * s, char * t){
    int i = 0;
    int lens = strlen(s);
    int lent = strlen(t);
    if(lens == 0){return true;}
    for(int j = 0;j<lent;j++){
        if(s[i] == t[j]){
            i++;
        }
        if(i == lens){
            return true;
        }
    }
    return false;
}

// s = ['a', 'b', 'c']  t = ['a', 'h', 'b', 'g', 'd', 'c']
//       ^ i                  ^ j                           use 2 pointer i & j for j++, if s[i] == t[j] i++. 
//                                                          if finally i == len(s) return true else return false
