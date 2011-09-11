#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

ifstream in;

void backtrack(const vector<string>& , int );

vector<string> x; //The solution vector
bool possible = false;

int main()
{
int t;
in.open("data.txt");
vector< vector<string> > vec;

in>>t;

//cout<<t;
  for(int i=0;i<t;i++) {
          int num;
          in>>num;
          vector<string> temp;
                         
                         for(int j=0;j<num;j++)
                                 {
                                               string str;
                                               in>>str;
                                               //cout<<str<<endl;
                                               temp.push_back(str);              
                                 }
                         vec.push_back(temp);
          }
  
//cout<<vec[0][0];
//string str = vec[0][0];
//cout<<str.substr(str.length() -1,1);

for(int i=0;i<t;i++){
        vector<string> temp = vec[i];
       
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
          for(int i=0;i<pos;i++)
                  if(x[i]==candidate) return false;
          
          if(pos!=0){
          string str = x[pos-1];
          //cout<<str.substr(str.length()-1,1);
          
          if(str.substr(str.length()-1,1)!=candidate.substr(0,1))
                 return false;
          }
          
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
                                     if(isAllowed(vec[i],pos)==true)
                                              {    
                                                   if(x.size()<pos+1) x.resize(pos+1); x[pos]=vec[i];
                                                   backtrack(vec,pos+1);                                
                                              }
                                      
                                      if(possible==true)
                                                        return;            
                }                   
}
