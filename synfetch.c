#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <synnixos.h>

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
    printf("\x1b[1;34mShell:\x1b[0m %s\n", "SynnixOS Shell");

    long milli = xtime();

    long days = milli / (1000 * 60 * 60 * 24);
    long hours = (milli % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60);
    long minutes = (milli % (1000 * 60 * 60)) / (1000 * 60);
    long seconds = (milli % (1000 * 60)) / 1000;

    printf("\x1b[1;34mUptime:\x1b[0m %d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);

    return 0;
}
