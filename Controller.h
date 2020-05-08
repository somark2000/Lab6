#pragma once
#include "Repository.h"
#include "FileWatchlist.h"
#include "MovieValidator.h"
#include <memory>

class Controller
{
private:
	Repository repo;
	FileWatchlist* watchlist;
	MovieValidator validator;

public:
	Controller(const Repository& r, FileWatchlist* p, MovieValidator v) : repo{ r }, watchlist{ p }, validator{ v } {}

	Controller(const Controller& ctrl) = delete;		// controller cannot be copied now, because it contains unique_ptr
	void operator=(const Controller& ctrl) = delete;	// same for assignment

	Repository getRepo() const { return repo; }
	Watchlist* getWatchlist() const { return watchlist; }

	/*
	Adds a movie with the given data to the repo repository.
	Throws: MovieException - if the song is not valid
	DuplicateMovieException - if there is another song with the same artist and title
	Throws: FileException - if the repository file cannot be opened.
	*/
	void addMovieToRepository(const std::string &title, const std::string &genre, const int &year, const int &like, const std::string &trailer);

	void removeMovieFromRepository(const std::string& title, const std::string& genre, const int& year);

	void updateMovieFromRepository(const std::string& title, const std::string& genre, const int& year);
	/*
	Adds a given movie to the current Watchlist.
	Input: movie, must belong to the repository.
	Output: the movie is added to the Watchlist.
	*/
	void addMovieToWatchlist(const Filme& movie);

	void startWatchlist();
	void nextMovieWatchlist();
	void display();
	/*
	Saves the Watchlist.
	Throws: FileException - if the given file cannot be opened.
	*/
	void saveWatchlist(const std::string& filename);

	/*
	Removes given movie from watchlist
	*/
	void removeMovieFromWatchlist(const Filme& movie);

	/*
	Opens the Watchlist, with an appropriate application.
	Throws: FileException - if the given file cannot be opened.
	*/
	void openWatchlist() const;
};

