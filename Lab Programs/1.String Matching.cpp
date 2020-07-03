/*
 Author : AMAN JAIN
 DATE: 03-07-2020

 PROGRAM ->  Implement brute force String matching algorithm. 


Time complexity :  Overall Time complexity O(n*m)

1. Best Case O(m) (where m is the length of the pattern) -> Total number of comparisions (m)
2. Worst Case O(n*m) (Where n is the  length of the string and m is the length of the pattern)  -> total numberof comparisions  (n-m+1)

*/

#include<iostream>
using namespace std;

int stringMatch( string str, string pat){
   int len1=str.length();
   int len2=pat.length();
 
  for(int i=0 ; i<=len1-len2 ; i++){
        int j=0;
        while(str[i+j]==pat[j])
            j++;

       if(j==len2)
       return i;     
   }
   return -1;
}



int main(){
 string str,pat;
 cin>>str>>pat;

  if(stringMatch(str,pat)==-1)
    cout<<"Match failed"<<endl;
  else 
    cout<<"Match found starting from "<<stringMatch(str,pat);

}