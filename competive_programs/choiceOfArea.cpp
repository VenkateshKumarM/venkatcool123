//Choice of Area

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Area {
	int a;
	int b;
	
	Area(int A,int B){
		a = A;
		b = B; 
	}
};

int max(int A,int B,int C){
	return max(max(A,B),C);
}


int choiceOfArea(int A,int B,Area X,Area Y, Area Z,int choice,int count){
	
	//cout<<choice;
	
	if(A>=0 && B>=0 && count !=0){
		return count;
	}
	
			switch(choice){
			case 1:
				A += X.a;
				B += X.b;
				count++;
				cout<<"X count"<<count<<" ";
				cout<<"A,B"<<A<<" "<<B<<"\n";
				if(count)
					return max(choiceOfArea(A,B,X,Y,Z,2,count),choiceOfArea(A,B,X,Y,Z,3,count));
				else
					return 0;
				break;
			case 2:
				A += Y.a;
				B += Y.b;
				count++;
				cout<<"Y count"<<count<<" ";
				cout<<"A,B"<<A<<" "<<B<<"\n";
				if(count)
					return max(choiceOfArea(A,B,X,Y,Z,1,count),choiceOfArea(A,B,X,Y,Z,3,count));
				else 
					return 0;
				break;
			case 3:
				A += Z.a;
				B += Z.b;
				count++;
				cout<<"Z count"<<count<<" ";
				cout<<"A,B"<<A<<" "<<B<<"\n";
				if(count)
					return max(choiceOfArea(A,B,X,Y,Z,1,count),choiceOfArea(A,B,X,Y,Z,2,count));
				else 
					return 0;
				break;				
		}
	
	
	
}



int main(){
	
	Area X(3,2), Y(-5,-10), Z(-20,5);
	
	int A=20,B=8;
	
	if(A<0 || B<0)
		cout<<-1;
	else
		cout<<max(choiceOfArea(A,B,X,Y,Z,3,0), choiceOfArea(A,B,X,Y,Z,2,0), choiceOfArea(A,B,X,Y,Z,1,0))-1;
	
	return 0;
}
