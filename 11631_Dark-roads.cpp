#include <bits/stdc++.h>

using namespace std;
#define pb push_back
typedef struct edge {
    int frm, to, len;

    edge(int frm, int to, int len) : frm(frm), to(to), len(len) {}
} edge;

int n, m, x, y, z, p[200001];
vector<edge> edges;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int comp(edge a, edge b) {
    return a.len < b.len;
}

int main() {
    while (true) {
        cin >> m >> n;
        if (!n && !m)break;
        for (int i = 0; i < m; ++i) p[i] = i;
        edges = vector<edge>();
        for (int i = 0; i < n; ++i) {
            cin >> x >> y >> z;
            edges.pb(edge(x, y, z));
        }
        sort(edges.begin(), edges.end(), comp);
        long long ans = 0;
        for (int i = 0; i < edges.size(); ++i) {
            edge e = edges[i];
            int pFrm = find(e.frm), pto = find(e.to);
            if (pFrm != pto)
                p[pFrm] = pto;
            else ans += e.len;
        }
        cout << ans << "\n";
    }
}
