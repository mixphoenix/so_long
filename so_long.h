/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenli <ibenli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:43:15 by abmisk            #+#    #+#             */
/*   Updated: 2023/09/10 18:39:23 by ibenli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}t_stack;


typedef struct s_player_pos
{
	int i;
	int j;
}			t_player_pos;

typedef struct s_data_map
{
	int		r;
	int		player_pos;
	int		col;
	int		collectibles;
	int		exit;
}			t_data_map;

typedef struct s_champ
{
	int		i;
	int		j;
}			t_champ;

typedef struct s_game
{
	void *mlx_init;
	void *mlx_window;
	void *mlx_coin;
	void *mlx_player;
	void *mlx_exit;
	void *mlx_ground;
	int	w;
	int	h;
	void *mlx_wall;
	char **map;
	int counter;
	t_player_pos pos;
} t_game;

// int ft_check_arg(int ac, char **av);
int	ft_strcmp(char *s1, char *s2);
void	ft_error(void);
int search_for_ber(char **av, char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t  ft_strlen(const char *s);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *next);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *next);
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstclear(t_stack **lst, void (*del)(void*));
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
int check_size_line(char **lines);
char    *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
void ft_str_free(char **str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
int ft_check_walls(char **lines);
int ft_a_wall(char *line);
int ft_linesln(char **lines);
char **ft_store_map(char *file);
char	*ft_strjoin(char const *s1, char const *s2);
t_data_map	ft_check_collectible(char **lines, int mark);
char **ft_check_map(char **av);
t_player_pos    ft_get_player_pos(char **lines);
char    *ft_strdup(char *src);
t_data_map ft_rcol(char **lines);

void ft_flood_fill(char **lines);
void ft_free_double_ptr(char **ptr);

void ft_game(char **map);
void    ft_swap(char *a, char *b);

#endif