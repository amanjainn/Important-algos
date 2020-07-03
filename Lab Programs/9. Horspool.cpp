/*
 Author : AMAN JAIN
 DATE: 04-07-2020

 PROGRAM ->  Horspool algorithm

   O(n/m) time in the best case.
   O(mn) time in worst case

    The worst case occurs when all characters of the text and pattern are same. For example, txt[] = “AAAAAAAAAAAAAAAAAA” and pat[] = “AAAAA”.
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 500 //declaring the size of the index table

int  index_table[MAX];   //global array for shift table


void shift_table(string ptr){  //function to find the position of each character in the shift table

    int length=ptr.length();

    for(int i=0; i<MAX ;i++){
        index_table[i]=length;      //initializing the value of shift table with the length of pattern
    }

    for(int i=0 ;i<length-1 ; i++){  //calculating the position of each character using the formula length-index-1
     index_table[ptr[i]]=length-i-1;
    }

}

int horspool(string str,string ptr){

    int str_length=str.length();
    int pat_length=ptr.length();

    int index=pat_length-1;
    int k;
    while(index<str_length)//continue the search until we match the last index of pattern with the
    {
        k=0;
        while(k<pat_length && ptr[pat_length-k-1] == str[index-k])
        {
            k++;
        }
        if(k==pat_length)
            return (index-pat_length+1); //return the first index
        else
            index+=index_table[str[index]];//if char doesnt match we will increase the index using the shift table
    }
    return -1;
}

int main()
{
    string str,pat;
    int pos;
    getline(cin,str);
    getline(cin,pat);
    shift_table(pat);

    int position= horspool(str,pat);
    if(horspool(str,pat)==-1)
    cout<<"Pattern Not found"<<endl;

    else
    cout<<"Pattern Found at "<<position+1;
}
