#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

typedef struct s_map_info {
    int lines;
    char empty;
    char obstacle;
    char full;
} t_map_info;

typedef struct s_square {
    int size;
    int row;
    int col;
} t_square;

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *str) {
    while (*str) {
        ft_putchar(*str++);
    }
}

void ft_puterr(char *str) {
    while (*str) {
        write(2, str++, 1);
    }
}

int ft_strlen(char *str) {
    int len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

void *ft_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        ft_puterr("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void ft_free(void *ptr) {
    if (ptr) {
        free(ptr);
    }
}

int ft_min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int ft_atoi(char *str) {
    int num = 0;
    while (*str >= '0' && *str <= '9') {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num;
}

void parse_map_info(char *first_line, t_map_info *map_info) {
    int len = ft_strlen(first_line);
    map_info->full = first_line[len - 1];
    map_info->obstacle = first_line[len - 2];
    map_info->empty = first_line[len - 3];
    first_line[len - 3] = '\0';
    map_info->lines = ft_atoi(first_line);
}

int validate_map(char **map, t_map_info *map_info) {
    int len = ft_strlen(map[0]);
    for (int i = 0; i < map_info->lines; i++) {
        if (ft_strlen(map[i]) != len) return 0;
        for (int j = 0; j < len; j++) {
            if (map[i][j] != map_info->empty && map[i][j] != map_info->obstacle) {
                return 0;
            }
        }
    }
    return 1;
}

void find_largest_square(char **map, t_map_info *map_info, t_square *sq) {
    int rows = map_info->lines;
    int cols = ft_strlen(map[0]);
    int **dp = (int **)ft_malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int *)ft_malloc(cols * sizeof(int));
    }

    int max_size = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == map_info->empty) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = ft_min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
                if (dp[i][j] > max_size) {
                    max_size = dp[i][j];
                    sq->size = max_size;
                    sq->row = i;
                    sq->col = j;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        ft_free(dp[i]);
    }
    ft_free(dp);
}

void fill_square(char **map, t_map_info *map_info, t_square *sq) {
    for (int i = sq->row - sq->size + 1; i <= sq->row; i++) {
        for (int j = sq->col - sq->size + 1; j <= sq->col; j++) {
            map[i][j] = map_info->full;
        }
    }
}

void print_map(char **map, t_map_info *map_info) {
    for (int i = 0; i < map_info->lines; i++) {
        ft_putstr(map[i]);
        ft_putchar('\n');
    }
}

void process_map(char *file) {
    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        ft_puterr("map error\n");
        return;
    }

    char buf[BUF_SIZE];
    int ret = read(fd, buf, BUF_SIZE);
    if (ret <= 0) {
        ft_puterr("map error\n");
        close(fd);
        return;
    }
    buf[ret] = '\0';

    char *lines[BUF_SIZE];
    int i = 0;
    lines[i++] = buf;
    for (char *p = buf; *p; p++) {
        if (*p == '\n') {
            *p = '\0';
            lines[i++] = p + 1;
        }
    }

    t_map_info map_info;
    parse_map_info(lines[0], &map_info);

    if (!validate_map(&lines[1], &map_info)) {
        ft_puterr("map error-\n");
        close(fd);
        return;
    }

    t_square sq = {0, 0, 0};
    find_largest_square(&lines[1], &map_info, &sq);
    fill_square(&lines[1], &map_info, &sq);
    print_map(&lines[1], &map_info);

    close(fd);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        ft_puterr("map error\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        process_map(argv[i]);
        if (i < argc - 1) ft_putchar('\n');
    }

    return 0;
}
