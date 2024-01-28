#include <SDL2/SDL.h>

// 小人
typedef struct {
    int x, y;
    int charging;
    int charge_val;
} StickMan;

// 平台
typedef struct {
    int x, y, w, h;
} Platform;

// 游戏状态
typedef struct {
    StickMan stick_man;
    int score;
    int high_score;
    Platform* platforms;
} GameState;

GameState* game_state;
SDL_Window* window
SDL_Renderer* renderer;

void chargeJump() {
    // ...
}

void performJump() {
    // ...
}

void generatePlatform() {
    // ...
}

void drawUI() {
    // ...
}

void mainLoop() {
    SDL_Event e;
    while (1) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return;
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_SPACE) {
                    // 开始蓄力
                    chargeJump();
                }
            } else if (e.type == SDL_KEYUP) {
                if (e.key.keysym.sym == SDLK_SPACE) {
                    // 释放跳跃
                    performJump();
                    generatePlatform();
                }
            }
        }

        SDL_RenderClear(renderer);
        drawUI();
        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60); // 简单的帧率控制
    }
}

int main(int argc, const char* argv[]) {
    // 初始化 SDL
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("跳一跳", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    game_state = initGameState();
    
    mainLoop();

    // 释放资源
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}#include <SDL2/SDL.h>

// 小人
typedef struct {
    int x, y;
    int charging;
    int charge_val;
} StickMan;

// 平台
typedef struct {
    int x, y, w, h;
} Platform;

// 游戏状态
typedef struct {
    StickMan stick_man;
    int score;
    int high_score;
    Platform* platforms;
} GameState;

GameState* game_state;
SDL_Window* window
SDL_Renderer* renderer;

void chargeJump() {
    // ...
}

void performJump() {
    // ...
}

void generatePlatform() {
    // ...
}

void drawUI() {
    // ...
}

void mainLoop() {
    SDL_Event e;
    while (1) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return;
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_SPACE) {
                    // 开始蓄力
                    chargeJump();
                }
            } else if (e.type == SDL_KEYUP) {
                if (e.key.keysym.sym == SDLK_SPACE) {
                    // 释放跳跃
                    performJump();
                    generatePlatform();
                }
            }
        }

        SDL_RenderClear(renderer);
        drawUI();
        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60); // 简单的帧率控制
    }
}

int main(int argc, const char* argv[]) {
    // 初始化 SDL
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("跳一跳", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    game_state = initGameState();
    
    mainLoop();

    // 释放资源
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}