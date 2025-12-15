#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    const char *writefile;
    const char *writestr;
    FILE *fp;

    // Open connection to syslog
    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: expected 2, got %d", argc - 1);
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        return 1;
    }

    writefile = argv[1];
    writestr  = argv[2];

    // Log what we're about to do
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error opening file %s: %s", writefile, strerror(errno));
        fprintf(stderr, "Error: could not open file '%s': %s\n",
                writefile, strerror(errno));
        closelog();
        return 1;
    }

    if (fputs(writestr, fp) == EOF) {
        syslog(LOG_ERR, "Error writing to file %s: %s", writefile, strerror(errno));
        fprintf(stderr, "Error: could not write to file '%s': %s\n",
                writefile, strerror(errno));
        fclose(fp);
        closelog();
        return 1;
    }

    if (fclose(fp) != 0) {
        syslog(LOG_ERR, "Error closing file %s: %s", writefile, strerror(errno));
        fprintf(stderr, "Error: could not close file '%s': %s\n",
                writefile, strerror(errno));
        closelog();
        return 1;
    }

    closelog();
    return 0;
}
