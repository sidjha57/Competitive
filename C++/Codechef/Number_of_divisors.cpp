#include<bits/stdc++.h>
using namespace std;

using ll = long long;

long long f(int n, int k) {
	if (n == 0) return 0;
	long long res = (n/k);
	return f(n/k, k) + n * (ll)(n+1) / 2ll - (res * (res + 1) / 2ll) * k;
}               	

int main () {
	int T = 1;
	scanf("%d", &T);
	assert(T >= 1 && T <= 300000);
	while(T--) {

		int n, k;
		scanf("%d%d", &n, &k);
		assert(n <= 1e9);
		assert(k >= 2 && k <= 1e9);

		printf("%lld\n", f(n, k));
		
	}

	return 0;
}