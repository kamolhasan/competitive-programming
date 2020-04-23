// C. Two Teams Composing solution
// Link: https://codeforces.com/contest/1335/problem/C

#include <bits/stdc++.h>
using namespace std;

int t, n, mn, dist, ans, ar[200010], cnt[200010];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		dist = 0;
		for (int i = 1; i <= n; i++)cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", ar + i);
			cnt[ar[i]]++;
			if (cnt[ar[i]] == 1)dist++;
		}

		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt[i]) {
				mn = min(dist - 1, cnt[i]);

				if (mn == cnt[i]) {
					ans = max(ans, cnt[i]);
				}  else {
					if (cnt[i] - mn > 1)
						ans = max(ans, mn + 1);
					else
						ans = max(ans, mn);
				}
			}
		}

		printf("%d\n", ans);
	}
}