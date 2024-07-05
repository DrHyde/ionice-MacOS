A simple implementation of ionice for OS X.

It can't query a process's existing ionice-ness, or set the
ionice-ness of an existing process, but it can at least set
the IO priority of a new process, which is all I need.

After I'd written this someone pointed out `taskpolicy` which
does all that this does plus more, and is bundled with the OS,
so you should probably use that instead:
  https://apple.stackexchange.com/questions/423642/ionice-equivalent-for-macos
