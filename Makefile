BINS = bp-example bp-example-sort
CC = gcc

CFLAGS = -o3

.PHONY:	all clean

all:	$(BINS)

bp-example:	bp-example.c
	$(CC) $(CFLAGS) -o $@ $<

bp-example-sort: bp-example.c
	$(CC) $(CFLAGS) -DSORT_FIRST -o $@ $<

clean:
	rm -f $(BINS) *.o
