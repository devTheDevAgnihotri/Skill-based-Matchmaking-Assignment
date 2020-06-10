# Skill-based-Matchmaking-Assignment
You are given N players who want to play a M vs M match. Each Player has an attribute Score which is a positive integer. The program needs to find possible unique matches of M vs M players depending on their Score. The matches should be sorted based on the quality of each match. The quality of the match is defined as the closeness of the scores between the teams.
This code is written in c++.

#How to compile the code <br>
.gcc program-source-code.c -o executable-file-name<br>
USE THIS COMMAND TO COMPILE THE CODE IN LINUX ENVIRONMENT<br><br>
prerequite is to download the c++ in system<br>
$ sudo apt-get update<br>
$ sudo apt-get install build-essential manpages-dev <br>
is the command  to install it on ubuntu

<br><br>Some Key points of code:<br>
.The first input of the player is kept fixed in code in order to reduce the complexity as one whole loop is neglected
<br>
.Used multimap in order to store the <key,value> pair of player and score as it allows multiple elements to have same keys
<br>
.Used try catch statement to handle the errors and anonymous input