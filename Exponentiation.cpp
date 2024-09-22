/*Description

Your task is to efficiently calculate values a^b modulo 10^9+7.
Note that in this task we assume that 0^0=1.

*//*Input
The first input line contains an integer n: the number of calculations.
After this, there are n lines, each containing two integers a and b.

Constraints
1≤n≤2⋅10 ^5
0≤a,b≤10^9
 
The first test case is Sample 1.

*//*Output
Print each value a^b modulo 10^9+7.

*//*Sample
*//*Input 1
3
3 4
2 8
123 123
Output 1
81
256
921450052
*//*Input 2
20
129612095 411099530
241615980 487174929
60862511 511830781
758816482 982657640
381899780 537757870
737206144 709589242
218115696 65863590
955221267 383458399
620860555 415026976
256085374 889700300
704408019 435387509
27905971 814556102
274349094 71634903
109301837 551314958
351812087 745484961
195812377 958145715
855767278 293063714
90347788 945356857
134650730 923760026
726541406 208406017
Output 2
276067146
838400234
148093882
546897305
467086232
747544981
668283116
487962372
714530936
697061579
111182865
12753197
839642224
72900589
933299952
150736790
311205058
41367745
34848201
121550166

*//*Hint
The following code contains a helpful function.

const long long MOD = 1e9+7;

long long pp(long long x, long long a) {
    if (a == 0)
        return 1;
    if (a == 1)
        return x % MOD;
    long long ret = pp(x, a >> 1);
    ret = (ret * ret) % MOD;
    if (a & 1)
        ret = (ret * x) % MOD;
    return ret;
}

*//*Source

CSES 1095 Exponentiation (https://cses.fi/problemset/task/1095/)

*/
const long long MOD = 1e9+7;

long long pp(long long x, long long a) {
    if (a == 0)
        return 1;
    if (a == 1)
        return x % MOD;
    long long ret = pp(x, a >> 1);
    ret = (ret * ret) % MOD;
    if (a & 1)
        ret = (ret * x) % MOD;
    return ret;
}