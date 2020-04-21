// E1. Three Blocks Palindrome (easy version) solution
// Link: https://codeforces.com/contest/1335/problem/E1

#include <bits/stdc++.h>
using namespace std;

int t, n, ans, ar[200010], cnt[2001][27];


int main() {
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", ar + i);
			cnt[i][ar[i]]++;
			for (int j = 1; j < 27; j++)
			{
				cnt[i][j] = cnt[i][j] + cnt[i - 1][j];
			}
		}

		ans = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (cnt[i][ar[i]] <= (cnt[n][ar[i]] - cnt[j - 1][ar[i]]))
				{

					if (j - i > 1)
					{
						for (int k = 1; k < 27; k++)
						{
							ans = max(ans, (2 * cnt[i][ar[i]]) + (cnt[j - 1][k] - cnt[i][k]));
						}

					}
					else
					{
						ans = max(ans, (2 * cnt[i][ar[i]]));
					}



				}
			}
		}

		printf("%d\n", ans);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < 27; j++) {
				cnt[i][j] = 0;
			}
		}
	}
}