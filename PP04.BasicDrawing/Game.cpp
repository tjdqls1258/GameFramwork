#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	


	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			SDL_Surface *pTempSurface = SDL_LoadBMP("assets/rider.bmp");
			m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

			SDL_FreeSurface(pTempSurface);

			SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
			
		}
	}
	else
	{
		return false;
	}
	
	return true;
}


void Game::render()
{
	m_destubationRetangle.x = m_sourceRectangle.x = 0;
	m_destubationRetangle.y = m_sourceRectangle.y = 0;
	m_destubationRetangle.h = m_sourceRectangle.h;
	m_destubationRetangle.w = m_sourceRectangle.w;

	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destubationRetangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game \n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}