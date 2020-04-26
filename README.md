#Password Manager

Simple terminal password manager.

Program will allow users to :

1. Log in with a master password, change the master password.
2. Save passwords / add passwords to a list.
3. See a list of passwords they have saved.
4. Edit / remove passwords.

This is another practice program, so I keep a progress journal of the changes I made along the way.

Progress journal: 
# 24.04.2020 update

Used OOP / classes for the reading of the data. I wanted to separate the actual reading of the file and the printing of it's contents. Thought OOP was the way to go as I recently started using it and it seems like a good way encapsulate data. 

Disclaimer: I would never use such passwords from the example text file, it's just what came to my mind when testing.

# 26.04.2020 update

Separated the credentials array and input array. This is a good practice, because the user input could break the program if it is parsed directly to the functions. This way input limits could be implemented easier, if I were to do that. I think I will not spend to much time checking input this project, as I want to focus on the functionality primarily. 
I have also deleted redundant includes and I have used macro constants for the array sizes. There was no need to check the size of the array again after it was created with a limit size. If I wanted a dynamic array, I would have used a vector. However, since I went with arrays I could just set a bigger limit on it and it will function fine.
