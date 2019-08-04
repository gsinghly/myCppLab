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
#define inf 999999
#define lim 100005
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

bool comp(const pair < pair < ll, ll >, ll >&a,const pair < pair <ll, ll>, ll >&b){
    return (a.ff.ff > b.ff.ff ||(a.ff.ff == b.ff.ff && a.ss > b.ss));
}

signed main(){ 
    IOS
    string s;
    cin >> s;
    ll f = 0, c = 0;
    vll v;
    unordered_map < ll, ll > mpp;
    ll a[sz(s)+1] = {0}, ans[sz(s)] = {0}, i = 0, j = sz(s)-1;
    while(1){
        if(i == sz(s)-1){
            break;
        }
        if(s[i] == 'R' && s[i+1] == 'R'){
            c++;
        }
        else if(s[i] == 'R'){
            a[i] = c+1;
            c = 0;
        }
        i++;
    }
    c = 0;
    while(1){
        if(j == 0)  break;
        if(s[j] == 'L' && s[j-1] == 'L'){
            c++;
        }
        else if(s[j] == 'L'){
            a[j] = c+1;
            c = 0;
        }
        j--;
    }
    rep(i, sz(s)){
        if(a[i] != 0){
            if(s[i] == 'R' && s[i+1] == 'L'){
                ll c = (a[i]+a[i+1])/2;
                ll d = (a[i]+a[i+1])%2;
                if(d == 0){
                    ans[i] = c;
                    ans[i+1] = c; 
                }
                else{
                    if(a[i]%2 != 0){
                        ans[i] = c+1;
                        ans[i+1] = c;    
                    }
                    else{
                        ans[i] = c;
                        ans[i+1] = c+1;       
                    }

                }
                i++;
            }
        }
    }
    rep(i, sz(s)){
        cout << ans[i] << " ";
    }
    return 0;
} 

