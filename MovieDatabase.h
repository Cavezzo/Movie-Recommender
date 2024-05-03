//
//  MovieDatabase.h
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#ifndef MovieDatabase_h
#define MovieDatabase_h

#include <stdio.h>
#include <string>
#include <vector>
#include "treemm.h"
using namespace std;
class Movie;

class MovieDatabase
{
  public:
    MovieDatabase();
    ~MovieDatabase()
    {
        cleanVec();
    }
    bool load(const std::string& filename);
    Movie* get_movie_from_id(const std::string& id) const;
    std::vector<Movie*> get_movies_with_director(const std::string& director) const;
    std::vector<Movie*> get_movies_with_actor(const std::string& actor) const;
    std::vector<Movie*> get_movies_with_genre(const std::string& genre) const;
    void func();
  private:
    std::vector<std::string> createVec( std::string s )
    {
        std::vector<std::string> v;
        int i = 0,j = 0;
        while( i < s.size() && j < s.size()){
            if ( s[j] == ',' )
            {
                v.push_back( s.substr(i,j-i) );
                i = j+1;
            }
            j++;
        }
        
        v.push_back(s.substr(i,j-i));
        
        return v;
    }
    
    
    std::vector<Movie*> movieItems;
    TreeMultimap<std::string, unsigned long> directorMap;
    TreeMultimap<std::string, unsigned long> actorMap;
    TreeMultimap<std::string, unsigned long> genreMap;
    TreeMultimap<std::string, unsigned long> iDMap;
    
    void cleanVec();

};

#endif /* MovieDatabase_h */
