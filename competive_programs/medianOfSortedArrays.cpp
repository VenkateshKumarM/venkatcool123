//Median of two Sorted Arrays;

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
int main(){
	
	vector<int> arr1,arr2,arr3;
	int i,val,n1,n2,n3,n4;
	
	float sum;
	
	cout<<"Enter n1 val:";
	cin>>n1;
	
	cout<<"Enter n2 val:";
	cin>>n2;
	
	cout<<"List1:";
	for(i=0;i<n1;i++){
		cin>>val;
		arr1.push_back(val);
	}
	
	cout<<"List2:";	
	for(i=0;i<n2;i++){
		cin>>val;
		arr2.push_back(val);
	}
	
	n3 = (arr1.size()+arr2.size());
	
	vector<int>::iterator v1 = arr1.begin();
	vector<int>::iterator v2 = arr2.begin();
	
	while(v1!=arr1.end() && v2!=arr2.end() ){
		if(*v1<*v2){
			arr3.push_back(*v1);
			v1++;
		}
		else {
			arr3.push_back(*v2);
			v2++;
		}
	}
	
	while(v1!=arr1.end()){
		arr3.push_back(*v1);
		v1++;
	}
	
	while(v2!=arr2.end()){
		arr3.push_back(*v2);
		v2++;
	}
	
	vector<int>::iterator v3 = arr3.begin();
	
/*	cout<<"\n";
	
	while(v3!=arr3.end()){
		cout<<*v3<<" ";
		v3++;
	}*/
	
	if(n3%2 == 0){
		n4 = n3/2;		
		sum = ((float)arr3[n4-1]+arr3[n4])/2;
	}
	else{
		n4 = n3/2;
		sum = arr3[n4];
	} 
	
	cout<<"Median Val:"<<sum; 
}
