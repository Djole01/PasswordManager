/*
 * MasterPassword.h
 *
 *  Created on: May 18, 2020
 *      Author: root
 */

#ifndef MASTERPASSWORD_H_
#define MASTERPASSWORD_H_

void readFromFIleMaster();
int masterPasswordIsSet();
void writeMasterPass(std::string mp);
void passCheck(std::string teMP);
bool mpFileExists(std::string strDir);
void createNewFile(std::string FileName);



#endif /* MASTERPASSWORD_H_ */
