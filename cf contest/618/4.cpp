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
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll exp(ll a,ll b,ll m);
ll dis(pair<ll,ll> f1, pair<ll,ll> f2)
{
    ll ans = (f1.ff-f2.ff)*(f1.ff-f2.ff) + (f1.ss-f2.ss)*(f1.ss-f2.ss);
    return ans;
}
bool ang(pair<ll,ll> f1, pair<ll,ll> f2, pair<ll,ll> f3, pair<ll,ll> f4)
{
    if((f1.ff-f2.ff)*(f3.ss-f4.ss) == (f3.ff-f4.ff)*(f1.ss-f2.ss) )return 1;
    return 0;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

   #ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;
    vector< pair<ll,ll> > sb;
    ll x1,y;
    f(i,0,n)
    {
      cin>>x1>>y;
      sb.pb(mp(x1,y));
    }
    
    if(n%2==1)
    {
      cout<<"NO"<<endl;
      return 0;
    }
    
    bool ans = 1;

    ll x = n/2;

    f(i,0,x)
    {
        //debug(ans);
        ll i1 = i, i2 = i+1, i3 = x+i, i4 = (i2+x)%n;
       // cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<endl;
       // cout<<dis(sb[i1],sb[i2])<<endl;
       // cout<<dis(sb[i3],sb[i4])<<endl;
        if(dis(sb[i1],sb[i2])!=dis(sb[i3],sb[i4])) ans = 0;

         if(ang(sb[i1],sb[i2],sb[i3],sb[i4])==0) ans = 0;
         if(ans==0) break;
    }

    if(ans)
    {
      cout<<"Yes"<<endl;
    }
    else cout<<"NO"<<endl;
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
