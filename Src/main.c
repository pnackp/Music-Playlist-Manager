#include <stdio.h>
#include "playlist.h"

int main() {
    int choice ; char name[100];
    do {
        printf("\n🎶 Playlist Manager 🎶\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Play Current Song\n");
        printf("4. Next Song\n");
        printf("5. Previous Song\n");
        printf("6. Show Playlist\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
		printf("Enter Name:");
		scanf("%s",name);
		addSong(name);
                break;
            case 2:
                printf("Enter Name:");
		scanf("%s",name);
		deleteSong(name); 
                break;
            case 3:
                playCurrent();
                break;
            case 4:
                nextSong();
                break;
            case 5:
                prevSong();
                break;
            case 6:
                showPlaylist();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}


