#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if(ac ==2)
	{
		int i=0;
		char ltr;
		while(av[1][i]!='\0')
		{
			if(av[1][i]>='a' && av[1][i]<='m' || av[1][i]>='A' && av[1][i]<='M')
			{
				ltr=av[1][i]+13;
				write(1, &ltr, 1);
			}
			else if(av[1][i]>= 'n' && av[1][i]<='z' || av[1][i]>='N' && av[1][i]<='Z')
			{
				ltr=av[1][i]-13;
				write(1, &ltr, 1);
			}
			else
			{
				write(1, &av[1][i], 1);
			}
			i++;
		}
		write(1, "\n", 1);
	}
}
