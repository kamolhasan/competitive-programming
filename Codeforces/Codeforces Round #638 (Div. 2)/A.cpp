#include <bits/stdc++.h>
using namespace std;

long long t, n, a, b, two[40];
bool f;

void pre() {
	two[1] = 2;
	for (int i = 2; i < 31; i++) {
		two[i] = two[i - 1] * 2;
	}

}

int main() {
	pre();
	cin >> t;
	while (t--) {
		cin >> n;
		a = b = 0;
		for (int i = 1; i < n / 2; i++) {
			a += two[i];
		}
		for (int i = n / 2; i < n; i++) {
			b += two[i];
		}
		a += two[n];

		cout<<a-b<<endl;

	}
}