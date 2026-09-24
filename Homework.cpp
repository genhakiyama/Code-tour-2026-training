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

const int MAXN = (int) 5000;
const ll inf = (ll)1e18;
int cur = 0 ;

void solve(){
    int n , k , d; 
    cin >> n >> k >> d;
    ++cur;

    vector<int> t(n + 2 , 0) , a(k + 2 , 0) , b(k + 2 , 0);

    for(int i = 1; i <= n; ++i) cin >> t[i];
    for(int i = 1; i <= k; ++i) cin >> a[i];
    for(int i = 1; i <= k; ++i) cin >> b[i];

    auto get_cost = [&](int l , int r) -> ll{
        if (t[l] == t[r]) return b[t[l]];
        return a[t[r]];
    };

    vector<ll> pre(n + 2, 0);
    vector<int> prev_pos(n + 2 , 0) , pos(k + 2 , 0);

    for(int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + get_cost(i - 1 , i);
        prev_pos[i] = pos[t[i]];
        pos[t[i]] = i;
    }

    vector<deque<int>> bucket(2 , deque<int>());
    vector<vector<ll>>dp(n + 2 , vector<ll>(2 , inf));
    vector<vector<deque<int>>> bag(2 , vector<deque<int>>(k + 1 , deque<int>()));

    auto get_sub_cost = [&](int i , int t){
        return dp[i][t] - pre[i];
    };

    for(int i = 1; i <= n; ++i) {

        int min_j = i - d;
        while (bucket[0].size() && bucket[0].front() < min_j) bucket[0].pop_front();
        while (bucket[1].size() && bucket[1].front() < min_j) bucket[1].pop_front();
        
        if (bucket[0].empty()) {
            dp[i][0] = pre[i - 1] + a[t[i]];
        }
        else {
            int j = bucket[0].front();
            dp[i][0] = dp[j][1] + pre[i - 1] - pre[j] + get_cost(j - 1 , i);
        }

        if (bucket[1].empty()){
            assert(i <= d + 1);
            dp[i][1] = pre[i - 1] + a[t[i]];
        }
        else {
            int j = bucket[1].front();
            dp[i][1] = dp[j][0] + pre[i - 1] - pre[j] + get_cost(j - 1 , i);
        }

        if (prev_pos[i] < i - 1 ){
            while (bag[0][t[i]].size() && get_sub_cost(prev_pos[i]+1,1) <= get_sub_cost(bag[0][t[i]].back(),1)) bag[0][t[i]].pop_back();
            while (bag[1][t[i]].size() && get_sub_cost(prev_pos[i]+1,0) <= get_sub_cost(bag[1][t[i]].back(),0)) bag[1][t[i]].pop_back();
            bag[0][t[i]].push_back(prev_pos[i] + 1);
            bag[1][t[i]].push_back(prev_pos[i] + 1);
        }

        while (bag[0][t[i]].size() && bag[0][t[i]].front() < min_j) bag[0][t[i]].pop_front();
        while (bag[1][t[i]].size() && bag[1][t[i]].front() < min_j) bag[1][t[i]].pop_front();

        if (bag[0][t[i]].size()){
            int j = bag[0][t[i]].front();
            minimize(dp[i][0] , dp[j][1] + pre[i - 1] - pre[j] + get_cost(j - 1 , i));
        }

        if (bag[1][t[i]].size()){
            int j = bag[1][t[i]].front();
            minimize(dp[i][1] , dp[j][0] + pre[i - 1] - pre[j] + get_cost(j - 1 , i));
        }

        if (prev_pos[i] == i - 1){
            while (bag[0][t[i]].size() && get_sub_cost(prev_pos[i]+1,1) <= get_sub_cost(bag[0][t[i]].back(),1)) bag[0][t[i]].pop_back();
            while (bag[1][t[i]].size() && get_sub_cost(prev_pos[i]+1,0) <= get_sub_cost(bag[1][t[i]].back(),0)) bag[1][t[i]].pop_back();
            bag[0][t[i]].push_back(prev_pos[i] + 1);
            bag[1][t[i]].push_back(prev_pos[i] + 1);
        }

        while (bucket[0].size() && get_sub_cost(bucket[0].back(),1) >= get_sub_cost(i,1)) bucket[0].pop_back();
        while (bucket[1].size() && get_sub_cost(bucket[1].back(),0) >= get_sub_cost(i,0)) bucket[1].pop_back();
        bucket[1].push_back(i);
        bucket[0].push_back(i);
    }

    ll ans = inf;
    
    for(int i = max(0 , n - d); i < n; ++i) {
        minimize(ans , dp[i + 1][0] + pre[n] - pre[i + 1]);
        minimize(ans , dp[i + 1][1] + pre[n] - pre[i + 1]);
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
    while(test--) solve();
    return 0;
}
