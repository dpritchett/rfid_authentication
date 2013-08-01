#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log(const char* tag, const char* message) {
   time_t now;
   time(&now);
   FILE * fp=fopen(LOG_FILE_PATH,"w");
   fprintf(fp, "%s [%s]: %s\n", ctime(&now), tag, message);
   fclose(fp);

   openlog (RFID_LOG, LOG_AUTH, LOG_NOTICE);
   syslog (LOG_NOTICE, message);
   closelog();
}