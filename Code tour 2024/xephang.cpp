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

const int MAXN = (int) 1e6;
int h[MAXN + 2] , x[MAXN + 2];
int n , q;
vector<int> comp;

int BIT[MAXN + 2];
void update(int pos , int val){
    for(; pos <= comp.size(); pos += pos&-pos) BIT[pos] += val;
    return;
}
int Get(int pos){
    int sum = 0;
    for(; pos; pos -= pos&-pos) sum += BIT[pos];
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> h[i] , comp.push_back(h[i]);
    for(int i = 1; i <= q; ++i) cin >> x[i] , comp.push_back(x[i]);
    sort(comp.begin() , comp.end());
    comp.resize(unique(comp.begin() , comp.end()) - comp.begin());

    for(int i = 1; i <= n; ++i) update(upper_bound(comp.begin(),comp.end(),h[i]) - comp.begin(), 1);
    for(int i = 1; i <= q; ++i){
        cout << Get(upper_bound(comp.begin() , comp.end() , x[i]) - comp.begin()) + 1 << '\n';
        update(upper_bound(comp.begin() , comp.end() , x[i]) - comp.begin() , 1);
    }



}
