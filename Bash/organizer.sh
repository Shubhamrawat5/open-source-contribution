#!/bin/bash
#Script to organize downloads folder

user=$(whoami)															#recognizing the user
folder=/home/$user/Downloads/"$(date +%Y)"	     		#setting the path
while true;																	#making it run non-stop
do
		if [  "$(date +%H%M%S)" -eq  "000000" ]			#if midnight then start organising
		then 
			if [[ ! -d "$folder" ]];then									#checking if there is already a directory for this year
				mkdir $folder												#creating directory if it is not there
			fi

			cd $folder														
			dt="$(date --date="yesterday" +%b-%d)"			
			mkdir $dt		2>/dev/null													#making  a directory and naming it last day's date

			find /home/$user/Downloads -maxdepth 1 -mtime -1 -mmin +1|sed '1d'|		#finding files that are modified in between 24 hours and past one minute
			while read -r line																						#reading the output of last command one by one
			do
				mv $line /home/$user/Downloads/"$(date +%Y)"/$dt								#moving to the new directory if conditions passed

			done
			rmdir $dt 2>/dev/null 																				#to delete folder if empty
		fi
done
#Here trying to find files modified between last one day and before a minute so that mv command does not try to move the folder created right now