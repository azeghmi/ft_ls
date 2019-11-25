/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:54:40 by thflahau          #+#    #+#             */
/*   Updated: 2019/04/12 13:14:41 by thflahau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int					ft_atoi_light(char const *s);
int					ft_strcmp(char const *s1, char const *s2);
void				ft_putstr_endl(char const *s, uint64_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_fast_bzero(void *s, size_t n);
void				ft_fast_putnbr(uint8_t n);
void				ft_putchar(int c);
void				ft_strdel(char **s);
char				*ft_strdup(char const *s);
char				*ft_strnew(size_t n);
char				*ft_strndup(char const *s, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_fast_strlen(char const *s);
size_t				ft_strlen(char const *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);

#endif
