#define HASH_SIZE 20011

int qurtsum(int a){
    int sum = 0;
    while(a != 0){
        sum += (a % 10) * (a % 10);
        a /= 10;
    }
    return sum;
}

bool isHappy(int n){
    int hashmap[HASH_SIZE] = {0};
    int hashkey = n % HASH_SIZE;
    if(hashkey < 0){hashkey += HASH_SIZE;}
    hashmap[hashkey] = 1;
    while(n != 1){
        n = qurtsum(n);
        hashkey = n % HASH_SIZE;
        if(hashkey < 0){hashkey += HASH_SIZE;}
        if(hashmap[hashkey] == 1){return false;}
        hashmap[hashkey] = 1;
    }
    return true;
}
// write 1 algorithm to determine if 1 number "n" is happy

// 1 happy number is a number defined by following process
// starting with any positive integer, replace the number by the sum of the squares of its digits
// repeat the process until the number equals 1, or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy
// return true if n is a happy number, and false if not.

// ex: n = 19
//     1 ^ 2 + 9 ^ 2 = 82,
//     8 ^ 2 + 2 ^ 2 = 68,
//     6 ^ 2 + 8 ^ 2 = 100,
//     1 ^ 2 + 0 ^ 2 + 0 ^ 2 = 1 -> happy number.

// ex: n = 2
//     2 ^ 2 = 4,
//     4 ^ 2 = 16,
//     1 ^ 2 + 6 ^ 2 = 38,
//     3 ^ 2 + 8 ^ 2 = 9 + 64 = 73,
//     7 ^ 2 + 3 ^ 2 = 49 + 9 = 58,
//     5 ^ 2 + 8 ^ 2 = 25 + 64 = 89,
//     8 ^ 2 + 9 ^ 2 = 64 + 81 = 145,
//     1 ^ 2 + 4 ^ 2 + 5 ^ 2 = 1 + 16 + 25 = 42,
//     4 ^ 2 + 2 ^ 2 = 20,
//     2 ^ 2 + 0 ^ 2 = 4 -> repeat -> not the happy number

// so we can construct a hashmap to save the number ever appear
// hashmap[hashmap number] = {0} 
// -> if the value == 1 -> return true;
// -> if never appear -> hashmap[index] = 1
// -> if(hashmap[index] == 1) -> return false
