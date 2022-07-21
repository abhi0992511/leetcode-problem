#include <bits/stdc++.h>
using namespace std;
int main()  
{   
    int line;
    cin>>line;
    float x1, y1, x2, y2, x3, y3;  
     cin>>x1>>y1>>x2>>y2>>x3>>y3;

   float m = (y2 - y1) / (x2 - x1);  
    float n = (y3 - y2) / (x3 - x2);  
  
    if( m == n)  
    {  
     cout<<"1x-1y=0";
    }  
    else  
    {  
    cout<<"0"; 
    }  
  
  
}  