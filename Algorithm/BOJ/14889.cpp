#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <vector>
#include <deque>
#include <bitset>
#include <set>
#include <map>
using namespace std;
#define inf 2000000000
int arr[21][21],n,van,mini=inf;
vector<int> v1,v2;
void dfs(int su){
    if(su == n){
        int c1=0,c2=0,sum,vlen1=v1.size(), vlen2=v2.size();
		if(vlen1 != vlen2) return;
 //       cout << v1.size() << " "  << v2.size() << '\n';
        for(int i=0;i<vlen1;i++){
            for(int j=i+1;j<vlen1;j++){
                c1 += arr[v1[i]][v1[j]] + arr[v1[j]][v1[i]];
            }
        }
        
        for(int i=0;i<vlen2;i++){
            for(int j=i+1;j<vlen2;j++){
                c2 += arr[v2[i]][v2[j]] + arr[v2[j]][v2[i]];
            }
        }
     
        sum=abs(c1-c2);
        mini = min(mini,sum);
        return;
    }
    v1.push_back(su);
    dfs(su+1);
    v1.pop_back();

    v2.push_back(su);
    dfs(su+1);
    v2.pop_back();
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    van = (n / 2);
    dfs(0);
    cout << mini;
}
