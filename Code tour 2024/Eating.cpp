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
const ll inf = (ll)2e18;

void solve(){
    int n; cin >> n;
    vector<ll> a(n + 2 , 0);
    vector<ll> pre(n + 2 , 0);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    vector<ll> f(n + 2 , -inf);
    vector<ll> left(n + 2 , -inf);
    for(int i = n; i >= 1; --i){
        f[i] = max(f[i + 1] , a[i] - pre[i - 1]);
    }
    for(int i = 1; i <= n; ++i) left[i] = max(left[i - 1] , a[i] + pre[i]);

    ll current = 1;
    
    for(int i = 1; i <= n; ++i){
        if (current - pre[i - 1] >= f[i]){
            ll x = current + pre[n] - pre[i - 1];
            if (x + pre[i - 1] >= left[i - 1]) {
                return void(cout << "YES\n");
            }
        }
    }
    cout << "NO\n";
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    int test; cin >> test;
    while(test--) solve();
    return 0;
}
