#include <unistd.h>

int main(int ac, char **av)
{
	int i=0;
	char ltr;
	if(ac==2)
	{
		while(av[1][i]!='\0')
		{
			if(av[1][i]>='a' && av[1][i]<='y')
			{
				ltr=av[1][i]+1;
				write(1, &ltr, 1);
			}else if(av[1][i]=='z')
			{
				ltr='a';
				write(1,&ltr, 1);
			}else if(av[1][i]>='A' && av[1][i]<='Y')
			{
				ltr=av[1][i]+1;
				write(1, &ltr, 1);
			}else if(av[1][i]=='Z')
			{
				ltr='A';
				write(1,&ltr, 1);
			}else{
				write(1, &av[1][i], 1);
			}
			i++;
		} 
	}
}
