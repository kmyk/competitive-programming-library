---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"old/popen2.inc.cpp\"\npid_t popen2(const char *command,\
    \ int *fd_r, int *fd_w) {\n    constexpr int READ = 0;\n    constexpr int WRITE\
    \ = 1;\n    int p_stdin[2], p_stdout[2];\n    if (pipe(p_stdin) != 0 or pipe(p_stdout)\
    \ != 0) return -1;\n    pid_t pid = fork();\n    if (pid < 0) return -1;\n   \
    \ if (pid == 0) {\n        close(p_stdin[WRITE]);\n        dup2(p_stdin[READ],\
    \ STDIN_FILENO);\n        close(p_stdout[READ]);\n        dup2(p_stdout[WRITE],\
    \ STDOUT_FILENO);\n        execl(\"/bin/sh\", \"sh\", \"-c\", command, NULL);\n\
    \        exit(1);\n    } else {\n        if (fd_r == NULL) {\n            close(p_stdin[WRITE]);\n\
    \        } else {\n            *fd_r = p_stdin[WRITE];\n        }\n        if\
    \ (fd_w == NULL) {\n            close(p_stdout[READ]);\n        } else {\n   \
    \         *fd_w = p_stdout[READ];\n        }\n        return pid;\n    }\n}\n"
  code: "pid_t popen2(const char *command, int *fd_r, int *fd_w) {\n    constexpr\
    \ int READ = 0;\n    constexpr int WRITE = 1;\n    int p_stdin[2], p_stdout[2];\n\
    \    if (pipe(p_stdin) != 0 or pipe(p_stdout) != 0) return -1;\n    pid_t pid\
    \ = fork();\n    if (pid < 0) return -1;\n    if (pid == 0) {\n        close(p_stdin[WRITE]);\n\
    \        dup2(p_stdin[READ], STDIN_FILENO);\n        close(p_stdout[READ]);\n\
    \        dup2(p_stdout[WRITE], STDOUT_FILENO);\n        execl(\"/bin/sh\", \"\
    sh\", \"-c\", command, NULL);\n        exit(1);\n    } else {\n        if (fd_r\
    \ == NULL) {\n            close(p_stdin[WRITE]);\n        } else {\n         \
    \   *fd_r = p_stdin[WRITE];\n        }\n        if (fd_w == NULL) {\n        \
    \    close(p_stdout[READ]);\n        } else {\n            *fd_w = p_stdout[READ];\n\
    \        }\n        return pid;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: old/popen2.inc.cpp
  requiredBy: []
  timestamp: '2020-01-08 18:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/popen2.inc.cpp
layout: document
redirect_from:
- /library/old/popen2.inc.cpp
- /library/old/popen2.inc.cpp.html
title: old/popen2.inc.cpp
---
