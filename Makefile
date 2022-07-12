SOURCES = ${wildcard src/*.c}
OBJS = ${SOURCES:.c=.o}

CXX = gcc

CFLAGS = -I./include -O2 -Wall -g --static

curcl: $(OBJS)
	$(CXX) $(CFLAGS) obj/*.o -o $@

%.o: %.c
	$(CXX) $(CFLAGS) -c $< -o obj/$(notdir $@)

clean:
	rm -rf obj/