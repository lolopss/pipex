/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:41:17 by ldaniel           #+#    #+#             */
/*   Updated: 2023/05/23 15:16:28 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char *cmd, char **env)
{
	char	**g_cmd;
	char	*path;

	g_cmd = ft_split(cmd, ' ');
	path = get_path(g_cmd[0], env);
	if (execve(path, g_cmd, env) == -1)
	{
		free_tab(g_cmd);
		exit(0);
	}
	free_tab(g_cmd);
}

int	check_arg(int ac, char **av)
{
	if (ac != 5)
	{
		ft_putstr_fd("you need to put exactly 4 arguments", 2);
		return (-1);
	}
	if (open(av[1], O_RDONLY) == -1)
	{
		ft_putstr_fd("Infile does not exist", 2);
		return (-1);
	}
	if (ft_strlen(av[2]) == 0 || ft_strlen(av[3]) == 0)
	{
		ft_putstr_fd("You need to put commands in args 2 and 3", 2);
		return (-1);
	}
	if (!is_space(av[3]) || !is_space(av[2]))
	{
		ft_putstr_fd("You need to put commands in args 2 and 3", 2);
		return (-1);
	}
	return (0);
}

void	child(char **av, char **env, int *fd)
{
	int	g_fd;

	close(fd[0]);
	g_fd = open(av[1], O_RDONLY, 0777);
	if (g_fd == -1)
	{
		ft_putstr_fd("The child file doesn't exist\n", 2);
		exit(0);
	}
	dup2(g_fd, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	ft_exec(av[2], env);
}

void	parent(char **av, char **env, int *fd)
{
	int	g_fd;

	close(fd[1]);
	g_fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	dup2(g_fd, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	ft_exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (check_arg(ac, av) != 0)
		return (-1);
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (2);
	if (!pid)
		child(av, env, fd);
	parent(av, env, fd);
	return (0);
}
