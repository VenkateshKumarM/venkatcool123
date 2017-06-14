#include<iostream>
#include<string>
using namespace std;

int findCharVal(char a){
	int i;
	char arr[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
	for(i=0;i<26;i++) {
	 	if(a == arr[i]) {
	 		return i;	
		 }	 	
	}
}

int main() {
	int i,a[27],wc=0,maxheight=0,height,total;
	string str;
	for(i=0;i<26;i++)
		cin>>a[i];
	cin>>str;
	wc=str.length();
	for(i=0;i<str.length();i++) {
		height = a[findCharVal(str.at(i))];
		if(maxheight<height)	{
			maxheight = height;	
		}				
	}
	total = maxheight*wc*1;
	cout<<total;
}
