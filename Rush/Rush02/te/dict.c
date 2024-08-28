#include "rush02.h"

// dict
t_dict	*create_dict_entry(unsigned long long number, char *text)
{
	t_dict	*entry;

	entry = malloc(sizeof(t_dict));
	if (!entry)
		return (NULL);
	entry->number = number;
	entry->text = strdup(text);
	entry->next = NULL;
	return (entry);
}

void	add_dict_entry(t_dict **dict, unsigned long long number, char *text)
{
	t_dict	*new_entry;

	new_entry = create_dict_entry(number, text);
	if (!new_entry)
		return ;
	new_entry->next = *dict;
	*dict = new_entry;
}

char	*trim_whitespace(char *str)
{
	char	*end;

	while (*str == ' ' || *str == '\t')
		str++;
	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		*end-- = '\0';
	return (str);
}

t_dict	*parse_dict(char *filename)
{
	int					fd;
	t_dict				*dict;
	char				*line;
	char				buffer[4096];
	int					bytes_read;
	int					line_len;
	char				*pos;
	char				*endline;
	char				*colon;
	unsigned long long	number;
	char				*text;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	dict = NULL;
	line = NULL;
	line_len = 0;
	while ((bytes_read = read(fd, buffer + line_len, 4096 - line_len)) > 0)
	{
		buffer[bytes_read + line_len] = '\0';
		pos = buffer;
		while ((endline = strchr(pos, '\n')))
		{
			*endline = '\0';
			line = strdup(pos);
			pos = endline + 1;
			if (line)
			{
				colon = strchr(line, ':');
				if (colon)
				{
					*colon = '\0';
					number = atoll(trim_whitespace(line));
					text = trim_whitespace(colon + 1);
					if (*text != '\0')
						add_dict_entry(&dict, number, text);
				}
				free(line);
			}
		}
		line_len = strlen(pos);
		memmove(buffer, pos, line_len);
	}
	close(fd);
	if (bytes_read < 0 || !dict)
	{
		free_dict(dict);
		return (NULL);
	}
	return (dict);
}
// convert

t_dict	*find_dict_entry(t_dict *dict, unsigned long long number)
{
	while (dict)
	{
		if (dict->number == number)
			return (dict);
		dict = dict->next;
	}
	return (NULL);
}
void	append_str(char **result, const char *str)
{
	size_t	new_len;

	new_len = (*result ? strlen(*result) : 0) + strlen(str) + 2;
	*result = realloc(*result, new_len);
	if (!*result)
		return ;
	strcat(*result, str);
	strcat(*result, " ");
}
void	convert_helper(t_dict *dict, unsigned long long number, char **result)
{
	t_dict	*entry;
	t_dict	*entry;

	if (number == 0)
	{
		append_str(result, "zero");
		return ;
	}
	/*if (number >= 1000000000000000000000000000000000000)
	{
		convert_helper(dict, number / 1000000000000000000000000000000000000,
			result);
		append_str(result, "undecillion");
		number %= 1000000000000000000000000000000000000;
	}
	if (number >= 1000000000000000000000000000000000)
	{
		convert_helper(dict, number / 1000000000000000000000000000000000,
			result);
		append_str(result, "decillion");
		number %= 1000000000000000000000000000000000;
	}
	if (number >= 1000000000000000000000000000000)
	{
		convert_helper(dict, number / 1000000000000000000000000000000, result);
		append_str(result, "nonillion");
		number %= 1000000000000000000000000000000;
	}
	if (number >= 1000000000000000000000000000)
	{
		convert_helper(dict, number / 1000000000000000000000000000, result);
		append_str(result, "octillion");
		number %= 1000000000000000000000000000;
	}
	if (number >= 1000000000000000000000000)
	{
		convert_helper(dict, number / 1000000000000000000000000, result);
		append_str(result, "septillion");
		number %= 1000000000000000000000000;
	}
	if (number >= 1000000000000000000000)
	{
		convert_helper(dict, number / 1000000000000000000000, result);
		append_str(result, "sextillion");
		number %= 1000000000000000000000;
	}*/
	if (number >= 1000000000000000000)
	{
		convert_helper(dict, number / 1000000000000000000, result);
		append_str(result, "quintillion");
		number %= 1000000000000000000;
	}
	if (number >= 1000000000000000)
	{
		convert_helper(dict, number / 1000000000000000, result);
		append_str(result, "quadrillion");
		number %= 1000000000000000;
	}
	if (number >= 1000000000000)
	{
		convert_helper(dict, number / 1000000000000, result);
		append_str(result, "trillion");
		number %= 1000000000000;
	}
	if (number >= 1000000000)
	{
		convert_helper(dict, number / 1000000000, result);
		append_str(result, "billion");
		number %= 1000000000;
	}
	if (number >= 1000000)
	{
		convert_helper(dict, number / 1000000, result);
		append_str(result, "million");
		number %= 1000000;
	}
	if (number >= 1000)
	{
		convert_helper(dict, number / 1000, result);
		append_str(result, "thousand");
		number %= 1000;
	}
	if (number >= 100)
	{
		convert_helper(dict, number / 100, result);
		append_str(result, "hundred");
		number %= 100;
	}
	if (number >= 20)
	{
		entry = find_dict_entry(dict, (number / 10) * 10);
		if (entry)
			append_str(result, entry->text);
		number %= 10;
	}
	if (number > 0)
	{
		entry = find_dict_entry(dict, number);
		if (entry)
			append_str(result, entry->text);
	}
}
char	*convert_number(t_dict *dict, char *number_str)
{
	unsigned long long	number;
	char				*result;

	number = atoll(number_str);
	result = NULL;
	convert_helper(dict, number, &result);
	if (result)
	{
		result[strlen(result) - 1] = '\0';
		// Remove trailing space
	}
	return (result);
}
// free
void	free_dict(t_dict *dict)
{
	t_dict	*current;

	while (dict)
	{
		current = dict;
		dict = dict->next;
		free(current->text);
		free(current);
	}
}
