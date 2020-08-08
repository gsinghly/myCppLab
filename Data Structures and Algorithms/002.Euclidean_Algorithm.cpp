//gcd
//Recursive
ll gcd(ll a, ll b){
	//return b ? gcd(b, a%b) : a;
	if(!b)	return a;
	return gcd(b, a%b);
}

//Iterative
ll gcd(ll a, ll b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

//lcm

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b; //Avoids integer overflow 
}