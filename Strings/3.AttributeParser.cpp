#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
class parser{
    int tagcount;
    int pcount,qcount;
    map<string,map<string,string>> tagmap;
    public:
        parser(){
            cin>>pcount>>qcount;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            string lines[pcount],queries[qcount]; 
            for(int i = 0 ;i<pcount;i++){
                getline(cin,lines[i]);
            }
            for(int j = 0 ;j<qcount;j++){
                getline(cin,queries[j]);

            }
            parse(lines);
            runquery(queries);
        }
        void parse(string lines[]){            
            vector<string> prefixes;
            for(int i =0 ; i < pcount;i++){
                map<string,string> attrmap;
                string tag,attr,val;
                stringstream inpstream(lines[i]);
                char ch1,ch2;
                inpstream>>ch1>>tag;
                if(tag[0]=='/'){
                    prefixes.pop_back();
                   
                }
                else{
                    if(tag[tag.size()-1]=='>'){
                    	tag = tag.substr(0,tag.size()-1);
                    
                    }
                    prefixes.push_back(tag);
                    while(inpstream>>attr){
                        char ch3;
                        inpstream>>ch3;
                        string insertval;
                        inpstream>>val;
                        int pos=val.size();
                        pos = val.find('>');
                        if(pos!= -1)
                       		 insertval = val.substr(1,pos-2);
                       	else 
                       		insertval = val.substr(1,val.size()-2);
                        attrmap.insert(make_pair(attr,insertval));   
                    }
                    string tagprefix;
                    tagprefix = strconcat(prefixes);
                    tagmap.insert(make_pair(tagprefix,attrmap));                         
                }                      
            }
        }
        
        string strconcat(vector<string> tokens){
            string temp=tokens[0];
            int count=tokens.size();
            for(int i=1;i<count;i++){
                temp = temp+"."+tokens[i];
            }            
            return temp;
        }
        
        
        void runquery(string Q[]){
            for(int i=0;i< qcount ; i++){
                string query = Q[i];
                int pos = query.find('~');
                if(pos == -1){
                	pos = query.find_last_of('.');
                
                }
                string tagprefix = query.substr(0,pos);
                string attr = query.substr(pos+1);
                map<string,string> attrmap= tagmap[tagprefix];
                map<string,string>::iterator itr=attrmap.find(attr);
                if(itr != attrmap.end()){
                    string attrvalue = attrmap[attr];
                    cout<<attrvalue<<endl;
                }
                else cout<<"Not Found!"<<endl;
            }
            
        }
    
};

int main() {
    new parser();
    return 0;
}
