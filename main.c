#include <stdio.h>
#include "LinkList.h"
#include "SongLibrary.h"
int main(void) {
  struct song_library * main_table = malloc(sizeof(struct song_library *));
  setup_lib(main_table);
  struct song_node * test;
  make_song(main_table, "ai","test");
  make_song(main_table, "Ai","test");
  make_song(main_table, "zi","atest");
  make_song(main_table, "zk","ctest");
  make_song(main_table, "zk","Cstruct");
  make_song(main_table, "zi","Cstruct");
  make_song(main_table, "zi","hello");
  make_song(main_table, "bc","ty");
  //print_artist(main_table,"zi");
  print_library(main_table);
  delete_song(main_table, "zi","hello");
  delete_song(main_table, "bc","ty");
  //printf("%s",lib_search_artist(main_table,"zk")->name );
  print_library(main_table);
  return 0;
}
