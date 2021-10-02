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
 
int main()
{
 //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
     #ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 
    ll t;
    cin>>t;
    ll t1 = 0;
    while(t--)
    {
        t1++;
        cout<<"Case #"<<t1<<": ";
        ll n;
        cin>>n;
        string s;
        cin>>s;

        //cout<<n<<endl;
        //continue;
        s = "a" + s;
        ll ans = 0;

        ll dp[2][3];
        dp[0][0] = 0;
        dp[0][1]=0;
        dp[0][2] = 0;
        
        ll ex = 0;
        ll lans = 0;
        f(i,1,n+1)
        {
            ll i1 = i%2;
            ll i2 = (i-1)%2;
            if(s[i]=='F')
            {
                dp[i1][0] = dp[i2][0]+1;
                dp[i1][1] = dp[i2][1];
                dp[i1][2] = dp[i2][2];
                ex = 0;
            }
            else if(s[i]=='X')
            {
                dp[i1][0] = 0;
                dp[i1][1] = 0;
                dp[i1][2] = dp[i2][2]+dp[i2][1]+dp[i2][0]+1;
                ex = dp[i2][1];
            }
            else
            {
                dp[i1][0] = 0;
                dp[i1][1] = dp[i2][2]+dp[i2][1]+dp[i2][0]+1;
                dp[i1][2] = 0;
                ex = dp[i2][2];
            }
            lans = lans + ex;
            ans += lans;


            dp[i1][0] = dp[i1][0]%mod;
            dp[i1][1] = dp[i1][1]%mod;
            dp[i1][2] = dp[i1][2]%mod;

            lans = lans%mod;
            ans = ans%mod;
        }

        cout<<ans<<endl;

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
