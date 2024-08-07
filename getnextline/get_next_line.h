/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfleury <mfleury@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:59:33 by mfleury           #+#    #+#             */
/*   Updated: 2024/07/30 09:21:31 by mfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE > 10000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# define OPEN_MAX 1024
# define FALSE 0
# define TRUE 1
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	char			*content;
	int				eol;
	int				fd;
	struct s_list	*next;
	struct s_list	*bof;
}	t_list;
char	*get_next_line(int fd);
t_list	*gnl_lst_move(t_list *lst, int n, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
#endif
