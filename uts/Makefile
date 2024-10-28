CC = g++
CFLAGS = -Wall -Wextra -std=c++17
OUTPUT_DIR = output

all:	$(OUTPUT_DIR)/main

$(OUTPUT_DIR)/main:	go_food.o go_ride.o go_send.o main.o pembayaran.o
	$(CC) $(CFLAGS) -o $@ $^

%.o:	%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OUTPUT_DIR)/*.o $(OUTPUT_DIR)/main