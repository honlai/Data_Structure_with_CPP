/*Description
{Five years Five million dollars.
Tsing Hua Big Constructions.
-- By Anonymity}
Now, the new President of Tsing Hua University, W. John Kao, is going to make something different.
He's going to construct N stops, along with K U-ways and L O-ways extending between the stops.
An U-way bidirectionally connects two stops, say p(i) and q(i). An O-way also bidirectionally connects two stops, say r(i) and s(i).No two U-ways connect the same pair of stops. Similarly, no two O-ways connect the same pair of stops.
We say that stops A and B are connected by U-bike if stop B is reachable from stop A by traversing some number of U-ways. Here, any stop is considered to be connected to itself by U-bike. We will also define connectivity by the oloo(O-way) similarly.
Now, President Kao wants to find out the efficiency of this construction. The efficiency is defined as follows:
For each stop, find the number of stops connected to that stop by both U-bike and oloo.
Can you help him?

*//*Input
The first line contains three integers representing N,K and L.
Each of the following K lines contains two integers p(i) and q(i), representing the stops p(i) and q(i) are connected by U-ways.
Then, each of the following L lines contains two integers r(i) and s(i), representing the stops r(i) and s(i) are connected by O-ways.

Restrictions
2≤N≤2×10^5
1≤K,L≤10^5
1≤p(i),q(i),r(i),s(i)≤N
p(i)<q(i)
r(i)<s(i)
When i≠j,(p(i),q(i))≠(p(j),q(j))
When i≠j,(r(i),s(i))≠(r(j),s(j))

Testcases 15,16,17: (Each for 6 points.)
Sample test cases.

Remaining Testcases: (Total 72 points)
No further constraints.

*//*Output
Print N integers. The i-th integer represents the number of stops connected to the i-th stop by both U-bike and oloo.

*//*Sample
*//*Input 1
4 3 1
1 2
2 3
3 4
2 3
Output 1
1 2 2 1
*//*Input 2
4 2 2
1 2
2 3
1 4
2 3
Output 2
1 2 2 1
*//*Input 3
7 4 4
1 2
2 3
2 5
6 7
3 5
4 5
3 4
6 7
Output 3
1 1 2 1 2 2 2

*//*Hint
For sample 1, there are 3 U-way (1,2),(2,3), and (3,4), which connect stops 1,2,3,4. There is also 1 O-way (2,3) which connect stops 2,3. Stop 2 and Stop 3 can reach each other by both U-bike and oloo, while others can only be reached by U-bike. So the output will be 1 2 2 1.
In brief, the answer will be the intersection of the set that "can reach through U-way" and the set that "can reach through O-way". For example, Stop 2 can reach Stop 1,2,3,4 through U-ways, and reach Stop 2,3 through O-ways. So the intersection will be Stop 2,3 only. Hence the answer for Stop 2 will be 2.
{If you still can not solve this problem, you may try std::map}
*/