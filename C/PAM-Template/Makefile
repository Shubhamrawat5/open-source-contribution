CC = gcc
CFLAGS = -Wall -fPIC -shared
LDFLAGS = -lpam -shared

MAIN_FILE = pam-module-template
MODULE_NAME = pam_test
OBJ = $(MAIN_FILE).o

all: $(MODULE_NAME).so

$(MODULE_NAME).so: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(MAIN_FILE).c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -f *.o $(MODULE_NAME).so
