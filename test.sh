#!/bin/bash
RED='\033[0;31m'
NC='\033[0m'
CYAN='\033[0;36m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'

execute() {
	printf "${GREEN}>> Available Files:${NC}\n"
	printf "${YELLOW}"
	cd "${1}"
	ls *.cpp
	printf "${NC}${CYAN}>> Enter Filename: ${NC}"
	read FILENAME
	printf "${YELLOW}Please Wait...\n${NC}"
	cd ..
	g++ -o test "${1}/${FILENAME}.cpp"
	printf "${LGREEN}Code Complied...\n${NC}"
	# clear
	printf "${LGREEN}Output\n------\n${NC}"
	./test
	# printf "\n${CYAN}-------------------------------------------------------${NC}"
}

while true;
do
	printf "${LGREEN}
	 ____                 ____            
	|  _ \ _   _ _ __    / ___| _     _   
	| |_) | | | | '_ \  | |   _| |_ _| |_ 
	|  _ <| |_| | | | | | |__|_   _|_   _|
	|_| \_ \\__,_|_| |_|  \____||_|   |_|
	${NC}\n"
	printf "${YELLOW}1. practice\n2. c&cpp\n3. recursion\n${NC}${RED}0. Exit${NC}\n"
	printf "${CYAN}>> Enter the SI.No.:${NC} "
	read OPTION

	if [ $OPTION -eq 1 ]
	then
		execute 'practice'
	elif [ $OPTION -eq 2 ]
	then
		execute 'c&cpp'
	elif [ $OPTION -eq 3 ]
	then
		execute 'recursion'
	elif [ $OPTION -eq 0 ]
	then
		printf "${RED}Bye-Bye${NC}\n"
		break
	fi
	rm test
done