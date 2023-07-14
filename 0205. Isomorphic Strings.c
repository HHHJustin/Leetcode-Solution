bool isIsomorphic(char * s, char * t){
    int *map_s = calloc(sizeof(int), 128);
    int *map_tc = calloc(sizeof(int), 128);
    for(int i=0; s[i] != '\0'; i++){
        if(map_s[s[i]] != map_tc[t[i]]){return false;}
        map_s[s[i]] = i + 1;
        map_tc[t[i]] = i + 1;
    }
    return true;
}

// give 2 strings "s" & "t", determine if they are isomorphic.
// 2 strings are isomorphic if the characters in "s" can be replaced to get "t"

// ex: s = [e, g, g]   t = [a, d, d]
//          e -> a, g -> d -> isomorphic. 
// we need to check if letter in s map different letter in t.

// construct an array(128 ASCII code number) -> save the s map letter in t
// ex: s = [e, g, g, g]   t = [a, d, d, a]   map_s = {0}
//          ^i                 ^i            map_tc = {0}
//                                           both need to map each other
//                                           so we save the index
//                                           

// ex: s = [e, g, g, g]   t = [a, d, d, a]  
//                ^i                 ^i      map_s['g'] = 2  map_tc['d'] = 2
// ex: s = [e, g, g, g]   t = [a, d, d, a]  
//                   ^i                 ^i   (map_s['g'] = 2) !=  (map_tc['a'] = 0) -> return false
