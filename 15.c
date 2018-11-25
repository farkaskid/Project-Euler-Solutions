#include <stdio.h>

#define ll unsigned long long int

ll arr[1000000] = { 0 };

ll fact(ll x) {
	ll result;
	if (arr[x]) {
		return arr[x];
	}

	if (x == 1 || x == 0) {
		result = 1;
	} else {
		result = x * fact(x - 1);
	}

	arr[x] = result;
	return result;
}

ll ncr(ll n, ll r) {
	return fact(n) / (fact(r) * fact(n - r));
}

int main() {
	ll n = 18;
	ll m = 18;
	ll ans = 0;
	for (ll i = 0; i < m; i++) {
		ans += ncr(n + 1, i + 1) * ncr(m - 1, i);
	}
	printf("%llu\n", ans);
}
