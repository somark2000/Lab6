#include "Repository.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include "RepositoryExceptions.h"
#include <iostream>
using namespace std;

Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repository::addMovie(const Filme& m)
{
	Filme m1{};
	try
	{
		m1 = this->findByTitleandGenre(m.getTitle(), m.getGenre(),m.getYear());
		throw DuplicateMovieException();
	}
	catch (InexistentMovieException& e) {}
	this->movielist.push_back(m);
	this->writeToFile();
}

void Repository::removeMovie(const Filme& m)
{
	auto it = find(this->movielist.begin(), this->movielist.end(), m);
	if (it == this->movielist.end())
		throw InexistentMovieException{};
	this->movielist.erase(it);
	this->writeToFile();
}

void Repository::updateMovie(const Filme& m)
{
	removeMovie(m);
	cout << "Current number of likes is: "<<m.getLikes();
	cout << "Do you want to change it?(y/n)";
	std::string w;
	Filme m1 = m;
	cin >> w;
	//throw ConsoleerrorChar("Your answer must be or the letter y or n");
	if (w == "y")
	{
		int likes;
		cout << "The new amount of likes is: ";
		cin >> likes;
		m1.setLikesUpdate(likes);
	}
	
	cout << "The current source is: " << m.getSource();
	cout << "Do you want to change it?(y/n)";
	cin >> w;
	if (w == "y")
	{
		std::string link;
		cout << "The new link is: ";
		cin >> link;
		m1.setSource(link);
	}
	addMovie(m1);
}

Filme Repository::findByTitleandGenre(const std::string& title, const std::string& genre, const int& year) const
{
	for (auto m : this->movielist)
	{
		if (m.getTitle() == title and m.getGenre() == genre and m.getYear()==year)
			return m;
	}

	throw InexistentMovieException{};
}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Filme m;
	while (file >> m)
		this->movielist.push_back(m);

	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto m : this->movielist)
	{
		file << m;
	}

	file.close();
}