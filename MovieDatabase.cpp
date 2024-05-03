//
//  MovieDatabase.cpp
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#include "MovieDatabase.h"
#include "Movie.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

MovieDatabase::MovieDatabase()
{
    // Replace this line with correct code.
}

//bool MovieDatabase::load(const string& filename)
//{
//    ifstream infile(filename);
//
//    if ( !infile )
//    {
//        cerr << "Error: Cannot open movies.txt!" << endl;
//        return false;
//    }
//
//        string iD, title, year, d, a, g;
//        float rating = 0;
//        vector<string> directors, actors, genres;
//        string s;
//        int i = 0;
//        while ( getline(infile, s) )
//        {
//            switch (i)
//            {
//                case 0:
//                    iD = s;
//                    i++;
//                    break;
//                case 1:
//                    title = s;
//                    i++;
//                    break;
//                case 2:
//                    year = s;
//                    i++;
//                    break;
//                case 3:
//                    d = s;
//                    directors = createVec(d);
//                    i++;
//                    break;
//                case 4:
//                    a = s;
//                    actors = createVec(a);
//                    i++;
//                    break;
//                case 5:
//                    g = s;
//                    genres = createVec(g);
//                    i++;
//                    break;
//                case 6:
//                    rating = stof(s);
//                    i++;
//                    break;
//                case 7:
//                    i = 0;
//                    Movie * m = new Movie(iD, title, year, directors, actors, genres, rating );
//                    movieItems.push_back(m);
//
//                    int slot = movieItems.size()-1;
//                    iDMap.insert( iD, slot);
//
//                    for ( vector<string>::iterator dit = directors.begin(); dit != directors.end(); dit++ )
//                        directorMap.insert(*dit, slot);
//                    for ( vector<string>::iterator ait = actors.begin(); ait != actors.end(); ait++ )
//                        actorMap.insert(*ait, slot);
//                    for ( vector<string>::iterator git = genres.begin(); git != genres.end(); git++ )
//                        genreMap.insert(*git, slot);
//                    break;
//            }
//        }
//
//    return true;
//}

Movie* MovieDatabase::get_movie_from_id(const string& id) const
{
    string ID = id;
    ID[0] = tolower(id[0]);
    ID[1] = tolower(id[1]);
    
    TreeMultimap<string, unsigned long>::Iterator i;
    i = iDMap.find(ID);
    
    if ( !i.is_valid() )
    {
        cerr << "This is not a valid ID";
        return nullptr;
    }
    
    return movieItems[i.get_value()];
    
}

vector<Movie*> MovieDatabase::get_movies_with_director(const string& director) const
{
    
    string DIRECTOR;
    for ( int i = 0; i < director.size(); i++ )
        DIRECTOR += tolower(director[i]);
    
    vector<Movie*> ret;
    
    TreeMultimap<string, unsigned long>::Iterator i;
    i = directorMap.find(DIRECTOR);
    
    if ( !i.is_valid() )
    {
        return ret;
    }
    
    while ( i.is_valid() )
    {
        ret.push_back( movieItems[i.get_value()] );
        i.advance();
    }
    
    return ret;
}


vector<Movie*> MovieDatabase::get_movies_with_actor(const string& actor) const
{
    
    string ACTOR;
    for ( int i = 0; i < actor.size(); i++ )
        ACTOR += tolower(actor[i]);

    vector<Movie*> ret;
    
    TreeMultimap<string, unsigned long>::Iterator i;
    i = actorMap.find(ACTOR);
    
    if ( !i.is_valid() )
    {
        return ret;
    }
    
    while ( i.is_valid() )
    {
        ret.push_back( movieItems[i.get_value()] );
        i.advance();
    }
    
    return ret;
}

vector<Movie*> MovieDatabase::get_movies_with_genre(const string& genre) const
{
    
    string GENRE;
    for ( int i = 0; i < genre.size(); i++ )
        GENRE += tolower(genre[i]);
    
    vector<Movie*> ret;
    
    TreeMultimap<string, unsigned long>::Iterator i;
    i = genreMap.find(GENRE);
    
    if ( !i.is_valid() )
    {
        return ret;
    }
    
    while ( i.is_valid() )
    {
        ret.push_back( movieItems[i.get_value()] );
        i.advance();
    }
    
    return ret;
}



void MovieDatabase::cleanVec()
{
    vector<Movie*>::iterator i = movieItems.begin();
    while ( i != movieItems.end() )
    {
        delete *i;
        i++;
    }
}




bool MovieDatabase::load(const string& filename)
{
    ifstream infile(filename);

    if ( !infile )
    {
        cerr << "Error: Cannot open movies.txt!" << endl;
        return false;
    }

        string iD, title, year, d, a, g;
        float rating = 0;
        vector<string> directors, actors, genres;
    
    
        string s;

        while ( getline(infile, s) )
        {
            
            string iD = s;
            string iDKEY = s;
            iDKEY[0] = tolower(iD[0]);
            iDKEY[1] = tolower(iD[1]);

            getline( infile, s);
            string title = s;
            string titleKEY;
            for ( int i = 0; i < title.size(); i++ )
                titleKEY += tolower(title[i]);
            
            
            getline( infile, s);
            string year = s;
            string yearKEY;
            for ( int i = 0; i < year.size(); i++ )
                yearKEY += tolower(year[i]);
            
            
            getline( infile, s);
            string d = s;
            vector<string> directors = createVec(d);
            string dKEY;
            for ( int i = 0; i < d.size(); i++ )
                dKEY += tolower(d[i]);
            vector<string> directorsKEY = createVec(dKEY);
            
            
            getline( infile, s);
            string a = s;
            vector<string> actors = createVec(a);
            string aKEY;
            for ( int i = 0; i < a.size(); i++ )
                aKEY += tolower(a[i]);
            vector<string> actorsKEY = createVec(aKEY);
            
            getline( infile, s);
            string g = s;
            vector<string> genres = createVec(g);
            string gKEY;
            for ( int i = 0; i < g.size(); i++ )
                gKEY += tolower(g[i]);
            vector<string> genresKEY = createVec(gKEY);
            
            getline( infile, s);
            float rating = stof( s );
            
            Movie * m = new Movie(iD, title, year, directors, actors, genres, rating);
            movieItems.push_back(m);
            unsigned long slot = movieItems.size()-1;
            iDMap.insert( iDKEY, slot);
            
            for ( vector<string>::iterator dit = directorsKEY.begin(); dit != directorsKEY.end(); dit++ )
                    directorMap.insert(*dit, slot);
            for ( vector<string>::iterator ait = actorsKEY.begin(); ait != actorsKEY.end(); ait++ )
                    actorMap.insert(*ait, slot);
            for ( vector<string>::iterator git = genresKEY.begin(); git != genresKEY.end(); git++ )
                    genreMap.insert(*git, slot);

            getline( infile, s);
            
        }
    
    
    return true;
}
