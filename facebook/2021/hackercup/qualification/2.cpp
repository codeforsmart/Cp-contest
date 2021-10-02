#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
ll exp(ll a,ll b,ll m);
vector<ll> tr[26];
ll di[26][26];

void dfs(ll a, ll pr, ll va)
{
    if(di[pr][a]!=-1 && di[pr][a]<=va) return;

    di[pr][a] = va;

    for(auto v: tr[a])
    {
        dfs(v,pr,va+1);
    }
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 
    ll t;
    cin>>t;
    f(tt,1,t+1)
    {
        cout<<"Case #"<<tt<<": ";

        f(i,0,26) tr[i].clear();
        string s;
        cin>>s;
        ll n = s.size();
        ll k;
        cin>>k;
        
        string x;
        f(i,0,k)
        {
            cin>>x;
            tr[x[0]-'A'].pb(x[1]-'A');
        }

        f(i,0,26)
        {
            f(j,0,26)
            {
                di[i][j] = -1;
            }
        }

        f(i,0,26) dfs(i,i,0);

        ll sol = mod;
        f(i,0,26)
        {
            ll ans = 0;
            f(j1,0,n)
            {
                ll j = s[j1] - 'A';
                ans += di[j][i];
                if(di[j][i]==-1)
                {
                    ans=-1;
                    break;
                }
            }

            if(ans!=-1) sol = min(sol,ans);
        }

        if(sol==mod) sol = -1;
        cout<<sol<<endl;

    }

     
return 0;
}
 
ll exp(ll a,ll b,ll m)
{
    if(b==0)
    {
        return 1;
    }
    ll temp =exp(a,b/2,m);
    temp=(temp*temp)%m;
    if(b&1)
    {
        return (temp*(a%m))%m;
    }
    return temp;
}
