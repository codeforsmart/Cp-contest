#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
bool ch[8][8];
bool dom[8][8];
vector<ll> tr[8];
ll val[8];
ll sb[8];
void khali()
{
	//f(i,0,8) f(j,0,8) ch[i][j] = 0;
	f(i,0,7) f(j,0,7) dom[i][j] = 0;
	f(i,0,8) val[i]=0;
	//f(i,0,8) sb[i]=i+1;
}

ll co = 0;
ll cou[7]={0};
void dfs(ll a, ll p)
{
	
	if(ch[a][p]==1 || ch[p][a]==1) return;
	ch[a][p]=1;
	//cout<<a<<" "<<p<<endl;
	if(val[a]==0)
	{
		co++;
		val[a] = co;
		co = co%6;
	}
	f(i,0,tr[a].size())
	{
		if(val[tr[a][i]]!=0)
		{
			dom[val[a]][val[tr[a][i]]]=1;
			dom[val[tr[a][i]]][val[a]]=1;
		}
	}
	vector<ll> sb;
	ll a1 = val[a];
	if(dom[a1][a1]==0) sb.pb(a1);
	f(i,1,7)
	{
		if(dom[a1][i]==0 && i!=a1) sb.pb(i);
	}
	
	//f(i,0,sb.size()) cout<<sb[i]<<" ";
	//cout<<endl;
	f(i,0,tr[a].size())
	{
		if(val[tr[a][i]]==0)
		{
			if(sb.size()) 
			{
				val[tr[a][i]] = sb.back();
				//val[tr[a][i]] = ++co;
				//co = co%6;
				dom[val[a]][val[tr[a][i]]]=1;
				dom[val[tr[a][i]]][val[a]]=1;
				sb.pop_back();
			}
		}
		//dfs(tr[a][i],a);
	}

	f(i,0,tr[a].size())
	{
		
		dfs(tr[a][i],a);
	}

}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    khali();
    ll n,m;
    cin>>n>>m;
    f(i,0,8) sb[i]=i+1;
    sb[6]=6;
    ll x,y;
    f(i,0,m)
    {
    	cin>>x>>y;
    	tr[x].pb(y);
    	tr[y].pb(x);
    }
    
    //f(i,1,n+1) dfs(i,0);
    ll ans1 = 0;

    do {
    f(i,0,n) val[i+1] = sb[i];
    		f(i,1,n+1)
		    {
		    	f(j,0,tr[i].size())
		    	{
		    		ll a1 = val[i];
		    		ll a2 = val[tr[i][j]];
		    		dom[a1][a2] = 1;
		    		dom[a2][a1] = 1;
		    	}
		    }
    ll ans = 0;
    f(i,1,7) f(j,1,7) ans+= (dom[i][j])*(1+(i==j));
    ans = ans/2;
    khali();
    ans1 = max(ans,ans1);
  	} while ( std::next_permutation(sb,sb+n) );

    
    cout<<ans1<<endl;
    
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