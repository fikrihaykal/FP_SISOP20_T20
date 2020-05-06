#include "fcntl.h"
#include "types.h"
#include "stat.h"
#include "user.h"

void tail(int fd);

int main(int argc, char *argv[]){
    int fd;

    if(argc <= 1){
        printf(1, "tail fail : tail [filename]\n");
        exit();
    } else{
        for(int i=2; i<=argc; i++){
            if((fd = open(argv[i], O_RDONLY)) < 0){
                printf(1, "tail fail: cannot open %s\n", argv[i]);
                exit();
            } else{
                tail(fd);
            }
            close(fd);
        }
    }
    exit();

    return 0;
}

void tail(int fd){
    int fr, count, tenLines, fd2;
    char buf[512];

    count = 0;
    fd2 = open("~implisit", O_CREATE | O_RDWR);

    while((fr = read(fd, buf, sizeof(buf))) > 0){
        write(fd2, buf, fr);
        for(int i=0; i<fr; i++){
            if(buf[i] == '\n'){
                count++;
            }
        }
    }

    if(fr < 0){
        printf(1, "tail fail : read error\n");
        exit();
    } else if(count < 10){
        tenLines = 0;
    } else{
        tenLines = count - 10;
    }

    close(fd2);

    fd2 = open("~implisit", 0);
    count = 0;

    while((fr = read(fd2, buf, sizeof(buf))) > 0){
        for(int i=0; i<fr; i++){
            if(count >= tenLines){
                printf(1, "%c", buf[i]);
            }

            if(buf[i] == '\n'){
                count++;
            }
        }
    }

    close(fd2);
    unlink("~implisit");
}
