#include<iostream>
#include<string>
#include<vector>
using namespace std;

void backtrack(const vector<string>& , int );

vector<string> x; //The solution vector
bool possible = false;

int main()
{
int t;
vector< vector<string> > vec;

cin>>t;

//cout<<t;
  for(int i=0;i<t;i++) {
          int num;
          cin>>num;
          vector<string> temp;
                         
                         for(int j=0;j<num;j++)
                                 {
                                               string str;
                                               cin>>str;
                                               //cout<<str<<endl;
                                               temp.push_back(str);              
                                 }
                         vec.push_back(temp);
          }
  
//cout<<vec[0][0];
//string str = vec[0][0];
//cout<<str.substr(str.length() -1,1);

for(int i=0;i<t;i++){
        backtrack(vec[i],0);
        
        if(possible==true)
                       cout<<"Ordering is possible."<<endl;
        else
                       cout<<"The door cannot be opened."<<endl;
 
        possible=false;
              
}

system("Pause");
return 0;
}


bool isAllowed(string candidate, int pos)
{
           if(pos!=0){
          string str = x[pos-1];
          //cout<<str.substr(str.length()-1,1);
          
          if(str.substr(str.length()-1,1)!=candidate.substr(0,1))
                 return false;
          }
          
          for(int i=0;i<pos;i++)
                  if(x[i]==candidate) return false;
          
          return true;
}


void backtrack(const vector<string>& vec, int pos)
{
     if(pos==vec.size())
                        {
                                    possible=true;
                                    return;
                        }
        
      //cout<<vec[pos]<<endl;
     //int i=0;
     //cout<<vec.size()<<endl;
     int lim = vec.size();
     
      for(int i=0;i<lim;i++)
                {
                                       if(possible==true)
                                                        return; 
                                                        
                                     if(isAllowed(vec[i],pos)==true)
                                              {    
                                                   if(x.size()<pos+1) x.resize(pos+1); 
                                                   x[pos]=vec[i];
                                                   backtrack(vec,pos+1);                                
                                              }
                                      
                                               
                }                   
}
