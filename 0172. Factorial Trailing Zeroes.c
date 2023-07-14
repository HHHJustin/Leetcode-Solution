int trailingZeroes(int n){
    int count = 0;
    int power_5 = 5;
    while(n/power_5){
        count += (n/power_5);
        power_5*=5;
    }
    return count;
    
}

// give 1 integer n, return the number of trailing zeros in n!.
// n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

// ex : n = 3 -> return 0;
// ex : n = 0 -> return 0;
// once the number has trailing number :(2 + 5), 10 -> zeros count++

// because the number of trailing zeroes appear time is about 2 and 5, especially 5.
// -> we can only check the 5 appear times.
// 5 only appear 5, 10, 15, 20, 25.....
// we need notice that -> 25 have 5 * 5 -> 2 times i.e. if the multiples of 25, 125, 625 need record more 1, 2, 3... times respectively.
