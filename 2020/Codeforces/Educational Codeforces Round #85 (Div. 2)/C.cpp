// C. Circle of Monsters solution
// Link: https://codeforces.com/contest/1334/problem/C

#include<bits/stdc++.h>
using namespace std;

long long t, n, minAns, x, ar[300010], a[300010], b[300010], vis[300010], ans;
int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);

		for (int i = 0; i < n; i++) {
			scanf("%lld %lld", a + i, b + i);
		}

		for (int i = 0; i < n; i++) {
			a[(i + 1) % n] -= b[i];
		}

		ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0)ans += a[i];
		}

		minAns = 1e18;
		for (int i = 0; i < n; i++) {
			x = ans;
			if (a[i] > 0)x -= a[i];
			a[i] += b[(i - 1 + n) % n];
			x += a[i];
			minAns = min(x, minAns);
		}

		printf("%lld\n", minAns);
	}

}