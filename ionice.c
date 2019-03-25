#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h>

void show_usage(char *name) {
    fprintf(stderr, "\n");
    fprintf(stderr, "%s: set the I/O priority level for a command\n\n", name);
    fprintf(stderr, "Usage: %s --high   <utility>\n", name);
    fprintf(stderr, "    or %s --low    <utility>\n", name);
    fprintf(stderr, "    or %s --normal <utility>\n\n", name);
}

int main(int argc, char *argv[]) {
    int status = 0;

    if(argc < 3) {
        show_usage(argv[0]);
        exit(1);
    }

    if(strncmp("--high", argv[1], 6) == 0) {
        setiopolicy_np(
            IOPOL_TYPE_DISK, IOPOL_SCOPE_PROCESS, IOPOL_IMPORTANT
        );
    } else if(strncmp("--normal", argv[1], 6) == 0) {
        /* do nothing */
    } else if(strncmp("--low", argv[1], 6) == 0) {
        setiopolicy_np(
            IOPOL_TYPE_DISK, IOPOL_SCOPE_PROCESS, IOPOL_THROTTLE
        );
    } else {
        show_usage(argv[0]);
        exit(1);
    }

    execvp(argv[2], &argv[2]);
    perror(argv[2]);
    show_usage(argv[0]);
    exit(1);
}
