#include<iostream>

int main(){
	int a[] = {1, 2, 3, 4, 4, 5, 6, 6, 6, 7};
	int i,len=(sizeof(a)/4)-1,lastNum ,midNum;
	//printf("length=%d\n",len);
	lastNum = a[len];
	//printf("lastNum=%d\n",lastNum);
	if(lastNum%2 != 0)
	{	
	midNum = (lastNum/2)+1;
	//printf("midNum=%d\n",midNum);
	for(i=0;i<len;i++)
	{
		if(a[i]==midNum){
			//printf("Matched..");
			printf("%d\n",a[i]);
			printf("1");
			return i;
		}
	}
	}
	else
	    printf("-1");
}
