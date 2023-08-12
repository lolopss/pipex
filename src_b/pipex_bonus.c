/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:41:17 by ldaniel           #+#    #+#             */
/*   Updated: 2023/05/23 15:16:28 by ldaniel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (in_or_out == 2)
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (ret == -1)
		exit(0);
	return (ret);
}

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

int	check_arg(int ac, char **av, int i)
{
	if (ac < 5 || (ft_strcmp(av[1], "here_doc") == 0 && ac < 6))
	{
		ft_putstr_fd("Error\nFollow this syntax\n./pipex file1", 2);
		ft_putstr_fd(" cmd1 cmd2 ... outfile\n", 2);
		ft_putstr_fd("OR\nThis syntax\n./pipex here_doc", 2);
		ft_putstr_fd(" LIMITER cmd1 cmd2 ... outfile\n", 2);
		return (-1);
	}
	while (++i <= ac - 2)
	{
		if (!ft_strlen(av[i]) || !is_space(av[i]))
		{
			ft_putstr_fd("Error\n./pipex file1 cmd1 cmd2 ... outfile\n", 2);
			return (-1);
		}
	}
	return (0);
}

void	mkpipe(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_exec(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		fd_in;
	int		fd_out;

	if (check_arg(ac, av, 1) != 0)
		return (0);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		i = 3;
		fd_out = open_file(av[ac - 1], 2);
		here_doc(av);
	}
	else
	{
		i = 2;
		fd_in = open_file(av[1], 0);
		fd_out = open_file(av[ac - 1], 1);
		dup2(fd_in, 0);
		check_arg_2(av);
	}
	while (i < ac - 2)
		mkpipe(av[i++], env);
	dup2(fd_out, 1);
	ft_exec(av[ac - 2], env);
	return (0);
}
