#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int c, r;
map<string, string> p;
map<string, int> cnt;

string find(string x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}


void merge(string x, string y) {
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
    ios_base::sync_with_stdio(false);
    cin.tie();
    while (1) {
        cin >> c >> r;
        if (!c && !r) break;
        cnt.clear();
        p.clear();
        for (int i = 0; i < c; ++i) {
            string s;
            cin >> s;
            p[s] = s, cnt[s] = 1;
        }

        for (int i = 0; i < r; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            if (find(s1) != find(s2)) merge(s1, s2);
        }
        int ans = 1;
        for (map<string, int>::iterator i = cnt.begin(); i != cnt.end(); i++) {
            ans = max(ans, i->second);
        }
        cout << ans << "\n";
    }
}
