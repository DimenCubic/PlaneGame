#include<stdio.h>
#include<graphics.h>

IMAGE bk;
IMAGE img_plane[2]; // Plane 

enum Axis {
	
	// BK
	WIDTH = 480,          
    HEIGHT = 850
};

struct PLANE {
	int x;
	int y;
	bool live;
}player;


// Initialize plane
void planeInit() {
	player.x = WIDTH / 2;
	player.y = HEIGHT - 120;
	player.live = true;
}


void loadImg() {
	// Initilization picture.
	loadimage(&bk, "material\\Background.jpg");
	
	// Load plane picture
	loadimage(&img_plane[0], "material\\Plane.jpg");
	//loadimage(&img_plane[1], "material\\Enemy.jpg");
}

void gameDraw() {
	
	// Initilization
	loadImg();
	
	// Draw Pictures
	putimage(0, 0, &bk); 

	 
	putimage(player.x, player.y, &img_plane[0]);
	//putimage(WIDTH/2, 0, &img_plane[1]);
	
	

}


int main()
{
	// Game window
	initgraph(480, 850);

	planeInit();
	
	

	// Two cache technique - deal with flash
	BeginBatchDraw();
	while (1) {
		gameDraw();
		FlushBatchDraw();
	}
	 
	return 0;
}

 
