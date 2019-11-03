#include <stdlib.h>
#include <stdio.h>
#include "SongLibrary.h"
#include "LinkList.h"

void add_song(struct song_library *lib, struct song_node *song){
  int ch = getBucket(song->artist[0]);
  struct song_node *tmp = insert(lib->main_table[ch], song);
  lib->main_table[ch] = tmp;
}
int getBucket(char *str){
  int ch = str;
  if(isalpha(ch)){
    if(ch > 96 && ch < 123){
      ch -=32;
    }
    ch-=65;
  }else{
    ch = 26;
  }
  return ch;
}

void make_song(struct song_library *lib, char *artist, char *song){
  struct song_node* output = malloc(sizeof(struct song_node));
  strncpy(output->artist,artist, sizeof(output->artist));
  strncpy(output->name,song, sizeof(output->name));
  add_song(lib, output);
}

void setup_lib(struct song_library *lib){
  int i;
  for(i = 0; i < 27; i++){
    lib->main_table[i] = malloc(sizeof(struct song_node *));
    lib->main_table[i] = 0;
  }
}
void print_library(struct song_library *lib){
  int i;
  for(i = 0; i < 27; i++){
    if(lib->main_table[i]){
      printf("%d",i);
      print_list(lib->main_table[i]);
    }
  }
}

void print_letter(struct song_library * lib){
  
}

struct song_node* print_artist(struct song_library* lib, char *artist){
  struct song_node* start = lib_search_artist(lib, artist);
  struct song_node* cpy = start;
  printf("Songs by %s:\n",artist);
  if(!start){
    printf("[]\n");
    return 0;
  }
  printf ("[");
  while (start)
  {
    printf ("Song %s by %s", start->name,artist);
    //Check if last element, if so, don't use comma and exit
    if (!(start->next) || strcmp(start->artist,artist)){
      break;
    }
    printf (",");
    //go to next element
    start = start->next;
  }
  printf ("]\n");
  return cpy;
}

struct song_node* lib_search_song(struct song_library* lib, char *song){
  int i;
  struct song_node* tmp = 0;
  for(i = 0; i < 27; i++){
    if(lib->main_table[i]){
      //search in list
    }
  }
  return tmp;
}


struct song_node* lib_search_artist(struct song_library* lib, char* artist){
  int bucket = getBucket(artist[0]);
  return search_artist(lib->main_table[bucket], artist);
}

void shuffle(struct song_library *lib){

}

struct song_library* delete_song(struct song_library* lib, char *artist, char *song){
 printf("Removing %s by %s\n",song,artist);
 int bucket = getBucket(artist[0]);
 struct song_node* start = lib_search_artist(lib, artist);
 lib->main_table[bucket] = remove_node(start,artist,song);
 return lib;
}

void clear_library(struct song_library *lib){
  int i;
  for(i = 0; lib->main_table[i]; i++){
    free_list(lib->main_table[i]);
  }
}