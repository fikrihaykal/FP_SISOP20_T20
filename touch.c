#include "fcntl.h"
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]){
	int fd;

	if(argc!=2){
		printf(1, "touch fail : touch [filename]\n");
	}

	if((fd = open(argv[1], O_CREATE | O_RDWR)) < 0){
		printf(1, "touch fail : failed update timestamp: %s\n", argv[1]);
	} else{
		write(fd, "", 0);
	}

	close(fd);
	exit();
}
