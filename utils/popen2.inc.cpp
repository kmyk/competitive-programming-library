pid_t popen2(const char *command, int *fd_r, int *fd_w) {
    constexpr int READ = 0;
    constexpr int WRITE = 1;
    int p_stdin[2], p_stdout[2];
    if (pipe(p_stdin) != 0 or pipe(p_stdout) != 0) return -1;
    pid_t pid = fork();
    if (pid < 0) return -1;
    if (pid == 0) {
        close(p_stdin[WRITE]);
        dup2(p_stdin[READ], STDIN_FILENO);
        close(p_stdout[READ]);
        dup2(p_stdout[WRITE], STDOUT_FILENO);
        execl("/bin/sh", "sh", "-c", command, NULL);
        exit(1);
    } else {
        if (fd_r == NULL) {
            close(p_stdin[WRITE]);
        } else {
            *fd_r = p_stdin[WRITE];
        }
        if (fd_w == NULL) {
            close(p_stdout[READ]);
        } else {
            *fd_w = p_stdout[READ];
        }
        return pid;
    }
}
