#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int maxn=100000;

int nxt[maxn];

void set_nextvalue(string t)
{
    int tlen=t.length();
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<tlen){
        if(k==-1||t[j]==t[k]){
            ++j;
            ++k;
            if(t[j]!=t[k])
                nxt[j]=k;
            else
                nxt[j]=nxt[k];
        }
        else
            k=nxt[k];
    }
    return;
}

int kmp_match(string s,string t)
{
    set_nextvalue(t);
    int i=0,j=0;
    int slen=s.length(),tlen=t.length();
    while(i<slen&&j<tlen){
        if(j==-1||s[i]==t[j]){
            ++i;
            ++j;
        }
        else{
            j=nxt[j];
        }
    }
    if(j==tlen)
        return i-j;
    else
        return -1;
}

int main()
{
    freopen("in3.txt","r",stdin);//input through files
    string a,b;
    printf("Please input two strings:\n");
    printf("S:");
    cin>>a;
    printf("T:");
    cin>>b;
    int ans=kmp_match(a,b);
    ans==-1?printf("These two string can't match!"):printf("%d",ans+1);
    return 0;
}
