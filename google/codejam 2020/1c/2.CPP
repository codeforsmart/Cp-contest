#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
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

    	ll u;
        cin>>u;
        ll n = 10000;
        string a[n],b[n];

        f(i,0,n) cin>>a[i]>>b[i];

        ll co[26]={0};
        ll nz[26]={0};

        ll bap[26]={0};
        f(i,0,26) bap[i] =10;
        vector< pair<ll,ll> > msm[26];
        ll szz[n]={0};
        f(i,0,n)
        {
            ll sz = b[i].length();
            szz[i] = sz;
            ll sa = a[i].length();
            if(sa==sz)
            {
                ll op = a[i][0]-'0';
                bap[b[i][0]-'A'] = min(bap[b[i][0]-'A'],op);
                nz[b[i][0]-'A']++;
                msm[b[i][0]-'A'].pb(mp(i,1));
            }
            else if(a[i]=="-1")
            {
                nz[b[i][0]-'A']++;
            }

            f(j,0,sz) co[b[i][j]-'A']++;
        }
        vector<ll> sb;
        f(i,0,26)
        {
            if(co[i]) sb.pb(i);
        }

        ll sz = sb.size();

        ll va[10];
        f(i,0,10) va[i] = -1;

       /* f(i,0,26)
        {
            cout<<bap[i]<<" ";
        }
        cout<<endl;*/
        set<pair<ll,ll> > ai;
        f(i,0,sz)
        {
            if(bap[sb[i]]>0)
            {
                ai.insert(mp(bap[sb[i]],sb[i]));
            }
        }

        ll ass = 1;
        ll zer = 0;

        bool ok[26]={0};
        while(ai.size())
        {
            auto vv = ai.begin();
            ll val = vv->ff, ind = vv->ss;
            if(zer==0 && nz[ind]==0)
            {
                va[0] = ind;
                ok[ind] = 1;
            }
            else
            {
                va[ass] = ind;
                ok[ind] = 1;
                ass++; 
            }
            ai.erase(vv);
        }
        vector<ll> re;
        f(i,0,sz)
        {
            if(ok[sb[i]]==0) re.pb(sb[i]);
        }

        f(i,0,26)
        {
            if(co[i]==0) re.pb(i);
        }
    /*f(i,0,re.size()) cout<<re[i]<<" ";
    cout<<endl;*/
        ll indd = 0;
        ll check=-1;

        if(va[0]==-1)
        {
            f(i,0,re.size())
            {
                if(nz[re[i]]==0) 
                {
                    va[0] = re[i];
                    cout<<re[i]<<endl;
                    check=re[i];
                    break;
                }
            }
        }
        f(i,1,10)
        {
            //cout<<check[re[indd]]<<endl;
            //cout<<va[i]<<endl;
            //debug(re[indd]);
            if(va[i]==-1)
            {
                if(re[indd]==check) indd++;
               /// cout<<"aya"<<endl;
                va[i] = re[indd];
                indd++;
            }
        }
/*
        f(i,0,sz) 
        {   char an = sb[i]+ 'A';
            cout<<an;
        }
        cout<<endl;*/
        f(i,0,10)
        {
            char an = va[i]+ 'A';
            cout<<an;
        }
        cout<<endl;
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
