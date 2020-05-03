#include <bits/stdc++.h>
using namespace std;

int t, n, k, ar[200010], p, mxp, l;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", ar + i);
		}
		p = 0;
		for (int i = 1; i < k - 1; i++) {
			if (ar[i - 1] < ar[i] && ar[i] > ar[i + 1]) {
				p++;
			}
		}

		l = 0;
		mxp = p;
		for (int i = k - 1; i < n - 1; i++) {
			if (ar[i - k + 1] < ar[i - k + 2] && ar[i - k + 2] > ar[i - k + 3]) {
				p--;
			}
			if (ar[i - 1] < ar[i] && ar[i] > ar[i + 1]) {
				p++;
			}
			if (p > mxp) {
				mxp = p;
				l = i - k + 2;
			}
		}
		printf("%d %d\n", mxp + 1, l + 1);
	}
}