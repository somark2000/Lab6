#include "Watchlist.h"


Watchlist::Watchlist()
{
	this->current = 0;
}

void Watchlist::add(const Filme& movie)
{
	this->movielist.push_back(movie);
}

Filme Watchlist::getCurrentMovie()
{
	if (this->current == this->movielist.size())
		this->current = 0;
	return this->movielist[this->current];
	return Filme{};
}

void Watchlist::play()
{
	if (this->movielist.size() == 0)
		return;
	this->current = 0;
	Filme currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

void Watchlist::next()
{
	if (this->movielist.size() == 0)
		return;
	this->current++;
	Filme currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

bool Watchlist::isEmpty()
{
	return this->movielist.size() == 0;
}

void Watchlist::display()
{
	if (this->movielist.size() == 0)
		return;
	for (auto i = movielist.begin(); i != movielist.end(); ++i)
	{
		i->show();
	}
}

void Watchlist::removeFromWatchlist(const Filme& m)
{
	if (this->movielist.size() == 0)
		return;
	for (int i = 0; i != movielist.size(); ++i)
	{
		if (movielist.at(i) == m)
		{
			movielist.erase(movielist.begin() + i);
		}
	}
}

int Watchlist::size()
{
	return movielist.size();
}

