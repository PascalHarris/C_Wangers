TARGET = tedditor
ifeq ($(OS),Windows_NT)
	TARGET = tedditor.exe
	CC = gcc
else
	UNAME = $(shell uname -s)
endif
ifeq ($(UNAME), Linux)
	CC = gcc
endif
ifeq ($(UNAME), Darwin)
	CC = gcc
endif
GTKLIBS = `pkg-config --libs gtk+-3.0`
CFLAGS = `pkg-config --cflags gtk+-3.0`
WGR_DIR = wangers

objects = c_wangers_buffer.o c_wangers_number.o c_wangers_time.o gtk_wangers_combobox.o \
          gtk_wangers_file.o gtk_wangers_menus.o gtk_wangers_widget.o c_wangers_file.o \
          c_wangers_string.o gtk_wangers_action.o gtk_wangers_document.o \
          gtk_wangers_layout.o gtk_wangers_tableview.o gtk_wangers_window.o \

all: tedditor clean

tedditor: $(objects)
	$(CC) tedditor.c $(CFLAGS) -o $(TARGET) $(GTKLIBS) *.o

# c object files
$(objects):
	$(CC) -c $(WGR_DIR)/c_*.c
	$(CC) $(CFLAGS) -c $(WGR_DIR)/gtk_*.c

clean:
	rm -f *.o