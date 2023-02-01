//
// Created by admin on 2023/1/31.
//
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>

#ifndef STUDY_AIRPLAY_H
#define STUDY_AIRPLAY_H
#define BG_WIDTH 400
#define BG_HEIGHT 600
#define MYAIR_WIDTH 40
#define MYAIR_HEIGHT 40
#define ENUMY_PLANE_WIDTH 25
#define ENUMY_PLANE_HEIGHT 25
#define BULLET_WIDTH 15
#define BULLET_HEIGHT 15
IMAGE img[4];
IMAGE imgbg;

void gammDraw();

void bulletMove(int i);

void playPlanet();

const int BULLET_NUM = 30;
const int ENEMY_NUM = 15;
 int SCORE_SUM = 0;

#endif //STUDY_AIRPLAY_H
struct PLAYER {
    int x;
    int y;
    bool live;
    int width;
    int height;
    int hp;
    int type;

} Player, bullet[BULLET_NUM], enemy[ENEMY_NUM];

void init() {
    loadimage(&img[0], "res\\game_bg.jpg", BG_WIDTH, BG_HEIGHT);
    loadimage(&imgbg, "..\\res\\game_bg.jpg", BG_WIDTH, BG_HEIGHT);
    loadimage(&img[1], "..\\res\\planet.jpg", MYAIR_WIDTH, MYAIR_HEIGHT);
    loadimage(&img[2], "..\\res\\enemy.jpg", ENUMY_PLANE_WIDTH, ENUMY_PLANE_HEIGHT);
    loadimage(&img[3], "..\\res\\bullet.jpg", BULLET_WIDTH, BULLET_HEIGHT);
    Player.x = BG_WIDTH / 2;
    Player.y = BG_HEIGHT - 100;
    Player.live = true;
    for (int i = 0; i < BULLET_NUM; ++i) {
        bullet[i].live = false;
        bullet[i].x = 0;
        bullet[i].y = 0;
    }
    for (int i = 0; i < ENEMY_NUM; ++i) {
        enemy[i].live = false;
        enemy[i].x = 25;
        enemy[i].y = 0;
        enemy[i].width = 25;
        enemy[i].height = 25;
        enemy[i].hp = 2;
    }
//    enemy[0].live = true;
//    enemy[0].x = 25;
//    enemy[0].y = 0;
//    enemy[0].hp = 100;
}

//创建子弹
void createBullet() {
    for (int i = 0; i < BULLET_NUM; ++i) {
        if (!bullet[i].live) {
//            bullet[i].x = Player.x + 13;
            bullet[i].x = Player.x-50 + rand() % 100;
//            bullet[i].y = Player.y - rand() % 100;
            bullet[i].y = Player.y - 15;
            bullet[i].live = true;
        }
    }
}
//创建敌机
void createEnemy() {
    for (int i = 0; i < ENEMY_NUM; ++i) {
        if (!enemy[i].live) {
            enemy[i].x = rand() % (BG_WIDTH - 20);
            enemy[i].y = rand() % 100;
            enemy[i].live = true;
            enemy[i].hp =4;
        }
    }
}

//定时器。；懒得封装了

bool timer2(int ms) {
    static DWORD t1, t2;
    if (t2 - t1 > ms) {
        createEnemy();
        t1 = t2;
        return true;
    }
    t2 = clock();
    return false;
}
//玩家移动
void playMove(int speed) {
    createBullet();
#if 0
    char key = _getch();
    switch (key) {

        case 'W':
        case 'w':
            Player.y -= speed;
            break;

        case 's':
        case 'S':
            Player.y += speed;
            break;

        case 'D':
        case 'd':
            Player.x += speed;
            break;

        case 'a':
        case 'A':
            Player.x -= speed;
            break;
    }
#elif 1
    if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
        if (Player.y > 0) {
            Player.y -= speed;
        }
    }

    if (GetAsyncKeyState(VK_DOWN)) {
        if (Player.y < BG_HEIGHT - MYAIR_HEIGHT) {
            Player.y += speed;
        }

    }

    if (GetAsyncKeyState(VK_LEFT)) {
        if (Player.x > 0 - 20) {
            Player.x -= speed;
        }

    }

    if (GetAsyncKeyState(VK_RIGHT)) {
        if (Player.x < BG_WIDTH - MYAIR_WIDTH + 20) {
            Player.x += speed;
        }

    }
//按住空格键发射子弹
    if (GetAsyncKeyState(VK_SPACE)&&timer2(50)) {
        createBullet();
    }


#endif

}

void enemyMove(int j) {
    for (int i = 0; i < ENEMY_NUM; ++i) {
        if (enemy[i].live) {
            enemy[i].y += j;
            if (enemy[i].y > BG_HEIGHT) {
                enemy[i].live = false;
            }
        }
    }

}

bool timer(int ms) {
    static DWORD t1, t2;
    if (t2 - t1 > ms) {
        createEnemy();
        t1 = t2;
        return true;
    }
    t2 = clock();
    return false;
}

void start() {
    initgraph(BG_WIDTH, BG_HEIGHT);
    init();

    std::cout << "start Hello, World!" << std::endl;
    // 在屏幕中央输出字符串
//    RECT r = {0, 0, 0, 0};
//    drawtext(_T("Hello World"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
//    getch();				//等待输入，以防立刻退出
//    closegraph();
    BeginBatchDraw();
    while (1) {
        static DWORD t1, t2;
        if (timer(500)) {
            createEnemy();
        }

        gammDraw();
        playPlanet();//碰撞检测
        FlushBatchDraw();
        bulletMove(3);
        enemyMove(1);
        playMove(6);

        Sleep(2);
    };
    EndBatchDraw();

}

void playPlanet() {
    for (int i = 0; i < ENEMY_NUM; ++i) {
        if (!enemy[i].live) {
            continue;
        }

        for (int K = 0; K < BULLET_NUM; ++K) {
            if (!bullet[K].live) {
                continue;
            }
            if (bullet[K].x > enemy[i].x && bullet[K].x < enemy[i].x + enemy[i].width
                && bullet[K].y > enemy[i].y && bullet[K].y < enemy[i].y + enemy[i].height
                    ) {
                bullet[K].live = false;
                enemy[i].hp--;
            }
        }
        if (enemy[i].hp <= 0) {
            ++SCORE_SUM;
            enemy[i].live = false;
        }
    }

}

//子弹移动
void bulletMove(int j) {
    for (int i = 0; i < BULLET_NUM; ++i) {
        if (bullet[i].live) {

            bullet[i].y -=j;
//            bullet[i].y -= i * 2;
            if (bullet[i].y < 0) {
                bullet[i].live = false;
            }
        }
    }

}

//绘制图像各种
void gammDraw() {

    putimage(0, 0, &imgbg);
    putimage(Player.x, Player.y, &img[1], NOTSRCERASE);
    putimage(Player.x, Player.y, &img[1], SRCINVERT);
    putchar(SCORE_SUM);
    //绘制子弹
    for (int i = 0; i < BULLET_NUM; ++i) {
        if (bullet[i].live) {
            putimage(bullet[i].x, bullet[i].y - i * 2, &img[3], NOTSRCERASE);
            putimage(bullet[i].x, bullet[i].y - i * 2, &img[3], SRCINVERT);
        }
    }
    //绘制敌机
    for (int i = 0; i < ENEMY_NUM; ++i) {
        if (enemy[i].live) {
            putimage(enemy[i].x, enemy[i].y, &img[2], NOTSRCERASE);
            putimage(enemy[i].x, enemy[i].y, &img[2], SRCINVERT);
        }
    }
    // 输出字符串（MBCS 字符集）
    // 输出字符串（自适应字符集）
    CHAR str[] = "";

    sprintf(str, "SCORE = %d", SCORE_SUM);
    puts(str);
    outtextxy(10, 20,str);

}

