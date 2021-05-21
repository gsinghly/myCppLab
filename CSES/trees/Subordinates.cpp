#include <bits/stdc++.h>
using namespace std;
 
//using int = long long int;
using ll = long long int;
using pii = pair < int, int >;
 
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, j, n)    for(int i = j; i < n; i++)
#define ren(i, j, n)    for(int i = n-1; i >= j; i--)
 
#define cerr cout
void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {
    cerr << t; if(sizeof...(v)) cerr << ", "; _print(v...);
}
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
 
const int mod = 1000000007;
 
void io_set(){
    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
    #endif
}

const int N = 200005;
vector < int > g[N];
int subtree_size[N];
bool vis[N];

void dfs(int s){
    vis[s] = true;
    subtree_size[s] = 1;
    for(auto &i : g[s]){
        if(!vis[i]){
            dfs(i);
            subtree_size[s] += subtree_size[i];
        }
    }
}
 
void solve(){
    int n;  cin >> n;
    rep(i, 1, n){    
        int x;  cin >> x, --x;
        g[i].pb(x), g[x].pb(i);
    }
    dfs(0);
    rep(i, 0, n)  cout << subtree_size[i]-1 << " ";
}
 
signed main(int argc, char **argv){
    io_set();
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
