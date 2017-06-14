
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
    string time,hour,meridiem;
    
    int hr;

    cin >> time;    
    
  	hour = time.substr(0,2);
    
    meridiem = time[8];
	meridiem += time[9];
	
	if(meridiem == "PM"){
		hr = stoi(time[0]);
		hr += 12;
	}
        
    cout<<"Hour:"<<hr;
    cout<<"Meridiem:"<<meridiem; 
    return 0;
}

