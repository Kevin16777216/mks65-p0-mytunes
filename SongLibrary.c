#include <stdlib.h>
#include <stdio.h>
#include "SongLibrary.h"
#include "LinkList.h"

void add_song(struct song_library *lib, struct song_node *song){
  int ch = getBucket(song->artist[0]);

  lib->main_table[ch] = insert(lib->main_table[ch], song);
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

void reset_lib(struct song_library *lib){
  int i;
  for(i = 0; i < 27; i++){
    lib->main_table[i] = realloc(lib->main_table[i], sizeof(struct song_node *));
    lib->main_table[i] = 0;
  }
}


struct song_library* clear_library(struct song_library *lib){
  int i;
  for(i = 0; i < 27; i++){
    lib->main_table[i] = free_list(lib->main_table[i]);
  }
  //reset_lib(lib);
  return lib;
}
void print_library(struct song_library *lib){
  printf("Printing List...\n");
  int i;
  for(i = 0; i < 27; i++){
    if(lib->main_table[i]){
      printf("%d",i);
      print_list(lib->main_table[i]);
    }
  }
}

void print_letter(struct song_library *lib, char c){
  int bucket = getBucket(c);
  print_list(lib->main_table[bucket]);
}

struct song_node* print_artist(struct song_library* lib, char *artist){
  struct song_node* start = find_artist(lib, artist);
  struct song_node* cpy = start;
  printf("Songs by %s:\n",artist);
  if(!start){
    printf("[]\n");
    return 0;
  }
  printf ("[");
  while (start)
  {
    printf ("%s by %s", start->name,artist);
    //Check if last element, if so, don't use comma and exit
    if (!(start->next) || strcmp(start->artist,artist)){
      break;
    }
    printf (", ");
    //go to next element
    start = start->next;
  }
  printf ("]\n");
  return cpy;
}

struct song_node* find_song(struct song_library* lib, char *artist, char *song){
  int i;
  struct song_node* tmp;
  for(i = 0; i < 27; i++){
    if(lib->main_table[i]){
      tmp = search_song(lib->main_table[i], artist, song);
      if(tmp) break;
    }
  }
  return tmp;
}


struct song_node* find_artist(struct song_library* lib, char* artist){
  int bucket = getBucket(artist[0]);
  return search_artist(lib->main_table[bucket], artist);
}

int numSongs(struct song_library *lib){
  int i;
  int n = 0;
  for(i = 0; i < 27; i++){
    n += sizeList(lib->main_table[i]);
    //printf("%d\n", sizeList(lib->main_table[i]));
  }
  return n;
}
void shuffle(struct song_library *lib, int n){
  int i;
  for(i = 0; i < n; i++){
    if (numSongs(lib) < 1){
      printf("No songs in playlist.\n");
      return;
    }
    int random = rand() % numSongs(lib) + 1;
    //printf("Random: %d\n", random);
    int j;
    for(j = 0; j < 27; j++){
      if(random > sizeList(lib->main_table[j])){
        random -= sizeList(lib->main_table[j]);
      }else{
        struct song_node * front = lib->main_table[j];
        while(random > 1){
          front = front -> next;
          random--;
        }
        print_song(front);
        break;
      }
    }
  }
}

struct song_library* delete_song(struct song_library* lib, char *artist, char *song){
 
 int bucket = getBucket(artist[0]);
 struct song_node* start = find_artist(lib, artist);
 if(search_song(start, artist, song)){
  printf("Removing %s by %s\n",song,artist);
  lib->main_table[bucket] = remove_node(lib->main_table[bucket],artist,song);
 } else{
  printf("%s by %s not found!\n", song, artist);
 }
 return lib;
}
