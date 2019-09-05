#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

const int SCREEN_WIDTH = 640; //������ �ʺ�
const int SCREEN_HEIGHT = 480; //������ ����

SDL_Window* gWindow = NULL; //������ ������
SDL_Surface* gScreenSurface = NULL; //�����쿡 ���� �����̽� ���

//�Լ� ����
bool init();

int main(void) {

	init();
	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e)!=0) {
			if (e.type == SDL_QUIT) quit = true;
		}
	}

	return 0;
}
bool init() {

	//SDL�ʱ�ȭ ���н�
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL �ʱ�ȭ ���� �εεεε�...");
		return false;
	}

	else {
		gWindow = SDL_CreateWindow(
			"WP", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
		);

		gScreenSurface = SDL_GetWindowSurface(gWindow);
	}

	return true;
}