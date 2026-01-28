#include "Application.h"
#include "imgui/imgui.h"
#include "classes/TicTacToe.h"

namespace ClassGame {
        //
        // our global variables
        //
        TicTacToe *game = nullptr;
        bool gameOver = false;
        int gameWinner = -1;

        //
        // game starting point
        // this is called by the main render loop in main.cpp
        //
        // added setNumberOfPlayers to be able to start game with either ai or player
        void GameStartUp() 
        {
            game = new TicTacToe();
            game->setNumberOfPlayers(2);
            game->setUpBoard();
        }

        //
        // game render loop
        // this is called by the main render loop in main.cpp
        //
        // added menu option to start game with ai or two player
        void RenderGame() 
        {
                ImGui::DockSpaceOverViewport();

                //ImGui::ShowDemoWindow();

                if (!game) return;
                // if (!game->getCurrentPlayer()) return;

                
                
                ImGui::Begin("Settings");
                if (game->getCurrentPlayer()) {
                    ImGui::Text("Current Player Number: %d", game->getCurrentPlayer()->playerNumber());
                    ImGui::Text("Current Board State: %s", game->stateString().c_str());
                } else {
                    ImGui::Text("Game not started yet.");
                }

                static int mode = 0; // 0 = Two Players, 1 = Vs AI

                ImGui::Separator();
                ImGui::Text("Mode:");
                ImGui::RadioButton("Two Players", &mode, 0);
                ImGui::RadioButton("Random AI [vs] Player 1", &mode, 1);

                if (ImGui::Button("Start / Restart With Mode")) {
                    game->stopGame();
                    game->setNumberOfPlayers(2);
                    if (mode == 1) {
                        game->setAIPlayer(1);
                    }
                    game->setUpBoard();

                    gameOver = false;
                    gameWinner = -1;
                }

                if (gameOver) {
                    ImGui::Text("Game Over!");
                    ImGui::Text("Winner: %d", gameWinner);
                    if (ImGui::Button("Reset Game")) {
                        // game->stopGame();
                        // game->setUpBoard();
                        // gameOver = false;
                        // gameWinner = -1;
                        game->stopGame();
                        game->setNumberOfPlayers(2);
                        if (mode == 1) {
                            game->setAIPlayer(1);
                        }
                        game->setUpBoard();
                        gameOver = false;
                        gameWinner = -1;
                    }
                }
                ImGui::End();

                ImGui::Begin("GameWindow");
                if (game->getCurrentPlayer()) {
                    game->drawFrame();
                } else {
                    ImGui::Text("Press Start to begin.");
                }
                ImGui::End();
        }

        //
        // end turn is called by the game code at the end of each turn
        // this is where we check for a winner
        //
        void EndOfTurn() 
        {
            Player *winner = game->checkForWinner();
            if (winner)
            {
                gameOver = true;
                gameWinner = winner->playerNumber();
            }
            if (game->checkForDraw()) {
                gameOver = true;
                gameWinner = -1;
            }
        }
}
