// A. Level Statistics solution
// Link: https://codeforces.com/contest/1334/problem/A

#include<bits/stdc++.h>
using namespace std;

int t, n;
pair<int, int> ar[100010];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> ar[i].first >> ar[i].second;
		}

		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (ar[i - 1].first <= ar[i].first && ar[i - 1].second <= ar[i].second) {
				int diff1 = ar[i].first - ar[i - 1].first;
				int diff2 = ar[i].second - ar[i - 1].second;
				if (diff2 > diff1) {
					flag = false;
				}

			} else {
				flag = false;
			}
		}

		if (flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

}