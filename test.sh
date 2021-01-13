#!/bin/bash
RED='\033[0;31m'
NC='\033[0m'
CYAN='\033[0;36m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'

execute() {
	printf "\n${GREEN}>> Available Files:${NC}\n"
	printf "${YELLOW}"
	ls "${1}"
	printf "${NC}${CYAN}\n>> Enter Filename: ${NC}"
	read FILENAME
	printf "${YELLOW}Please Wait...${NC}\n"
	g++ -o test "${1}/${FILENAME}.cpp"
	printf "${LGREEN}Code Complied...\n${NC}"
	./test
	printf "\n${CYAN}---------------------------------------------${NC}"
}

while true;
do
	printf "\n${CYAN}---------RUN & COMPILE C++ PROGRAMS----------${NC}\n"
	printf "${YELLOW}1. practice\n2. C&C++\n${NC}${RED}0. Exit${NC}\n"
	printf "${CYAN}>> Enter the SI.No.:${NC} "
	read OPTION

	if [ $OPTION -eq 1 ]
	then
		execute 'practice'
	elif [ $OPTION -eq 2 ]
	then
		execute 'C&C++'
	elif [ $OPTION -eq 0 ]
	then
		printf "${RED}\nBye-Bye${NC}\n"
		break
	fi
done