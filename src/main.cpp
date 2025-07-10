
#include <cstdio>
#include <Core/Game.h>
#include <SFML/System/Clock.hpp>

int main()
{
    Game::GameCreateInfo gameCI;
    gameCI.gameTitle = "UI project";
    gameCI.frameRateLimit = 60u;

    Game game;
    const bool gameInitialized = game.init(gameCI);

    if (gameInitialized == false)
    {
        printf("Game could not be initialized\n");
        return 0;
    }

    sf::Clock clock;

    while (game.isRunning())
    {
        const sf::Time elapsed = clock.restart();

        game.update(elapsed.asMilliseconds());
        game.render();
    }

    return 0;
}
