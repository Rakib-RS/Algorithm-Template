#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define INF 1e18
using namespace std;
typedef pair<long long int,long long int>iPair;
vector<pair<long long int,long long int>>graph[100005];
int node;
void dijskstra(long long int s, vector<long long int> &d, vector<long long int>&p){
    d.assign(node,INF);
    p.assign(node,-1);
    priority_queue<iPair,vector<iPair>,greater<iPair>>pq;
    pq.push({0,s});
    d[s] = 0;
    while(!pq.empty()){
        long long int dist = pq.top().first;
        long long int u = pq.top().second;
        pq.pop();
        if(dist != d[u]) continue;
        for(int i = 0; i< graph[u].size();i++){
            long long int v = graph[u][i].first;
            long long int cost = graph[u][i].second;
            //cout<<v<<"  "<<cost<<endl;
            if(d[u] + cost < d[v]){
                d[v] = d[u] + cost;
                p[v] = u;
                pq.push({d[u] + cost, v});
            }
        }
    }

}
int main(){
    long long int n,e,i,j,k;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>node>>e;
    long long int u,v,c;
    for(int i = 1;i<=e;i++){
        cin>>u>>v>>c;
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }
    vector<long long int> d;
    vector<long long int>p;
    d.assign(node+2,INF);
    p.assign(node+2,-1);
    dijskstra(1,d,p);
   // cout<<"node         distance\n";
    // for(int i = 1; i<=node;i++){
    //     cout<<i<<"---------"<<d[i]<<endl;
    // }
   // cout<<"path\n";
    int des;
    des = node;
    stack<long long int>st;
    st.push(des);
    while(p[des]!=-1){
        st.push(p[des]);
        des = p[des];
    }
    if (st.size() == 1) cout<<"-1\n";
    else {
        while(st.size()> 1){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<st.top()<<endl;
    }
    


    return 0;
}