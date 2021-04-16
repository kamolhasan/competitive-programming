#include <bits/stdc++.h>
using namespace std;

int t, n, a, b;
char s[200010];
stack<char> T, MT;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", s);
		bool ans = true;
		int ct = 0, cm = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == 'M')cm++;
			else ct++;

			if (cm > ct)ans = false;
		}

		if (ct != (cm + cm))ans = false;

		ct = 0, cm = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == 'M')cm++;
			else ct++;

			if (cm > ct)ans = false;
		}
		
		if (ans) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}

	}
}