#include<stdio.h>
#include<graphics.h>

IMAGE bk;
IMAGE img_plane[2]; // Plane 

enum Axis {
	
	// BK
	WIDTH = 480,          
    HEIGHT = 850
};


void loadImg() {
	// Initilization picture.
	loadimage(&bk, "material\\Background.jpg");
	
	// Load plane picture
	loadimage(&img_plane[0], "material\\Plane.jpg");
	loadimage(&img_plane[1], "material\\Enemy.jpg");
}

void gameDraw() {
	
	// Initilization
	loadImg();
	
	// Draw Pictures
	putimage(0, 0, &bk); 

	 
	putimage(WIDTH/2, HEIGHT - 120, &img_plane[0]);
	putimage(WIDTH/2, 0, &img_plane[1]);
	
	

}


int main()
{
	// Game window
	initgraph(480, 850);

	gameDraw();
	
	
	while (1);

	return 0;
}

 
