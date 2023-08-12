/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:57:26 by ldaniel           #+#    #+#             */
/*   Updated: 2023/05/23 15:59:07 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		str = ft_substr(env[i], 0, j);
		if (ft_strcmp(str, name) == 0)
		{
			free(str);
			return (env[i] + j + 1);
		}
		i++;
		free(str);
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	**all_path;
	char	*ret;
	char	*str;
	int		i;

	i = -1;
	all_path = ft_split(get_env("PATH", env), ':');
	while (all_path[++i])
	{
		str = ft_strjoin(all_path[i], "/");
		ret = ft_strjoin(str, cmd);
		free(str);
		if (!access(ret, F_OK | X_OK))
		{
			free_tab(all_path);
			return (ret);
		}
		free(ret);
	}
	free_tab(all_path);
	return (cmd);
}
