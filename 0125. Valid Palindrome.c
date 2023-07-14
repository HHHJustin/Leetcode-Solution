// palindrome
// after converting all uppercase letters into lowercase letters
// remove all non-alphanumeric charaters.
// Alphanumeric characters include letters and numbers

// We need convert all uppercase to lowercase and remove all non-alphanumeric characters.

bool is_valid(char c){
    bool a = false;
    // if(('a'<= *c <='z') || ('A'<= *c <='Z') || ('0' <= *c <= '9')){
    if(('a'<= c && c <= 'z') || ('A'<= c && c <='Z') || ('0' <= c && c <= '9')){
        a = true;
    }
    return a;
}

void tolowercase(char *c){
    if('A' <= *c && *c <= 'Z'){
        *c = *c - 'A' + 'a';
    }
}

bool isPalindrome(char * s){
    int n = 0, i = 0;
    while(s[n] != '\0'){
        if(is_valid(s[n]) == true){
            tolowercase(&s[n]);
            s[i] = s[n];
            i++;
            }
        n++;
    }
    s[i] = '\0';
    int t = strlen(s);
    for(int n = 0; n < t/2; n++){
        if(s[n]!=s[t-n-1]){
            return false;
        }
    }
    return true;
}

