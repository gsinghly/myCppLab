//gauravsinghh
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define ld long double
#define db double
#define pii pair<int,int>
#define pll pair<long long,long long>
#define sii set<int>
#define sll set<long long>
#define vii vector<int> 
#define vll vector<long long>
#define mii map<int,int>
#define mll map<long long, long long>
#define lob lower_bound
#define upb upper_bound
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ins insert
#define mp make_pair
#define w(t) cin >> t;while(t--)
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define os cout<<" "
#define bitcount __builtin_popcount
#define gcd __gcd
#define endl "\n"
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define ford(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define fors(container, it, a, b) for(__typeof(container.begin()) it = a; it != b; it++) 
#define MOD 998244353
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define lim 100000ll
#define siz 1000005
#define fbo find_by_order
#define ook order_of_key
#define sz(s) (int)s.size()
#define mem(n,m) memset(n,m,sizeof(n))
#define rep(i,n) for(ll i = 0; i < n; i++)
#define ren(i,n) for(ll i = n-1; i >= 0; i--)
#define all(x) x.begin(),x.end()
#define fo(i, a, b) for(ll i = a; i <= b; i++)
#define ffo(i, a, b) for(ll i = a; i >= b; i--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector < ll > g[200005];
bool vis[200005];
ll a[200005], tt;
unordered_map < ll, ll >mpp;
vector < ll > ans;

bool bfs(ll s){
    queue < ll > q;
    vis[s] = true;
    q.push(s);
    while(!q.empty()){
        s = q.front();
        q.pop();
        ans.pb(s);
        for(auto it : g[s]){
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
            }
        }
    }
    rep(i, sz(ans)){
        if(ans[i] != a[i]){
            return false;
        }
    }
    return true;
}

bool comp(const ll &a, const ll &b){
    return mpp[a] < mpp[b];
}

signed main(){ 
    IOS
    ll u, v;
    cin >> tt;
    rep(i, tt-1){
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    rep(i, tt){
        cin >> a[i];
        a[i]--;
        mpp[a[i]] = i;
    }
    rep(i, tt){
        sort(all(g[i]), comp);
    }
    if(bfs(0)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
} 
