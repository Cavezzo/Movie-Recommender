//
//  User.cpp
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#include "User.h"

#include <string>
#include <vector>

using namespace std;

User::User(const string& full_name, const string& email,
           const vector<string>& watch_history) : m_name(full_name), m_email(email)
{
    for ( vector<string>::const_iterator i = watch_history.begin(); i != watch_history.end(); i++ )
    {
        watchHistory.push_back(*i);
    }
}

string User::get_full_name() const
{
    return m_name;
}

string User::get_email() const
{
    return m_email;
}

vector<string> User::get_watch_history() const
{
    return watchHistory;
}

