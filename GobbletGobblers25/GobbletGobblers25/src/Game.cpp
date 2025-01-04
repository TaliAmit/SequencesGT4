
/*
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "../headers/ResourcesManager.h"
#include "../headers/Game.h"
#include "../headers/Rules.h"

Game::Game() 
    : m_players()
    , m_board(3, 3)
    , m_isRunning(false) // true?
    , m_currentPlayerIdx(0) // ?
    , m_rules(std::make_unique<Rules>()) // after Haim uploads Rules class
    //, m_resourcesManager() // not implemented yet
    , m_isGoblerTakenFromHand(false)
{
    initPlayers();
}


void Game::handleEvents(SDL_Event& e)
{
    switch (e.type)
    {
    case SDL_QUIT:
        m_isRunning = false;
        break;

    case SDL_MOUSEBUTTONDOWN:
    {
        break;
    }

    case SDL_KEYDOWN: // keyboard events
    {
        if (e.key.keysym.sym == SDLK_ESCAPE)
        {
            m_isRunning = false;
        }
        break;
    }

    default:
        break;
    }
}

void Game::run()
{
	while (m_isRunning)
	{
        

	}
}

void Game::update()
{

}



void Game::switchTurn()
{
	m_currentPlayerIdx = (m_currentPlayerIdx + 1) % m_players.size();
}


void Game::initPlayers()
{
	// It will be a UiManager function :
	m_players.push_back(Player(HUMAN, ORANGE));
	m_players.push_back(Player(HUMAN, GREEN));
}
*/



/*
enum Games
{
    TicTacToe,
    GobbletGobblers,
    FourInARow
};

void run()
{
    while (true)
    {
        // Prompt the player to select a game
        int gameChoice = showMenu();
        switchToGame(gameChoice);
        
}

void switchToGame(Games gameChoice)
{
        switch (gameChoice)
        {
        case Games::TicTacToe:
            switchGame(std::make_unique<TicTacToeRules>(),
                std::make_unique<TicTacToeResourcesManager>(),
                std::make_unique<TicTacToeUIManager>());
            break;

        case Games::GobbletGobblers:
            switchGame(std::make_unique<GobbletGobblersRules>(),
                std::make_unique<GobbletGobblersResourcesManager>(),
                std::make_unique<GobbletGobblersUIManager>());
            break;

        case Games::FourInARow:
            switchGame(std::make_unique<FourInARowRules>(),
                std::make_unique<FourInARowResourcesManager>(),
                std::make_unique<FourInARowUIManager>());
            break;

        default:
            std::cout << "Invalid game choice!" << std::endl;
            return;
        }
}


void switchGame(
    std::unique_ptr<Rules> rules,
    std::unique_ptr<ResourcesManager> resourceManager,
    std::unique_ptr<UIManager> uiManager)
{
    // If a game is already running, stop it
    if (m_currentGame)
    {
        m_currentGame.reset(); // Clean up the current game
    }

    // Initialize a new game with the provided components
    m_currentGame = std::make_unique<Game>
    (
        std::move(rules),
        std::move(resourceManager),
        std::move(uiManager)
    );

    // Start the new game
    m_currentGame->run();  // Runs the game loop for the selected game
}

*/
