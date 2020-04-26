#pragma once
#include "Filme.h"
#include <vector>
#include <iostream>
using namespace std;

template <class E>
class CrudRepository
{
public:
	virtual vector<E> read(std::string filename);
};

class Repo : public CrudRepository<Filme*>
{
	friend class contr_user;
	friend class contr_admin;
public:
	std::vector<Filme*> movies;
	std::vector<Filme*> watch_list;
	
	//constructor
	Repo();

	//destructor
	~Repo();

	//read from text
	 vector<Filme*> read(string filename);

};
