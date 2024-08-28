void ft_putchar(char c);

void rush(int x, int y)
{
	//for the negative numbers, function shuldn't return anything
	if (x <= 0 || y <= 0)
	{
		return;
	}
	.
	
	//Declare variables
	int i;
	int j;

	i = 0;
	j = 0;

	/*
	breakdown:
	upper left corner -/ 
	upper right corner - \
	lower left corner - \
	lower right corner - /
	rest - *
	middle space - space
	*/
	
	while (i < y)
	{
		while (j < x)
		{
			
			
				if (i == 0 && j == 0)
				{
					ft_putchar('/');
				}
				else if((i == 0 && j == x-1) || (i == y-1 && j == 0))
				{
					ft_putchar('\\');
				}
				else if (i == y - 1 && j == x - 1)
				{
					ft_putchar('/');
				}
				else if (i == 0 || i == y - 1)
				{
					ft_putchar('*'); 
				}
				else if (j == 0 || j == x - 1)
				{
					ft_putchar('*'); 
				}
				else
				{
					ft_putchar(' '); 
				}
						
			
			j++;
		}
		i++;
		ft_putchar('\n');
		j=0;
		
	}
    
}


