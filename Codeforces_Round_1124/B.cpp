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

const int MAXN = (int)800;
const int MAXSTEP = 30 * 3;
bool ok[MAXN + 2][MAXN + 2];

ll digit_sum(int k){
    ll res = 0;
    while(k){
        res += (k % 10) * (k % 10);
        k/=10;
    }
    return res ;
}

bool check(int x , int y){
    int step = 0;
    while (x != y && step <= MAXSTEP) {
        x = digit_sum(x);
        y = digit_sum(y);
        ++step;
    }
    return x == y;
}


void solve(){
    int n; cin >> n;
    vector<int> a(n + 2 , 0);
    ll ans = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if (a[i] == a[j]) ++ans;
            else {
                int t1 = digit_sum(a[i]);
                int t2 = digit_sum(a[j]);
                if (t1 > t2) swap(t1,t2);
                if (ok[t1][t2]) ++ans;
            }
        }
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

    for(int i = 1; i <= 800; ++i){
        for(int j = i; j <= 800; ++j){
            ok[i][j] = check(i,j);
        }
    }  
  
    while(test--) solve();
    return 0;
}