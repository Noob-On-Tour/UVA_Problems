#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
typedef struct edge {
    int src, to, c;

    edge(int src, int to, int c) : src(src), to(to), c(c) {}
} edge;
int n, k, p[1000001], line = 0;
ll m;
vector<edge> edges;

int comp(edge a, edge b) {
    return a.c < b.c;
}

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
    while (scanf("%d", &n) == 1) {
        ll w = 0, t = 0;
        for (int i = 1; i < n; ++i) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            t += z;
            p[i] = i;
        }
        p[n] = n;
        scanf("%d", &k);
        edges = vector<edge>();
        for (int i = 0; i < k; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges.pb(edge(x, y, z));
        }
        scanf("%lld", &m);
        for (int i = 0; i < m; ++i) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges.pb(edge(x, y, z));
        }
        sort(edges.begin(), edges.end(), comp);
        for (int i = 0; i < edges.size(); ++i) {
            edge e = edges[i];
            int pF = find(e.src), pT = find(e.to);
            if (pF != pT) p[pF] = pT, w += e.c;
        }
        if (line) puts("");
        printf("%lld\n%lld\n", t, w);
        line = 1;
    }
}
