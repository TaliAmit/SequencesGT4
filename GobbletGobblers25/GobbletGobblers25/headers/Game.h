#pragma once
#include <memory>
#include "Board.h"
#include "Rules.h"
#include "Player.h"
//#include "UIManager.h"  
/*
class Game
{
public:
    explicit Game();
    ~Game() = default;

    void run(); // main game loop
    void handleEvents(SDL_Event& e);

private:
    // void handleMouseEvent(const SDL_Event& event); // handle mouse events
    void update(); // game status update
    //void render(); // display game graphics
    // void reset();


    // bool handlePlayerAction(Player& player, const SDL_Point& mousePosition); // handle mouse action
    void switchTurn();

    void initPlayers();

private:
    Board m_board;
    std::vector<Player> m_players;
    size_t m_numOfPlayers;
    bool m_isRunning;
    size_t m_currentPlayerIdx;
    bool m_isGoblerTakenFromHand;

    std::unique_ptr<Rules> m_rules;
    //ResourcesManager m_resourceManager;
    // UIManager& m_uiManager;
};
*/