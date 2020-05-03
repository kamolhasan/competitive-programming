#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, q, r, value, ar[40001], br[40001], csum[40001];

long long L, R;

void precal() {
	value = 0;
	r = (a * b) / __gcd(a, b);
	for (int i = 0; i < r; i++) {
		ar[i] = (i % a) % b;
		br[i] = (i % b) % a;
		if (ar[i] != br[i]) {
			value++;
		}
	}
	for (int i = 1; i < r; i++) {
		csum[i] = csum[i - 1] + (ar[i] != br[i]);
	}
}

long long findAns(long long x) {
	if (x <= 0)return 0;
	long long rem, ans = 0;
	ans = (x / r) * value;
	rem = x % r;
	ans += csum[rem];
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &a, &b, &q);
		precal();
		for (int i = 0; i < q; i++) {
			scanf("%lld %lld", &L, &R);
			printf("%lld ", findAns(R) - findAns(L - 1));
		}
		printf("\n");
	}
}