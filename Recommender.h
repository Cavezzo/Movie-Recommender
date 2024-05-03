//
//  Recommender.h
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#ifndef Recommender_h
#define Recommender_h

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "treemm.h"
#include "UserDatabase.h"
#include "MovieDatabase.h"

class Movie;
class User;

struct MovieAndRank
{
    MovieAndRank(const std::string& id, int score)
     : movie_id(id), compatibility_score(score)
    {}

    std::string movie_id;
    int compatibility_score;
};

class Recommender
{
  public:
    Recommender(const UserDatabase& user_database,
                const MovieDatabase& movie_database);
    std::vector<MovieAndRank> recommend_movies(const std::string& user_email,
                                               int movie_count);

  private:
    UserDatabase *uDb;
    MovieDatabase *mDb;
};

#endif /* Recommender_h */
