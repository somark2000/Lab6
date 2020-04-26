#pragma once
#include <iostream>
#include <string>
class Filme
{
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string source;		// youtube Link

public:
	// default constructor
	Filme();

	// constructor with parameters
	Filme(const std::string& title, const std::string& genre, const int year, const int likes, const std::string& source);

	std::string getTitle() const;
	std::string getGenre() const;
	int getYear() const;
	int getLikes() const;
	std::string getSource() const;

	void setTitle(std::string title);
	void setGenre(std::string genre);
	void setYear(int year);
	void setLikes(int likes);
	void setSource(std::string source);

	// Plays the current trailer: the page corresponding to the source link is opened in a browser.
	void play();

	//displays the current film
	void show();

	// destructor
	~Filme();
};

