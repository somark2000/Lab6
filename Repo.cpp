#include "Repo.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Filme.h"
#include <sstream>
#include <string>

using namespace std;

Repo::Repo()
{
	movies=read("filme.csv");
	watch_list = read("watch.csv");
}

vector<Filme*> Repo::read(string filename)
{
	ifstream f(filename);
	string line,word;
	vector<Filme*>movie_list;//containerul care va fi returnat
	vector<std::string> row;
	int contor = 0;
	while (!f.eof())
	{
		getline(f,line);//citim o linie din csv
		stringstream ss(line);
		while (getline(ss,word,','))
		{
			row.push_back(word);
		}
		int a, b;
		try //se incearca convertirea de date
		{
			a = std::stoi(row[2]);
			b = std::stoi(row[3]);
		}
		catch (invalid_argument const& e)//daca apare eroare, aceasta este semnalata
		{
			cout << "Bad input: std::invalid_argument thrown at element in row "<<contor<<"\n";
		}

		Filme* film = new Filme(row[0], row[1], a,b, row[4]);
		movie_list.push_back(film);
	}
	f.close();
	return movie_list;
}