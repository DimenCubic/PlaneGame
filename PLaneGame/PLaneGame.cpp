#include<stdio.h>
#include<graphics.h>

IMAGE bk;
IMAGE img_plane[2]; // Plane and Enemy
IMAGE img_bullet;

enum Axis {

	// BK
	WIDTH = 480,
	HEIGHT = 850,

	//Bullet
	BULLET_NUM = 15
};

struct PLANE {
	int x;
	int y;
	bool live;
}player, bullet[BULLET_NUM];


// Initialize game
void gameInit() {
	
	//Initialize plane.
	player.x = WIDTH / 2;
	player.y = HEIGHT - 120;
	player.live = true;

	// Initilization bullet
	for (int i = 0; i < BULLET_NUM; i++) {
		bullet[i].x = 0;
		bullet[i].y = 0;
		bullet[i].live = false;
	}
}


void loadImg() {
	// Initilization Background.
	loadimage(&bk, "material\\Background.jpg");
	
	// Load pictures.
	loadimage(&img_plane[0], "material\\Plane.jpg");
	
	loadimage(&img_bullet, "material\\Bullet.jpg");
}

void gameDraw() {
	
	// Initilization
	loadImg();
	
	// Draw Pictures
	putimage(0, 0, &bk); 

	 
	putimage(player.x, player.y, &img_plane[0]);
	
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet[i].live) {
			putimage(bullet[i].x, bullet[i].y, &img_bullet);
		}
	}
	
}


void createBullet() {
	for (int i = 0; i < BULLET_NUM; i++) {
		if (!bullet[i].live) {
			
			//Generate one bullet.
			bullet[i].x = player.x + 40;
			bullet[i].y = player.y - 40;
			bullet[i].live = true;

			break;
		}
	}
}


void planeMove(int speed) {
	// Use Keyboard 
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
		
		if(player.y > 0) player.y -= speed;

	}

	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
		if (player.y < HEIGHT - 105) player.y += speed;
	}

	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
		if (player.x > 0) player.x -= speed;
	}

	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		if (player.x < WIDTH - 105) player.x += speed;
	}

	if (GetAsyncKeyState(VK_SPACE)) {
		
		//Generate one bullet.
		createBullet();           
	}
}

int main()
{
	// Game window
	initgraph(480, 850);

	gameInit();
	
	
	// Two cache technique - deal with flash
	BeginBatchDraw();
	while (1) {
		gameDraw();
		FlushBatchDraw();
		planeMove(3);
	}
	 
	return 0;
}

 
