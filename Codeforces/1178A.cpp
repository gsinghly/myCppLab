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
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define inf 999999999999999999
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
#define MAX 100005
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

signed main(){ 
    IOS
    ll n, s = 0; 
    cin >> n;
    ll a[n];
    vector < pair < ll, ll > >  v;
    vll ans;
    rep(i, n){
        cin >> a[i];
        s += a[i];
        if(i > 0){
            if(a[0] >= 2*a[i]){
                v.eb(a[i], i+1);
            }
        }
    }
    sort(all(v));
    if(a[0] > s/2){
        cout << "1\n1";
        return 0;
    }
    ans.pb(1);
    ll req = s/2 - a[0], tt = 0, i = 0;
    while(tt <= req && i < sz(v)){
        tt += v[i].ff;
        ans.pb(v[i].ss);
        i++;
    }
    if(tt <= req){
        cout << 0 << endl;
        return 0;
    }
    cout << sz(ans) << endl;
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
