#include <unistd.h>

int main()
{
	char i[]="see the world";
	
	char *ptr=i;
	
	
	write(1, ptr, 1);
}	
