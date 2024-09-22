/*Description

Kaito Kuroba(黒羽 快斗) has sent a note and a problem to you.
He asked you to solve the following problem. If not, he will steal your points.
A box contains n chocolates, each with an integer between 1 and m−1 written on it.
For i=1,2,⋯,n, the integer written on the i-th chocolate is a(i).
While the box has two or more chocolates remaining, Kuroba will repeat "Choose Two and Eat One," which is the following operation.
First, choose two chocolates arbitrarily.
Then, get a score equal to (x^y+y^x mod m), where x and y are the integers written on the two chocolates.
Finally, choose one of the two chocolates arbitrarily, eat it, and return the other to the box.
Print the possible maximum total score Kuroba will get.

*//*Input
The first line of each test case contains two integers n,m.
The second line of each test case contains n numbers a(1),a(2),⋯,a(n).

Restrictions
2≤n≤500^2
2≤m≤10^9
1≤a(i)≤m−1
All values in the input are integers.

Testcases 1 ~ 3: (Each for 4 points.)
Sample test cases.

Testcases 4 ~ 14: (Each for 8 points.)
No further constraints.

*//*Output
Print the possible maximum total score Kuroba will get.

*//*Sample
*//*Input 1
4 10
4 2 3 2
Output 1
20
*//*Input 2
20 100
29 31 68 20 83 66 23 84 69 96 
41 61 83 37 52 71 18 55 40 8
Output 2
1733
*//*Input 3
20 951955678
602745444 39054577 114030145 21269346 116990337 
672330354 454851422 26587058 684687970 424120461 
157916102 863307499 625411389 449487300 60276600 
441428835 640777581 188565916 83102420 898359376
Output 3


*//*Hint
The explanation for Sample 1:
Consider the following scenario. Below, X mod Y denotes the remainder when a non-negative integer X is divided by a positive integer Y.

1. Take the first and third chocolates from the box to score (4^3+3^4) mod 10 =5 points. Then, eat the first chocolate and return the third to the box. Now, the box has the second, third, and fourth chocolates.
2. Take the third and fourth chocolates from the box to score (3^2+2^3) mod 10 =7 points. Then, eat the third chocolate and return the fourth to the box. Now, the box has the second and fourth chocolates.
3. Take the second and fourth chocolates from the box to score (2^2+2^2) mod 10 =8 points. Then, eat the second chocolate and return the fourth to the box. Now, the box has just the fourth chocolate.

In the end, Kuroba scores a total of 5+7+8=20 points which is the maximum possible value.

*/