//
// Created by franc on 07/04/2022.
//
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include "invocateur.h"
#include "daemon.h"


void help(){
    printf("WALLA TU TE DEMERDE FRERE\n");
}
void stop() {
    if (isalive()) {
        FILE *pidfic = fopen(TEMPOFIC, "r");
        int pid = fscanf(pidfic);
        fclose(pidfic);
        kill(pid, SIGKILL);
        remove(TEMPOFIC);
    }
}

int isalive(){
    return !access(TEMPOFIC, F_OK);
}

void restart(){
    stop();
    startdemon();
}