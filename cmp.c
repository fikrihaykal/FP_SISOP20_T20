#include "fcntl.h"
#include "types.h"
#include "stat.h"
#include "user.h"

char sA[10000], sB[10000];
int baris, difCheck;

void compare();

int main(int argc, char *argv[]){
    int fd1, fd2, fr;
    baris = 1;
    difCheck = -1;

    if(argc <= 2){
        printf(1, "cmp fail : cmp [file1] [file2]\n");
        exit();
    } else{
        if((fd1 = open(argv[1], O_RDONLY)) < 0){
            printf(1, "cmp fail : cannot open %s\n", argv[1]);
            exit();
        } else if((fd2 = open(argv[2], O_RDONLY)) < 0){
            printf(1, "cmp fail : cannot open %s\n", argv[2]);
            exit();
        } else{
            while((fr = read(fd1, sA, sizeof(sA))) > 0){}
            while((fr = read(fd2, sB, sizeof(sB))) > 0){}

            compare();

            if(difCheck != -1){
                printf(1, "%s %s differ: byte %d, line %d\n", argv[1], argv[2], difCheck+1, baris);
            }
        }
    }

    close(fd1);
    close(fd2);

    exit();

    return 0;
}

void compare(){
    for(int i=0; i<sizeof(sA) && i<sizeof(sB); i++){
        if(sA[i] == '\n'){
            baris++;
        }

        if(sA[i] != sB[i]){
            difCheck = i;
            break;
        }
    }
}
