.PHONEY:clean main

CC=gcc
SRCS=$(wildcard *.c)
BASEDIR=$(shell pwd)
OBJDIR=$(BASEDIR)/obj
$(shell mkdir -p $(OBJDIR))
OBJS=$(SRCS:.c=.o)
OBJS:=$(addprefix $(OBJDIR)/,$(OBJS))
main:$(OBJS)
	$CC -o $@ $^
$(OBJDIR)/%.o: %.c
	$(CC) -c $< -o $@
clean:
	rm -rf $(OBJS)