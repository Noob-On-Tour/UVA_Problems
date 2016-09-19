#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, p[30011], cnt[30011];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}


void merge(int x, int y) {
    x = p[x], y = p[y];
    if (cnt[x] > cnt[y]) {
        p[y] = x;
        cnt[x] += cnt[y];
    } else {
        p[x] = y;
        cnt[y] += cnt[x];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) p[i] = i, cnt[i] = 1;

        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (find(x) != find(y)) merge(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, cnt[i]);
        }
        printf("%d\n", ans);
    }
}
