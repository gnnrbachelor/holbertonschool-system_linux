CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -g


SRC = src
UTIL = util

TASK_0 = todo_api_0
TASK_1 = todo_api_1
TASK_2 = todo_api_2
TASK_3 = todo_api_3
TASK_4 = todo_api_4
TASK_5 = todo_api_5
TASK_6 = todo_api_6
TASK_7 = todo_api_7


OBJ0 += $(patsubst %.c, %.o, $(wildcard $(SRC)/$(TASK_0)/*.c))
OBJ0 += $(patsubst %.c, %.o, $(wildcard $(SRC)/$(UTIL)/*.c))
OBJ1 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(TASK_1)/*.c))
OBJ1 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(UTIL)/*.c))
OBJ2 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(TASK_2)/*.c))
OBJ2 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(UTIL)/*.c))
OBJ3 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(TASK_3)/*.c))
OBJ3 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(UTIL)/*.c))
OBJ4 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(TASK_4)/*.c))
OBJ4 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(UTIL)/*.c))
OBJ5 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(TASK_5)/*.c))
OBJ5 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(UTIL)/*.c))
OBJ6 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(TASK_6)/*.c))
OBJ6 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(UTIL)/*.c))
OBJ7 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(TASK_7)/*.c))
OBJ7 += $(patsubst %.c, %o, $(wildcard $(SRC)/$(UTIL)/*.c))

$(TASK_0): $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(TASK_0)

$(TASK_1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(TASK_1)

$(TASK_2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(TASK_2)

$(TASK_3): $(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) -o $(TASK_3)

$(TASK_4): $(OBJ4)
	$(CC) $(CFLAGS) $(OBJ4) -o $(TASK_4)

$(TASK_5): $(OBJ5)
	$(CC) $(CFLAGS) $(OBJ5) -o $(TASK_5)

$(TASK_6): $(OBJ6)
	$(CC) $(CFLAGS) $(OBJ6) -o $(TASK_6)

$(TASK_7): $(OBJ7)
	$(CC) $(CFLAGS) $(OBJ7) -o $(TASK_7)

clean:
	rm -f todo_api_0 todo_api_1 todo_api_2 todo_api_3 todo_api_4 todo_api_5 todo_api_6 todo_api_7

	find . -type f -name '*.o' -delete





