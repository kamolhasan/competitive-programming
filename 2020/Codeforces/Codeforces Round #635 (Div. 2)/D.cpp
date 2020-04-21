#include<bits/stdc++.h>
using namespace std;

int t;
long long na, nb, x, nc, ans;
vector<long long> a, b, c;

long long cal(long long aa, long long bb, long long cc) {
	return (aa - bb) * (aa - bb) + (bb - cc) * (bb - cc) + (cc - aa) * (cc - aa);
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld %lld", &na, &nb, &nc);

		a.clear();
		for (int i = 0; i < na; i++) {
			scanf("%lld", &x);
			a.push_back(x);
		}
		sort(a.begin(), a.end());

		b.clear();
		for (int i = 0; i < nb; i++) {
			scanf("%lld", &x);
			b.push_back(x);
		}
		sort(b.begin(), b.end());

		c.clear();
		for (int i = 0; i < nc; i++) {
			scanf("%lld", &x);
			c.push_back(x);
		}
		sort(c.begin(), c.end());

		ans = 2e18;
		for (int i = 0; i < a.size(); i++) {
			int value = a[i];
			int lob = int(lower_bound(b.begin(), b.end(), value) - b.begin());
			int loc = int(lower_bound(c.begin(), c.end(), value) - c.begin());
			if (lob - 1 > 0) {
				if (loc - 1 > 0) {
					ans = min(ans, cal(a[i], b[lob - 1], c[loc - 1]));
				}
				if (loc < c.size()) {
					ans = min(ans, cal(a[i], b[lob - 1], c[loc]));
				}
				if  (loc + 1 < c.size()) {
					ans = min(ans, cal(a[i], b[lob - 1], c[loc + 1]));
				}
			}
			if (lob < b.size()) {
				if (loc - 1 > 0) {
					ans = min(ans, cal(a[i], b[lob], c[loc - 1]));
				}
				if (loc < c.size()) {
					ans = min(ans, cal(a[i], b[lob], c[loc]));
				}
				if  (loc + 1 < c.size()) {
					ans = min(ans, cal(a[i], b[lob], c[loc + 1]));
				}
			}
			if (lob + 1 < b.size()) {
				if (loc - 1 > 0) {
					ans = min(ans, cal(a[i], b[lob + 1], c[loc - 1]));
				}
				if (loc < c.size()) {
					ans = min(ans, cal(a[i], b[lob + 1], c[loc]));
				}
				if  (loc + 1 < c.size()) {
					ans = min(ans, cal(a[i], b[lob + 1], c[loc + 1]));
				}
			}
		}

		printf("%lld\n", ans);
	}
}
