#!/bin/bash
RED='\033[0;31m'
NC='\033[0m'
CYAN='\033[0;36m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'
WHITE='\033[1;37m'

execute() {
	printf "${GREEN}>> Available Files:${NC}\n"
	printf "${YELLOW}"
	cd "${1}"
	fileArray=( *.cpp )
	declare -i fileCount=1

	for i in "${fileArray[@]}";
	do 
		printf "${RED}$fileCount.${NC}${WHITE} $i${NC}\n"
		((fileCount++))
	done
	printf "${NC}${CYAN}>> Enter File No.: ${NC}"
	read FILENO
	printf "${YELLOW}Please Wait...\n${NC}"
	cd ..
	g++ "${1}/${fileArray[$FILENO - 1]}"
	printf "${LGREEN}Code Complied...\n${NC}"
	# clear
	printf "${LGREEN}Output\n------\n${NC}"
	printf "${WHITE}"
	./a
	printf "${NC}"
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

	dirArray=( */ )
	declare -i dirCount=1

	for i in "${dirArray[@]}";
	do 
		printf "${WHITE}$dirCount. $i${NC}\n"
		((dirCount++))
	done

	printf "${RED}0. Exit${NC}\n"

	printf "${CYAN}>> Enter the SI.No.:${NC} "
	read OPTION

	if [ $OPTION -ge 1 ]
	then
		execute "${dirArray[$OPTION - 1]}"
	elif [ $OPTION -eq 0 ]
	then
		printf "${RED}Bye-Bye${NC}\n"
		break
	fi
	rm a.exe
done