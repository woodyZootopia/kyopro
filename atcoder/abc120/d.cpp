#include <bits/stdc++.h>
using namespace std;

#define pq priority_queue
#define mp make_pair
#define cauto const auto &

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define clr(ar, val) memset(ar, val, sizeof(ar))

typedef long long int64;
typedef long long lint;
typedef long long lli;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

typedef pair<int, int> pint;
typedef pair<long, long> plong;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

const int iinf = 1 << 29;
const long long linf = 1ll << 61;

template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T = int> T in() {
    T x;
    cin >> x;
    return (x);
}
template <class T> void print(T &x) {
    cout << x << '\n';
    return;
}

template <class T> ll iterate_sized_subset(T &comb) {
    T x = comb & -comb, y = x + comb;
    return ((comb & ~y) / x) >> 1 | y;
}

struct union_find {
    int size;
    vector<int> par;
    union_find(int N) : size(N), par(N) { REP(i, N) par[i] = i; }
    int root(int x) {
        if (par[x] == x)
            return x;
        else {
            par[x] = root(par[x]);
            return par[x];
        }
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        else {
            par[rx] = ry;
            return;
        }
    }
    bool same(int x, int y) { return root(x) == root(y); }
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll solve(union_find t) {
    map<int, int> m;
    REP(i, t.size) {
        if (m.find(t.root(i)) == m.end()) {
            m[t.root(i)] = 1;
        } else {
            m[t.root(i)]++;
        }
    }
    ll ans = 0;
    for (auto ite = m.begin(); ite != m.end(); ite++) {
        auto itebuf = ite;
        for (auto ite2 = ++itebuf; ite2 != m.end(); ite2++) {
            ans += ite->second * ite2->second;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int from[m], to[m];
    union_find t(n);
    REP(i, m) { cin >> from[i] >> to[i]; }
    ll ans[m];
    ans[0] = 0;
    REP(i, m) {
        int j = m - i - 1;
        if (t.same(from[j] - 1, to[j] - 1)) {
            ans[j] = -1;
        } else {
            ans[j] = solve(t);
        }
        t.unite(from[j] - 1, to[j] - 1);
    }

    REP(i, m - 2) {
        int j = m - i - 1;
        if (ans[j] == -1)
            ans[j] = ans[j + 1];
    }
    REP(i, m) { cout << (ans[i] == -1 ? 0 : ans[i]) << endl; }
    return 0;
}
