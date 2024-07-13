#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define INF 0X3f3f3f
using namespace std;
typedef pair<int,int>iPair;
vector<pair<int,int>>graph[100];
int node;
void dijskstra(int s, vector<int> &d, vector<int>&p){
    d.assign(node,INF);
    p.assign(node,-1);
    priority_queue<iPair,vector<iPair>,greater<iPair>>pq;
    pq.push({0,s});
    d[s] = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(dist != d[u]) continue;
        for(int i = 0; i< graph[u].size();i++){
            int v = graph[u][i].first;
            int cost = graph[u][i].second;
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
    int n,e,i,j,k;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>node>>e;
    int u,v,c;
    for(int i = 1;i<=e;i++){
        cin>>u>>v>>c;
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }
    vector<int> d;
    vector<int>p;
    d.assign(node+2,INF);
    p.assign(node+2,-1);
    dijskstra(1,d,p);
    cout<<"node         distance\n";
    for(int i = 1; i<=node;i++){
        cout<<i<<"---------"<<d[i]<<endl;
    }
    cout<<"path\n";
    int des;
    cin>>des;
    stack<int>st;
    st.push(des);
    while(p[des]!=-1){
        st.push(p[des]);
        des = p[des];
    }
    while(!st.empty()){
        cout<<st.top()<<" >> ";
        st.pop();
    }
    cout<<endl;


    return 0;
}