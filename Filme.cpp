#include "Filme.h"
#include <Windows.h>
#include <shellapi.h>
#include <iostream>

Filme::Filme()
{
	// Fiecare film e unic dupa titlu,gen si an
}

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

void Filme::setLikes(int likes)
{
	this->likes = likes;
}

void Filme::setSource(std::string source)
{
	this->source = source;
}

void Filme::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}

void Filme::show()
{
	std::cout << this->getTitle() << ' ' << this->getGenre() << ' ' << this->getYear() << ' ' << this->getLikes() << ' ' << this->getSource() << '\n';
}

Filme::~Filme()
{

}