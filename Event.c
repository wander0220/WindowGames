#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

const int SCREEN_WIDTH = 640; //윈도우 너비
const int SCREEN_HEIGHT = 480; //윈도우 높이

SDL_Window* gWindow = NULL; //생성할 윈도우
SDL_Surface* gScreenSurface = NULL; //윈도우에 담을 설페이스 요맨

//함수 정의
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

	//SDL초기화 실패시
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL 초기화 실패 두두두두둥...");
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