#include<bits/stdc++.h>
using namespace std;

#define d 256
#define q 3001
void rabinKarp(string txt, string pat)
{
   int n=txt.length();
   int m=pat.length();

   int h=1;
   for(int i=0; i<m-1 ;i++)
   {
       h=(h*d)%q;
   }
   int p=0,t=0;
   for(int i=0; i<m ;i++)
   {
       p=(p*d+pat[i])%q;
       t=(t*d+txt[i])%q;
   }
   
   for(int i=0; i<=n-m ; i++)
   {
         if(t==p)
         {
             int j=0;
             for(j=0; j<m ; j++)
             {
                 if(txt[i+j]!=pat[j])
                 {
                     break;
                 }
             }
             
             if(j==m)
             {
                 cout<<i<<" ";
             }
         }
         if(i<n-m)
         {
             t=(d*(t-txt[i]*h)+txt[i+m])%q;
             if(t<0)
             {
                 t+=q;
             }
         }
   }


}

int main()
{
    string txt,pat;
    cin>>txt>>pat;
    rabinKarp(txt,pat);
}
