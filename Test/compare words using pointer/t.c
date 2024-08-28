#include <stdio.h>

char compare(char *s1, char *s2)
{
	int i=0;
	while(s1[i] != '\0' && s2[i] != '\0')
	{
		//printf("S1: %c , S2 : %c \n" ,s1[i], s2[i]);
		if(s1[i] != s2[i])
		{
			printf("S1 : %c and S2 : %c so, S1-S2 is : %d \n", s1[i], s2[i], s1[i]-s2[i]);
		}
		i++;
	}	
	//printf("%d", i);
	
	return 'c';
}

int main()
{
	char word1[]="HEll";
	char word2[]="Hello";
	char *word1_p;
	char *word2_p;
	
	word1_p=word1;
	word2_p=word2;
	compare(word1_p, word2_p);
}
