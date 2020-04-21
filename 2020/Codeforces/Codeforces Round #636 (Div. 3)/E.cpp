// E. Weights Distributing solution
// Link: https://codeforces.com/contest/1343/problem/E

#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, c, u, v, x, p[200010], da[200010], db[200010], dc[200010];
long long ans, csum[200010];
vector<int> edge[200010];
queue<int> Q;

void bfsA() {
	da[a] = 1;
	Q.push(a);
	while (!Q.empty()) {
		int f = Q.front();
		Q.pop();
		for (int k = 0; k < edge[f].size(); k++) {
			if (!da[edge[f][k]]) {
				da[edge[f][k]] = da[f] + 1;
				Q.push(edge[f][k]);
			}
		}
	}
}

void bfsB() {
	db[b] = 1;
	Q.push(b);
	while (!Q.empty()) {
		int f = Q.front();
		Q.pop();
		for (int k = 0; k < edge[f].size(); k++) {
			if (!db[edge[f][k]]) {
				db[edge[f][k]] = db[f] + 1;
				Q.push(edge[f][k]);
			}
		}
	}
}

void bfsC() {
	dc[c] = 1;
	Q.push(c);
	while (!Q.empty()) {
		int f = Q.front();
		Q.pop();
		for (int k = 0; k < edge[f].size(); k++) {
			if (!dc[edge[f][k]]) {
				dc[edge[f][k]] = dc[f] + 1;
				Q.push(edge[f][k]);
			}
		}
	}
}

void cleanUp() {
	for (int i = 1; i <= n; i++) {
		edge[i].clear();
		da[i] = db[i] = dc[i] = 0;
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
		for (int i = 1; i <= m; i++) {
			scanf("%d", p + i);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d %d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		sort(p + 1, p + m + 1);
		csum[1] = p[1];
		for (int i = 2; i <= m; i++) {
			csum[i] = csum[i - 1] + p[i];
		}
		bfsA();
		bfsB();
		bfsC();
		ans = 1e18;
		for (int i = 1; i <= n; i++) {
			if (da[i] + db[i] + dc[i] - 3 <= m) {
				ans = min(ans, (2 * csum[db[i] - 1]) + (csum[da[i] + db[i] + dc[i] - 3] - csum[db[i] - 1]));
			}
		}

		printf("%lld\n", ans);
		cleanUp();
	}
}