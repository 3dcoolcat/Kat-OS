#include <stdio.h> /*adds stdio to file*/
#include <sys/types.h> /*adds sys/types to file*/
#include <unistd.h> /*adds unistd to file*/
#include <dirent.h> /*adds dirent to file*/
int main() { /*initializes the file*/
  char str[100]; /*creates a 100 character variable*/
  char *args[]={"main",NULL};
  
  printf("please enter a command :"); /*asks you to enter a command*/
  gets( str ); //saves your input to str
  DIR *folder; //initialises folder
  struct dirent *entry; //loads file info into entry
  int files = 0; //creates a new variable "files" and sets it to 0
  
  folder = opendir(str); //opens the specified directory
  if(folder == NULL) { //if no directory can be found, program quits
  perror("Unable to read directory");
      return(1);
  }
  
  while( (entry=readdir(folder)) ) { //sees if the directory has any entries and if so, prints their names to the screen
    if (fork() == 0); //creates a child program to execute a file
      execvp(args[0],args); //opens the file
    else
      closedir(folder); //closes the directory

  return(0);
}
