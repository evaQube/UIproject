#pragma once

#include <cstdint>
#include <string>

namespace sf
{
	class RenderWindow;
}

class Game
{
	public:

		struct GameCreateInfo
		{
			std::string gameTitle;
			uint32_t frameRateLimit{ 60u };
		};

		~Game();

		bool init(GameCreateInfo& createInfo);

		bool isRunning() const;

		void update(uint32_t deltaMilliseconds);
		void render();

	private:

		GameCreateInfo m_createInfo;

		sf::RenderWindow* m_window{ nullptr };
};