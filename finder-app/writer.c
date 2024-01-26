
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

void writeFile(const char *filepath, const char *content) {
    FILE *file = fopen(filepath, "w");
    if (file != NULL) {
        fprintf(file, "%s", content);
        fclose(file);
    } else {
        syslog(LOG_ERR, "Unable to create or write to the file '%s'", filepath);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
	
    syslog(LOG_DEBUG, "Inside write.c file");
	
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

    writeFile(writefile, writestr);

    // Log the message with LOG_DEBUG level
    syslog(LOG_DEBUG, "Writing '%s' to '%s'", writestr, writefile);

    closelog();

    return EXIT_SUCCESS;
}
