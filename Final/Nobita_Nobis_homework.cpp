/*Description

As usual, Nobita Nobi(野比 のび太) was called by the teacher to stand in the hallway because he didn't do his homework.
"You have to stand there until you finish it." The teacher said.
Since Nobi hates doing homework, he asks you for help. (Note that he hasn't met Doraemon yet.)

The task is to maintain an integer set that supports the following operations:
I x : Insert. If x is NOT in the set, insert x into the set. Otherwise, don't do anything. Print the size of the set after finishing the operation.
D x : Delete. If x is in the set, delete x from the integer set. Otherwise, don't do anything. Print the size of the set after finishing the operation.
S x : Search. If x is in the set, print "YES". Otherwise, print "NO".
L x : Lower bound. Print the smallest element greater than or equal to x in the set. If the element doesn't exist, print "−1".
U x k : Upper bound. Print the kth smallest element greater than x in the set. If the element doesn't exist, print "−1".
The numbers x in this problem are generated randomly.

*//*Input
The first line contains the number of operations n.
Each of the following n lines contains one of the operations described above.

Restrictions 
1≤n≤10^5
1≤x≤10^9 for every integer x in all operations 
1≤k≤5 for every integer k in U x k operation

Test cases 1 ~ 3: (Each for 3 points)
Sample test cases.

Test cases 4 ~ 5: (Each for 3 points)
Only I and S operations.

Test cases 6 ~ 10: (Each for 5 points)
Only I, S, and L operations.

Test cases 11 ~ 15: (Each for 5 points)
k=1 for all U x k operations.

Test cases 16 ~ 20: (Each for 7 points)
No further constraints.
*//*Output
For each operation:
I x or D x : Print the size of the set after finishing the operation.
S x : If x is in the set, print "YES". Otherwise, print "NO".
L x or U x k : Print the element if the required element is in the set. Otherwise, print "-1".
*//*Sample 
*//*Input 1 
5
I 1
I 3
S 2
S 3
I 5
Output 1
1
2
NO
YES
3
*//*Input 2
10
I 2
S 1
L 1
I 4
L 5
I 7
L 4
S 4
I 4
S 1
Output 2
1
NO
2
2
-1
3
4
YES
3
NO
*//*Input 3
20
I 4
I 8
I 7
I 6
I 3
S 8
I 8
S 7
L 9
L 8
L 7
L 6
U 9 1
U 4 4 
U 3 3
U 2 2
U 1 5
D 7
D 5
D 4
Output 3
1
2
3
4
5
YES
5
YES
-1
8
7
6
-1
-1
7
4
8
4
4
3
*/

