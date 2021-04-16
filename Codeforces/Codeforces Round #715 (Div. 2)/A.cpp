#include <bits/stdc++.h>
using namespace std;

int t, n, ar[2005];
vector<int> ans;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			if (ar[i] & 1)ans.push_back(ar[i]);
		}

		for (int i = 0; i < n; i++) {
			if (!(ar[i] & 1))ans.push_back(ar[i]);
		}

		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}

		cout << endl;
		ans.clear();

	}
}