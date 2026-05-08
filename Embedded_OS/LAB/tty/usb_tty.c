/*#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define PATH "/dev/ttyUSB0"

int main(){

	int fd = open(PATH, O_RDWR);

	if(fd < 0){
		errno = fd;
		perror("Error opening: ");
	}

	printf("FD: %d\n", fd);

	char buffer;

	int ret = 1;
	while(ret != 0){
		printf("inside while FD: %d\n", fd);
		ret = read(fd, &buffer, 1);
		write(1, &buffer, 1);
	}

	close(fd);
	return 0;
}*/

#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <errno.h>

int main() {
    // 1. Open the port
    int fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("Error opening /dev/ttyUSB0");
        return 1;
    }

    // 2. Configure the port
    struct termios tty;
    if (tcgetattr(fd, &tty) != 0) {
        perror("Error from tcgetattr");
        return 1;
    }

    // Set Baud Rate to 115200
    cfsetospeed(&tty, B115200);
    cfsetispeed(&tty, B115200);

    // Set 8N1 (8 bits, no parity, 1 stop bit)
    tty.c_cflag &= ~PARENB; // Clear parity bit
    tty.c_cflag &= ~CSTOPB; // Clear stop field (1 stop bit)
    tty.c_cflag &= ~CSIZE;  // Clear current size
    tty.c_cflag |= CS8;     // 8 bits per byte
    
    tty.c_cflag |= (CLOCAL | CREAD); // Ignore modem lines, enable receiver
    tty.c_lflag &= ~(ICANON | ECHO | ISIG); // Raw mode: no echo, no newline processing

    // 3. Apply settings
    tcsetattr(fd, TCSANOW, &tty);

    // 4. Read Loop
    char buf[256];
    while (1) {
        int n = read(fd, buf, sizeof(buf) - 1);
        if (n > 0) {
            buf[n] = '\0';
            printf("Received: %s", buf);
        }
    }

    close(fd);
    return 0;
}

