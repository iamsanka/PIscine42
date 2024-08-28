#include "rush02.h"


int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	*number;
	char	*result;

	if (argc == 2)
	{
		dict = parse_dict("numbers.dict");
		number = argv[1];
	}
	else if (argc == 3)
	{
		dict = parse_dict(argv[1]);
		number = argv[2];
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!dict || !is_valid_number(number))
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	result = convert_number(dict, number);
	if (result)
	{
		write(1, result, strlen(result));
		write(1, "\n", 1);
		free(result);
	}
	else
	{
		write(1, "Dict Error\n", 11);
	}
	free_dict(dict);
	return (0);
}
