string multiply(string str1, string str2) {
        
    int m= str1.length();
    int n= str2.length();
    int  v[m+n];
        
        for(int i=0 ; i<m+n ;i++)
            v[i]=0;

    for(int i= m-1 ; i>=0; i--)
    {
        for(int j= n-1; j>=0; --j)
        {
            int mul = (str1[i] - '0') * (str2[j]-'0');
            int sum= v[i+j+1] + mul;
            v[i+j]+=sum/10;
            v[i+j+1]=sum%10;
        }
    }
 
    string str3;
    for(int i=0 ; i<m+n  ;i++)
    {
        if(str3.length()!=0 || v[i]!=0)
        str3+=to_string(v[i]);
        
    }
    if(str3.length()==0)
        return "0";
    
    
    return str3;
   

    }
