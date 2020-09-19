### Power Mod (a^b)%c

ll power(ll a, ll b, ll c){
  ll ans = 1;
  a = a%c;
  while(y > 0){
    if(y&1){
      ans = (ans*c)%c;
    }
    y >>= 1;
    x = (x*x)%c;
  }
  return ans;
}




### Mul Mod (a*b)%c; a, b, c <= 1e18

ll mulmod(ll a, ll b, ll c){
  if(b == 0)  return 0;
  ll s = mulmod(a, b/2, c);
  if(b&1) return (a%c * 2*(s%c))%c;
  return (2*(s%c))%c;
}

