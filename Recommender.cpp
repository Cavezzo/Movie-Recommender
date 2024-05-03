//
//  Recommender.cpp
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#include "Recommender.h"
#include "User.h"
#include "UserDatabase.h"
#include "MovieDatabase.h"
#include "Movie.h"
#include <map>
#include <unordered_map>


#include <string>
#include <vector>
using namespace std;


Recommender::Recommender(const UserDatabase& user_database,
                         const MovieDatabase& movie_database)
{

    uDb =  new UserDatabase(user_database);
    mDb =  new MovieDatabase(movie_database);
}

vector<MovieAndRank> Recommender::recommend_movies(const string& user_email, int movie_count)
{  



    unordered_map<string, int> directors;
    unordered_map<string, int> genres;
    unordered_map<string, int> actors;


        User * u = uDb->get_user_from_email(user_email);
        vector<string> watchHistory = u->get_watch_history();

    for ( vector<string>::iterator p = watchHistory.begin(); p < watchHistory.end(); p++ )
    {
        Movie * m;
        m = mDb->get_movie_from_id(*p);
        vector<string> dirs = m->get_directors();
        for ( auto d : dirs)
            ++directors[d];

        vector<string> acts = m->get_actors();
        for ( auto a : acts)
            ++actors[a];

        vector<string> gens = m->get_genres();
        for ( auto g : gens)
            ++genres[g];
    }

    unordered_map<string, int> MAP;

    for ( auto jo : directors )
    {
        vector<Movie*> movs = mDb->get_movies_with_director(jo.first);
        for ( auto jp : movs )
        {
            unordered_map<string, int>::iterator val = MAP.find(jp->get_id());
            int cs = 20*jo.second;
            if ( val != MAP.end() )
            {
                cs += val->second;
                MAP.at(jp->get_id() ) = cs;
            }
            else
                MAP[jp->get_id()] = cs;
        }

    }

    for ( auto jo : actors )
    {
        vector<Movie*> movs = mDb->get_movies_with_actor(jo.first);
        for ( auto jp : movs )
        {
            unordered_map<string, int>::iterator val = MAP.find(jp->get_id());
            int cs = 30*jo.second;
            if ( val != MAP.end() )
            {
                cs += val->second;
                MAP.at(jp->get_id() ) = cs;
            }
            else
                MAP[jp->get_id()] = cs;
        }
    }

    for ( auto jo : genres )
    {
        vector<Movie*> movs = mDb->get_movies_with_genre(jo.first);
        for ( auto jp : movs )
        {
            unordered_map<string, int>::iterator val = MAP.find(jp->get_id());
            int cs = 1*jo.second;
            if ( val != MAP.end() )
            {
                cs += val->second;
                MAP.at(jp->get_id() ) = cs;
            }
            else
                MAP[jp->get_id()] = cs;
        }

    }


    for ( auto p : watchHistory )
    {
        if ( MAP.find(p) != MAP.end() )
            MAP.erase(p);
    }

    vector<MovieAndRank> result;

        for ( int i = 0; i < movie_count; i ++ )
        {
            string maxID = "";
            int maxVal = 0;
            for ( auto p : MAP )
            {
                if ( p.second == maxVal )
                {
                    if ( mDb->get_movie_from_id(p.first)->get_rating() == mDb->get_movie_from_id(maxID)->get_rating() )
                    {
                        string t1 = mDb->get_movie_from_id(p.first)->get_title();
                        string t2 = mDb->get_movie_from_id(maxID)->get_title();
                        if ( t1[0] > t2[0] )
                        {
                            maxVal = p.second;
                            maxID = p.first;
                        }
                    }
                    else if ( mDb->get_movie_from_id(p.first)->get_rating() > mDb->get_movie_from_id(maxID)->get_rating() )
                    {
                        maxVal = p.second;
                        maxID = p.first;
                    }
                }
                else if ( p.second > maxVal )
                {
                    maxVal = p.second;
                    maxID = p.first;
                }
            }

            unordered_map<string, int>::iterator VAL = MAP.find(maxID);
            if ( VAL != MAP.end() )
            {
                MovieAndRank mAr(VAL->first, VAL->second);
                result.push_back(mAr);
                MAP.erase(VAL);
            }


        }

    return result;



}


