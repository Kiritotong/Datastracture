#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123;

int graph[maxn][maxn],n;
int book[maxn];

void bfs()
{
    queue<int>box;
    box.push(0);
    book[0]=1;
    while(!box.empty()){
        int now=box.front();box.pop();
        printf("%d ",now);
        for(int i=0;i<n;i++){
            if(i!=now&&book[i]==0&&graph[now][i]==1){
                box.push(i);
                book[i]=1;
            }
        }
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
    bfs();
    return 0;
}