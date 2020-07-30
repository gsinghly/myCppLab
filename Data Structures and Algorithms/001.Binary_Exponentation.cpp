// f.(g.h) = (f.g).h, O(log n)

const ll mod = 1e9 + 7;
const ll n = 2e6 + 5;

//Recursive
ll power(ll a, ll b) {
	if (!b)	return 0;
	if (b & 1)	return (a % mod * power(a * a % mod, b / 2) % mod) % mod;
	return power((a * a) % mod, b / 2);
}

//Iterative
ll power(ll a, ll b) {
	ll ans = 1;
	a %= mod;
	while (b > 0) {
		if (b & 1)	ans = (ans * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}
