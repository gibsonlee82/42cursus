#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>

// pipex.c
void	run_pipex(char **argv, char **envp, pid_t *pid1, pid_t *pid2);
void	child1_process(char **argv, char **envp, int *pipefd, int infile);
void	child2_process(char **argv, char **envp, int *pipefd, int outfile);

// utils.c
void	free_split(char **arr);
char    *get_cmd_path(char *cmd, char **envp);
char    **get_cmd_path_env(char **envp);
// void	free_split_exit(char **arr, int exit_code);
void	error_exit(char *text, int exit_code);
void    free_split_error_exit(char **arr, char *text, int exit_code);

// libft
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
