#include <bits/stdc++.h>            
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// template<typename T>
// using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*   in log(n) time...
    find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
    order_of_key()  - The number of items in a set that are strictly smaller than our item
    // Rest same as set
*/
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 2e18
#define minf -2e18
#define PI 3.141592653589793238462
#define ll long long
#define lld long double
#define all(x) x.begin(), x.end()
#define min3(a, b, c) min(min(a, b), c)
#define max3(a, b, c) max(max(a, b), c)
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define ub upper_bound
#define lb lower_bound
#define sz(v) (ll)v.size()
#define nline "\n"

/*----------------------------Setting up the debugger---------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
  
void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/* -----------------------------------------------------------------------------*/

ll powr(ll a, ll b, ll p) { if(b == 0) return 1; else if(b == 1) return a; else if(!(b & 1)) return powr((a * a) % p, b / 2, p); else return (a * powr(a, b - 1, p)) % p; }
ll gcd(ll a, ll b){ if(b == 0) return a; else return gcd(b, a % b); }
ll lcm(ll a, ll b){ return a * b / gcd(a, b); }
void extendgcd(ll a, ll b, ll *v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return (arr[0] + b) % b ; } //for non prime b 
ll mod_inv(ll a, ll p){ return powr(a,p-2,p); } /*For prime p  "Fermet lill theorem"*/
ll mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return ((a + b) % m + m) % m; }
ll mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return ((a * b) % m + m) % m; }
ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return ((a - b) % m + m) % m; }
ll mod_div(ll a, ll b, ll m) { a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m) + m) % m; } /*For prime p*/
// void swap(ll &a, ll &b) { ll temp = a; a = b; b = temp; }
ll spf(ll n) { for(ll i = 2; i * i <= n; i++) { if(n % i == 0) return i; } return n; }/* spf in sqrt(n) time... */
vector<ll> fact_modp(ll n, ll p) { vector<ll> fact(n + 1); fact[0] = 1; for(ll i = 1; i <= n; i++){ fact[i] = (i * fact[i - 1]) % p; } return fact; }
/*For prime p "Fermet lill theorem..."*/
ll nCr_modp(ll n, ll r, ll p, vector<ll> fact) {  if(n < r) return 0; if(r == 0) return 1; else { return ((fact[n] * mod_inv(fact[r], p)) % p * mod_inv(fact[n - r], p)) % p; } }


vector<ll> prime_sieve(ll n) { /*Returns vector of prime <= n  in nloglogn time*/
    vector<ll> t;
    vector<bool> a(n + 1, true);
    a[0] = a[1] = false;
    for(ll i = 2; i * i <= n; i++) {
        if(a[i]) {
            for(ll j = i * i; j <= n; j += i)
            a[j] = false;
        }
    }
    for(ll i = 0; i <= n; i++) {
        if(a[i])
        t.push_back(i);
    }
    return t;
}
vector<ll> spf_sieve(ll n) { /*Returns vector of spf[n] in nloglogn time*/
    vector<ll> a(n + 1, -1);
    for(ll i = 2; i * i <= n; i++) {
        if(a[i] == -1) {
            a[i] = i;
            for(ll j =i * i; j <= n; j += i) { if(a[j] == -1) a[j] = i;}
        }
    }
    for(ll i = 2; i <= n; i++) { if(a[i] == -1) a[i] = i;}
    return a;
}
     /* --------------------------------------Template ends, Dee codes---------------------------------------*/


int main()
{
    fastio();

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif


    int tests = 1;
    cin >> tests;                  
    while(tests--)
    {
       string s;  cin>>s ;
       int n=s.size();
       vector<int> v1,v2;
       for(int i=0;i<n-1;i++){
           if(s[i]=='a' && a[i-1]=='b')
           v1.push_back(i);
           else if(s[i]=='b' && s[i]=='a')
           v2.push_back(i);
       }
       if(v1.size()>v2.size())
       {
           s1[v1[0]]='b';
       }
       else if(v1.size()<v2.size()){
           s1[v1[0]]='b';
       }
       for(int i=0;i<n;i++)
       cout<<s[i];
    }
  return 0;
}



