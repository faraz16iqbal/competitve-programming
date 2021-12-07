#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int MOD = 1e9 + 7;

using mpii = map<int, int>;
#define int long long
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<int> vi;
typedef priority_queue<pii, vector<pii>, greater<pii>> pqii;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class T2> inline int cmax(T &x, const T2 &y) { return x < y ? x = y, 1 : 0; }
template<class T, class T2> inline int cmin(T &x, const T2 &y) { return x > y ? x = y, 1 : 0; }
int modpow(int x, int n, int m = MOD) {int res = 1; while (n > 0) {if (n & 1)res = (res * x) % m; x = (x * x) % m; n >>= 1;} return res;}
int binpow(int x, int n) { int res = 1; while (n > 0) {if (n & 1)res = res * x; x = (x * x); n >>= 1;} return res;}
int modinv(int x, int m = MOD) {return modpow(x, m - 2, m);}
int add(long long a, long long b) {return ((a % MOD) + (b % MOD)) % MOD;}
int subt(long long a, long long b) {return ((a % MOD) - (b % MOD)) % MOD;}
int mult(long long a, long long b) {return ((a % MOD) * (b % MOD)) % MOD;}
int divmod(int a, int b, int m) {a = a % m; int inv = modinv(b, m); int c = (inv * a) % m ; return c;}
int gcd(int a, int b) {while (b > 0) {a %= b; swap(a, b);} return a;}
string intobinary(int n) {return bitset<8>(n).to_string();}
#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
      cerr << #x << " ";                                                           \
      _print(x);                                                                   \
      cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
// void _print(int double t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(stack <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue <T> v) {cerr << "[ "; while (v.size()) {_print(v.front()); cerr << " "; v.pop();} cerr << "]";}
template <class T> void _print(deque <T> v) {cerr << "[ "; while (v.size()) {_print(v.front()); cerr << " "; v.pop_front();} cerr << "]";}
template <class T> void _print(stack <T> v) {cerr << "[ "; while (v.size()) {_print(v.top()); cerr << " "; v.pop();} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
double eps = 1e-12;
#define forn(i, e) for (int i = 0; i < e; i++)
#define forsn(i, s, e) for (int i = s; i < e; i++)
#define ln "\n"
#define pb push_back
#define eb emplace_back
const int INF = 2e18;
#define fast_cin()                                                             \
          ios_base::sync_with_stdio(false);                                            \
          cin.tie(NULL);                                                               \
          cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
const int MX = 5e18;
const int N = 2e5 + 5;

void run_cases() {
}
signed main() {
    fast_cin();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int tests = 1;
    cin >> tests;
    for (int i = 1; i <= tests; i++) {
        // cout << "Case #" << i << ": ";
        run_cases();
    }
    return 0;
}
