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

const int MAXN = (int) 2e5;
ll f[MAXN + 2][2] = {};
ll sum[MAXN + 2][2] = {};
int cnt[MAXN + 2][2] = {};

int n , m;
int l[MAXN + 2] , r[MAXN + 2] , k[MAXN + 2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> k[i] >> l[i] >> r[i];
        if (k[i] == 0){
            f[l[i]][0]++ , f[r[i] + 1][0]--;
        }
        if (k[i] == 1){
            f[l[i]][1]++ , f[r[i] + 1][1]--;
        }
        if (k[i] == 2){
            sum[l[i]][0] += l[i] - 1;
            sum[r[i] + 1][0] -= l[i] - 1;

            cnt[l[i]][0]++;
            cnt[r[i] + 1][0]--;
        }
        if (k[i] == 3) {
            sum[l[i]][1] += l[i] - 1;
            sum[r[i] + 1][1] -= l[i] - 1;

            cnt[l[i]][1]++;
            cnt[r[i] + 1][1]--;
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= 1; ++j){
            f[i][j] += f[i - 1][j];
            sum[i][j] += sum[i - 1][j];
            cnt[i][j] += cnt[i - 1][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << f[i][0] - f[i][1] + (ll)i*cnt[i][0] - sum[i][0] - ((ll)i*cnt[i][1] - sum[i][1]) << ' ';
    }
    
}