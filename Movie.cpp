//
//  Movie.cpp
//  Pnet Phlix
//
//  Created by Callum Lavezzo on 3/10/23.
//

#include "Movie.h"

#include <string>
#include <vector>
using namespace std;

Movie::Movie(const string& id, const string& title, const string& release_year,
             const vector<string>& directors, const vector<string>& actors,
             const vector<string>& genres, float rating)
{
    m_iD = id;
    m_title = title;
    m_year = release_year;
    m_rating = rating;
    
    vector<string>::const_iterator i = directors.begin();
    while ( i != directors.end() )
    {
        m_directors.push_back(*i);
        i++;
    }

    vector<string>::const_iterator i2 = actors.begin();
    while ( i2 != actors.end() )
    {
        m_actors.push_back(*i2);
        i2++;
    }

    vector<string>::const_iterator i3 = genres.begin();
    while ( i3 != genres.end() )
    {
        m_genres.push_back(*i3);
        i3++;
    }
}

string Movie::get_id() const
{
    return m_iD;
}

string Movie::get_title() const
{
    return m_title;
}

string Movie::get_release_year() const
{
    return m_year;
}

float Movie::get_rating() const
{
    return m_rating;
}

vector<string> Movie::get_directors() const
{
    return m_directors;
}

vector<string> Movie::get_actors() const
{
    return m_actors;
}

vector<string> Movie::get_genres() const
{
    return m_genres;
}
