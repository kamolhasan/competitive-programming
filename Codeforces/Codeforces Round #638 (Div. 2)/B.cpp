#include <bits/stdc++.h>
using namespace std;

int t, ar[1000], mx, n, k, x, y;
bool f;
set <int> st;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		st.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", ar + i);
			st.insert(ar[i]);
		}

		if (st.size() > k) {
			printf("-1\n");
		} else {
			x = 1;
			while (st.size() != k) {
				if (st.find(x) == st.end()) {
					st.insert(x); 
				}
				x++;
			}

			printf("%d\n", int(n * st.size()));
			for (int i = 0; i < n; i++)
			{
				for (auto it = st.begin(); it != st.end(); ++it) {
					printf("%d ", *it);
				}
			}
			printf("\n");
		}

	}
}