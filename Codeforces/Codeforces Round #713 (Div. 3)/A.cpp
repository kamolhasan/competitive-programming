#include <bits/stdc++.h>
using namespace std;

int t, n, ar[101], x, cnt[101];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			cnt[ar[i]]++;
		}

		x = 0;
		for (int i = 1; i <= 100; i++) {
			if (cnt[i] == 1) {
				x = i; break;
			}
		}

		for (int i = 0; i < n; i++) {
			if (ar[i] == x) {
				cout << i + 1 << endl; break;
			}
		}
	}
}