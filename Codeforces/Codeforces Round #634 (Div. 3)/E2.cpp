// E2. Three Blocks Palindrome (hard version) solution
// Link: https://codeforces.com/contest/1335/problem/E2

#include <bits/stdc++.h>
using namespace std;

int t, n, ans, L, R, M, ar[200010], cnt[200001][201];

bool ck(int val, int x, int c) {
	return val <= cnt[n][c] - cnt[x - 1][c];
}

int getJ(int val, int x, int c) {

	L = x, R = n;
	while (R - L > 1) {
		M = (R + L) >> 1;
		if (ck(val, M, c)) {
			L = M;
		} else {
			R = M;
		}
	}
	if (ck(val, R, c)) {
		return R;
	} else if (ck(val, L, c)) {
		return L;
	}
	return -1;
}

int main() {
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", ar + i);
			cnt[i][ar[i]]++;
			for (int j = 1; j < 201; j++)
			{
				cnt[i][j] = cnt[i][j] + cnt[i - 1][j];
			}
		}

		ans = 1;
		for (int i = 1; i < n; i++)
		{
			int j = getJ( cnt[i][ar[i]], i + 1, ar[i]);
			
			if (j != -1)
			{
				if (j - i > 1) {
					for (int k = 1; k < 201; k++)
					{
						ans = max(ans, (2 * cnt[i][ar[i]]) + (cnt[j - 1][k] - cnt[i][k]));
					}
				

				}
				else {
					ans = max(ans, (2 * cnt[i][ar[i]]) );
				}

			}
		}
        
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < 201; j++) {
				cnt[i][j] = 0;
			}
		}
	}
}