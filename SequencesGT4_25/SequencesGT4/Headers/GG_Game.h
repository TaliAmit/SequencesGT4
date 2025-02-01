#pragma once
#include <memory> //?
#include <map>
#include <vector>

#include <SDL_image.h>
#include <SDL.h>

#include "SDLGame.h"
#include "Grid.h"
#include "Cell.h"
#include "GG_Rules.h"
#include "GG_Player.h"
#include "GG_ResourceMng.h"
#include "GG_UI.h"
#include "GG_Enums.h"

class GGGame : public SDLGame
{
public:
    explicit GGGame();
    ~GGGame() = default;

    void handleEvents(SDL_Event& e);

private:
    // gvoid handleMouseEvent(const SDL_Event& event);
    void update(); // game status update
    void render(); // display game graphics
    void reset();


    // bool handlePlayerAction(Player& player, const SDL_Point& mousePosition); // handle mouse action
    void switchTurn();

    void initPlayers();

private:
    std::vector<GGPlayer> m_players;
    Grid<Cell> m_board;
    std::map<PlayerColor, Grid<Gobbler*>> m_hands;
    
    size_t m_numOfPlayers;
    //size_t m_currentPlayerIdx;
    PlayerColor m_currentPlayerColor;

    bool m_isGoblerTakenFromHand;

    std::unique_ptr<GGRules> m_rules;
    std::unique_ptr <GGResourceManager> m_resourceManager;
    GGUI& m_UI;
};
