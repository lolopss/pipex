/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:43:47 by ldaniel           #+#    #+#             */
/*   Updated: 2023/05/23 15:57:16 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_path(char *cmd, char **env);
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
void	ft_buf_cut(char *dest);
void	ft_exec(char *cmd, char **env);
void	free_tab(char **tab);
void	here_doc_put_in(char **av, int *p_fd);
void	here_doc(char **av);
int		ft_chr(char *s);
int		ft_len(char *s, int j);
int		ft_strcmp(char *s1, char *s2);
int		check_arg(int ac, char **av, int i);
int		check_arg_2(char **av);
int		is_space(char *str);

#endif
