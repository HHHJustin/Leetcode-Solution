bool canConstruct(char * ransomNote, char * magazine){
    int *letter = (int *)calloc(sizeof(int) , 26);
    for(int i=0;magazine[i] != '\0';i++){
        letter[magazine[i] - 'a']++;
    }
    for(int i=0;ransomNote[i] != '\0';i++){
        letter[ransomNote[i] - 'a']--;
        if(letter[ransomNote[i] - 'a']<0){
            return false;
        }
    }
    return true;
}

// give 2 strings "ransomNote" and "magazine"

// if the letter in magazine can construnct ransomNote : return true. else : return false.
// each letter in magazine can only be used once in ransomNote.

// ex: ransomNote = [a, a], magazine = [a, a, b] 
// scan magazine and use a array to record the letter appear times in magazine.
// ex: a, b, c, d, .........
//    [2, 1, 0, 0 .........]
//    then check the ransomNote. if letter appear then check the used array substract. 
//    if one element number <0 : represent the magazine can't construct the ransomNote return false.
//    else return true.
