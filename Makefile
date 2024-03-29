include Make_dir.mk

TARGET = KMA_server



CC = g++

CFLAGS += -Wall -std=c++17

LIBS += -lboost_program_options -lpthread 
LIBS += -lPocoNet -lPocoUtil -lPocoJSON -lPocoData -lPocoFoundation

BOOST_PATH = /usr/include/boost

BILD_DIR = build/

SRC_DIR = src/


CFILES += $(SRC_DIR)main.cpp



all:
	mkdir -p build
	$(CC) $(CFILES) $(LIBS) -o $(BILD_DIR)$(TARGET) $(CFLAGS)


clean_dir:
	rm -Rf $(BILD_DIR)

clean:clean_dir