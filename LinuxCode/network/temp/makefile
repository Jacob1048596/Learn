.PHONY:clean all
TARGET =svr client
CC=gcc
FLAGSS= -lpthread

all: $(TARGET)

svr: svr.o public.o
	$(CC) -o $@ $^ $(FLAGSS)
client: client.o public.o
	$(CC) -o $@ $^ $(FLAGSS)
%.o:%.c
	$(CC) -c $^ $(FLAGSS)
clean:
	rm -rf *.o $(TARGET)