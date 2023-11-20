all:

	g++ ./src/*.cpp ./src/*.hpp -o ./bin/ex

clean:

	rm -rf ./bin/ex

run:

	./bin/ex

c: clean all run
