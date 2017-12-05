//(Edit Distance)   str1 = "geek", str2 = "gesek"

#include<iostream>

using namespace std;

int matchStr(string str1,string str2,int m,int n){
	string::iterator it;
	
	for(it=str1.begin();it!=str1.end();it++){
		
	}
}

int main(){
	string str1 = "geek",str2 = "gesek";
	
	int m = str1.length();
	int len = str2.length();
	
	cout<<len-matchStr(str1,str2,m,len);
	
	return 0;	
}


