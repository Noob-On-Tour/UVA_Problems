#include <bits/stdc++.h>

using namespace std;
#define OO (LLONG_MAX-INT_MAX)
#define mp make_pair
#define pb push_back
#define sz(x) ((ll)(x.size()))

typedef long long ll;

ll N, n, m, S, T, dist[20001], visit[20001];

class prioritize {
public:
    bool operator()(pair<ll, ll> &p1, pair<ll, ll> &p2) { return p1.second > p2.second; }
};

ll dijkstra(vector<pair<ll, ll>> *g, ll S, ll T) {
    for (ll i = 0; i < n; ++i) dist[i] = OO;
    memset(visit, 0, sizeof(visit));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, prioritize> pq;
    pair<ll, ll> frm, cur;
    pq.push(mp(S, dist[S] = 0));
    while (!pq.empty()) {
        frm = pq.top(), pq.pop();
        if (visit[frm.first])continue;
        visit[frm.first] = 1;
        for (ll i = 0; i < sz(g[frm.first]); ++i) {
            cur = g[frm.first][i];
            if (!visit[cur.first] && cur.second + frm.second < dist[cur.first]) {
                dist[cur.first] = cur.second + frm.second;
                pq.push(mp(cur.first, dist[cur.first]));
            }
        }
    }
    return dist[T];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
    cin >> N;
    for (ll cases = 1; cases <= N; ++cases) {
        memset(dist, 0, sizeof(dist));
        memset(visit, 0, sizeof(visit));
//        g->clear();
        vector<pair<ll, ll> > g[20001];
        cin >> n >> m >> S >> T;
        for (ll i = 0; i < m; ++i) {
            ll u, v, w;
            cin >> u >> v >> w;
            g[u].pb(mp(v, w)), g[v].pb(mp(u, w));
        }
        ll dist = dijkstra(g, S, T);
        dist < OO ? cout << "Case #" << cases << ": " << dist << endl :
        cout << "Case #" << cases << ": unreachable" << endl;
    }
}
