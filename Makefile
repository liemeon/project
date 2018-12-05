CFLAGS = -Wall
OBJS = func1.o func2.o myapp.o
TARGET = myapp

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean : 
	rm -f $(TARGET) $(OBJS)
