#include <bits/stdc++.h>
using namespace std;

long long t, n, ar[200010], csum[200010];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			cin >> ar[i];
			csum[i] = 0;
		}
		sort(ar, ar + n + 2);
		csum[0] = ar[0];
		for (int i = 1; i < n + 2; i++) {
			csum[i] = csum[i - 1] + ar[i];
		}

		int x, y;
		x = y = -1;

		for (int j = n + 1; j >= n - 1; j--) {
			//cout<<"j: "<<ar[j]<<endl;
			for (int i = 0; i < n + 2; i++) {
				if (i == j)continue;

				if (csum[n + 1] - ar[j] - ar[i] == ar[j]) {
					x = i;
					y = j;
				}
			}
		}

		if (x != -1) {
			for (int i = 0; i < n + 2; i++) {
				if (i == x || i == y)continue;
				cout << ar[i] << ' ';
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}

	}
}