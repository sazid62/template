
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(x) x.begin(), x.end()
#define pb push_back

const int N = 1e3;

int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {

  }
  return 0;
}

 
 


phi…
void phi_1_to_N(){
    for(int i = 0; i <= N; i++) phi[i] = i;
    for(int i = 2; i <= N; i++){
        if(phi[i] == i){
            for(int j = i; j <= N; j += i){
                phi[j] -= phi[j] / i;
            }
        }
        phi[i] = phi[i] * phi[i];
        phi[i] += phi[i - 1];
    }
}
 
 
 



 




Power , Multiplication , Inverse
 
#include<iostream>
using namespace std;
long long binmul(long long a, long long b, long long m) {
   long long res = 0LL;
   a = a % m;
   while (b > 0) {
       if (b & 1) res = (res + a) % m;
       a = (a + a) % m;
       b >>= 1;
   }
   return res;
}
long long binpow(long long a, long long b, long long m) {
   a %= m;
   long long res = 1LL;
   while (b > 0) {
       if (b & 1) res = binmul(res , a, m);
       a = binmul(a, a, m);
       b >>= 1;
   }
   return res;
}
long long inverse(long long a, long long p) {
 return binpow(a, p - 2, p);
}
int main(){
   long long a, b, p;
   cin >> a >> b >> p;
   cout << binpow(a, b, p) << '\n';
   cout << binmul(a, b, p) << '\n';
   cout << binmul(a, inverse(b, p), p) << '\n';
   return 0;
}




 ORDERED SET->
 
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  o_set<int> se;
  se.insert(4);
  se.insert(2);
  se.insert(5);
  // sorted set se = [2, 4, 5]
  cout << se.order_of_key(5) << '\n'; // number of elements < 5
  cout << se.order_of_key(6) << '\n'; // number of elements < 6
  cout << (*se.find_by_order(1)) << '\n'; // if you imagine this as a 0-indexed vector, what is se[1]?
  return 0;
}



TERNARY_SEARCH

 #include<bits/stdc++.h>
double ternary_search(double l, double r) {
    double eps = 1e-9;              
    while (r - l > eps) {
        double m1 = l + (r - l) 
        double m2 = r - (r - l)  
        double f1 = f(m1);       
        double f2 = f(m2);      
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                
}




next_permutation

 string s = "CBA";
  for(int mask = 0; mask < pow(2 , s.size()); mask++) {
   for(int i = 0; i < s.size(); i++) {
       if(mask & (1 << i)) cout << s[i];
 
   }
   cout << endl;
  }
 
  do{
   for(int i = 0 ;  i< s.size(); i++) cout << s[i];
   cout << endl;
 
  }while(prev_permutation(s.begin() , s.end()));





NCR->> 

long long nCr(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    

    for(int i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


spf
void  SPF() {
   for(int i = 1; i < N; i++) {
      spf[i] = i;
   }

   for(int i = 2; i < N; i++) {
      if(spf[i] == i) {
         for(int j = i * 2; j < N ; j+= i) {
            spf[j] = min (spf[j] , i);
         }
      }
   }
}



 

hashing
 
int modpow(long long a, long long n, const int m) {
    int r = 1 % m;
    a %= m;
    if(n < 0) a += m;
    while (n) {
        if(n & 1) r = (long long) r * a % m;
        a = (long long) a * a % m;
        n >>= 1;
    }
    return r;
}


const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = modpow(p1, MOD1 - 2, MOD1);
    ip2 = modpow(p2, MOD2 - 2, MOD2);
    ipw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }
}
struct Hashing {
    int n;
    string s;
    vector<pair<int, int>> hs;
    Hashing() {}
    Hashing(string _s) {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for(int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r) {
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<int, int> get_hash() {
        return get_hash(1, n);
    }
}hs, hrs;

// int dp[N][N];
// string s;
// int n;

// int ispalindrome(int i, int j) {
//     return hs.get_hash(i, j) == hrs.get_hash(n - j + 1, n - i + 1);
// }

// int yo(int i, int j) {
//     if(i > j || i >= n || j < 0) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     return dp[i][j] = ispalindrome(i + 1, j + 1) + yo(i, j - 1) + yo(i + 1, j) - yo(i + 1, j - 1);
// }

 
        // string s; cin >> s;
        // string rs = s;
        // reverse(all(rs));
        //  Hashing hs(s), hrs(rs);
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
int a[N];
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  long long t[4 * N], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    t[n] = t[n] + lazy[n] * (e - b + 1);
    if (b != e) {
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) {
    return a + b;
  }
  inline void pull(int n) {
    t[n] = t[lc] + t[rc];
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v; //set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
};
int32_t main() {
    
}

 
