//Substring "abcabcbb", "pwwkew"
#include<stdio.h>
#include<stdlib.h>

int lengthOfNonRepeatingCharacters(char* str){
	int i,curr_len=1,max_len=1,prev_index;
	
	int* visited = (int *)malloc(sizeof(int)*256);
	
	for(i=0;i<256;i++){
		visited[i] = -1;
	}
	
	visited[str[0]] = 0;
	
	for(i=1;str[i]!='\0';i++){			
		prev_index = visited[str[i]];
		
		if(visited[str[i]] == -1 || i-curr_len > prev_index)
			curr_len++;
		else{
			if(curr_len>max_len)
				max_len = curr_len;
			
			curr_len = i- prev_index;	
		}
		
		visited[str[i]] = i;		
	}
	if(curr_len>max_len)
		max_len = curr_len;
	
	free(visited);	
	return max_len;
}

int main(){
	char str[] = "abcabcbb";
	
	printf("%d",lengthOfNonRepeatingCharacters(str));
}
