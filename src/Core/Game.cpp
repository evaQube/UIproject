#include <cassert>
#include <Core/Game.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

bool Game::init(GameCreateInfo& createInfo)
{
	m_createInfo = createInfo;

	assert(m_window == nullptr && m_world == nullptr && "Game is already initialized, we are about to leak memory");

	m_window = new sf::RenderWindow({ 500, 500 }, m_createInfo.gameTitle);
	m_window->setFramerateLimit(m_createInfo.frameRateLimit);
	
	const bool loadOk = true;

	return loadOk;
}

Game::~Game()
{
	delete m_window;
}

bool Game::isRunning() const 
{ 
	return m_window->isOpen(); 
}

void Game::update(uint32_t deltaMilliseconds)
{
	for (auto event = sf::Event(); m_window->pollEvent(event);)
	{
		if (event.type == sf::Event::Closed)
		{
			m_window->close();
		}
	}
}

void Game::render()
{
	m_window->clear();

	m_window->display();
}