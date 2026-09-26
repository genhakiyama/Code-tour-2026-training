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
int id[MAXN + 2] , h[MAXN + 2] , v[MAXN + 2];
int n;

pair<ll,int> st[MAXN * 4 + 2] = {};
void update(int id , int l , int r , int pos , pair<ll,int> val){
    if (l == r) st[id] = val;
    else {
        int m = (l + r) / 2;
        if (pos <= m) update(id * 2 , l , m , pos , val);
            else update(id * 2 + 1 , m + 1  , r , pos , val);

        st[id] = max(st[id * 2] , st[id * 2 + 1]);
        return ;
    }
}

pair<ll,int> get(int id , int l , int r , int u , int v){
    if (l > v || r < u) return {0,0};
    if (u <= l && r <= v) return st[id];
    int m = (l + r) / 2;
    return max(get(id * 2 , l , m , u , v) , get(id * 2 + 1 , m + 1 , r , u , v));
}

pair<ll,int> result[MAXN + 2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
        id[i] = i;
    }
    for(int i = 1; i <= n; ++i) cin >> v[i];

    sort(id+1,id+n+1,[&](int i , int j){
        if (h[i] != h[j]) return h[i] < h[j];
        return i < j;
    });
    pair<ll,int> ans = {0 , 0};

    for(int i = 1 , ptr = 1; i <= n; ++i){
        while (ptr <= i && h[id[ptr]] < h[id[i]]) {
            update(1 , 1 , n , id[ptr] , result[id[ptr]]);
            ++ptr;
        }        
        pair<ll,int> t = get(1,1,n,1,id[i]);

        // cout << id[i] << ' ' << t.first + v[id[i]] << ' ' << t.second + 1 << '\n';

        result[id[i]].first = t.first+ v[id[i]];
        result[id[i]].second = t.second + 1;
        ans = max(ans , result[id[i]]);
    }

    cout << ans.first << ' ' << ans.second;
}