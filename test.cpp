#include<bits/stdc++.h>

using namespace std;
using ll= long long;

#define pb push_back

vector<vector<ll>>dp;
vector<ll>w,v;


void disp(vector<ll>v){
    for(auto el:v) cout<<el<<" ";
    cout<<"\n";
}
void disp(vector<vector<ll>>v){
    for(auto el:v) disp(el);
}
void changeDp(ll i,ll j,ll v){
    dp[i][j]=v;
    cout<<"\nState of dp for W="<<j<<"and i="<<i<<":\n";
    disp(dp);
    cout<<"\n";
}


// ll dpSolve(ll n, ll W){
//     if(dp[n][W]!=-1){
//         return dp[n][W];
//     }

//     ll k=max(dpSolve(n-1,W-w[n])+v[n],dpSolve(n-1,W));
//     changeDp(n,W,k);
//     return dp[n][W];
// }

ll dpSolve(ll n,ll W){
    
    if(W<=0) return 0;
    if(n<=0) return 0;
    dp[0][0]=0;
    for(ll i=0;i<=W;++i){
        if(i<w[0]){
            dp[0][i]=0;
        }
        else dp[0][i]=v[0];
    }

    for(ll j=0;j<n;++j){
        dp[j][0]=0;
    }

    for(ll i=1;i<n;++i){
        for(ll j=1;j<=W;++j){
            if(j-w[i]>=0){
                dp[i][j]=dp[i-1][j-w[i]]+v[i];
            }
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
    }
    return dp[n-1][W];
}

void solve(){
    ll N,W;
    cin>>N>>W;
    for(ll i=0;i<N;++i){
        vector<ll>a;
        for(ll j=0;j<=W;++j) a.pb(-1);
        dp.pb(a);

        ll wi,vi;
        cin>>wi>>vi;
        w.pb(wi);
        v.pb(vi);
    }
    ll ans=dpSolve(N,W);
    cout<<ans<<"\n";
}


int main(){
    solve();
    return 0;
}