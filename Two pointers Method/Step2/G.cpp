#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define sorta(vec) sort(vec.begin(),vec.end())
#define sortd(vec) sort(vec.begin(),vec.end(),greater<int>())
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds; // find_by_order, order_of_key(0-indexed)
//less , less_equal , greater , greater_equal -> rule for insertion 
 
#define clock_start auto start = std::chrono::high_resolution_clock::now();
#define clock_stop auto stop = std::chrono::high_resolution_clock::now();
#define execution_time auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); cerr<<"Time taken : "<<((long double)duration.count())/((long double)1e9) <<"s"<<endl; 
 
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
 
void add(int s[],int n,string st)
{
    for(int i=0;i<st.size();i++)
    {
        char c=st[i];
        int a=int(c)-97+1;
        s[a]++;
    }
}
void debug(multiset<int>&st)
{
    cout<<"Debugged output"<<endl;
    for(auto x:st)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
 
struct Stack
{
    vector<ll> s,sgcd{0};
    void push(ll x)
    {
        s.push_back(x);
        sgcd.push_back(__gcd(sgcd.back(),x));
    }
    ll pop()
    {
        ll res=s.back();
        s.pop_back();
        sgcd.pop_back();
        return res;
    }
    ll curr_gcd()
    {
        return sgcd.back();
    }
    bool empty()
    {
        return s.empty();
    }
};
Stack s1,s2;
void add(ll x)
{
    s2.push(x);
}
void remove()
{
    if(s1.empty())
    {
        while(!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
bool good()
{
    return __gcd(s1.curr_gcd(),s2.curr_gcd())==1;
    
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast;
    clock_start
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll int n;
        cin>>n;
        vector<ll int>vec(n);
        read(vec);
        ll int left=0;
        ll int cnt=0;
        
        ll int ans=1e18;
        for(ll int right=0;right<n;right++)
        {
            add(vec[right]);
            while(good())
            {
                ans=min(ans,right-left+1);
                remove();
                left++;
            }
        }
        if(ans==1e18)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
 
        
    }
    clock_stop
    execution_time
    return 0;
}
