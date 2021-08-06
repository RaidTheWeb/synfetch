#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <synnixos.h>
#include <math.h>

char * calculateSize( off_t size ) {
    char *result = (char *) malloc(sizeof(char) * 20);
    static int GB = 1024 * 1024 * 1024;
    static int MB = 1024 * 1024;
    static int KB = 1024;
    if (size >= GB) {
        if (size % GB == 0)
            sprintf(result, "%d GB", size / GB);
        else
            sprintf(result, "%d GB", size / GB);
    }
    else if (size >= MB) {
        if (size % MB == 0)
            sprintf(result, "%d MB", size / MB);
        else
            sprintf(result, "%d MB", size / MB);
    }
    else {
        if (size == 0) {
            result[0] = '0';
            result[1] = '\0';
        }
        else {
        if (size % KB == 0)
            sprintf(result, "%d KB", size / KB);
        else
            sprintf(result, "%d KB", size / KB);
        }
    }
    return result;
}

int main(int argc, const char** argv) {
    printf("\x1b[1;32m____ _   _ _  _ _  _ _ _  _ \x1b[0m____ ____ \n");
    printf("\x1b[1;32m[__   \\_/  |\\ | |\\ | |  \\/  \x1b[0m|  | [__  \n");
    printf("\x1b[1;32m___]   |   | \\| | \\| | _/\\_ \x1b[0m|__| ___] \n");
    printf("\x1b[1;32m                            \x1b[0m          \n");

    struct utsname buf;
    uname(&buf);
    printf("\x1b[1;34mOS:\x1b[0m %s %s\n", buf.sysname, buf.machine);
    printf("\x1b[1;34mHostname:\x1b[0m %s\n", buf.nodename);
    printf("\x1b[1;34mKernel:\x1b[0m %s\n", buf.release);
    
    long milli = xtime();

    long days = milli / (1000 * 60 * 60 * 24);
    long hours = (milli % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60);
    long minutes = (milli % (1000 * 60 * 60)) / (1000 * 60);
    long seconds = (milli % (1000 * 60)) / 1000;

    printf("\x1b[1;34mUptime:\x1b[0m %d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);
    printf("\x1b[1;34mShell:\x1b[0m %s\n", "SynnixOS Shell");
    printf("\x1b[1;34mRAM:\x1b[0m %s / %s\n", calculateSize(totalmem() - leakedmem() - freemem()), calculateSize(totalmem()));
    return 0;
}
