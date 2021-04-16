
# Password Manager George

Simple Unix terminal password manager.

Program allows user to:

1. Log in with a master password.
2. Save passwords / add passwords to a list.
3. See a list of passwords they have saved.
4. Edit / remove passwords.

Masterpassword gets encrypted with OpenBSD's bcrypt, hash gets saved in .MasterPass.txt
Passwords get encrypted through my own character manipulation algorithm. 

Program creates 3 hidden files in home directory, .MasterPass.txt , passwords.txt and tmpCrypt.txt. 
These are neccessary for the program to work. Deleting these means deleting your passwords.

# Install and run
Download binary from releases
./PasswordManagerGeorge in binary's location.

To remove: 
delete the binary + 3 hidden files in home directory, .MasterPass.txt , passwords.txt and tmpCrypt.txt. 



Credits: 
- OpenBSD for Bcrypt, and hilch for c++ wrapper 
https://github.com/hilch/Bcrypt.cpp


