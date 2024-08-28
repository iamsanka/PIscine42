#ifndef RUSH02_H
# define RUSH02_H
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_dict
{
	unsigned long long	number;
	char				*text;

	struct s_dict		*next;
}

t_dict;

t_dict					*parse_dict(char *filename);
char					*convert_number(t_dict *dict, char *number_str);
void					free_dict(t_dict *dict);
int						is_valid_number(char *str);
t_dict					*create_dict_entry(unsigned long long number,char *text);
void					add_dict_entry(t_dict **dict, unsigned long long number,char *text);
char					*trim_whitespace(char *str);
t_dict					*find_dict_entry(t_dict *dict,unsigned long long number);
void					append_str(char **result, const char *str);
void					convert_helper(t_dict *dict, unsigned long long number,char **result);
#endif
