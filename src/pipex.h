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
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_path(char *cmd, char **env);
void	ft_exec(char *cmd, char **env);
int		ft_strcmp(char *s1, char *s2);
int		check_arg(int ac, char **av);
int		is_space(char *str);
void	free_tab(char **tab);

#endif
