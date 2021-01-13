#!/bin/bash
RED='\033[0;31m'
NC='\033[0m'
CYAN='\033[0;36m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'

printf "${CYAN}-------------DIR Name:--------------${NC}\n"
printf "${YELLOW}0. practice\n1. C&C++${NC}\n"
printf "${CYAN}Enter the SI.No.:${NC} "
read OPTION

execute() {
	printf "\n${GREEN}Available Files:${NC}\n"
	printf "${YELLOW}"
	ls "${1}"
	printf "${NC}${CYAN}\nEnter Filename: ${NC}"
	read FILENAME
	printf "${LGREEN}Please Wait...${NC}\n"
	g++ -o test "${1}/${FILENAME}.cpp"
	./test
}

if [ $OPTION -eq 0 ]
then
	execute 'practice'
elif [ $OPTION -eq 1 ]
then
	execute 'C&C++'
fi
