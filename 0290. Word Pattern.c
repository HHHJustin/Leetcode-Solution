bool wordPattern(char * pattern, char * s){
    char *hash[26] = {0};
    int i = 0, j = 0, k = 0, hash_key;
    while(pattern[i] != '\0'){
        hash_key = pattern[i] - 'a';
        while((s[k]!='\0') && (s[k]!=' ')){k++;}
        if(!hash[hash_key]){   // if hash[hash_key] no value
            for(int l=0; l<i; l++){if(!strncmp(hash[pattern[l]-'a'], s+j, k-j)){return false;}}
            hash[hash_key] = (char *)malloc(sizeof(char) * (k - j + 1));
            memcpy(hash[hash_key], s+j, k-j);
            hash[hash_key][k-j] = '\0';
        }
        else{
            if(strncmp(hash[hash_key], s+j,k-j)){return false;}
        }

        // Judeg over and move the pointer 
        // pattern pointer
        i++;
        // s pointer  & judge if finish ('\0')
        if(s[k] == '\0'){break;}
        j = k + 1;
        k = j;
    }
    return pattern[i] == '\0' && s[k] == '\0';
}

// give 1 pattern (ex : abba)
// and 1 string s. (ex : "dog cat cat dog")
// find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection a letter in pattern and a non-empty word in s.
// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and space ' '.
// no leading and trailing spaces.
// All words in s are separated by a single space.

/*  
    ex: hash[26] pattern = [a, b, b, a]  s = [cat dog dog cat]
                            ^ i               ^ j   
    1. construct a hashmap -> hash key = pattern[i] - 'a'
    -> 0(a)   
       1(b)   
       2(c)
       .
       .
       .
      25(z)
      
    pattern = [a, b, b, a]  s = [cat dog dog cat]
               ^ i             j ^..^ k : use k to scan until s[k] = ' '                    
    2. if (!hash[hash key]) -> save the string into hashmap (malloc a space hash[hash key] -> memcpy(hash[hash key], s + j, k - j))
    -> 0(a) : cat
       1(b) : dog  
       2(c)
       .
       .
       .
      25(z)
 
    pattern = [a, b, b, a]  s = [cat dog dog cat]
               ^ i             j ^..^ k : use k to scan until s[k] = ' '                    
    3. if (hash[hash key]) -> compare hash[hash key] and string (strncmp(hash[hash key], s + j, k - j)) -> if != 0 -> return false.
    -> 0(a) : cat
       1(b) : dog  
       2(c)
       .
       .
       .
      25(z)
    
    if s[i] == '\0' -> break
    finally return pattern[i]== '\0' && s[j] == '\0' -> represent the number is different.

*/
