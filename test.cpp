#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> umap = {
        {"Tom", 1},
        {"Ann", 4},
        {"Jack", 2}
    };
    umap["Tom"]=2;
    cout<<umap["Tom"]+1<<endl;
    return 0;
}