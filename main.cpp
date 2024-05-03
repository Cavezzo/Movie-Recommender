#include "UserDatabase.h"
#include "User.h"
#include "MovieDatabase.h"
#include "treemm.h"
#include "Movie.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <unordered_map>
#include "Recommender.h"
using namespace std;

//////////////////////////i/////////////////////////////////////////////////////
//
// You are free to do whatever you want with this file, since you won't
// be turning it in.  Presumably, you will make changes to help you test
// your classes.  For example, you might try to implement only some User
// member functions to start out with, and so replace our main routine with
// one that simply creates a User and verifies that the member functions you
// implemented work correctly.
//
//////////////////////////i/////////////////////////////////////////////////////


  // If your program is having trouble finding these files. replace the
  // string literals with full path names to the files.  Also, for test
  // purposes, you may want to create some small, simple user and movie
  // data files to makde debuggiing easier, so you can replace the string
  // literals with the names of those smaller files.

const string USER_DATAFILE  = "users.txt";
const string MOVIE_DATAFILE = "movies.txt";


void findMatches( Recommender& r,
     const MovieDatabase& md,
     const string& user_email,
     int num_recommendations)
{

vector<MovieAndRank> recommendations = r.recommend_movies(user_email, num_recommendations);

if ( recommendations.empty() )
cout << "We found no movies to recommend :(.\n";
else
{
for (int i = 0; i < recommendations.size(); i++)
{
const MovieAndRank& mr = recommendations[i];
Movie* m = md.get_movie_from_id(mr.movie_id);
cout << i+1 << ". " << m->get_title() << " (" << m->get_release_year() << ")\n Rating: " << m->get_rating() << "\n Compatibility Score: " << mr.compatibility_score << "\n";
}
}
}


int main()
{
//    UserDatabase udb;
//    if (0&&!udb.load(USER_DATAFILE))  // In skeleton, load always return false
//    {
//        cout << "Failed to load user data file " << USER_DATAFILE << "!" << endl;
//        return 1;
//    }
//    for (;;)
//    {
//        cout << "Enter user email address (or quit): ";
//        string email;
//        getline(cin, email);
//        if (email == "quit")
//            return 0;
//        User* u = udb.get_user_from_email(email);
//        if (u == nullptr)
//            cout << "No user in the database has that email address." << endl;
//        else
//            cout << "Found " << u->get_full_name() << endl;
//    }
 
    
    //*** USER TESTING
//    vector<string> wH;
//    wH.push_back("the man");
//    wH.push_back("thesadjcn");
//    const string name = "Callum";
//    const string email = "cvezzo@hotmail.com";
//
//    User u(name, email, wH );
//
//    cout << u.get_email() << endl;
//    cout << u.get_full_name() << endl;
//    vector<string> v = u.get_watch_history();
//    for ( vector<string>::iterator i = v.begin(); i != v.end(); i++ )
//    {
//        cout << *i << endl;
//    }
    
    //*** TREEMM TESTING
//
//    TreeMultimap<std::string, int> tm;
//    tm.insert("Bob", 5);
//    tm.insert("Joe", 6);
//    tm.insert("Colby", 10);
//    tm.insert("Colby", 69);
//
//    TreeMultimap<std::string, int>::Iterator i = tm.find("Colby");
//
//    i.advance();
//    cout << i.get_value() << endl;
    
    
    //*** MOVIEDATABASE TESTING
    

//    MovieDatabase mDb;
//
//    mDb.load("/Users/callumlavezzo/Desktop/COM SCI 32/Pnetphlix Skeleton/movies.txt");
//
//    Movie * m;
//    m = mDb.get_movie_from_id("id17845");
//
//    cout << m->get_title() << endl;
//
//    vector<Movie*> vM = mDb.get_movies_with_genre("cOmeDy");
//
//    vector<Movie*>::iterator g = vM.begin();
//    while ( g != vM.end() )
//    {
//        Movie* m2 = *g;
//        cout << m2->get_title() << endl;
//        g++;
//    }
//
    
    //*** USERDATABASE TESTING
    
//    ifstream infile("/Users/callumlavezzo/Desktop/COM SCI 32/Pnetphlix Skeleton/users.txt");
//
//    if ( !infile )
//    {
//        cerr << "Error: Cannot open users.txt!" << endl;
//    }
//
//    TreeMultimap<std::string, User*> users;
//        string email, name;
//        vector<string> movieIds;
//        string s;
//
//    bool isNum = false;
//    int j = 0;
//    bool isBlank = false;
//    bool isName = true;
//    bool isEmail = false;
//        while ( getline(infile, s) )
//        {
//            if ( j == 1 )
//            {
//                movieIds.push_back(s);
//                j--;
//                users.insert(email, new User(name, email, movieIds ));
//                isBlank = true;
//            }
//            else if ( j != 0 )
//            {
//                movieIds.push_back(s);
//                j--;
//            }
//            else if ( isName )
//            {
//                name = s;
//                isName = false;
//                isEmail = true;
//            }
//            else if ( isEmail )
//            {
//                email = s;
//                isEmail = false;
//                isNum = true;
//            }
//            else if ( isNum )
//            {
//                j = stoi(s);
//                isNum = false;
//            }
//            else if ( isBlank )
//            {
//                isName = true;
//                isBlank = false;
//            }
//        }
//
//    TreeMultimap<std::string, User*>::Iterator iter = users.find("vader@darkside.org");
//    User use = *iter.get_value();
//    cout << use.get_full_name() << endl;

    
    
    
    
//        UserDatabase uDb;
//
//        uDb.load("/Users/callumlavezzo/Desktop/COM SCI 32/PnetPhlix Skeleton/users.txt");
//
//        User * u;
//        u = uDb.get_user_from_email("vader@darkside.org");
//
//        cout << u->get_full_name() << endl;
//
//        vector<string> vU = u->get_watch_history();
//
//        vector<string>::iterator g = vU.begin();
//        while ( g != vU.end() )
//        {
//            cout << *g << endl;
//            g++;
//        }
    
    
    
    
    
    
    
    
    //*** RECOMMENDER TESTING
    
   UserDatabase uDb;
   MovieDatabase mDb;
   uDb.load("/Users/callumlavezzo/Desktop/COM SCI 32/PnetPhlix Skeleton/users2.txt");
   mDb.load("/Users/callumlavezzo/Desktop/COM SCI 32/PnetPhlix Skeleton/movies2.txt");
    
    

    Recommender rec(uDb, mDb);

    findMatches( rec, mDb, "climberkip@gmail.com", 20);

     
//
//        unordered_map<string, int> directors;
//        unordered_map<string, int> genres;
//        unordered_map<string, int> actors;
//
//
//        User * u = uDb.get_user_from_email("climberkip@gmail.com");
//        vector<string> watchHistory = u->get_watch_history();
//
//    for ( vector<string>::iterator p = watchHistory.begin(); p < watchHistory.end(); p++ )
//    {
//        Movie * m;
//        m = mDb.get_movie_from_id(*p);
//        vector<string> dirs = m->get_directors();
//        for ( auto d : dirs)
//            directors[d] = 0;
//
//        vector<string> acts = m->get_actors();
//        for ( auto a : acts)
//            actors[a] = 0;
//
////        vector<string> gens = m->get_genres();
////        for ( auto g : gens)
////            genres[g] = 0;
//    }
//
////
////for ( auto j : actors )
////    cout << j.first << endl;
//
//
//    unordered_map<string, int> MAP;
//
//    for ( auto jo : directors )
//    {
//        vector<Movie*> movs = mDb.get_movies_with_director(jo.first);
//        for ( auto jp : movs )
//        {
//                MAP[jp->get_id()] = 20;
//        }
//
//    }
//
//    for ( auto jo : actors )
//    {
//        vector<Movie*> movs = mDb.get_movies_with_actor(jo.first);
//        for ( auto jp : movs )
//        {
//            unordered_map<string, int>::iterator val = MAP.find(jp->get_id());
//            int cs = 30;
//            if ( val != MAP.end() )
//            {
//                cs += val->second;
//                MAP.at(jp->get_id() ) = cs;
//            }
//            else
//                MAP[jp->get_id()] = cs;
//        }
//
//    }
//
//    for ( auto jo : genres )
//    {
//        vector<Movie*> movs = mDb.get_movies_with_genre(jo.first);
//        for ( auto jp : movs )
//        {
//            unordered_map<string, int>::iterator val = MAP.find(jp->get_id());
//            int cs = 1;
//            if ( val != MAP.end() )
//            {
//                cs += val->second;
//                MAP.at(jp->get_id() ) = cs;
//            }
//            else
//                MAP[jp->get_id()] = cs;
//        }
//
//    }
//
//
//    for ( auto p : watchHistory )
//    {
//        if ( MAP.find(p) != MAP.end() )
//            MAP.erase(p);
//    }
//
//    vector<MovieAndRank> result;
//
//        for ( int i = 0; i < 5; i ++ )
//        {
////            unordered_map<string, int>::iterator maxVal = max_element(MAP.begin(), MAP.end() );
////            if ( maxVal != MAP.end() )
////            {
////                MovieAndRank mAr(maxVal->first, maxVal->second);
////                result.push_back(mAr);
////                MAP.erase(maxVal);
////            }
//            unordered_map<string, int>::iterator val = MAP.begin();
//            if ( val != MAP.end() )
//            {
//                MovieAndRank mAr(val->first, val->second);
//                result.push_back(mAr);
//                MAP.erase(val);
//            }
//        }


    
    return(0);
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//    string user_email = "AbFow2483@charter.net";
//
//    unordered_map<string, int> directors;
//    unordered_map<string, int> genres;
//    unordered_map<string, int> actors;
//
//
//        User * u = uDb.get_user_from_email(user_email);
//        vector<string> watchHistory = u->get_watch_history();
//
//    for ( vector<string>::iterator p = watchHistory.begin(); p < watchHistory.end(); p++ )
//    {
//        Movie * m;
//        m = mDb.get_movie_from_id(*p);
//        vector<string> dirs = m->get_directors();
//        for ( auto d : dirs)
//            directors[d] = 0;
//
//        vector<string> acts = m->get_actors();
//        for ( auto a : acts)
//            actors[a] = 0;
//
//        vector<string> gens = m->get_genres();
//        for ( auto g : gens)
//            genres[g] = 0;
//    }
//
//    unordered_map<string, int> MAP;
//
//    for ( auto jo : directors )
//    {
//        vector<Movie*> movs = mDb.get_movies_with_director(jo.first);
//        for ( auto jp : movs )
//        {
//                MAP[jp->get_id()] += 20;
//        }
//
//    }
//
//    for ( auto jo : actors )
//    {
//        vector<Movie*> movs = mDb.get_movies_with_actor(jo.first);
//        for ( auto jp : movs )
//        {
//            unordered_map<string, int>::iterator val = MAP.find(jp->get_id());
//            int cs = 30;
//            if ( val != MAP.end() )
//                cs += val->second;
//            MAP[jp->get_id()] = cs;
//        }
//
//    }
//
//    for ( auto jo : genres )
//    {
//        vector<Movie*> movs = mDb.get_movies_with_genre(jo.first);
//        for ( auto jp : movs )
//        {
//            unordered_map<string, int>::iterator val = MAP.find(jp->get_id());
//            int cs = 1;
//            if ( val != MAP.end() )
//                cs += val->second;
//            MAP[jp->get_id()] = cs;
//        }
//
//    }
//
//
//    for ( auto p : watchHistory )
//    {
//        if ( MAP.find(p) != MAP.end() )
//            MAP.erase(p);
//    }
//
//    for ( int i = 0; i < 200; i++ )
//    {
//        unordered_map<string, int>::iterator val = MAP.begin();
//        cout << val->first << " " << val->second << endl;
//        MAP.erase(val);
//    }
//
//
//}
//


            
            
            

            
            
            

            
            
            
            
            
            
            
