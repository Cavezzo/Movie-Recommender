//
//  UserDatabase.h
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#ifndef UserDatabase_h
#define UserDatabase_h

#include <stdio.h>
#include <string>
#include <stack>
#include "User.h"
#include <map>
#include "treemm.h"


class User;

class UserDatabase
{
  public:
    UserDatabase();
    ~UserDatabase()
    {
        cleanVec();
    }
    bool load(const std::string& filename);
    User* get_user_from_email(const std::string& email) const;

  private:
    std::vector<User*> userItems;

    TreeMultimap<std::string, int> emailMap;

    void cleanVec();
};

#endif /* UserDatabase_h */
