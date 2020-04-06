#include<stdio.h>
#include<Bangtal.h>
#pragma comment(lib, "Bangtal.lib")

SceneID scene1, scene2;
ObjectID img00, img01, img02, img10, img11, img12, img20, img21, img22;
ObjectID startButton, endButton, playButton;
TimerID timer1;

ObjectID img[3][3] = {
	{img00, img01, img02},
	{img10, img11, img12},
	{img20, img21, img22}
};

int X[3] = { 420, 740, 1060 };
int Y[3] = { 738, 526, 318 };
float scale = 1.0;
bool win;


void Puzzle() {
	locateObject(img00, scene2, X[1], Y[0]);
	locateObject(img01, scene2, X[2], Y[0]);
	locateObject(img02, scene2, X[1], Y[2]);
	locateObject(img10, scene2, X[2], Y[0]);
	locateObject(img11, scene2, X[0], Y[0]);
	locateObject(img12, scene2, X[1], Y[1]);
	locateObject(img20, scene2, X[0], Y[1]);
	locateObject(img21, scene2, X[0], Y[2]);
}

void endGame(bool success) {
	if (success) {
		showMessage("선물 배달 성공~~");
	}
	else {
		showMessage("선물 배달 실패..");
	}
	hideObject(playButton);
	setObjectImage(startButton, "restart.png");
	showObject(startButton);
	showObject(endButton);

	stopTimer(timer1);
}

void startGame() {
	hideObject(startButton);
	hideObject(endButton);
	enterScene(scene2);

	startTimer(timer1);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			showObject(img[i][j]);
		}
	}
	hideObject(img[2][2]);

	setTimer(timer1, 0);
	Puzzle();
}

void PuzzleMove() {
}

ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(name, image);
	locateObject(object, scene, x, y);
	if (shown) {
		showObject(object);
	}
	return object;
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == endButton) {
		endGame();
	}
	else if (object == startButton) {
		startGame();
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (object == img[i][j]) {
				if (action == MOUSE_DRAG_LEFT) {
				}
				else if (action == MOUSE_DRAG_RIGHT) {
				}
				else if (action == MOUSE_DRAG_UP) {
				}
				else if (action == MOUSE_DRAG_DOWN) {

				}
			}
		}
	}
}

int main() {
	int h = 0;

	setMouseCallback(mouseCallback);

	scene1 = createScene("고양이 퍼즐", "cat.jpg");
	scene2 = createScene("고양이 퍼즐", "공백.png");
	startButton = createObject("시작 버튼", "start.png", scene1, 900, 500, true);
	endButton = createObject("종료 버튼", "end.png", scene1, 900, 450, true);

	img00 = createObject("야옹이", "output\\cat_001.jpg", scene2, X[0], Y[0], true);
	scaleObject(img00, 0.5f);
	img01 = createObject("야옹이", "output\\cat_002.jpg", scene2, X[1], Y[0], true);
	scaleObject(img01, 0.5f);
	img02 = createObject("야옹이", "output\\cat_003.jpg", scene2, X[2], Y[0], true);
	scaleObject(img02, 0.5f);

	img10 = createObject("야옹이", "output\\cat_004.jpg", scene2, X[0], Y[1], true);
	scaleObject(img10, 0.5f);
	img11 = createObject("야옹이", "output\\cat_005.jpg", scene2, X[1], Y[1], true);
	scaleObject(img11, 0.5f);
	img12 = createObject("야옹이", "output\\cat_006.jpg", scene2, X[2], Y[1], true);
	scaleObject(img12, 0.5f);

	img20 = createObject("야옹이", "output\\cat_007.jpg", scene2, X[0], Y[2], true);
	scaleObject(img20, 0.5f);
	img21 = createObject("야옹이", "output\\cat_008.jpg", scene2, X[1], Y[2], true);
	scaleObject(img21, 0.5f);
	img22 = createObject("야옹이", "output\\cat_009.jpg", scene2, X[2], Y[2], true);
	scaleObject(img22, 0.5f);

	timer1 = createTimer();
	showTimer(timer1);

	startGame(scene1);
}