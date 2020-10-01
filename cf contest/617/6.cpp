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

    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    ll pr[n];
    f(i,0,n) pr[i] = -1;
    
    ll co[26]={0};
    f(i,0,26) co[i] = -1;
    f(i,0,n) co[s[i]-'a'] = i;
    
    f(i,0,26)
    {
    	if(co[i]==-1) continue;
    	for(ll j = co[i];j>=0;j--)
    	{
    		if(pr[j]==-1)
    		{
    			ll nu = s[j]-'a';
    			if(nu==i) pr[j] = 1;
    			else pr[j] = 0;
    		}
    	}
    }

    string s1 = "";
    f(i,0,n)
    {
    	if(pr[i]==0)
    	{
    		s1+=s[i];
    	}
    }
    bool ans = 0;
    ll cou = 2;
    
    string s2 = s1,s3;
    sort(s2.begin(),s2.end());
        
    if(s1==s2)
    {
        ans = 1;
    }
    ll col[26]={0};
    f(i,0,n)
    {
        if(ans) break;
        ll sz = s1.size();
        if(sz==0)
        {
            ans =1;
            break;
        }
        bool ok = 0;
        f(p,0,sz) 
        {
            ll po = s1[p]-'a';
            if(po==i) ok = 1;
        }

        if(ok==0) continue;

        ll st = sz;
        f(j,0,sz)
        {
            ll nu2 = s1[j]-'a';
            if(nu2==i) st = i;
            else break;
        }
        s3 = "";
        f(j,st+1,sz) s3+=s1[j];
        s1 = "";
        ll sz2 = s3.size();
        f(j,0,sz2)
        {
            ll po = s1[j]-'a';
            if(po!=i)
            {
                s1+=s3[j];
            }
        }
        if(s1==s3) continue;

        col[i]=cou;
        cou++;
       
    }
    bool mi = 0;
    f(i,0,n) 
    {   if(pr[i]==0) mi = 1;
        if(pr[i]==0) pr[i] = col[s[i]-'a'] + cou*(col[s[i]-'a']==0);
    }
    if(mi==0) cou--;
    cout<<cou<<endl;
    f(i,0,n) cout<<pr[i]<<" ";
    cout<<endl;
    
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
