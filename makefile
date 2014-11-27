all:
	@read -p "Enter directory name: " module; \
	g++ mysh.cpp -o $$module/mysh --std=c++11

yuidoc: 
	npm install yuidocjs

docs: yuidoc
	./node_modules/.bin/yuidoc . -e .cpp -o ./docs

clean:
	rm -rf ./docs