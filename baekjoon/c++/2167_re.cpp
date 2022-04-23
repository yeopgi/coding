#include<bits/stdc++.h>
using namespace std;
int N,M;
int Data[301][301];
int p_sum[301][301];
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>Data[i][j];
        }
    }
}
int s_dfs(int n,int m){
    if(n<1 || m<1)return 0;
    if(p_sum[n][m]!=0)return p_sum[n][m];
    p_sum[n][m] = s_dfs(n-1,m) + s_dfs(n,m-1) - s_dfs(n-1,m-1) + Data[n-1][m-1];
    return p_sum[n][m];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    memset(p_sum,0,sizeof(p_sum));
    s_dfs(N,M);
    int T;cin>>T;
    while(T--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;
        int res =p_sum[c][d]-p_sum[c][b]-p_sum[a][d]+p_sum[a][b];
        cout<<res<<"\n";
    }
}

// 시간 12ms 메모리 2692kb
