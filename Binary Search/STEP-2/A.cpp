#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pb push_back
#define sorta(vec) sort(vec.begin(),vec.end())
#define sortd(vec) sort(vec.begin(),vec.end(),greater<int>())
#define pb push_back
#define vll vector<long long int>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds; // find_by_order, order_of_key(0-indexed)
//less , less_equal , greater , greater_equal -> rule for insertion
#define start_execution auto start = std::chrono::high_resolution_clock::now();
#define stop_execution auto stop = std::chrono::high_resolution_clock::now();
#define execution_time auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); cerr<<"Time taken : "<<((long double)duration.count())/((long double)1e9) <<"s"<<endl; 
#define nline "\n"
ll int mod=1e9+7;
void debug(int x)
{
    cout<<"Value Debugged is "<<x<<endl;
}
void debug(vector<int>x)
{
    cout<<"Value Debugged is "<<endl;
    for(auto y:x)
    {
        cout<<y<<" ";
    }
    cout<<endl;
}
ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
int ceil_div(ll int a,ll int b)
{
    int k=a%b;
    if(k>0) return (a/b)+1;
    return a/b;
}
template<class ForwardIterator>
void read(ForwardIterator first,ForwardIterator last) 
{
    while (first != last) 
    {
        cin >> (*first);
        ++first;
    }
}
template<class T>
void read(vector<T> &v) 
{
    read(v.begin(), v.end());
}
#define pii pair<int,pair<int,int>>
//Code starts here


bool fit(ll int n,ll int w,ll int h,ll int mid)
{
    ll int x=mid/w;
    ll int y=mid/h;

    if((x*y)>=n)
    {
        return true;
    }
    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    start_execution
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        ll int w,h,n;
        cin>>w>>h>>n;

        ll int left=0;
        ll int right=1;
        while(fit(n,w,h,right)==false)
        {
            right=right*2;
        }
        while(left+1<right)
        {
            ll int mid=(left+right)/2;
            if(fit(n,w,h,mid))
            {
                right=mid;
            }
            else
            {
                left=mid;
            }
        }
        cout<<right<<endl;
    } 
    stop_execution
    //execution_time
    return 0;
}
