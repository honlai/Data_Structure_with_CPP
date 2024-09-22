/*Description
Miko has a binary tree T. (T stores strings)
Unfortunately, the wind in Hsinchu is so strong that her tree is blown away.
Luckily, she made a copy of the inorder and postorder traversal of the tree. Please help her recover the preorder traversal of the tree.
However, since Miko isn't a careful person, it is possible that she made some mistakes with the two traversals. In this case, tell her it is "Impossible" to recover the tree.

*//*Input
There are multiple test cases.
The first line of each input is t - The number of test cases. The description of the test cases follows.
The first line of each test case contains an integer n — The number of nodes of the binary tree.
The second line of each test case contains n integers in(1),in(2),⋯,in(n) — The inorder traversal of a tree.
The third line of each test case contains n integers post(1),post(2),⋯,post(n) — The postorder traversal of a tree.
Each data in the tree is a string s and is separated by a space " ".
All the strings s are distinct.

Restrictions
1≤t≤5
1≤s.length≤10
Test cases 1 to 3: (Each for 4 points)
Sample test cases.

Test cases 4 to 6: (Each for 4 points)
1≤n≤1000

Test cases 7 to 14: (Each for 4 points)
1000≤n≤10000

Test cases 15 to 20: (Each for 4 points)
10000≤n≤100000

Test cases 21 to 25: (Each for 4 points)
100000≤n≤200000

*//*Output
For each test case, print one line.
If the tree reconstruction is possible, print the preorder traversal of the binary tree with each vertex separated by a space.
Otherwise, print "Impossible" case-sensitively. (大小寫區分)

*//*Sample
*//*Input 1
2
5
e b gzv aeu vw 
e b gzv vw aeu 
5
ljk ke i ekl dekl 
ke ljk i ekl dekl 
Output 1
aeu gzv b e vw 
dekl ekl i ljk ke 
*//*Input 2
3
3
o zyo iqs 
zyo iqs o 
7
uzvd wyp tjy sku yc p utj 
uzvd tjy yc sku wyp utj p 
7
eto to w ojvq etoj zv vq 
w to vq zv eto etoj ojvq 
Output 2
o iqs zyo 
p wyp uzvd sku tjy yc utj 
Impossible
*//*Input 3
4
14
ozl lv xdi ucp s dinm veh pxd wu ysv uk h yoor oru 
ozl xdi lv s veh wu pxd uk yoor h oru ysv dinm ucp 
12
wt zvpw pse ops fwtz jfw e seje j pw vpw b 
e jfw seje ops vpw wt zvpw pse j pw b fwtz 
13
yv gh m ya k iq eakj o ra tbyv i dfra ltby 
yv m k eakj ra o i dfra ltby tbyv iq ya gh 
14
yk n d e wvvz b y ze weyr pbgd gd dtwe k u 
b k wvvz y u dtwe gd yk pbgd ze weyr n d e 
Output 3
ucp lv ozl xdi dinm s ysv pxd veh wu oru h uk yoor 
Impossible
gh yv ya m iq k tbyv o eakj ra ltby dfra i 
Impossible
*/