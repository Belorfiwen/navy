#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bateaux.h"
#include "grilles.h"
#include "fonctions.h"



#define BUFSIZE 256
#define CAPACITY 100 



int main() {

	setbuf(stdout, NULL);
	char buffer[BUFSIZE];


	// grilles

	struct grid1 grid;
	grid_create_joueur1(&grid);

	struct grid2 grid2;
	grid_create_joueur2(&grid2);


	// mines
	mine_placement('C', 2, &grid2);

	mine_placement('H', 2, &grid2);

	mine_placement('C', 7, &grid2);

	mine_placement('H', 7, &grid2);

	mine_placement('E', 5, &grid2);


	//bateaux

	struct ship a;
	ship_create(&a, 5, 'B', 1, 1);
	ship_placement(&grid, &a);

	struct ship b;
	ship_create(&b, 4, 'D', 7, 0);
	ship_placement(&grid, &b);

	struct ship c;
	ship_create(&c, 3, 'E', 2, 0);
	ship_placement(&grid, &c);

	struct ship d;
	ship_create(&d, 3, 'E', 4, 0);
	ship_placement(&grid, &d);

	struct ship e;
	ship_create(&e, 2, 'I', 1, 1);
	ship_placement(&grid, &e);
	
	start_or_kaboom(&grid2);

	affichage_grid_joueur1(&grid);
	fprintf(stderr, "\n");
	affichage_grid_joueur2(&grid2);

	size_t round = 0;

	char *poll[16] = {"B1","E1","H1","I1","B3","E3","H3","I3","B6","E6","H6","I6","B8","E8","H8","I8"};

	for (size_t j = 0; j < 16; ++j)
	{	
		size_t scan = 1;
		struct pos attack;
		attack.x = 0;
		attack.y = 0;
		do
		{
			round++;
			fprintf(stderr, "Round : %zu\n\nMon tour : \n", round);
			if (scan == 1)
			{
				scan = action_poll(&grid2, poll[j], &attack);
			}
			else
			{
				char x = ((char)attack.x+65);
				size_t y = attack.y;

				//envoie d'un tir
				printf("SHOOT\n"); // or POLL or MOVE 
				printf("%c%zu\n",x,y);
				grid2.size++;

				// recuperation resultat d'un tir
				fgets(buffer, BUFSIZE, stdin);
				if(strcmp(buffer, "MISS\n") == 0)
				{
					fprintf(stderr, "Tir raté : %c%zu\n", x,y);
					grid2.data[attack.x][attack.y] = 4; // marquage du tir raté, sur la grille adverse.
				}
				else
				{
					fprintf(stderr, "Tir reussi : %c%zu\n", x,y);
					grid2.data[attack.x][attack.y] = 2; // marquage du tir raté, sur la grille adverse.
				}
				scan = 1;
			}
			fprintf(stderr, "coucouc\n");
			tour_adverse(&grid2,&grid);

			affichage_grid_joueur1(&grid);
			fprintf(stderr, "\n");
			affichage_grid_joueur2(&grid2);

		} while (scan != 0);
	} 
	return EXIT_SUCCESS;
}