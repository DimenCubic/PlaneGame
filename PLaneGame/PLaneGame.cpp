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
	BULLET_NUM = 15,

	//Enemy
	ENEMY_NUM = 10
};

struct PLANE {
	int x;
	int y;
	bool live;

	// for enemy.
	int hp;

}player, bullet[BULLET_NUM], enemy[ENEMY_NUM];

 

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

	// Initilization enemy
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy[i].live = false;
		enemy[i].hp = 1;
	}

}


void loadImg() {
	// Initilization Background.
	loadimage(&bk, "material\\Background.jpg");
	
	// Load pictures.
	loadimage(&img_plane[0], "material\\Plane.jpg");
	
	loadimage(&img_bullet, "material\\Bullet.jpg");

	loadimage(&img_plane[1], "material\\Enemy.jpg");
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

void bulletMove() {
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet[i].live) {
			bullet[i].y -= 1;

			// Boundarty check.
			if (bullet[i].y < 0) bullet[i].live = false;
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

	
	
	static DWORD t1 = 0, t2 = 0;   // DWORD means unsigned long. t1 = last fire time, t2 = current time. milliseconds
	if (GetAsyncKeyState(VK_SPACE) && t2 - t1 > 100) {
		
		//BUG 1: It's not stable to generate several bullets as you want(It's a very weird performance, you will see multiple bullets sometime and only one bullet at another time). But what I want is the bullet should appear exactly when I click the space key.
		//   Solve: To slow the respond speed of this command artifically. 

		//Generate one bullet.
		createBullet();
		t1 = t2;
	}

	t2 = GetTickCount(); 
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
		bulletMove();
	}
	 


	return 0;
}

 
