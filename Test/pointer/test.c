#include <stdio.h>

void ft_test(int *a)
{
	

	printf("%p \n", a);
	printf("%d", *a);
}

int main()
{
	int num2=10;
	int *num1;
	num1=&num2;
	
	char ch= 'a';
	char *cha= "hello";
	
	printf("num %d \n", num2);
	printf("num %p \n", num1);
	printf("num %d \n", *num1);
	
	printf(" %s \n", cha);
	
	ft_test(num1);
		
	
	
	return 0;
}


