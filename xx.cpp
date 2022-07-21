
string getPhoneNumber(string s) {
    unordered_map<string,int>code;
    code["zero"]=0;
    code["one"]=1;
    code["two"]=2;
    code["three"]=3;
    code["four"]=4;
    code["five"]=5;
    code["six"]=6;
    code["seven"]=7;
    code["eight"]=8;
    code["nine"]=9;
    code["double"]=-2;
    code["triple"]=-3;
    string key="";
    string ans="";
    bool f1=false;
    bool f2=false;
    int a=1;
    for(int i=0;i<s.length();i++)
    {
        
        if(s[i]==' ')
        {
           if(key=="double")
           {
               f1=true;
               
           }
             else if(key=="triple")
           {
               f2=true;
           }
          else if(f1)
           {
               ans+=to_string(code[key])+to_string(code[key]);
               f1=false;
           }
        
           else if(f2)
           {
               ans+=to_string(code[key])+to_string(code[key])+to_string(code[key]);
               f2=false;
           }
           else {
           ans+=to_string(code[key]);
           }
           key="";
    
        }
        else {
        key+=s[i];
        }
        
    }
    ans+=to_string(code[key]);
    return ans;
    
    

}
int main()