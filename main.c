#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkList.h"
#include "SongLibrary.h"
int main(void) {
  srand(time(NULL));
  struct song_library * playlist = malloc(sizeof(struct song_library *));
  setup_lib(playlist);
  make_song(playlist,"green day", "wake me up when september ends");
  make_song(playlist,"good charlotte", "the anthem");
  make_song(playlist,"the goo goo dolls", "iris");
  make_song(playlist,"the killers", "mr. brightside");
  make_song(playlist,"avril lavigne", "sk8er boi");
  make_song(playlist,"green gay", "american idiot");
  make_song(playlist,"weezer", "buddy holly");
  make_song(playlist,"weezer", "say it ain't so");
  make_song(playlist, "green day", "21 guns");
  make_song(playlist, "green day", "delcome to paradise");
  make_song(playlist, "good charlotte", "lifestyles of the rich & famous");
  make_song(playlist, "weezer", "beverly hills");

  printf("LINKED LIST TESTS\n");
  printf("======================\n");
  printf("Testing print_list:\n");
  print_list(playlist->main_table[6]);
  printf("----------------------\n");
  printf("Testing print_song and search_song (American Idiot):\n");
  print_song(search_song(playlist->main_table[6], "green day", "american idiot"));
  printf("Testing print_song and search_song (The Anthem):\n");
  print_song(search_song(playlist->main_table[6], "good charlotte", "the anthem"));
  printf("Testing print_song and search_song (When I Come Around):\n");
  print_song(search_song(playlist->main_table[6], "green day", "when i come around"));
  printf("----------------------\n");
  printf("Testing s_cmp:\n");
  printf("Compare hello to hi: %d\n", s_cmp("hello", "hi"));
  printf("Compare hi to hello: %d\n", s_cmp("hi", "hello"));
  printf("Compare hi to hi: %d\n", s_cmp("hi", "hi"));
  printf("----------------------\n");
  printf("Testing random_node:\n");
  print_song(random_node(playlist->main_table[6]));
  printf("----------------------\n");
  printf("Testing remove_node (Buddy Holly):\n");
  print_list(playlist->main_table[22]);
  playlist->main_table[22] = remove_node(playlist->main_table[22], "weezer", "buddy holly");
  print_list(playlist->main_table[22]);
  printf("----------------------\n");
  printf("Testing free_list:\n");
  playlist->main_table[0] = free_list(playlist->main_table[0]);
  printf("\n======================\n");
  printf("MUSIC LIBRARY TESTS\n");
  printf("======================\n");
  printf("Testing print_library:\n");
  print_library(playlist);
  printf("----------------------\n");
  printf("Testing print_letter (t):\n");
  print_letter(playlist, 't');
  printf("Testing print_letter (k):\n");
  print_letter(playlist, 'k');
  printf("----------------------\n");
  printf("Testing find_song:\n");
  printf("Looking for Mr. Brightside by The Killers\n");
  if(find_song(playlist, "the killers", "mr. brightside")){
    printf("Found!\n");
  } else{
    printf("Not found!\n");
  }
  printf("Looking for Holiday by Green Day\n");
  if(find_song(playlist, "green day", "holiday")){
    printf("Found!\n");
  } else{
    printf("Not found!\n");
  }
  printf("----------------------\n");
  printf("Testing print_artist and find_artist:\n");
  print_artist(playlist, "green day");
  print_artist(playlist, "blink-182");
  printf("----------------------\n");
  printf("Testing delete_song:\n");
  playlist = delete_song(playlist,"avril lavigne", "sk8er boi");
  playlist = delete_song(playlist,"the killers", "mr. brightside");
  print_library(playlist);
  printf("----------------------\n");
  printf("Testing shuffle:\n");
  shuffle(playlist, 10);
  printf("----------------------\n");
  printf("Testing clear_library:\n");
  playlist = clear_library(playlist);
  print_library(playlist);
  printf("----------------------\n"); 
  return 0;
}
