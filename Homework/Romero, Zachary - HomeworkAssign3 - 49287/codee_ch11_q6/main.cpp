#include <iostream>
#include <string>
#include <vector>

struct MovieData
{
    std::string title;      //movie title
    std::string director;   //movie director
    int yearRel;            //release date
    int runTime;            //movie run-time
};

int main()
{
    int sizeIn;
    std::cin >> sizeIn;
    MovieData *movies = new MovieData[sizeIn];
    std::cout << "This program reviews structures" << std::endl;
    std::cout << "Input how many movies, the Title of the Movie, Director, "
              << "Year Released, and the Running Time in (minutes)." << std::endl;
    std::cout << std::endl;
    
    for(int i = 0; i < sizeIn; i++)
    {
        std::cin.ignore();
        getline(std::cin,movies[i].title);
        getline(std::cin,movies[i].director);
        std::cin >> movies[i].yearRel;
        std::cin >> movies[i].runTime;
        
        std::cout << "Title:     " << movies[i].title << std::endl;
        std::cout << "Director:  " << movies[i].director << std::endl;
        std::cout << "Year:      " << movies[i].yearRel << std::endl;
        std::cout << "Length:    " << movies[i].runTime << std::endl;
        
        std::cout << std::endl;
    }
    delete [] movies;
    return 0;
}


