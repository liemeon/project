CFLAGS = -Wall
OBJS = translate.o extract_text.o myapp.o
TARGET = myapp

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) ../lib/$(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) ../lib/$< -o ../lib/$@

clean_o :
	rm -f ../lib/$(OBJS)

clean :
	rm -f ../lib/$(OBJS) $(TARGET)
