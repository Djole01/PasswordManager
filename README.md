
# Password Manager George

Simple Unix terminal password manager.

Program allows users to:

1. Log in with a master password.
2. Save passwords / add passwords to a list.
3. See a list of passwords they have saved.
4. Edit / remove passwords.

Masterpassword gets hashed with OpenBSD's bcrypt, saved in .MasterPass.txt
Passwords get encrypted through my own character manipulation algorithm. 

Program creates 3 hidden files in home directory, .MasterPass.txt , passwords.txt and tmpCrypt.txt. 
These are neccessary for the program to work. Deleting these means deleting your passwords.

# Install and run
Download archive from releases, unzip and cd into its directory

./PasswordManagerGeorge

It's possible to create a launcher for the program to run in terminal from an icon, if you wish so.

To remove: 
delete the binary + 3 hidden files in home directory, .MasterPass.txt , passwords.txt and tmpCrypt.txt. 

Note: You should exit through the program by choosing option 4 to encrypt the passwords. Closing the terminal will not encrypt them, but it will not brake anything either, so when you run it next time you can encrypt by choosing option 4.


Credits: 
- OpenBSD for Bcrypt, and hilch for c++ wrapper 
https://github.com/hilch/Bcrypt.cpp


