
#include <libgen.h>  // Include for dirname function

// Updated createDirectoryPath function
void createDirectoryPath(const char *filepath) {
    char *path = strdup(filepath);
    if (path == NULL) {
        syslog(LOG_ERR, "Memory allocation error.");
        exit(EXIT_FAILURE);
    }

    char *dir = dirname(path);
    char *cmd = malloc(strlen(dir) + 12);  // Length of "mkdir -p " + dir + '\0'
    if (cmd == NULL) {
        syslog(LOG_ERR, "Memory allocation error.");
        free(path);
        exit(EXIT_FAILURE);
    }

    sprintf(cmd, "mkdir -p %s", dir);
    system(cmd);
    free(path);
    free(cmd);
}

int main(int argc, char *argv[]) {
    openlog("YourUtility", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Please provide exactly two arguments.");
        exit(EXIT_FAILURE);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    if (writefile[0] == '\0') {
        syslog(LOG_ERR, "Write file path is empty.");
        exit(EXIT_FAILURE);
    }

    if (writestr[0] == '\0') {
        syslog(LOG_ERR, "Write string is empty.");
        exit(EXIT_FAILURE);
    }

    createDirectoryPath(writefile);

    writeFile(writefile, writestr);

    // Log the message with LOG_DEBUG level
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);

    closelog();

    return EXIT_SUCCESS;
}
