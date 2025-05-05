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
	
	loadimage(&img_plane[0], "material\\Plane.webp");
	loadimage(&img_plane[1], "material\\Enemy.png");
}

void gameDraw() {
	
	// Initilization
	loadImg();
	
	// Draw Pictures
	//putimage(0, 0, &bk); 

	 
	putimage(WIDTH/2, HEIGHT - 120, &img_plane[0]);
	putimage(WIDTH / 2, HEIGHT , &img_plane[1]);
	
	

}


int main()
{
	// Game window
	initgraph(480, 850);

	gameDraw();
	
	
	while (1);

	return 0;
}

 
