#include<stdio.h>
#include<graphics.h>
#include<time.h>

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

	// Test
	/*enemy[0].live = true;;
	enemy[0].x = 10;
	enemy[0].y = 10;*/

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

	 // Draw player
	putimage(player.x, player.y, &img_plane[0]);
	
	//Draw bullets
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet[i].live) {
			putimage(bullet[i].x, bullet[i].y, &img_bullet);
		}
	}

	// Draw enemy
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy[i].live) {
			putimage(enemy[i].x, enemy[i].y, &img_plane[1]);
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


// Create enemy, keep the maximum to ENEMY_NUM.
// Have fixed y and random x.
// One cycle only generate one enemy.
void createEnemy() {
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (!enemy[i].live) {
			enemy[i].live = true;
			enemy[i].y = 10;
			enemy[i].x = rand() % (WIDTH - 60);
			break;
		}
	}
}

// BUG 2: After finishing this function, I find all enemy planes will move together. I want them to move independently.
//    Solve :  1.Maybe can solve this problem by using the samr idea of bulletMove function? Increasing the generating time of the enemy planes.
void moveEnemy(int s) {
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy[i].live) {
			enemy[i].y += s;

			//Boundary check;
			if (enemy[i].y > HEIGHT) enemy[i].live = false;
		}

		
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
		bulletMove();
		//createEnemy();

		static DWORD t1, t2;
		if (t2 - t1 > 500) {
			createEnemy();
			t1 = t2;
		}
		t2 = clock(); // clock() using the CPU time, GetTickCount() using the system time.

		moveEnemy(1);
	}
	 


	return 0;
}

 
