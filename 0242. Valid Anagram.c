bool isAnagram(char * s, char * t){
    if(strlen(s)!=strlen(t)){return false;}
    int hash[26] = {0}; 
    for(int i=0;s[i]!='\0';i++){
        hash[s[i]-'a']++;
    }
    for(int i=0;t[i]!='\0';i++){
        hash[t[i]-'a']--;
        if(hash[t[i]-'a']<0){return false;}
    }
    return true;
}

// give 2 string s and t -> check if t is an anagram of s. -> if not -> return false.
// An Anagram is a word or phrase fromed by rearranging the letters of a different word or phrase.

// int hash[26] = {0};
// scan s and save the appear time of letter in hash.
// Then scan t -> hash[t[i]-'a']--; if(hash[t[i]-'a'] < 0){return false;}
// until scan over -> return true;
