#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#include<unistd.h>
ssize_t readn(int fd,void* buf,size_t count);
ssize_t writen(int fd,const void* buf,size_t count);

//客户端和服务器之间的消息格式
typedef struct
{
    int len;//网络字节序，定长部分
    //char* p;
    char cont[1024];//真正要发送的内容，变长部分
    
}message_t;
#endif // __PUBLIC_H__
