 

#include<stdio.h>
#include<graphics.h>

IMAGE bk;
IMAGE img_plane[2]; // Plane 

void loadImg() {
	// Initilization picture.
	loadimage(&bk, "material\\Background.jpg");
	
	loadimage(&img_plane[0], "material\\Plane.jpg");
	loadimage(&img_plane[1], "material\\Enemy.jpg");
}

void gameDraw() {
	
	// Initilization
	loadImg();


}


int main()
{
	// Game window
	initgraph(480, 850);

	while (1);

	return 0;
}

 
