#include <bits/stdc++.h>
using namespace std;

int t, n;
char ar[500][500];

vector <pair<int, int>> v;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> ar[i][j];
				if (ar[i][j] == '*') {
					v.push_back({i, j});
				}
			}
		}

		if (v[0].first == v[1].first) {
			ar[(v[0].first + 1) % n][v[0].second] = '*';
			ar[(v[1].first + 1) % n][v[1].second] = '*';
		} else if (v[0].second == v[1].second) {
			ar[v[0].first][(v[0].second + 1) % n] = '*';
			ar[v[1].first][(v[1].second + 1) % n] = '*';
		} else {
			ar[v[0].first][v[1].second] = '*';
			ar[v[1].first][v[0].second] = '*';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ar[i][j];
			}
			cout << endl;
		}

		v.clear();
	}

}