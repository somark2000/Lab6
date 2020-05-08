#include "Filme.h"
#include <Windows.h>
#include <shellapi.h>
#include "Utils.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Filme::Filme() : title(""), genre(""), year(), likes(), source("") {}

Filme::Filme(const std::string& title, const std::string& genre, const int year, const int likes, const std::string& source)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->source = source;
}

std::string Filme::getTitle() const
{
	return title;
}

std::string Filme::getGenre() const
{
	return genre;
}

int Filme::getYear() const
{
	return year;
}

int Filme::getLikes() const
{
	return likes;
}

std::string Filme::getSource() const
{
	return source;
}

void Filme::setTitle(std::string title)
{
	this->title = title;
}

void Filme::setGenre(std::string genre)
{
	this->genre = genre;
}

void Filme::setYear(int year)
{
	this->year = year;
}

void Filme::setLikes()
{
	this->likes = likes + 1;
}

void Filme::setLikesUpdate(int likes)
{
	this->likes = likes;
}

void Filme::setSource(std::string source)
{
	this->source = source;
}



bool Filme::operator==(const Filme & m)
{
	return (this->title == m.title and this->genre == m.genre);
}

void Filme::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}

void Filme::show()
{
	std::cout << this->getTitle() << ' ' << this->getGenre() << ' ' << this->getYear() << ' ' << this->getLikes() << ' ' << this->getSource() << '\n';
}

istream & operator>>(istream & is, Filme & m)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) // make sure all the starship data was valid
		return is;

	m.title = tokens[0];
	m.genre = tokens[1];
	m.year = stoi(tokens[2]);
	m.likes = stoi(tokens[3]);
	m.source = tokens[4];

	return is;

}

ostream & operator<<(ostream & os, const Filme & m)
{
	os << m.title << ", " << m.genre << ", " << m.year << ", " << m.likes << ", " << m.source << "\n";
	return os;
}
