#include <bits/stdc++.h>
using namespace std;

int t, n, mn, taken, k, m[200010], val, mx = 0, his[200010], c[200010];

vector<int> ans[200010];
vector<pair<int, int>>mainAr, tempAr;
pair<int, int> tp;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", m + i);
		his[m[i]]++;
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", c + i);

		if (his[i]) {
			mainAr.push_back({i, his[i]});
		}
	}

	for (int i = 1; !mainAr.empty(); i++) {
		taken = 0;
		
		while (!mainAr.empty()) {
			tp = mainAr.back();
			mainAr.pop_back();

			if (taken < c[tp.first]) {
				mn = min(c[tp.first], tp.second);
				mn = min(mn, c[tp.first] - taken);
				tp.second -= mn;
				taken += mn;
				
				for (int jj = 0; jj < mn; jj++) {
					ans[i].push_back(tp.first);
				}
			}
			
			if (tp.second > 0) {
				tempAr.push_back(tp);
			}
		}
		mx = max(mx, i);
		while (!tempAr.empty()) {
			tp = tempAr.back(); tempAr.pop_back();
			mainAr.push_back(tp);
		}
	}

	printf("%d\n", mx);
	for (int i = 1; i <= mx; i++) {
		printf("%d ", int(ans[i].size()));
		for (int j = 0; j < ans[i].size(); j++) {
			printf(" %d", ans[i][j]);
		}
		printf("\n");
	}
}