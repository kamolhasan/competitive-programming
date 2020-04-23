// B. Middle Class solution
// Link: https://codeforces.com/contest/1334/problem/B

#include<bits/stdc++.h>
using namespace std;

long long t, n, L, R, M, sum, ar[100010], x, ans;

bool ck(long long k) {
	sum = 0;
	for (int i = n - 1, j = 0; j < k; i--, j++) {
		sum += ar[i];
	}
	return (k * x) <= sum;
}

int bsearch() {
	L = 0;
	R = n;
	while (R - L > 1) {
		M = (L + R) / 2;
		if (ck(M)) {
			L = M;
		} else {
			R = M;
		}
	}

	if (ck(R)) {
		return R;
	}

	return L;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar, ar + n);
		ans = bsearch();

		cout << ans << endl;
	}

}