all:
	@read -p "Enter directory name: " module; \
	g++ mysh.cpp -o $$module/mysh --std=c++11