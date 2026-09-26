#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define MASK(x) ((ll)(1)<<(x))
#define BIT(mask , x) (((mask)>>(x))&(1))
#define sz(x) (int)(x).size()

template<class T1, class T2>
    bool maximize(T1 &x , T2 y){
        if (x < y) return x = y , true;
        return false;
    }
template<class T1, class T2>    
    bool minimize(T1 &x , T2 y){
        if (x > y) return x = y , true;
        return false;
    }

void solve(){
    int n , k; cin >> n >> k;
    vector<int> a(n + 2 , 0);
    ll ans = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i];    
    vector<int> b(n + 2 , 0);
    int tmp = 0;
    if (n - k + 1 >= k){
        for(int i = k; i <= n - k + 1; ++i) ans += a[i];
        for(int i = 1; i < k; ++i) b[++tmp] = a[i];
        for(int i = n - k + 2; i <= n; ++i) b[++tmp] = a[i];
    }
    else b = a , tmp = n;
    n = tmp;
    
        for(int i = n - k + 1 , t = k; i >= 1; --i , ++t) {
            ans += max(b[i] , b[t]);
            // cout << i << ' ' << t << '\n';
        }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    int test; cin >> test;
    while (test--) solve();
}