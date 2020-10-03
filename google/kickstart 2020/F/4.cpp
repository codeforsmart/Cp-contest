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


ll n,m,k;
ll gc = 0;

ll c[100];

vector< vector<ll> > sb;
vector<ll> b;
ll dif(vector<ll> a)
{
    ll n1 = a.size();
    ll n2 = b.size();

    ll nm = max(n1,n2);

    ll a1[nm]={0},b1[nm]={0};

    f(i,0,n1) a1[nm-i-1] = a[n1-i-1];
    f(i,0,n2) b1[nm-i-1] = b[n2-i-1];

    ll ans = 0;
    f(i,0,nm) ans+=abs(a1[i]-b1[i]);

    return ans/2;
}
void pre(ll ind,vector<ll> a)
{
    if(ind==n) 
        {
            sb.pb(a);
            return;
        }

    f(i,1,m+1)
    {
        a.pb(i);
        pre(ind+1,a);
        a.pop_back();
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

    ll t1 = 0;

   // cout<<"ok"<<endl;
    while(t--)
    {
    	t1++;

    	cout<<"Case #"<<t1<<": ";
        cin>>n>>m>>k;
        
        b.clear();
        f(i,0,k) 
        {
            cin>>c[i];
            b.pb(c[i]);
        }
        

        sb.clear();

        vector<ll> te;
        pre(0,te);

        ll sz = sb.size();

        //cout<<sz<<endl;

        ll ans = 0;

        f(i,0,sz)
        {
            vector<ll> aa;
            vector<ll> mn = sb[i];
            ll com[m+1]={0};

            f(j,0,n) com[mn[j]]++;

            f(j,1,m+1)
            {
                if(com[j])
                {
                    aa.pb(com[j]);
                }
            }

            sort(aa.begin(),aa.end());
            ll di = dif(aa);
           /*if(di==1)
            {
                for(auto v:aa) cout<<v<<" ";
                cout<<endl;
           // cout<<di<<endl;
            }*/
            ans+=di;
        }

        ans*=(m*(m-1));
        double pr = 1.0;

        debug(ans);
        debug(sz);
        pr += double(ans)/double(sz);
        cout<<pr<<endl;


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
