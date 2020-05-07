#ifdef CS333_P5
#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

int main(int argc, char *argv[]){
    if(argc != 4){
        printf(1, "chown fail : chown [owner] [group] [filename]\n");
        exit();
    } else{
        if((chown(argv[3], argv[1]) && chgrp(argv[3], argv[2])) < 0){
            printf(1, "chown fail : chown [owner] [group] [filename]\n");
            exit();
        } else{
            printf(1, "chown : update %s owner and group\n", argv[3])
        }
    }
    exit();
}
