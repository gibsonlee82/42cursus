#include "pipex.h"

/**********************************************************************
 * Entry point of the pipex program.
 * - argc: Number of command-line arguments.
 * - argv: Array of command-line argument strings (file1 cmd1 cmd2 file2)
 * - envp: Array of environment variable strings.
 *
 * This function:
 * - Checks for correct argument count.
 * - Calls run_pipex() to handle setup and forking.
 * - Waits for both child processes to finish.
 * - Returns the exit status of the second command (cmd2).
 *
 * Returns:
 *  - Exit status of cmd2 on success.
 *  - 1 on incorrect usage or general failure.
 **********************************************************************/
int	main(int argc, char **argv, char **envp)
{
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	run_pipex(argv, envp, &pid1, &pid2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

/**********************************************************************
 * Sets up the input/output files, pipe, and forks child processes.
 * - argv: Command-line arguments passed to the program.
 * - envp: Environment variables passed to the program.
 *
 * This function:
 * - Opens the input and output files.
 * - Creates a pipe for inter-process communication.
 * - Forks two child processes to execute cmd1 and cmd2.
 * - Closes pipe file descriptors in the parent.
 *
 * On error, appropriate error messages are printed to stderr.
**********************************************************************/
void	run_pipex(char **argv, char **envp, pid_t *pid1, pid_t *pid2)
{
	int	pipefd[2];
	int	infile;
	int	outfile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		perror("infile");
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		perror("outfile");
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return ;
	}
	*pid1 = fork();
	if (*pid1 == 0)
		child1_process(argv, envp, pipefd, infile);
	*pid2 = fork();
	if (*pid2 == 0)
		child2_process(argv, envp, pipefd, outfile);
	close(pipefd[0]);
	close(pipefd[1]);
}

/**********************************************************************
Executes the first command with input from file1 and output to pipe.
- argv: Program arguments (file1 cmd1 cmd2 file2).
- envp: Environment variables for execve.
- pipefd: Pipe file descriptors.
- infile: File descriptor for input file1.
***********************************************************************/
void	child1_process(char **argv, char **envp, int *pipefd, int infile)
{
	char	**cmd;
	char	*cmd_path;

	if (infile < 0)
		exit(1);
	dup2(infile, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	cmd = ft_split(argv[2], ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
	{
		free_split(cmd);
		error_exit("Empty command\n", 127);
	}
	cmd_path = get_cmd_path(cmd[0], envp);
	if (!cmd_path)
	{
		perror("cmd1 not found");
		free_split_error_exit(cmd, NULL, 1);
	}
	execve(cmd_path, cmd, envp);
	perror("execve failed");
	free(cmd_path);
	free_split_error_exit(cmd, NULL, 1);
}

/**********************************************************************
Executes the second command with input from pipe and output to file2.
- argv: Program arguments (file1 cmd1 cmd2 file2).
- envp: Environment variables for execve.
- pipefd: Pipe file descriptors.
- outfile: File descriptor for output file2.
**********************************************************************/
void	child2_process(char **argv, char **envp, int *pipefd, int outfile)
{
	char	**cmd;
	char	*cmd_path;

	if (outfile < 0)
		error_exit("outfile open failed\n", 1);
	if (pipefd[0] < 0)
		exit(1);
	dup2(pipefd[0], 0);
	dup2(outfile, 1);
	close(pipefd[1]);
	cmd = ft_split(argv[3], ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		free_split_error_exit(cmd, "Empty command\n", 127);
	cmd_path = get_cmd_path(cmd[0], envp);
	if (!cmd_path)
		free_split_error_exit(cmd, "command not found\n", 127);
	execve(cmd_path, cmd, envp);
	perror("execve failed");
	free(cmd_path);
	free_split_error_exit(cmd, NULL, 1);
}
