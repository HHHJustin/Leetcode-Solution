int romantoint(char c){
    switch(c){
        case 'M':
        return 1000;
        break;

        case 'D':
        return 500;
        break;

        case 'C':
        return 100;
        break;

        case 'L':
        return 50;
        break;

        case 'X':
        return 10;
        break;

        case 'V':
        return 5;
        break;

        case 'I':
        return 1;
        break;

        default:
        return -1;
    }
}


int romanToInt(char * s){
    int sum = 0;
    int i = 0;
    while(s[i] != '\0'){
        if(romantoint(s[i]) >= romantoint(s[i+1])){
            sum += romantoint(s[i]);
        }
        else{
            sum -= romantoint(s[i]);
        }
        i ++;
    }
    return sum;
}

// give a string s(roman numeral) and return the corresponding integer.

// thousands digit
// MMM(3000), MM(2000), M(1000)
// hundreds digit
// CM(900), DCCC(800), DCC(700), DC(600), D(500), CD(400), CCC(300), CC(200), C(100)
// ten digit 
// XC(90), LXXX(80), LXX(70), LX(60), L(50), XL(40), XXX(30), XX(20), X(10)
// dights,
// IX(9), VIII(8), VII(7), VI(6), V(5), IV(4), III(3), II(2), I(1)

// check each char and judge it class.
// ex: [L, I, V]
//      ^  ^            → if s[i] >= s[i+1] sum += s[i] i.e.
//      i               s[i] (50) >= s[i+1] (1) sum += 50  -> 50

// ex: [L, I, V]
//         ^  ^         → if s[i] < s[i+1] sum -= s[i]     
//         i            i.e. s[i] (1) < s[i+1] (5) sum -= 1 -> 49

// ex: [L, I, V, '\0']
//            ^    ^    → if s[i] >= s[i+1] sum += s[i]        
//            i         i.e. s[i] (5) >= s[i+1] (0) sum += 5 -> 54




