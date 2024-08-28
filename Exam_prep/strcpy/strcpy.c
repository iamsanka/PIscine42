#include <stdio.h>
char *ft_strcmp(char *s1,char *s2)
{
	int i=0;
	while(s1[i]!= '\0')
	{
		s2[i]=s1[i];
		i++;
	}
	return s2;
}

int main()
{
	char s1[]="Happy";
	char s2[50];
	
	ft_strcmp(s1, s2);
	printf("%s", s2);
}
