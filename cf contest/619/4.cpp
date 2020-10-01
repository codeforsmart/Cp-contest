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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,m,k;
    cin>>n>>m>>k;

    if(k>4*n*m-2*n-2*m)
    {
    	cout<<"NO"<<endl;
    	return 0;
    }
    
    vector< pair<ll,string> > sb;

    f(i,0,n-1)
    {
    	ll j = 0;

    	ll ans = 0;
    	string s = "RDU";
    	while(j+1<m && k>=3)
    	{
    		k-=3;
    		ans++;
    		j++;
    	}
    	if(ans>0) sb.pb(mp(ans,s));

    	s = "";
    	ll mi = min((m-1-j)*3,k);
    	char po2[3] = {'R','D','U'};
    	k-=mi;
    	f(p,0,mi) s+=po2[p];
    	if(mi)sb.pb(mp(1,s));

    	j = m-1;
    	ans = 0;
    	s = "LLLL";

    	while(j-4>=0 && k>=4)
    	{
    		ans++;
    		j-=4;
    		k-=4;
    	}
    	if(ans>0) sb.pb(mp(ans,s));
    //	debug(sb.size());
    	ans = 0;
    	s = "";
    	char po[4]={'L','L','L'};
    	mi = min(j,k);
    	j-=mi;
    	k-=mi;
    	f(p,0,mi) s+=po[p];
    	if(j==0 && k>0 ) 
    		{
    			s+='D';
    			k--;
    			mi++;
    		}
    	
    	if(mi)sb.pb(mp(1,s));
    	// debug(sb.size());
    	// debug(k);
    }


    ll ans = 0;
    string s ="RRRR";

    ll j = 0;
    while(j+4<m && k>=4)
    {
    	k-=4;
    	ans++;
    	j+=4;
    }
    if(ans>0) sb.pb(mp(ans,s));

   	s = "";
    ll mi = min(k,m-1-j);
    k-=mi;
    j+=mi;
    f(i,0,mi) s+='R';
    if(mi) sb.pb(mp(1,s));
    

    s = "LLLL";
    ans = 0;
    while(j-4>=0 && k>=4)
    {
    	k-=4;
    	ans++;
    	j-=4;
    }
    if(ans>0) sb.pb(mp(ans,s));

   	s = "";
    mi = min(k,j);
    k-=mi;
    f(i,0,mi) s+='L';
    if(mi) sb.pb(mp(1,s));
    //debug(k);
    s = "UUUU";
    ans = 0;
    ll i1 = n-1;
    while(i1-4>=0 && k>=4)
    {
    	k-=4;
    	ans++;
    	i1-=4;
    }
    if(ans>0) sb.pb(mp(ans,s));

    s = "";
    mi = min(k,i1);
    k-=mi;
    f(i,0,mi) s+='U';
    if(mi) sb.pb(mp(1,s));


    ll sz = sb.size();
    cout<<"YES"<<endl;
    cout<<sz<<endl;
    f(i,0,sz)
    {
    	cout<<sb[i].ff<<" "<<sb[i].ss<<endl;
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
