SRC_DIR := algo
BUILD_DIR := executable
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
CFLAGS := -Wall -g       #option de compilation pour le debugging et rend compilateur plus exigent
TARGET := $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%) #Nommage automatique des fichiers build d'apres les noms des sources(SRC_FILES)


#using all to generate multiple files(cause makefile will generate only the first target listed
all: $(TARGET) menu
	chmod 755 $(TARGET) menu   
	
menu: menu.c
	gcc $(CFLAGS) menu.c -o menu


$(BUILD_DIR)/%: $(SRC_DIR)/%.c library.h
	gcc $(CFLAGS) $< -o $@

	
clean:         
	rm -f $(BUILD_DIR)/*  # executable/* est un joker qui indique à rm d'effacer tous les fichiers dans dossier executable
	rm -f menu
	rm -f liste.txt
	
