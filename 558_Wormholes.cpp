#include <bits/stdc++.h>

using namespace std;
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define OO INT_MAX
typedef long long ll;
typedef struct edge {
    int src, to, w;

    edge(int src, int to, int w) : src(src), to(to), w(w) {}
} edge;
ll C, N, M, dist[1001];
vector<bool> n;

bool bellmanFord(vector<edge> graph) {
    for (int i = 0; i < N; ++i) dist[i] = OO;
    dist[0] = 0;
    //get All pair shortest path
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            edge e = graph[j];
            if (dist[e.src] + e.w < dist[e.to]) dist[e.to] = dist[e.src] + e.w;
        }
    }
    //get the negative cycle
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            edge e = graph[j];
            if (dist[e.src] + e.w < dist[e.to]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios;
    cin >> C;
    for (int cases = 0; cases < C; ++cases) {
        cin >> N >> M;
        vector<edge> graph;
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.pb(edge(u, v, w));
        }
        n.pb(bellmanFord(graph));
    }
    for (int i = 0; i < C; ++i) n[i] == 1 ? cout << "possible\n" : cout << "not possible\n";
}
