# 🎵 Music Playlist Manager

A simple music playlist simulator using **Circular Doubly Linked List** in C.  
This project simulates adding, removing, and navigating through songs like a basic MP3 player.

## Features
- Add song to playlist
- Delete a song by name
- View current song
- Next / Previous navigation
- Circular loop
- Free memory on exit

## Build & Run
```bash
git clone https://github.com/pnackp/Music-Playlist-Manager.git
cd Music-Playlist-Manager
gcc main.c playlist.c utils.c -o playlist
./playlist
