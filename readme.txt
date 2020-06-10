# Skill-based-Matchmaking-Assignment
You are given N players who want to play a M vs M match. Each Player has an attribute Score which is a positive integer. The program needs to find possible unique matches of M vs M players depending on their Score. The matches should be sorted based on the quality of each match. The quality of the match is defined as the closeness of the scores between the teams.
This code is written in c++.

#How to compile the code 
.gcc program-source-code.c -o executable-file-name
USE THIS COMMAND TO COMPILE THE CODE IN LINUX ENVIRONMENT
prerequite is to download the c++ in system
$ sudo apt-get update
$ sudo apt-get install build-essential manpages-dev
is the command  to install it on ubuntu

Some Key points of code:
.The first input of the player is kept fixed in code in order to reduce the complexity as one whole loop is neglected

.Used multimap in order to store the <key,value> pair of player and score as it allows multiple elements to have same keys

.Used try catch statement to handle the errors and anonymous input