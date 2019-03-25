A simple implementation of ionice for OS X.

It can't query a process's existing ionice-ness, or set the
ionice-ness of an existing process, but it can at least set
the IO priority of a new process, which is all I need.
