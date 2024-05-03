//
//  User.h
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#ifndef User_h
#define User_h

#include <stdio.h>
#include <string>
#include <vector>
#include<stack>

class User
{
  public:
    User(const std::string& full_name, const std::string& email,
         const std::vector<std::string>& watch_history);
    std::string get_full_name() const;
    std::string get_email() const;
    std::vector<std::string> get_watch_history() const;

  private:
    std::string m_name;
    std::string m_email;
    std::vector<std::string> watchHistory;
};

#endif /* User_h */
