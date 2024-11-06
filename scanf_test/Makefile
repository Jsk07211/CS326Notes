PROG = scanf
OBJS = scanf_test.o

%.o:%.c
	gcc -c -g -o $@ $<

$(PROG):$(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
