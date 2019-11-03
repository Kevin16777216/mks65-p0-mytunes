#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

void print_list (struct song_node *list)
{
  if(!list){
    printf("[]");
    return;
  }
  printf ("[");
  while (list)
  {
    printf ("%s by %s", list->name, list->artist);
    //Check if last element, if so, don't use comma and exit
    if (!(list->next))break;
    printf (",");
    //go to next element
    list = list->next;
  }
  printf ("]\n");
}

struct song_node * insert_front (struct song_node *list, char *artist, char *name)
{
  struct song_node *n = malloc (sizeof (struct song_node));
  //set value
  strncpy (n->artist, artist, sizeof (n->artist));
  strncpy (n->name, name, sizeof (n->name));
  //Attach to front of list
  n->next = list;
  return n;
}
int s_cmp(char* s1,char * s2){
  if((tolower(*s1) == tolower(*s2)) && (*s1 || *s2))
    return s_cmp((s1 +1),(s2 +1));
  return tolower(*s1)-tolower(*s2);
}
struct song_node * insert(struct song_node * front, struct song_node * new_song){
  if(!front){
    return new_song;
  }
  struct song_node *trailingNode = front;
  struct song_node *currentNode = front->next;

  char* name = new_song->name;
  char* artist = new_song -> artist;

  //If at head, insert to front.
  int tmp = s_cmp(front->artist,artist);
  if (tmp >= 0)
  {
    //TODO:simplify this
    if (!(!tmp && (s_cmp(front->name,name) < 0))){
      new_song->next = front;
      return new_song;
    }
  }
  while (currentNode)
  {
    tmp = s_cmp(currentNode->artist,artist);
    if (tmp >= 0)
    {
      //TODO:simplify this
      if (!(!tmp && (s_cmp(currentNode->name,name) < 0))){
        trailingNode->next = new_song;
        new_song->next = currentNode;
        return front;
      }
    }
    //iterating both ptrs
    trailingNode = currentNode;
    currentNode = currentNode->next;
  }
  trailingNode->next = new_song;
  //return new font
  return front;
}

struct song_node * search_song(struct song_node * front, char * artist, char * name){

}

struct song_node * search_artist(struct song_node * front, char * artist){
  while (front)
  {
    if(!strcmp(front->artist,artist))break;
    front = front->next;
  }
  return front;
}

struct song_node * free_list (struct song_node *list)
{
  while (list)
  {
    struct song_node *next = list->next;
    printf ("Freeing song %s by %s\n", list->name, list->artist);
    free (list);
    list = next;
  }
  return list;
}

struct song_node * remove_node (struct song_node *front, char *artist, char *name)
{
  struct song_node *trailingNode = front;
  struct song_node *currentNode = front->next;
  //If at head, return next element.
  if (!strcmp(front->artist,artist) && !strcmp(front->name,name))
  {
    free (front);
    return currentNode;
  }
  while (currentNode)
  {
    if (!strcmp(currentNode->artist,artist) && !strcmp(currentNode->name,name))
    {
      //make new link
      trailingNode->next = currentNode->next;
      //remove old ptr
      free (currentNode);
      return front;
    }
    //iterating both ptrs
    trailingNode = currentNode;
    currentNode = currentNode->next;
  }
  //return new font
  return front;
}

struct song_node * random_node(struct song_node *front){
  
}