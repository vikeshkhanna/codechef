#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

ifstream in;

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

cout<<strcmp("A","B")<<endl;

string x="Ab";
string y="Ac";
cout<<(x==y)<<endl;

system("Pause");
return 0;
}
