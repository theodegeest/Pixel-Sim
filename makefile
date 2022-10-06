targets := game
objs := main.o element.o constants.o simulation.o 
CC := g++
CFLAGS := 
LFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

all: $(targets)

deps := $(patsubst %.o,%.d,$(objs)) 
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

game: $(objs)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)

clean:
	rm -f $(targets) $(objs) $(deps)
