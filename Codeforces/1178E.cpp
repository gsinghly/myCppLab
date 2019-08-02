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

string ans, tt;

signed main(){ 
    IOS
    string s;
    cin >> s;
    ll a = 0, b = 0, c = 0;
    rep(i, sz(s)){
        if(s[i] == 'a'){
            a++;
        }
        else if(s[i] == 'b'){
            b++;
        }
        else{
            c++;
        }
    }
    ll x = sz(s)/2;
    if(a >= x || b >= x || c >= x){
        if(a >= x){
            rep(i, a){
                cout << "a";
            }
        }
        else if(b >= x){
            rep(i, b){
                cout << "b";
            }
        }
        else if(c >= x){
            rep(i, c){
                cout << "c";
            }
        }
        return 0;
    }
    ll l = 0, r= sz(s) - 1;
    while(r-l > 2){
        ll c[3] = {0};
        c[s[l] - 'a']++;
        c[s[l+1] - 'a']++;
        c[s[r] - 'a']++;
        c[s[r-1] - 'a']++;
        rep(j, 3){
            if(c[j] >= 2){
                ans += (char)('a'+j);
                break;
            }
        }
        l+=2, r-=2;
    }
    tt = ans;
    reverse(all(tt));
    if(r-l >= 0){
        ans += (s[l] + tt);
    }
    else{
        ans += tt;
    }
    if(sz(ans) < x){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << ans << endl;
    }
    return 0;
}
