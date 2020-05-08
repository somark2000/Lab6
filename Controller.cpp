#include "Controller.h"
#include <algorithm>
#include "FileWatchlist.h"
#include "RepositoryExceptions.h"

using namespace std;

void Controller::addMovieToRepository(const std::string &title, const std::string &genre, const int &year, const int &like, const std::string &trailer)
{
	Filme m{title, genre, year, like, trailer };
	this->validator.validate(m);
	this->repo.addMovie(m);
}

void Controller::removeMovieFromRepository(const std::string & title, const std::string & genre, const int& year)
{
	Filme m = this->repo.findByTitleandGenre(title, genre,year);
	this->repo.removeMovie(m);

}

void Controller::updateMovieFromRepository(const std::string& title, const std::string& genre, const int& year)
{
	Filme m = this->repo.findByTitleandGenre(title, genre,year);
	this->repo.updateMovie(m);
}

void Controller::addMovieToWatchlist(const Filme& movie)
{
	if (this->watchlist == nullptr)
		return;
	this->watchlist->add(movie);
}

void Controller::startWatchlist()
{
	if (this->watchlist == nullptr)
		return;
	this->watchlist->play();
}

void Controller::nextMovieWatchlist()
{
	if (this->watchlist == nullptr)
		return;
	this->watchlist->next();
}

void Controller::saveWatchlist(const std::string& filename)
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->setFilename(filename);
	this->watchlist->writeToFile();
}

void Controller::openWatchlist() const
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->displayWatchlist();
}

void Controller::display()
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->display();
}

void Controller::removeMovieFromWatchlist(const Filme& m)
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->removeFromWatchlist(m);
}