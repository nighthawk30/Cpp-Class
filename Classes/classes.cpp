#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
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
void searchMedia(vector <media*>* list);
void deleteMedia(vector <media*>* list);

int main()
{
  //vector of media
  vector <media*>* list = new vector <media*>();
  char command = '-';
  //Intro
  cout << endl << "Welcome to the Media Database!" << endl << "Commands: " << endl << endl;
  cout << "'add' - Add a new object to the database" << endl;
  cout << "'search' - Allows the user to search for an object in the database" << endl;
  cout << "'delete' - Allows user to search for and delete specific objects in the database" << endl;
  cout << "'quit' - End the program" << endl;

  while (command != 'q')
    {
      if (command == 'a')
	{
	  cout << endl << "Add Function" << endl;
	  mediaTypeSplitter(list);
	}
      else if (command == 's')
	{
	  cout << endl << "Search Function" << endl;
	  searchMedia(list);
	}
      else if (command == 'd')
	{
	  cout << endl << "Delete Function" << endl;
	  deleteMedia(list);
	}

      //input user command
      command = '-';
      cout << endl << "Command: ";
      cin.get(command);
      while (cin.get() != '\n');
    }
  return 0;
}

//Determines which media the user wants to add
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
  //Test for Media type entry
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

//protocol for adding music to the database
void addMusic(vector <media*>* list)
{
  //input variable
  char input[10];
  //Music Descriptions
  char* title = new char[10];
  char* artist = new char[10];
  char* publisher = new char[10];
  //create music class
  
  
  cout << endl << "Year: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  int year = 0;
  for (int i = 0; i < strlen(input); i++)
    {
      year += (input[i] - 48) * pow(10, strlen(input) - i - 1);
    }

  cout << "Title: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  strcpy(title, input);
  
  cout << "Artist: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  strcpy(artist, input);
 
  cout << "Duration(seconds): ";
  cin.get(input, 10);
  int duration = 0;
  for (int i = 0; i < strlen(input); i++)
    {
      duration += (input[i] - 48) * pow(10, strlen(input) - i - 1);
    }
  while (cin.get() != '\n');
  
  cout << "Publisher: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  strcpy(publisher, input);

  //create the class with the new information
  music* nmuse = new music(title, year, 1/*type*/, duration, artist, publisher);

  //print test
  cout << endl << "Year: " << nmuse -> year << endl;
  cout << "Title: " << nmuse -> title << endl;
  cout << "Artist: " << nmuse -> artist << endl;
  cout << "Duration: " << nmuse -> duration << endl;
  cout << "Publisher: " << nmuse -> publisher << endl;
  cout << "Type: " << nmuse -> getType() << endl;

  //add it to the media vector
  list -> push_back(nmuse);
  
  return;
}
//protocol for adding movies to the database
void addMovie(vector <media*>* list)
{
  //input variable
  char input[10];
  //Descriptions
  char* title = new char[10];
  char* director = new char[10];
  //create class
  
  cout << endl << "Year: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  int year = 0;
  for (int i = 0; i < strlen(input); i++)
    {
      year += (input[i] - 48) * pow(10, strlen(input) - i - 1);
    }

  cout << "Title: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  strcpy(title, input);
  
  cout << "Director: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  strcpy(director, input);
 
  cout << "Duration(seconds): ";
  cin.get(input, 10);
  int duration = 0;
  for (int i = 0; i < strlen(input); i++)
    {
      duration += (input[i] - 48) * pow(10, strlen(input) - i - 1);
    }
  while (cin.get() != '\n');

  cout << "Rating(1-10): ";
  cin.get(input, 10);
  int rating = 0;
  for (int i = 0; i < strlen(input); i++)
    {
      rating += (input[i] - 48) * pow(10, strlen(input) - i - 1);
    }
  while (cin.get() != '\n');
  
  //create the class with the new information
  movies* nmov = new movies (title, year, 3/*type*/, director, duration, rating);

  //print test
  cout << endl << "Year: " << nmov -> year << endl;
  cout << "Title: " << nmov -> title << endl;
  cout << "Director: " << nmov -> director << endl;
  cout << "Duration: " << nmov -> duration << endl;
  cout << "Rating: " << nmov -> rating << endl;
  cout << "Type: " << nmov -> type << endl;

  //add it to the media vector
  list -> push_back(nmov);
  
  return;
}
//protocol for adding video games to the database
void addVideoGame(vector <media*>* list)
{
    //input variable
  char input[10];
  //Descriptions
  char* title = new char[10];
  char* publisher = new char[10];
  //create class
  
  cout << endl << "Year: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  int year = 0;
  for (int i = 0; i < strlen(input); i++)
    {
      year += (input[i] - 48) * pow(10, strlen(input) - i - 1);
    }
  
  cout << "Title: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  strcpy(title, input);

  cout << "Rating(1-10): ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  int rating = 0;
  for (int i = 0; i < strlen(input); i++)
    {
      rating += (input[i] - 48) * pow(10, strlen(input) - i - 1);
    }
  
  cout << "Publisher: ";
  cin.get(input, 10);
  while (cin.get() != '\n');
  strcpy(publisher, input);

  //create the class with the new information
  videogames* nvid = new videogames (title, year, 2/*type*/, rating, publisher);

  //print test
  cout << endl << "Year: " << nvid -> year << endl;
  cout << "Title: " << nvid -> title << endl;
  cout << "Rating: " << nvid -> rating << endl;
  cout << "Publisher: " << nvid -> publisher << endl;
  cout << "Type: " << nvid -> type << endl;

  //add it to the media vector
  list -> push_back(nvid);
  
  return;
}

void searchMedia()
{
  /*
vector <media*>::iterator it;
for (it = list -> begin(); it != lis -> end(); it++)
{
    cout << (*it) -> title << endl;
}
   */
  return;
}

void deleteMedia()
{

  /*
for loop:
list -> erase(it);
delete *it;
   */
  return;
}
