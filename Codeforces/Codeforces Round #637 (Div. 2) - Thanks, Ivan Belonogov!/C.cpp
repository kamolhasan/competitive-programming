#include <bits/stdc++.h>
using namespace std;

int t, n, a, p[100010], loc[100010], ck[100010], vis[100010], mx, f;

int main() {

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)loc[i] = ck[i] = vis[i] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", p + i);
			loc[p[i]] = i;
		}

		f = 1;

		for (int i = 1; i <= n; i++) {
			if (!loc[i]) {
				f = 0;
			}
		}

		mx = 0;
		for (int i = 1; i <= n && f; i++) {
			if (ck[loc[i]] == mx) {
				vis[loc[i]] = 1;
				ck[loc[i] + 1] = ck[loc[i]] + 1;
				if (vis[loc[i] + 1] || loc[i] + 1 > n)
					mx = 0;
				else
					mx = ck[loc[i] + 1];
			} else {
				f = 0;
			}
		}


		if (f) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

}