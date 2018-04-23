# scanner
# Usage
./scanner mysql_username
The program should be called with the mysql username to connect as. The user will be prompted for a password before connecting

# ToDo
Currently the program is running "arp -a" and parsing the output to identify the hostname, IP, and MAC
The next step is to implement the MySQL-C++ connector to update the database. Once the connection is established, logic will be implemented to meet the goals.

# Goals
The overall goal of this program is to improve situational awareness of my home network. I want to be able to run scans and check the results against a database to see if the devices are known. If a device MAC is known, the program should update the IP (if DHCP has changed). If the device MAC is not known, the user should be alerted. Eventually I would like this to be a recurring cron job that will email the user if a unknown device is discovered. 
