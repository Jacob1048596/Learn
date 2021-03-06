#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main( void ) 
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    inet_aton("192.168.204.200", &addr.sin_addr);

    int r = connect(fd, (struct sockaddr*)&addr, sizeof(addr));

    char buf[1024] = {};
    while ( fgets(buf, 1024, stdin) != NULL ) 
    {
        write(fd, buf, strlen(buf));
        memset(buf, 0x00, sizeof(buf));
        r = read(fd, buf, 1024);
        if ( r <= 0 ) 
        {
            printf("服务器关闭了\n");
            close(fd);
            break;
        }
        printf("buf => %s\n", buf);
        memset(buf, 0x00, sizeof(buf));
    
    }
}      