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

const int MAXLOG = 4;

void solve(){
    int n; cin >> n;
    int q; cin >> q;
    vector<int> arr(n + 2 , 0);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        ans += __builtin_popcount(arr[i]) % 2 == 0;
    }
    cout << ans << ' ';
    while(q--){
        int p , x; cin >> p >> x;
        ans -= __builtin_popcount(arr[p]) % 2 == 0;
        arr[p] = x;
        ans += __builtin_popcount(arr[p]) % 2 == 0;
        cout << ans << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    int test; cin >> test;

    vector<int> build = {3 , 6 , 9 , 12 , 15};
    set<int> st;
    for(int i = 0; i < MASK(build.size()) - 1; ++i){
        int tot = 0;
        for(int j = 0; j < build.size(); ++j) if (BIT(i , j)) tot ^= build[j];
        st.insert(tot);
    }


    while(test--) solve();
    return 0;
}