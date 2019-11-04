struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *list);
void print_song(struct song_node *song);
int s_cmp(char* s1,char * s2);
struct song_node * insert_front(struct song_node *, char* artist, char* name);
struct song_node * insert(struct song_node * front, struct song_node * new_song);
struct song_node * search_song(struct song_node * front, char * artist, char * name);
struct song_node * search_artist(struct song_node * front, char * artist);
struct song_node * free_list(struct song_node *);
struct song_node * remove_node(struct song_node *front, char* artist, char* name);
int sizeList(struct song_node *front);
struct song_node * random_node(struct song_node *front);