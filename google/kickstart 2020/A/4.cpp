#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lll long long int
#define ll int
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
    while(t--)
    {
    	t1++;
    	cout<<"Case #"<<t1<<": ";
    	ll n,k;
    	cin>>n>>k;
    	string s5[n];
        ll le[n]={0};
        ll len = 0;
        f(i,0,n)
        {
            cin>>s5[i];
            le[i] = s5[i].length();
            len = max(len,le[i]);
        }
        map< pair<ll,string> , ll > sb;
        lll ans = 0;
    	f(j,0,len)
        {   set<string> msm;
            f(i,0,n)
            {
                if(le[i]<=j) continue;
                string s1 = s5[i].substr(0,j+1);
                sb[mp(-j-1,s1)]++;
                msm.insert(s1);
            }
            set<string> msm2;
            for(auto st: msm)
            {
                ll lp = st.length();
                ll co = sb[mp(-lp,st)];
                sb[mp(-lp,st)] = (co/k)*k;
                if((co/k)*k==0)
                {
                    sb.erase(mp(-lp,st));
                }
                if(lp==1) continue;
                string sh = st;
                sh.pop_back();
                sb[mp(-lp+1,sh)]-=(co/k)*k;
                msm2.insert(sh);
            }

            for(auto st: msm2)
            {
                ll lp = st.length();
                ll co = sb[mp(-lp,st)];
                ans += (co/k)*lp;
               
                sb.erase(mp(-lp,st));
            }
        }
        
        for(auto v:sb)
        {
            ll ans1 = v.ss/k;
       
            ll le = -v.ff.ff;
          
            ans+=ans1*le;
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
