#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct Song{
	char title[100];
	struct Song* next;
	struct Song* prev;
}Song;

void addSong(char* title);
void deleteSong(char* title);
void showPlaylist();
void playCurrent();
void nextSong();
void prevSong();
void clearPlaylist();

#endif
