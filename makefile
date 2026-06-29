

BUILD=./bin/bst.o ./bin/main.o


all: $(BUILD)
	gcc -o ./main ./bin/bst.o ./bin/main.o

./bin/main.o: ./src/main.c
	gcc ./src/main.c -c -g -o ./bin/main.o

./bin/bst.o: ./src/bst/bst.c
	gcc ./src/bst/bst.c -c -g -o ./bin/bst.o


cl:
	rm ./bin/*.o ./main