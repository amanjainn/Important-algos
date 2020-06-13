/*

Name : AMAN JAIN
DATE: 13-06-2020

*/


#include<bits/stdc++.h>
using namespace std;

int R,C;

void printMat(char arr[][100]){
    for(int i=0 ; i<R; i++){
        for(int j=0 ; j<C; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int dx[] ={-1,0,1,0};
int dy[] ={0,-1,0,1};

void floodFill(char input[][100], int i, int j,char ch, char color){
    if(i<0 || j<0 || i>=R || j>=C)
     return ;

    if(input[i][j]!=ch)
    return ;

    input[i][j]=color;

    for(int k=0 ;k<4 ; k++){
        floodFill(input,i+dx[k],j+dy[k],ch,color);
    }

}

int main(){

   cin>>R>>C;

   char input[100][100];

   for(int i=0 ; i<R; i++){
       for(int j=0 ; j<C;j++){
           cin>>input[i][j];
       }
   }

   floodFill(input,1,1,'.','*');
   printMat(input);

}
