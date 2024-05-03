//
//  UserDatabase.cpp
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#include "UserDatabase.h"
#include "User.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

UserDatabase::UserDatabase() {};

bool UserDatabase::load(const string& filename)
{
    ifstream infile(filename);

    if ( !infile )
    {
        cerr << "Error: Cannot open users.txt!" << endl;
        return false;
    }

    string s;

        while ( getline(infile, s) )
        {
            
            string full_name = s;
            
            getline( infile, s);
            string email = s;
            
            getline( infile, s);
            int num_moveIDs = stoi( s );
            vector<string> moveIDs;

            for (int i = 0; i < num_moveIDs; i++) {
                getline( infile, s );
                moveIDs.push_back( s );
            }
            
              userItems.push_back( new User(full_name, email, moveIDs));
              int slot = userItems.size()-1;
              emailMap.insert( email, slot);
            

            getline( infile, s);
            
        }

        return true;

}



User* UserDatabase::get_user_from_email(const string& email) const
{
    
    TreeMultimap<string, int>::Iterator i;
    i = emailMap.find(email);

    if ( !i.is_valid() )
    {
        cerr << "This is not a valid email";
        return nullptr;
    }

    return userItems[ i.get_value() ];

}


void UserDatabase::cleanVec()
{

        vector<User*>::iterator p = userItems.begin();
        while ( p != userItems.end() )
        {
                delete *p;
            p = userItems.erase(p);
        }
    
}
