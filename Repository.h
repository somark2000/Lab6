#pragma once
#include "Filme.h"
#include <vector>

class Repository
{
private:
	std::vector<Filme> movielist;
	std::string filename;

public:
	/*
	Constructor with parameters.
	Initializes an object of type repository, by reading data from the given file.
	Throws: FileException - if the file cannot be opened.
	*/
	Repository(const std::string& filename);

	/*
	Adds a movie to the repository.
	Input: m - Movie.
	Output: the movie is added to the repository.
	Throws: FileException - if the file cannot be opened.
	DuplicateMovieException - if there is another song with the same artist and title.
	*/
	void addMovie(const Filme& m);

	/*
	Removes the movie with the given genre and title.
	Throws: InexistenSongException - if there are no songs with the given artist and title.
	*/
	void removeMovie(const Filme& m);

	/*
	Updates the movie with the given genre and title.
	Throws: InexistenSongException - if there are no songs with the given artist and title.
	*/
	void updateMovie(const Filme& m);

	/*
	Finds a movie, by title and gerne.
	Input: gerne, title - string
	Output: the movie that was found, or an "empty" movie (all fields empty and duration 0), if nothing was found.
	*/
	Filme findByTitleandGenre(const std::string& title, const std::string& genre, const int& year) const;

	std::vector<Filme> getMovies() const { return movielist; }

private:
	void readFromFile();
	void writeToFile();
};