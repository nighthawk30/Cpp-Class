#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
#include <cmath>
//#include "media.h"
//#include "movies.h"
//#include "videogames.h"
#include "music.h"

using namespace std;

void mediaTypeSplitter();
void addMusic();
void addMovie();
void addVideoGame();
void searchMedia();
void deleteMedia();

int main()
{
  //char* t = new char[10];
  //media* m = new media(t);
  //vector of media
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
	  mediaTypeSplitter();
	}
      else if (command == 's')
	{
	  cout << endl << "Search Function" << endl;
	  searchMedia();
	}
      else if (command == 'd')
	{
	  cout << endl << "Delete Function" << endl;
	  deleteMedia();
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
void mediaTypeSplitter()
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
      addVideoGame();
    }
  else if (command[1] == 'o')
    {
      cout << "Movie Media" << endl;
      addMovie();
    }
  else if (command[1] == 'u')
    {
      cout << "Music Media" << endl;
      addMusic();
    }
  return;
}

//protocol for adding music to the database
void addMusic()
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
  music* nmuse = new music(title, year, duration, artist, publisher);

  //print test
  cout << endl << "Year: " << nmuse -> year << endl;
  cout << "Title: " << nmuse -> title << endl;
  cout << "Artist: " << nmuse -> artist << endl;
  cout << "Duration: " << nmuse -> duration << endl;
  cout << "Publisher: " << nmuse -> publisher << endl;
  return;
}
//protocol for adding movies to the database
void addMovie()
{
  return;
}
//protocol for adding video games to the database
void addVideoGame()
{
  return;
}

void searchMedia()
{
  return;
}

void deleteMedia()
{
  return;
}
