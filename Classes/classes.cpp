/*
Nathan Taylor
11/5/2018
Database of Media made with classes
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
#include <cstdlib>
#include <cmath>
#include "media.h"
#include "movies.h"
#include "videogames.h"
#include "music.h"

using namespace std;

void mediaTypeSplitter(vector <media*>* list);
void addMusic(vector <media*>* list);
void addMovie(vector <media*>* list);
void addVideoGame(vector <media*>* list);
void searchMedia(vector <media*>* list, bool delt);
int arrayToInteger(char* inputArray);
void printInfo(media* parent);

int main()
{
  /*vector of media*/
  vector <media*>* list = new vector <media*>();
  char mainprompt;
  mainprompt = '-';
  /*Intro*/
  cout << endl << "Welcome to the Media Database!" << endl << "Commands: " << endl << endl;
  cout << "'add' - Add a new object to the database" << endl;
  cout << "'search' - Allows the user to search for an object in the database" << endl;
  cout << "'delete' - Allows user to search for and delete specific objects in the database" << endl;
  cout << "'quit' - End the program" << endl;

  while (mainprompt != 'q')
    {
      if (mainprompt == 'a')
	{
	  cout << endl << "Add Function" << endl;
	  mediaTypeSplitter(list);
	}
      else if (mainprompt == 's')
	{
	  cout << endl << "Search Function" << endl;
	  searchMedia(list, false);
	}
      else if (mainprompt == 'd')
	{
	  cout << endl << "Delete Function" << endl;
	  searchMedia(list, true);
	}

      /*input user command*/
      mainprompt = '-';
      cout << endl << "Command: ";
      cin.get(mainprompt);
      while (cin.get() != '\n');
    }
  cout << "Aborted (core dumped)\t\t\t\t-jk" << endl;
  return 0;
}

/*Determines which media the user wants to add*/
void mediaTypeSplitter(vector <media*>* list)
{
  char command[2];
  command[0] = '-';
  command[1] = '-';
  while (command[1] != 'i' && command[1] != 'o' && command[1] != 'u')
    {
      command[0] = '-';
      command[1] = '-';
      cout << "Media Type: ";
      cin.get(command, 3);
      while (cin.get() != '\n');
    }
  /*Test for Media type entry*/
  if (command[1] == 'i')
    {
      cout << "Video Game Media" << endl;
      addVideoGame(list);
    }
  else if (command[1] == 'o')
    {
      cout << "Movie Media" << endl;
      addMovie(list);
    }
  else if (command[1] == 'u')
    {
      cout << "Music Media" << endl;
      addMusic(list);
    }
  
  return;
}

/*protocol for adding music to the database*/
void addMusic(vector <media*>* list)
{
  /*input variable*/
  char input[80];
  /*Music Descriptions*/
  char* title = new char[80];
  char* artist = new char[80];
  char* publisher = new char[80];
  /*create music class*/
  
  cout << endl << "Year: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  int year = arrayToInteger(input);
  
  cout << "Title: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  strcpy(title, input);
  
  cout << "Artist: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  strcpy(artist, input);
 
  cout << "Duration(seconds): ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  int duration = arrayToInteger(input);
  
  cout << "Publisher: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  strcpy(publisher, input);
  
  /*create the class with the new information*/
  music* nmuse = new music(title, year, 1/*type*/, duration, artist, publisher);
  
  //
  //add it to the media vector
  list -> push_back(nmuse);
  //  
  return;
}
/*protocol for adding movies to the database*/
void addMovie(vector <media*>* list)
{
  /*input variable*/
  char input[80];
  /*Descriptions*/
  char* title = new char[80];
  char* director = new char[80];
  /*create class*/
  
  cout << endl << "Year: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  int year = arrayToInteger(input);;

  cout << "Title: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  strcpy(title, input);
  
  cout << "Director: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  strcpy(director, input);
 
  cout << "Duration(seconds): ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  int duration = arrayToInteger(input);
  
  cout << "Rating(1-80): ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  int rating = arrayToInteger(input);
  
  /*create the class with the new information*/
  movies* nmov = new movies (title, year, 3/*type*/, director, duration, rating);
  
  /*add it to the media vector*/
  list -> push_back(nmov);

  return;
}

/*protocol for adding video games to the database*/
void addVideoGame(vector <media*>* list)
{
  /*input variable*/
  char input[80];
  /*Descriptions*/
  char* title = new char[80];
  char* publisher = new char[80];
  /*create class*/
  
  cout << endl << "Year: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  int year = arrayToInteger(input);
  
  cout << "Title: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  strcpy(title, input);

  cout << "Rating(1-80): ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  int rating = arrayToInteger(input);
  
  cout << "Publisher: ";
  cin.get(input, 80);
  while (cin.get() != '\n');
  strcpy(publisher, input);

  /*create the class with the new information*/
  videogames* nvid = new videogames (title, year, 2/*type*/, rating, publisher);

  /*add it to the media vector*/
  list -> push_back(nvid);

  return;
}

/*search method*/
void searchMedia(vector <media*>* list, bool delt)
{
  char search[80];
  bool match = false;

  cout << "Search by: ";
  cin.get(search, 80);
  while (cin.get() != '\n');
  
  if (search[0] == 't')
    {
      /*search by title*/
      cout << "Title: ";
      cin.get(search, 80);
      while (cin.get() != '\n');
      //
      vector <media*>::iterator it;
      int i = 1;

      for (it = list -> begin(); it != list -> end(); it++, i++)
	{
	  if (strcmp((*it) -> title, search) == 0)//apparently it compares ascii values by subtracting
	    {
	      match = true;
	      cout << endl << "Source " << i << endl;
	      printInfo(*it);
	      if (delt)
		{
		  cout << endl << "Do you want to delete this media?: ";
		  char yn[80];
		  cin.get(yn, 80);
		  while (cin.get() != '\n');
		  if (yn[0] == 'y')
		    {
		      cout << "Media Deleted" << endl;
		      list -> erase(it);
		      delete *it;
		      break;
		    }
		}
	    }
	}
	
    }
  else
    {
      /*search by year*/
      cout << "Year: ";
      cin.get(search, 80);
      while (cin.get() != '\n');
      int year = arrayToInteger(search); //atoi

      vector <media*>::iterator it;
      int i = 1;
      for (it = list -> begin(); it != list -> end(); it++, i++)
	{
	  if ((*it) -> year == year)
	    {
	      match = true;
	      cout << endl << "Source " << i << endl;
	      printInfo(*it);
	      if (delt)
		{
		  cout << endl << "Do you want to delete this media?: ";
		  char yn[80];
		  cin.get(yn, 80);
		  while (cin.get() != '\n');
		  if (yn[0] == 'y')
		    {
		      cout << "Media Deleted" << endl;
		      list -> erase(it);
		      delete *it;
		      break;
		    }
		}
	    }
	}
    }
  
  //No match found
  if (!match)
    {
      cout << endl << "No Match Found" << endl;
    }
    
  return;
}

int arrayToInteger (char* inputArray)
{
  int num = 0;
  for (int i = 0; i < strlen(inputArray); i++)
    {
      num += (inputArray[i] - 48) * pow(10, strlen(inputArray) - i - 1);
    }
  return num;
}

void printInfo (media* parent)
{
  if (parent -> type == 1)/*Music Media*/
    {
      /*https://stackoverflow.com/questions/24858067/c-polymorphism-from-parent-class-to-child*/
      music* child = static_cast<music*>(parent);
      /*print out*/
      cout << "Year: " << child -> year << endl;
      cout << "Title: " << child -> title << endl;
      cout << "Artist: " << child -> artist << endl;
      cout << "Duration: " << child -> duration << endl;
      cout << "Publisher: " << child -> publisher << endl;
    }
  else if (parent -> type == 2)/*Video game Media*/
    {
      videogames* child = static_cast<videogames*>(parent);
      cout << "Year: " << child -> year << endl;
      cout << "Title: " << child -> title << endl;
      cout << "Rating: " << child -> rating << endl;
      cout << "Publisher: " << child -> publisher << endl;
    }
  else if (parent -> type == 3)/*Movie Media*/
    {
      movies* child = static_cast<movies*>(parent);
      cout << "Year: " << child -> year << endl;
      cout << "Title: " << child -> title << endl;
      cout << "Director: " << child -> director << endl;
      cout << "Duration: " << child -> duration << endl;
      cout << "Rating: " << child -> rating << endl;
    }
  return;
}

  /*
vector <media*>::iterator it;
for (it = list -> begin(); it != list -> end(); it++)
{
    cout << (*it) -> title << endl;
}
   */
