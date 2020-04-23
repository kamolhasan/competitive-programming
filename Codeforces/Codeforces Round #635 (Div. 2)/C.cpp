// C. Linova and Kingdom solution
// Link: https://codeforces.com/contest/1337/problem/C

#include<bits/stdc++.h>
using namespace std;

int t, n, k, m, u, v,  vis[200010];
long long result;

vector<int> edge[200010];
pair<int, int> ans[200010];

int dfs(int node, int d) {
	if (vis[node])return 0;

	vis[node] = 1;
	ans[node].first = d;
	int s = 0;
	for (int i = 0; i < edge[node].size(); i++) {
		s += dfs(edge[node][i], d + 1);
	}
	ans[node].second = s;
	return s + 1;
}


bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first - a.second > b.first - b.second;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}


	dfs(1, 0);
	sort(ans + 1, ans + n + 1, cmp);

	result = 0;
	for (int i = 1; i <= k; i++) {
		result += (ans[i].first - ans[i].second);
	}
	printf("%lld\n", result);
}
