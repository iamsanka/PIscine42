#include <unistd.h>
 
int main(int ac,  char **av)
{
	if(ac==2)
	{
		int ltr;
		int rpt;
		while(av[1][ltr]!='\0')
		{
			if(av[1][ltr]>='a' && av[1][ltr]<='z')
				rpt=av[1][ltr]-'a';
			else if(av[1][ltr]>='A' && av[1][ltr]<='Z')
				rpt=av[1][ltr]-'A';
			while(rpt>=0)
			{
				write(1,&av[1][ltr], 1);
				rpt--;
			}
			ltr++;
		}
		write(1, "\n", 1);
	}
}
