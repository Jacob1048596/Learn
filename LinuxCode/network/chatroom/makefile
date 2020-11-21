.PHONY:clean all
TARGET =svr client
CC=gcc
FLAGSS= -lpthread

all: $(TARGET)

svr: chat_svr.o
	$(CC) -o $@ $^ $(FLAGSS)
client: chat_client.o
	$(CC) -o $@ $^ $(FLAGSS)
%.o:%.c
	$(CC) -c $^ $(FLAGSS)
clean: