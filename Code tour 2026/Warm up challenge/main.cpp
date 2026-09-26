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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) ; cout.tie(0) ;

    if (fopen("main.inp","r")){
        freopen("main.inp","r",stdin);
        freopen("main.out","w",stdout);
    }

    
}