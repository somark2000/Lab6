#include "UI.h"
#include <string>
#include "MovieValidator.h"
#include "RepositoryExceptions.h"

using namespace std;

void UI::printMenu()
{
	cout << "Choose: " << endl;
	cout << "\t 1 - User Mode" << endl;
	cout << "\t 2 - Admin Mode" << endl;
	cout << "\t 0 - Exit" << endl;
}

void UI::printAdminMenu()
{
	cout << "Choose: " << endl;
	cout << "\t 1 - Add film" << endl;
	cout << "\t 2 - Remove film" << endl;
	cout << "\t 3 - Update film" << endl;
	cout << "\t 4- Show database\n";
	cout << "\t 0 - Return to main menu" << endl;
}

void UI::printUserMenu()
{
	cout << "Choose: " << endl;
	cout << "\t 1 - Search for something new" << endl;
	cout << "\t 2 - Remove viewed film" << endl;
	cout << "\t 3 - Display watch list" << endl;
	cout << "\t 4 - Save watch list" << endl;
	cout << "\t 5 - Open watch list" << endl;
	cout << "\t 0 - Return to main menu" << endl;
}

void UI::addMovieToRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	int year;
	cout << "Enter the year: ";
	cin >> year;
	cin.ignore();
	int like;
	cout << "Enter the number of likes: ";
	cin >> like;
	cin.ignore();
	cout << "Trailer: ";
	std::string trailer;
	getline(cin, trailer);

	try
	{
		this->ctrl.addMovieToRepository(title, genre, year, like, trailer);
	}
	catch (MovieException& e)
	{
		for (auto s : e.getErrors())
			cout << s;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::removeMovieFromRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the year: ";
	int year;
	cin>>year;

	try
	{
		this->ctrl.removeMovieFromRepository(title, genre, year);
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::updateMovieFromRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the year: ";
	int year;
	cin >> year;
	try
	{
		this->ctrl.updateMovieFromRepository(title, genre, year);
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::displayAllMoviesRepo()
{
	vector<Filme> movielist = this->ctrl.getRepo().getMovies();
	if (movielist.size() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}

	for (auto m : movielist)
	{
		cout << m << endl;
	}
}

void UI::addMovieToWatchlist()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the year: ";
	int year;
	cin >> year;
	// search for the movie in the repository
	try
	{
		Filme m = this->ctrl.getRepo().findByTitleandGenre(title, genre, year);
		this->ctrl.addMovieToWatchlist(m);
	}
	catch (InexistentMovieException& e)
	{
		cout << e.what();
		cout << "Nothing will be added to the playlist." << endl;
	}
}

void UI::saveWatchlistToFile()
{
	std::string filename;
	cout << "Input the file name (absolute path): ";
	getline(cin, filename);

	try
	{
		this->ctrl.saveWatchlist(filename);

		if (this->ctrl.getWatchlist() == nullptr)
		{
			cout << "Watchlist cannot be displayed!" << endl;
			return;
		}
	}
	catch (FileException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::removeMovieFromWatchlist()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	cout << "Enter the year: ";
	int year;
	cin >> year;

	try
	{
		Filme m = this->ctrl.getRepo().findByTitleandGenre(title, genre, year);
		this->ctrl.removeMovieFromWatchlist(m);
	}
	catch (InexistentMovieException& e)
	{
		cout << e.what();
		cout << "Nothing will be removed from the watch list." << endl;
	}
}

void UI::view()
{
	std::string s;
	cout << "Please enter a genre you are searching for: ";
	getline(cin, s);
	//getline(cin, s);
	vector<Filme> v;
	if (s == "")
	{
		cout << "The string is empty!" << endl;
		v= this->ctrl.getRepo().getMovies();
	}
	else
	{
		v= ctrl.addgenre(s);
	}
	int i = 0;
	bool f = true;
	while (i != v.size() and f)
	{
		v[i].show();
		cout << "Do you want to play it? (y/n) ";
		cin >> s;
		if (s == "y") {
			v[i].play();
		}
		cout << "Do you want to add this film to your watchlist?(y/n) ";
		cin >> s;
		if (s == "y")
		{
			ctrl.addMovieToWatchlist(v[i]);
			cout << "Film added succesfully\n";
		}
		cout << "Do you want to continue?(y/n) ";
		cin >> s;
		if (s == "y")
		{
			i++;
		}
		else
		{
			f = false;
		}
	}
	if (f) cout << "You watched all our films\n";
}


void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// admin management
		if (command == 2)
		{
			while (true)
			{
				UI::printAdminMenu();
				int commandRepo=0;
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addMovieToRepo();
					break;
				case 2:
					this->removeMovieFromRepo();
					break;
				case 3:
					this->updateMovieFromRepo();
					break;
				case 4:
					this->displayAllMoviesRepo();
					break;
				}
			}
		}

		// user management
		if (command == 1)
		{
			while (true)
			{
				UI::printUserMenu();
				int commandPlaylist{ 0 };
				cout << "Input the command: ";
				cin >> commandPlaylist;
				cin.ignore();
				if (commandPlaylist == 0)
					break;
				switch (commandPlaylist)
				{
				case 1://search
				{
					this->view();
					break;
				}
				case 2:
				{
					if (this->ctrl.getWatchlist()->isEmpty())
					{
						cout << "Watch list is empty." << endl;
						continue;
					}
					this->removeMovieFromWatchlist();
					break;
				}
				case 3:
				{
					if (this->ctrl.getWatchlist()->isEmpty())
					{
						cout << "Nothing to display, the watch list is empty." << endl;
						continue;
					}
					this->ctrl.display();
					break;
				}
				case 4:
				{
					this->saveWatchlistToFile();
					break;
				}
				case 5:
				{
					this->ctrl.openWatchlist();
					break;
				}
				}
			}
		}
	}
}