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

const int MAXN = (int) 1e5;
vector<int> adj[MAXN + 2];
int n;
int x[MAXN + 2] , y[MAXN + 2] , trace[MAXN + 2];
bool used[MAXN + 2];

vector<int> cycle;

bool find_cycle(int u , int p){
    used[u] = true;
    for(int id : adj[u]){
        int v = x[id] ^ y[id] ^ u;
        if (v == p) continue;

        if (used[v] == false) {
            trace[v] = u;
            if (find_cycle(v , u)) return true;
        }
        if (used[v]){
            int tmp = u;
            while (tmp != v) {
                cycle.push_back(tmp);
                tmp = trace[tmp];
            }
            cycle.push_back(v);
            return true;
        }
    }
    return false;
}

int ans = 0;
int sub[MAXN + 2] = {};

void max_length(int u , int p){
    used[u] = true;
    sub[u] = 1;
    int mx1 = 0 , mx2 = 0;
    for(int id : adj[u]){
        int v = x[id] ^ y[id] ^ u;
        if (v == p) continue;
        if (used[v]) continue;
            max_length(v , u);
            if (mx1 < sub[v]) {
                mx2 = mx1;
                mx1 = sub[v];
            }
            else maximize(mx2 , sub[v]);
            maximize(sub[u] , sub[v] + 1);
    }
    ans = max(ans , mx1 + mx2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        adj[x[i]].push_back(i);
        adj[y[i]].push_back(i);
    }

    find_cycle(1,0);
    memset(used , false , sizeof(used));
    for(auto&  x: cycle) used[x] = true;
    for(auto& x : cycle) max_length(x , 0);
    int t = cycle.size();
    for(int i = 0; i < t; ++i) cycle.push_back(cycle[i]);
    // for(auto& x : cycle) cout << x << ' '; cout << '\n';
    multiset<int> st;
    for(int i = 0; i < cycle.size(); ++i){
        if (i - t >= 0) {
            st.erase(st.find(sub[cycle[i - t]] - (i - t)));
        }
        if (st.size()) ans = max(ans , sub[cycle[i]] + i + *st.rbegin() - 1);
        ans = max(ans , sub[cycle[i]]);
        // if (st.size() && i - t >= 0)  cout << sub[cycle[i]] + i << ' ' << *st.rbegin() << ' ' << cycle[i] << ' ' << sub[cycle[i]] - i << ' ' << cycle[i - t] << '\n';
        st.insert(sub[cycle[i]] - i);
    }
    cout << ans;
}