/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:51:57 by thflahau          #+#    #+#             */
/*   Updated: 2019/05/09 12:32:12 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <sys/types.h>

# include "libft.h"

# define OPTION_L	0x00000001u
# define OPTION_A	0x00000010u
# define OPTION_F	0x00000020u
# define OPTION_T	0x00000100u
# define OPTION_R	0x00001000u
# define OPTION_CR	0x00100000u

# define BUFF_SIZE	256

typedef struct stat	t_stat;

typedef struct		s_files
{
	uint64_t		len;
	char			*name;
	struct stat		infos;
	struct s_files	*next;
}					t_files;

typedef struct		s_list
{
	char			*name;
	t_files			*files;
	struct s_list	*next;
}					t_list;

typedef struct		s_parsing
{
	t_list			*list;
	t_files			*sinfile;
	uint32_t		size;
	uint32_t		options;
}					t_parsing;

typedef int			(t_cmptr)(t_files *s1, t_files *s2);

int					ft_ascii_compare(t_files *s1, t_files *s2);
int					ft_time_compare(t_files *s1, t_files *s2);
int					ft_printf(char const *s, ...);
void				ft_lstreverse(t_files **p);
void				ft_lstdel(t_list **p);
void				ft_filelstdel(t_files **p);
void				ft_read_links(char const *s);
void				ft_lstreverse_args(t_list **p);
void				ft_delete_garbage(t_parsing *p);
void				ft_detailed_files(t_files *p);
void				ft_detailed_print(t_parsing *p);
void				ft_print_total_blocks(t_files *p);
void				ft_sort_list(t_list *l, t_parsing *p);
void				ft_are_valid_directories(t_parsing *p);
void				ft_print_type_and_permissions(mode_t p);
void				ft_sinfiles_ls(t_parsing *p, t_files *l);
void				ft_padding_uid(t_list *p, char const *s);
void				ft_padding_gid(t_list *p, char const *s);
void				ft_print_date_of_last_modification(struct timespec *t);
int8_t				ft_append(t_files **p, char const *s, int64_t n, t_stat *f);
int8_t				ft_parse_args(int ac, char const **av, t_parsing *p);
int8_t				ft_recur_lsdir_suite(t_parsing *p, char const name[512]);
int8_t				ft_lst_pushback(t_list **p, char const *s);
int8_t				ft_iterative_lsdir(t_parsing *p);
int8_t				ft_recursive_lsdir(t_parsing *p);
int8_t				ft_print_usage(int8_t n);
size_t				ft_lstsize(t_list *p);
t_list				*ft_lstnew(char const *s);
t_files				*ft_recursive_merge_sort(t_files *p, t_cmptr *cmp);
void				ft_recur(t_files *tmp, char const name[512], t_parsing *p);

#endif
