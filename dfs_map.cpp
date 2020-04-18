#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123;

int graph[maxn][maxn],n;
int book[maxn];

void dfs(int now)
{
    printf("%d ",now);
    book[now]=1;
    for(int i=0;i<n;i++){
        if(i!=now&&book[i]==0&&graph[now][i]==1)
            dfs(i);
    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    dfs(0);
    return 0;
}