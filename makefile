all:
	@read -p "Enter Executable name: " module; \
	g++ mysh.cpp -o $$module --std=c++11