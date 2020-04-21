// B. Kind Anton solution
// Link: https://codeforces.com/contest/1333/problem/B

#include <bits/stdc++.h>
using namespace std;

int n, t, a[100010], b[100010];
set<int> st;
bool f;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		f = true;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int j = 0; j < n; j++) {
			cin >> b[j];
		}

		for (int i = 0; i < n; i++) {
			if (!f)break;

			if (a[i] == b[i]) {
				st.insert(a[i]);
				continue;
			}

			if (b[i] == 0) {
				if (a[i] == 1 && st.find(-1) != st.end()) {
					st.insert(a[i]);
					continue;
				} else if (a[i] == -1 && st.find(1) != st.end()) {
					st.insert(a[i]);
					continue;
				} else {
					f = false;
				}
			} else if (b[i] >= 1) {
				if (st.find(1) != st.end()) {
					st.insert(a[i]);
					continue;
				} else {
					f = false;
				}
			} else {
				if (st.find(-1) != st.end()) {
					st.insert(a[i]);
					continue;
				} else {
					f = false;
				}
			}
		}

		if (f) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		st.clear();
	}
}