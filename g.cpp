#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back


void funofdiv()
{
   ll n,m,x,y,z,i,j,k,l = 0, sum=0,ans=0;
   cin>>n;
   map<ll,vector<ll>>mp;
   map<string, ll>mp2;
   for(i=0;i<n;i++)
   {
      ll time;
      string s;
      string key;
      ll userid;
      cin >> time >> s >> key >> userid;
      z=0;
      for(j=0;j<key.size();j++)
      {
         if(key[j]>=65 && key[j]<=90)
         {
            continue;
         }
         else if (key[j] >=97 &&key[j]<=122)
         {
            continue;
         }
         else if (key[j] >=48 &&key[j]<=57)
         {
            continue;
         }
         else
         {
            z=1;
            break;
         }
      }
      if (z==1 || key.size()<2) 
      {
         cout<<"NO\n";
         continue;
      }
      if(s.size()>=7 && s.substr(0,7)=="http://")
      {

      }
      else if(s.size()>=8 && s.substr(0,8)=="https://")
      {

      }
      else
      {
         cout<<"NO/n";
         continue;
      }

      if (mp[userid].size() > 0 && mp[userid][0]+5>time)
      {
         cout<<"NO\n";
         continue;
      }

      if(mp2[key]==1)
      {
         cout<<"NO\n";
         continue;
      }
      
      cout<<"YES\n";
      mp2[key]=1;
      if(mp[userid].size()==0)
      {
         mp[userid].pb(time);
      }
      else
      {
         mp[userid][0]=time;
      }
   }

}

signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n =1;
   
   while(n--)
   {
      funofdiv();
   }
   return 0;
}
