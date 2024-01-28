#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#define Width_Window 900
#define Height_Window 350
#define MinInterval_Half 100
#define mFPS 40
#define V 9
#define Tan 2

SDL_Window *Window = NULL;
SDL_Renderer *Renderer = NULL;
SDL_Event MainEvent;
Mix_Music *Bgm;
TTF_Font *Score_Font = NULL;
TTF_Font *Gameover_Font = NULL;
SDL_Color Score_Color = {0, 0, 0, 0};
SDL_Color Gameover_Color = {20, 20, 230, 255};

SDL_Surface *Birds_Surface = NULL;
SDL_Texture *Birds_Texture = NULL;
SDL_Surface *Blinking_Surface = NULL;
SDL_Texture *Blinking_Texture = NULL;
SDL_Surface *Cloud_Surface = NULL;
SDL_Texture *Cloud_Texture = NULL;
SDL_Surface *Crouching_Surface = NULL;
SDL_Texture *Crouching_Texture = NULL;
SDL_Surface *Dino_menu_Surface = NULL;
SDL_Texture *Dino_menu_Texture = NULL;
SDL_Surface *Hit_Surface = NULL;
SDL_Texture *Hit_Texture = NULL;
SDL_Surface *Restart_Surface = NULL;
SDL_Texture *Restart_Texture = NULL;
SDL_Surface *Road_Surface = NULL;
SDL_Texture *Road_Texture = NULL;
SDL_Surface *Running_Surface = NULL;
SDL_Texture *Running_Texture = NULL;
SDL_Surface *Sun_Surface = NULL;
SDL_Texture *Sun_Texture = NULL;
SDL_Surface *Life_Surface[5];
SDL_Texture *Life_Texture[5];
SDL_Surface *Obstacle_Surface[14];
SDL_Texture *Obstacle_Texture[14];
SDL_Surface *Score_Surface = NULL;
SDL_Texture *Score_Texture = NULL;
SDL_Surface *HI_Surface = NULL;
SDL_Texture *HI_Texture = NULL;
SDL_Surface *Gameover_Surface = NULL;
SDL_Texture *Gameover_Texture = NULL;

SDL_Rect Dino_menu_Rect;
SDL_Rect Road_Rect[2];
SDL_Rect Cloud_Rect[4];
SDL_Rect Sun_Rect;
SDL_Rect Life_Rect;
SDL_Rect TheDINO_Rect[2];
SDL_Rect running_rect[2];
SDL_Rect crouching_rect[2];
SDL_Rect Obstacles_Rect[14];
SDL_Rect Birds_Rect[2];
SDL_Rect birds_rect[2];
SDL_Rect Hit_Rect;
SDL_Rect Restart_Rect;
SDL_Rect Score_Rect;
SDL_Rect HI_Rect;
SDL_Rect Gameover_Rect;

clock_t FDurTime;

bool jump;
bool down;
bool crouch;
bool collision;
bool detect[3];
int j;
int life;
unsigned long score_m;
unsigned long highestscore = 0;
unsigned int r;
unsigned long r_bird[3];
double std;
double rate;
char Score[7];
char HI[10] = "HI ";
struct use
{
	int Obstacle_i;
	int space;
	bool detect;
	SDL_Rect Rect[2];
} Obstacle_Use[3];

void Load();
void PrepareAll();
void QUIT();
void Jump(); // First Jump (to start)
void Play();
void Set();
void CD(); // Collision Detection
void RenderDino();
void RenderObstacle();
void RenderBackground();
void RenderScore(unsigned long score);
void ControlFPS(clock_t FStartTime);

#undef main
int main(int argc, char *argv[])
{
	PrepareAll();

	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 0);
	SDL_RenderClear(Renderer);
	SDL_RenderCopy(Renderer, Dino_menu_Texture, NULL, &Dino_menu_Rect);
	SDL_RenderPresent(Renderer);

	Mix_VolumeMusic(5);
	Mix_FadeInMusic(Bgm, -1, 10000);

	while (SDL_WaitEvent(&MainEvent))
	{
		switch (MainEvent.type)
		{
		case SDL_QUIT:
			QUIT();
			break;

		case SDL_KEYDOWN:

			switch (MainEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				QUIT();
				break;

			case SDLK_RETURN:
			case SDLK_SPACE:
				SDL_RenderClear(Renderer);
				SDL_RenderCopy(Renderer, Blinking_Texture, NULL, TheDINO_Rect);
				SDL_RenderCopy(Renderer, Road_Texture, NULL, Road_Rect);
				Jump();
				Play();
				QUIT();
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}
	}
	return 0;
}

void Load()
{
	Score_Font = TTF_OpenFont("fonts/JOKERMAN.TTF", 32);
	Gameover_Font = TTF_OpenFont("fonts/CHILLER.TTF", 90);

	Blinking_Surface = IMG_Load("images/Blinking.png");
	Birds_Surface = IMG_Load("images/Birds.png");
	Cloud_Surface = IMG_Load("images/Cloud.png");
	Crouching_Surface = IMG_Load("images/Crouching.png");
	Dino_menu_Surface = IMG_Load("images/Dino_menu.png");
	Hit_Surface = IMG_Load("images/Hit.png");
	Restart_Surface = IMG_Load("images/Restart.png");
	Road_Surface = IMG_Load("images/Road.png");
	Running_Surface = IMG_Load("images/Running.png");
	Sun_Surface = IMG_Load("images/Sun.png");

	Life_Surface[0] = IMG_Load("images/Life_0.png");
	Life_Surface[1] = IMG_Load("images/Life_1.png");
	Life_Surface[2] = IMG_Load("images/Life_2.png");
	Life_Surface[3] = IMG_Load("images/Life_3.png");
	Life_Surface[4] = IMG_Load("images/Life_4.png");

	Obstacle_Surface[0] = IMG_Load("images/Obstacle_a.png");
	Obstacle_Surface[1] = IMG_Load("images/Obstacle_b.png");
	Obstacle_Surface[2] = IMG_Load("images/Obstacle_c.png");
	Obstacle_Surface[3] = IMG_Load("images/Obstacle_d.png");
	Obstacle_Surface[4] = IMG_Load("images/Obstacle_e.png");
	Obstacle_Surface[5] = IMG_Load("images/Obstacle_f.png");
	Obstacle_Surface[6] = IMG_Load("images/Obstacle_g.png");
	Obstacle_Surface[7] = IMG_Load("images/Obstacle_h.png");
	Obstacle_Surface[8] = IMG_Load("images/Obstacle_i.png");
	Obstacle_Surface[9] = IMG_Load("images/Obstacle_j.png");
	Obstacle_Surface[10] = IMG_Load("images/Obstacle_k.png");
	Obstacle_Surface[11] = IMG_Load("images/Obstacle_l.png");
	Obstacle_Surface[12] = IMG_Load("images/Obstacle_m.png");
	Obstacle_Surface[13] = IMG_Load("images/Obstacle_n.png");
}

void PrepareAll()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_StopTextInput();
	TTF_Init();
	Mix_Init(MIX_INIT_MP3);
	Window = SDL_CreateWindow("MY DINO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width_Window, Height_Window, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);

	// Surface
	Load();
	Gameover_Surface = TTF_RenderUTF8_Blended(Gameover_Font, "G A M E  O V E R", Gameover_Color);

	// Create Texture
	Blinking_Texture = SDL_CreateTextureFromSurface(Renderer, Blinking_Surface);
	Birds_Texture = SDL_CreateTextureFromSurface(Renderer, Birds_Surface);
	Cloud_Texture = SDL_CreateTextureFromSurface(Renderer, Cloud_Surface);
	Crouching_Texture = SDL_CreateTextureFromSurface(Renderer, Crouching_Surface);
	Dino_menu_Texture = SDL_CreateTextureFromSurface(Renderer, Dino_menu_Surface);
	Hit_Texture = SDL_CreateTextureFromSurface(Renderer, Hit_Surface);
	Restart_Texture = SDL_CreateTextureFromSurface(Renderer, Restart_Surface);
	Road_Texture = SDL_CreateTextureFromSurface(Renderer, Road_Surface);
	Running_Texture = SDL_CreateTextureFromSurface(Renderer, Running_Surface);
	Sun_Texture = SDL_CreateTextureFromSurface(Renderer, Sun_Surface);
	for (int i = 0; i < 5; i++)
	{
		Life_Texture[i] = SDL_CreateTextureFromSurface(Renderer, Life_Surface[i]);
	}
	for (int i = 0; i < 14; i++)
	{
		Obstacle_Texture[i] = SDL_CreateTextureFromSurface(Renderer, Obstacle_Surface[i]);
	}
	Gameover_Texture = SDL_CreateTextureFromSurface(Renderer, Gameover_Surface);

	// Determine Rect

	Dino_menu_Rect = (SDL_Rect){50, Height_Window - 120, Dino_menu_Surface->w, Dino_menu_Surface->h};

	TheDINO_Rect[0] = (SDL_Rect){Dino_menu_Rect.x + 4, Dino_menu_Rect.y, Blinking_Surface->w, Blinking_Surface->h};
	TheDINO_Rect[1] = (SDL_Rect){Dino_menu_Rect.x + 4, Dino_menu_Rect.y + 34, Crouching_Surface->w, Crouching_Surface->h / 2};

	Road_Rect[0] = (SDL_Rect){0, Dino_menu_Rect.y + Dino_menu_Rect.h - 24, Road_Surface->w, Road_Surface->h};
	Road_Rect[1] = (SDL_Rect){Road_Surface->w, Dino_menu_Rect.y + Dino_menu_Rect.h - 24, Road_Surface->w, Road_Surface->h};
	Cloud_Rect[0] = (SDL_Rect){0.11 * Width_Window, 0.29 * Height_Window, Cloud_Surface->w, Cloud_Surface->h};
	Cloud_Rect[1] = (SDL_Rect){0.36 * Width_Window, 0.23 * Height_Window, Cloud_Surface->w, Cloud_Surface->h};
	Cloud_Rect[2] = (SDL_Rect){0.61 * Width_Window, 0.37 * Height_Window, Cloud_Surface->w, Cloud_Surface->h};
	Cloud_Rect[3] = (SDL_Rect){0.89 * Width_Window, 0.21 * Height_Window, Cloud_Surface->w, Cloud_Surface->h};
	Sun_Rect = (SDL_Rect){200, 40, 100, 100};
	Life_Rect = (SDL_Rect){214, 54, 72, 72};

	for (int i = 0; i < 2; i++)
	{
		running_rect[i] = (SDL_Rect){0, Running_Surface->h / 2 * i, Running_Surface->w, Running_Surface->h / 2};
		crouching_rect[i] = (SDL_Rect){0, Crouching_Surface->h / 2 * i, Crouching_Surface->w, Crouching_Surface->h / 2};
	}

	Birds_Rect[0] = (SDL_Rect){0, Height_Window - 160, 84, 60};
	Birds_Rect[1] = (SDL_Rect){0, Height_Window - 172, 84, 52};
	birds_rect[0] = (SDL_Rect){0, 12, 84, 60};
	birds_rect[1] = (SDL_Rect){0, 72, 84, 52};

	for (int i = 0; i < 14; i++)
	{
		Obstacles_Rect[i] = (SDL_Rect){0, Road_Rect->y - Obstacle_Surface[i]->h + 22, Obstacle_Surface[i]->w, Obstacle_Surface[i]->h};
	}

	Gameover_Rect = (SDL_Rect){(Width_Window - Gameover_Surface->w) / 2, Height_Window / 4, Gameover_Surface->w, Gameover_Surface->h};

	Restart_Rect = (SDL_Rect){(Width_Window - Restart_Surface->w) / 2, Gameover_Rect.y + Gameover_Surface->h + 5, Restart_Surface->w, Restart_Surface->h};
}

void QUIT()
{
	SDL_FreeSurface(Birds_Surface);
	SDL_FreeSurface(Blinking_Surface);
	SDL_FreeSurface(Cloud_Surface);
	SDL_FreeSurface(Crouching_Surface);
	SDL_FreeSurface(Dino_menu_Surface);
	SDL_FreeSurface(Hit_Surface);
	SDL_FreeSurface(Restart_Surface);
	SDL_FreeSurface(Road_Surface);
	SDL_FreeSurface(Running_Surface);
	SDL_FreeSurface(HI_Surface);
	SDL_FreeSurface(Gameover_Surface);

	SDL_DestroyTexture(Birds_Texture);
	SDL_DestroyTexture(Blinking_Texture);
	SDL_DestroyTexture(Cloud_Texture);
	SDL_DestroyTexture(Crouching_Texture);
	SDL_DestroyTexture(Dino_menu_Texture);
	SDL_DestroyTexture(Hit_Texture);
	SDL_DestroyTexture(Restart_Texture);
	SDL_DestroyTexture(Road_Texture);
	SDL_DestroyTexture(Running_Texture);
	SDL_DestroyTexture(HI_Texture);
	SDL_DestroyTexture(Gameover_Texture);

	for (int i = 0; i < 5; i++)
	{
		SDL_DestroyTexture(Life_Texture[i]);
	}

	for (int i = 0; i < 14; i++)
	{
		SDL_DestroyTexture(Obstacle_Texture[i]);
	}

	TTF_CloseFont(Gameover_Font);
	TTF_CloseFont(Score_Font);

	Mix_FreeMusic(Bgm);

	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}

void Jump()
{
	double t = TheDINO_Rect[0].y;
	for (int i = 0; i < 2 * V * Tan + 1; i++)
	{
		t += (i - V * Tan) * 2 * Height_Window / (double)(3 * V * Tan * V * Tan);
		TheDINO_Rect[0].y = t;
		SDL_RenderClear(Renderer);
		SDL_RenderCopy(Renderer, Blinking_Texture, NULL, TheDINO_Rect);
		SDL_RenderCopy(Renderer, Road_Texture, NULL, Road_Rect);
		SDL_RenderPresent(Renderer);
		SDL_Delay(1000 / mFPS);
	}
	TheDINO_Rect->y = Dino_menu_Rect.y; // Reset TheDINO_Rect[0].y(bug来自于std取整)
}

void Set()
{
	srand((unsigned int)time(NULL));

	jump = false;
	down = false;
	crouch = false;
	collision = false;
	j = 0;
	life = 4;
	rate = 1.0;
	score_m = 0;
	r = 4111;
	for (int i = 0; i < 3; i++)
	{
		r_bird[i] = 2147516415;
	}
	TheDINO_Rect[0].y = Dino_menu_Rect.y;
	std = Dino_menu_Rect.y;
	for (int i = 0; i < 3; i++)
	{
		Obstacle_Use[i] = (struct use){-1, Width_Window / 2 * (i + 2), false};
	}

	unsigned long temp = highestscore % 1000000;
	for (int i = 5; i >= 0; i--)
	{
		Score[i] = '0';
		HI[i + 3] = temp % 10 + '0';
		temp /= 10;
	}
	HI_Surface = TTF_RenderUTF8_Blended(Score_Font, HI, Score_Color);
	HI_Texture = SDL_CreateTextureFromSurface(Renderer, HI_Surface);
	HI_Rect = (SDL_Rect){Width_Window * 0.8 - HI_Surface->w - 20, 20, HI_Surface->w, HI_Surface->h};
}

void Play()
{
	Set();
	while (true)
	{
		clock_t FStartTime = clock();
		if (SDL_PollEvent(&MainEvent))
		{
			switch (MainEvent.type)
			{
			case SDL_QUIT:
				return;
				break;

			case SDL_KEYDOWN:
				switch (MainEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					return;
					break;

				case SDLK_DOWN:
					down = true;
					break;

				case SDLK_UP:
				case SDLK_SPACE:
					jump = true;
					break;

				default:
					break;
				}
				break;

			case SDL_KEYUP:
				switch (MainEvent.key.keysym.sym)
				{
				case SDLK_DOWN:
					down = false;
					crouch = false;
					break;

				default:
					break;
				}
				break;

			default:
				break;
			}
		}

		score_m++;
		// Select Speed
		if (score_m >= 2500)
		{
			rate = 1.25;
		}
		else if (score_m >= 10000)
		{
			rate = 1.5;
		}

		SDL_RenderClear(Renderer);

		// Render All
		RenderBackground();
		RenderObstacle();
		RenderDino();
		RenderScore(score_m / 5 % 1000000);

		SDL_RenderPresent(Renderer);

		CD();

		if (life < 0)
		{
			Mix_PauseMusic();

			// Render Gameover
			if (crouch)
			{
				Hit_Rect = (SDL_Rect){TheDINO_Rect[1].x + TheDINO_Rect[1].w - Hit_Surface->w, TheDINO_Rect[1].y + 2, Hit_Surface->w, Hit_Surface->h};
				SDL_RenderCopy(Renderer, Hit_Texture, NULL, &Hit_Rect);
			}
			else
			{
				Hit_Rect = (SDL_Rect){TheDINO_Rect[0].x + TheDINO_Rect[0].w - Hit_Surface->w, TheDINO_Rect[0].y, Hit_Surface->w, Hit_Surface->h};
				SDL_RenderCopy(Renderer, Hit_Texture, NULL, &Hit_Rect);
			}
			SDL_RenderCopy(Renderer, Gameover_Texture, NULL, &Gameover_Rect);
			SDL_RenderCopy(Renderer, Restart_Texture, NULL, &Restart_Rect);
			SDL_RenderPresent(Renderer);

			while (SDL_WaitEvent(&MainEvent))
			{
				bool Replay = false;
				switch (MainEvent.type)
				{
				case SDL_QUIT:
					return;
					break;

				case SDL_KEYDOWN:
					switch (MainEvent.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						return;
						break;

					case SDLK_RETURN:
						Replay = true;
						break;

					default:
						break;
					}
					break;

				case SDL_MOUSEBUTTONDOWN:
					if (MainEvent.button.x > Restart_Rect.x && MainEvent.button.y > Restart_Rect.y && MainEvent.button.x < Restart_Rect.x + Restart_Rect.w && MainEvent.button.y < Restart_Rect.y + Restart_Rect.h)
					{
						Replay = true;
					}
					break;

				default:
					break;
				}

				if (Replay)
				{
					Mix_ResumeMusic();

					if (score_m / 5 > highestscore)
					{
						highestscore = score_m / 5;
					}

					SDL_FreeSurface(HI_Surface);
					SDL_DestroyTexture(HI_Texture);
					Set();

					break;
				}
			}
			SDL_Delay(100);
		}
		else
		{
			ControlFPS(FStartTime);
		}
	}
}

void RenderObstacle()
{
	// Select Obstacle Randomly
	if (Obstacle_Use[0].space == Width_Window || Obstacle_Use[1].space == Width_Window || Obstacle_Use[2].space == Width_Window)
	{
		for (int i = 0; i < 3; i++)
		{
			if (Obstacle_Use[i].space == Width_Window)
			{
				Obstacle_Use[i].detect = false;
				int t = score_m > 500 ? 16 : 5;
				Obstacle_Use[i].Obstacle_i = rand() % t;

				if (Obstacle_Use[i].Obstacle_i >= 14) // Bird作为Obstacle
				{
					int pre_x = Width_Window + MinInterval_Half + rand() % (Width_Window / 2 - MinInterval_Half * 2 - Birds_Rect[i].w);
					for (int h = 0; h < 2; h++)
					{
						Obstacle_Use[i].Rect[h] = Birds_Rect[h];
						Obstacle_Use[i].Rect[h].x = pre_x;
					}
					break;
				}

				Obstacle_Use[i].Rect[0] = Obstacles_Rect[Obstacle_Use[i].Obstacle_i];
				Obstacle_Use[i].Rect->x = Width_Window + MinInterval_Half + rand() % (Width_Window / 2 - MinInterval_Half * 2 - Obstacle_Use[i].Rect->w);

				break;
			}
		}
	}

	// Render Obstacle
	for (int i = 0; i < 3; i++)
	{
		Obstacle_Use[i].space -= V;

		if (Obstacle_Use[i].space < -Width_Window / 2) // 回到起点以被继续使用
		{
			Obstacle_Use[i].space = Width_Window;
		}

		if (Obstacle_Use[i].Obstacle_i > -1)
		{
			if (Obstacle_Use[i].Obstacle_i >= 14)
			{
				r_bird[i] >>= 1;
				if (r_bird[i] == 0)
				{
					r_bird[i] = 2147516415;
				}
				Obstacle_Use[i].Rect[0].x -= V;
				Obstacle_Use[i].Rect[1].x -= V;
				SDL_RenderCopy(Renderer, Birds_Texture, birds_rect + r_bird[i] % 2, Obstacle_Use[i].Rect + r_bird[i] % 2);
			}
			else
			{
				Obstacle_Use[i].Rect->x -= V;
				SDL_RenderCopy(Renderer, Obstacle_Texture[Obstacle_Use[i].Obstacle_i], NULL, Obstacle_Use[i].Rect);
			}
		}
	}
}

void RenderDino()
{
	if (down)
	{
		if (jump && TheDINO_Rect[0].y != Dino_menu_Rect.y) // Rapidly Drop
		{
			j = j <= V * Tan ? 2 * V * Tan + 1 - j : j;
			for (int i = 0; i < 3 && jump; i++)
			{
				std += (j - V * Tan) * 2 * Height_Window / (double)(3 * V * Tan * V * Tan);
				TheDINO_Rect[0].y = std;
				j++;
				if (j == 2 * V * Tan + 1)
				{
					j = 0;
					TheDINO_Rect->y = Dino_menu_Rect.y; // Reset TheDINO_Rect[0].y(bug来自于std取整)
					jump = false;
				}
			}
			SDL_RenderCopy(Renderer, Blinking_Texture, NULL, TheDINO_Rect);
		}
		else // Crouch
		{
			SDL_RenderCopy(Renderer, Crouching_Texture, crouching_rect + r % 2, TheDINO_Rect + 1);
			r >>= 1;
			if (r == 16)
			{
				r = 4111;
			}
			jump = false;
			crouch = true;
		}
	}
	else if (jump)
	{
		std += (j - V * Tan) * 2 * Height_Window / (double)(3 * V * Tan * V * Tan);
		TheDINO_Rect[0].y = std;
		j++;
		SDL_RenderCopy(Renderer, Blinking_Texture, NULL, TheDINO_Rect);
		if (j == 2 * V * Tan + 1)
		{
			j = 0;
			TheDINO_Rect->y = Dino_menu_Rect.y; // Reset TheDINO_Rect[0].y(bug来自于std取整)
			jump = false;
		}
	}
	else // Running
	{
		SDL_RenderCopy(Renderer, Running_Texture, running_rect + r % 2, TheDINO_Rect);
		r >>= 1;
		if (r == 16)
		{
			r = 4111;
		}
	}
}

void RenderScore(unsigned long score)
{
	for (int i = 5; i >= 0 && score != 0; i--)
	{
		Score[i] = score % 10 + '0';
		score /= 10;
	}
	Score_Surface = TTF_RenderUTF8_Blended(Score_Font, Score, Score_Color);
	Score_Texture = SDL_CreateTextureFromSurface(Renderer, Score_Surface);
	Score_Rect = (SDL_Rect){Width_Window - Score_Surface->w - 20, 20, Score_Surface->w, Score_Surface->h};
	SDL_RenderCopy(Renderer, Score_Texture, NULL, &Score_Rect);
	SDL_RenderCopy(Renderer, HI_Texture, NULL, &HI_Rect);

	SDL_FreeSurface(Score_Surface);
	SDL_DestroyTexture(Score_Texture);
}

void RenderBackground()
{
	for (int i = 0; i < 2; i++)
	{
		Road_Rect[i].x -= V;
		if (Road_Rect[i].x < -Road_Surface->w)
		{
			Road_Rect[i].x += Road_Surface->w * 2;
		}
		SDL_RenderCopy(Renderer, Road_Texture, NULL, Road_Rect + i);
	}

	SDL_RenderCopy(Renderer, Sun_Texture, NULL, &Sun_Rect);

	for (int i = 0; i < 4; i++)
	{
		Cloud_Rect[i].x -= V / 4;
		if (Cloud_Rect[i].x < -Cloud_Surface->w)
		{
			Cloud_Rect[i].x = Width_Window;
		}
		SDL_RenderCopy(Renderer, Cloud_Texture, NULL, Cloud_Rect + i);
	}

	SDL_RenderCopy(Renderer, Life_Texture[life], NULL, &Life_Rect);
}

void CD()
{
	for (int i = 0; i < 3; i++)
	{
		if (Obstacle_Use[i].detect == false && Obstacle_Use[i].Rect->x < TheDINO_Rect->x + TheDINO_Rect[1].w + V && Obstacle_Use[i].Rect->x + Obstacle_Use[i].Rect->w >= 20)
		{
			if (crouch)
			{
				if (Obstacle_Use[i].Obstacle_i < 14 && Obstacle_Use[i].Rect->x >= TheDINO_Rect[1].x && Obstacle_Use[i].Rect->x <= TheDINO_Rect[1].x + TheDINO_Rect[1].w)
				{
					collision = true;
				}
			}
			else
			{
				if (Obstacle_Use[i].Rect->x >= TheDINO_Rect[0].x && Obstacle_Use[i].Rect->x <= TheDINO_Rect[0].x + TheDINO_Rect[0].w)
				{
					if (Obstacle_Use[i].Rect->y <= TheDINO_Rect[0].y + TheDINO_Rect[0].h && Obstacle_Use[i].Rect->y >= TheDINO_Rect[0].y)
					{
						if (Obstacle_Use[i].Obstacle_i < 4)
						{
							if (Obstacle_Use[i].Rect->y - TheDINO_Rect[0].y < (91 - (Obstacle_Use[i].Rect->x - TheDINO_Rect[0].x)) * 1.5)
							{
								collision = true;
							}
						}
						else if (Obstacle_Use[i].Obstacle_i < 7)
						{
							if (Obstacle_Use[i].Rect->y - TheDINO_Rect[0].y < (86 - (Obstacle_Use[i].Rect->x - TheDINO_Rect[0].x)) * 1.5)
							{
								collision = true;
							}
						}
						else
						{
							if (Obstacle_Use[i].Rect->y - TheDINO_Rect[0].y < (96 - (Obstacle_Use[i].Rect->x - TheDINO_Rect[0].x)) * 1.5)
							{
								collision = true;
							}
						}
					}
					else if (Obstacle_Use[i].Rect->y >= TheDINO_Rect[0].y - Obstacle_Use[i].Rect->h && Obstacle_Use[i].Rect->y <= TheDINO_Rect[0].y)
					{
						if (Obstacle_Use[i].Obstacle_i < 14)
						{
							collision = true;
						}
						else if (Obstacle_Use[i].Rect->x <= TheDINO_Rect[0].x + TheDINO_Rect[0].w - 30)
						{
							collision = true;
						}
					}
				}
				else if (Obstacle_Use[i].Rect->x + Obstacle_Use[i].Rect->w >= TheDINO_Rect[0].x && Obstacle_Use[i].Rect->x < TheDINO_Rect[0].x)
				{
					if (Obstacle_Use[i].Rect->y <= TheDINO_Rect[0].y + TheDINO_Rect[0].h && Obstacle_Use[i].Rect->y >= TheDINO_Rect[0].y)
					{
						if (Obstacle_Use[i].Obstacle_i < 3)
						{
							if (Obstacle_Use[i].Rect->y - TheDINO_Rect[0].y < 2 * (Obstacle_Use[i].Rect->x + Obstacle_Use[i].Rect->w - TheDINO_Rect[0].x) + 47)
							{
								collision = true;
							}
						}
						else if (Obstacle_Use[i].Obstacle_i < 7)
						{
							if (Obstacle_Use[i].Rect->y - TheDINO_Rect[0].y < 2 * (Obstacle_Use[i].Rect->x + Obstacle_Use[i].Rect->w - TheDINO_Rect[0].x) + 34)
							{
								collision = true;
							}
						}
						else
						{
							if (Obstacle_Use[i].Rect->y - TheDINO_Rect[0].y < 2 * (Obstacle_Use[i].Rect->x + Obstacle_Use[i].Rect->w - TheDINO_Rect[0].x) + 54)
							{
								collision = true;
							}
						}
					}
					else if (Obstacle_Use[i].Rect->y >= TheDINO_Rect[0].y - Obstacle_Use[i].Rect->h && Obstacle_Use[i].Rect->y <= TheDINO_Rect[0].y)
					{
						if (Obstacle_Use[i].Obstacle_i >= 14)
						{
							if (r_bird[i] % 2 == 1)
							{
								if (Obstacle_Use[i].Rect[1].y + Obstacle_Use[i].Rect[1].h - TheDINO_Rect[0].y > 30 || Obstacle_Use[i].Rect[1].x + Obstacle_Use[i].Rect[1].w - TheDINO_Rect[0].x > 40)
								{
									collision = true;
								}
							}
							else
							{
								if (Obstacle_Use[i].Rect->y + Obstacle_Use[i].Rect->h - TheDINO_Rect[0].y >= -0.75 * (Obstacle_Use[i].Rect->x + Obstacle_Use[i].Rect->w - TheDINO_Rect[0].x - 80))
								{
									if (Obstacle_Use[i].Rect[1].y + Obstacle_Use[i].Rect[1].h - TheDINO_Rect[0].y > 30 || Obstacle_Use[i].Rect[1].x + Obstacle_Use[i].Rect[1].w - TheDINO_Rect[0].x > 40)
									{
										collision = true;
									}
								}
							}
						}
						else
						{
							if (Obstacle_Use[i].Rect->y + Obstacle_Use[i].Rect->h - TheDINO_Rect[0].y >= -0.75 * (Obstacle_Use[i].Rect->x + Obstacle_Use[i].Rect->w - TheDINO_Rect[0].x - 40))
							{
								collision = true;
							}
						}
					}
				}
			}
			if (collision)
			{
				collision = false;
				Obstacle_Use[i].detect = true;
				life--;
			}
			break;
		}
	}
}

void ControlFPS(clock_t FStartTime)
{
	FDurTime = clock() - FStartTime;
	if (FDurTime <= 1000 / mFPS / rate)
	{
		SDL_Delay(1000 / mFPS / rate - FDurTime);
	}
}