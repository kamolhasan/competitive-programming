// C. Alternating Subsequence solution
// https://codeforces.com/contest/1343/problem/C

#include <bits/stdc++.h>
using namespace std;

int t, n;
long long ar[200010], sum = 0, value;
bool f;

bool isPos(long long x) {
	return x > 0;
}

bool isNeg(long long x) {
	return x < 0;
}

bool isOp(long long x, long long y) {
	return ( ( isPos(x) && isNeg(y) ) || (isNeg(x) && isPos(y)));
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", ar + i);
		}
		sum = 0;
		value = ar[0];
		for (int i = 1; i < n; i++) {
			if (isOp(ar[i], ar[i - 1])) {
				sum += value;
				value = ar[i];
			} else {
				value = max(value, ar[i]);
			}
		}

		sum += value;

		printf("%lld\n", sum);

	}
}