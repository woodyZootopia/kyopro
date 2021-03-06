#include <bits/stdc++.h>
using namespace std;

#define pq priority_queue
#define mp make_pair
#define cauto const auto &

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define clr(ar, val) memset(ar, val, sizeof(ar))

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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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

int main() {
    ll n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 1) {
        cout << m - 2 << endl;
        return 0;
    }
    if (m == 1) {
        cout << n - 2 << endl;
        return 0;
    }
    cout << (n - 2) * (m - 2) << endl;
    return 0;
}
