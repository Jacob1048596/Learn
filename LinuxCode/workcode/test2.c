#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main( void )
{
// 创建监听套接字
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("创建socket成功\n");

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    inet_aton("192.168.204.200", &addr.sin_addr);

// 绑定
    int r = bind(lfd, (struct sockaddr*)&addr, sizeof(addr));
    if ( r == -1 ) perror("bind"),exit(1);
    printf("绑定成功\n");

// 设置成被动套接字
    if ( (r=listen(lfd, SOMAXCONN)) == -1 )
    perror("listen"),exit(1);
    printf("设置成监听套接字成功\n");

// 等待客户端的连接
    int newfd = accept(lfd, NULL, NULL);
    printf("有客户端链接上来\n");
    while ( 1 ) 
    {
        char buf[1024] = {};
        r = read(newfd, buf, 1024);
        if ( r == 0 )
        break;
        printf("===> %s\n", buf);
        write(newfd, buf, r);
    }      

    close(newfd);
    close(lfd);
}
