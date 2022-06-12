#include "game.h"

 uint32_t Game::game_steps{9};

Game::Game() {

    uint32_t step_x {0};
    uint32_t step_y {10};
    int32_t start_x {450};
    int32_t start_y {150};

    random_choise = static_cast<bool>(GetRandomChoise( min , max));
    PrintAlarm();

    size_of_game_filed = 3;

        game_field =  new gamenode*  [size_of_game_filed];

    for (uint32_t count {0}; count < size_of_game_filed; ++count) {

        game_field[count] = new gamenode [size_of_game_filed];
    }

    for(uint32_t count1{0}; count1 < size_of_game_filed; ++count1) {

        for (uint32_t count2{0}; count2 < size_of_game_filed; ++count2) {

            game_field[count1][count2].x = start_x + step_x;
            game_field[count1][count2].y = start_y + step_y;

            step_x = step_x +(30 + (*game_field)->width);
        }
        step_x = 0;
        step_y = step_y + (30 + (*game_field)->heigth);
    }

}

void Game::SetChoise(bool choise) {
    random_choise = choise;
}



void Game::HumanSelect(int32_t mouse_x, int32_t mouse_y) {

for(uint32_t count1{0}; count1 < size_of_game_filed; ++count1) {

for (uint32_t count2{0}; count2 <  size_of_game_filed ; ++count2) {

 if ((mouse_x >=game_field[count1][count2].x && mouse_x <= ( game_field[count1][count2].x  + (game_field[count1][count2].width ))  &&  (mouse_y >= game_field[count1][count2].y && mouse_y <= game_field[count1][count2].y  + game_field[count1][count2].heigth )) ) {

       game_field[count1][count2].color.SetColourFromNums(105,105,105,0);

        if ( game_field[count1][count2].is_image){
                game_field[count1][count2].color.SetColourA(100);
        } else {
                game_field[count1][count2].color.SetColourA(0);
        }
       game_field[count1][count2].is_fill = true;

}else {
        game_field[count1][count2].color.SetColourFromNums(0,0,0,0);
        game_field[count1][count2].is_fill = false;
}
}
}
}



void Game::HumanTakeAmove(int32_t mouse_x, int32_t mouse_y) {

if (random_choise ==  human_choise) {

 bool is_seek = true;



   for(uint32_t count1{0}; count1 < size_of_game_filed; ++count1) {


      for (uint32_t count2{0}; count2 < size_of_game_filed; ++count2) {

        if ((  (mouse_x >= game_field[count1][count2].x) && mouse_x < ( game_field[count1][count2].x  + game_field[count1][count2].width ))  &&  ( (mouse_y >= game_field[count1][count2].y) && (mouse_y < game_field[count1][count2].y  + game_field[count1][count2].heigth) ))  {
            if( game_field[count1][count2].game_node_toy == empty_gametoy) {
            game_field[count1][count2].is_image = true;
            game_field[count1][count2].game_node_toy = human_gametoy;
            random_choise = ii_choise;
            --game_steps;
            goto END;
         }
      }
    }
 }
}
END:;
PrintAlarm();
}



void Game::IiTakeAmove() {

if(random_choise == ii_choise && game_steps > 0) {

    uint32_t min_rand_index{0};
    uint32_t max_rand_index{2};   

    uint32_t count_human_moves {0};
    static uint32_t count_ii_moves {0};
    static uint32_t count_of_random_trying{0};
    uint32_t rand_row{0};
    uint32_t rand_coll{0};


    uint32_t global_statement = GetRandomChoise(min,max);

    if (count_of_random_trying > 1) {
        global_statement = GetRandomChoise(min,max);
    }

     if (global_statement || count_ii_moves == 0) {

      std::cout << "Random trying" << std::endl;
      ++count_of_random_trying;

       do {

            rand_row = GetRandomChoise(min_rand_index,max_rand_index);
            rand_coll = GetRandomChoise(min_rand_index,max_rand_index);

        } while (game_field[rand_row][rand_coll].game_node_toy != empty_gametoy);

        game_field[rand_row][rand_coll].is_image = true;
        game_field[rand_row][rand_coll].game_node_toy = ii_gametoy;

        } else {

           uint32_t state_first_find_neighbor = GetRandomChoise(min,max);

                if (state_first_find_neighbor) {

                    std::cout << "Find  ii neighbor" << std::endl;

                     do {

                        rand_row = GetRandomChoise(min_rand_index,max_rand_index);
                        rand_coll = GetRandomChoise(min_rand_index,max_rand_index);

                      } while(game_field[rand_row][rand_coll].game_node_toy != ii_gametoy);

                  } else {

                          std::cout << "Find human neigthbor " << std::endl;

                          do {

                          rand_row = GetRandomChoise(min_rand_index,max_rand_index);
                          rand_coll = GetRandomChoise(min_rand_index,max_rand_index);

                          } while (game_field[rand_row][rand_coll].game_node_toy != human_gametoy);

                  }
                   for(uint32_t count1{rand_row}; count1 < size_of_game_filed; ++count1) {

                    for (uint32_t count2{rand_coll}; count2 < size_of_game_filed; ++count2) {

                            if (game_field[count1][count2].game_node_toy == empty_gametoy ) {
                                game_field[count1][count2].is_image = true;
                                game_field[count1][count2].game_node_toy = ii_gametoy;

                                goto END;

                               }

                        }

                 }
                    for(int32_t count1{static_cast<int32_t>(rand_row)}; count1 >= 0 ; --count1) {

                       for (int32_t count2{static_cast<int32_t>(rand_coll)}; count2 >= 0; --count2) {

                           if (game_field[count1][count2].game_node_toy == empty_gametoy ) {
                                  game_field[count1][count2].is_image = true;
                                   game_field[count1][count2].game_node_toy = ii_gametoy;
                                     goto END;
                              }
                         }
                     }

}
END:

      ++count_ii_moves;
      --game_steps;
      random_choise = human_choise;
       PrintAlarm();
}
}

bool Game::CalculateWinner() {

    bool win = false;
    uint32_t empty_toy_count{0};

    if (game_field[0][0].game_node_toy == game_field[0][1].game_node_toy && game_field[0][1].game_node_toy == game_field[0][2].game_node_toy && game_field[0][1].game_node_toy != empty_gametoy) {

        if (game_field[0][1].game_node_toy == human_gametoy) {

            std::cout << "Human Wins!!!" << std::endl;
        } else {
              std::cout << "Ii Wins!!!" << std::endl;
        }
        win = true;
        game_steps = 0;


    } else if (game_field[1][0].game_node_toy == game_field[1][1].game_node_toy && game_field[1][1].game_node_toy == game_field[1][2].game_node_toy && game_field[1][1].game_node_toy != empty_gametoy) {

        if (game_field[1][1].game_node_toy == human_gametoy) {

            std::cout << "Human Wins!!!" << std::endl;
        } else {
              std::cout << "Ii Wins!!!" << std::endl;
        }
        win = true;
        game_steps = 0;

    } else if (game_field[2][0].game_node_toy == game_field[2][1].game_node_toy && game_field[2][1].game_node_toy == game_field[2][2].game_node_toy && game_field[2][1].game_node_toy != empty_gametoy) {

        if (game_field[2][1].game_node_toy == human_gametoy) {

            std::cout << "Human Wins!!!" << std::endl;
        } else {
              std::cout << "Ii Wins!!!" << std::endl;
        }
        win = true;
        game_steps = 0;

     } else if (game_field[0][0].game_node_toy == game_field[1][0].game_node_toy && game_field[1][0].game_node_toy == game_field[2][0].game_node_toy && game_field[1][0].game_node_toy != empty_gametoy){

        if (game_field[1][0].game_node_toy == human_gametoy) {

            std::cout << "Human Wins!!!" << std::endl;
        } else {
              std::cout << "Ii Wins!!!" << std::endl;
        }
        win = true;
        game_steps = 0;

    } else if (game_field[0][1].game_node_toy == game_field[1][1].game_node_toy && game_field[1][1].game_node_toy == game_field[2][1].game_node_toy && game_field[1][1].game_node_toy != empty_gametoy){
        if (game_field[1][1].game_node_toy == human_gametoy) {

            std::cout << "Human Wins!!!" << std::endl;
        } else {
              std::cout << "Ii Wins!!!" << std::endl;
        }
        win = true;
        game_steps = 0;

     } else if (game_field[0][2].game_node_toy == game_field[1][2].game_node_toy && game_field[1][2].game_node_toy == game_field[2][2].game_node_toy && game_field[1][2].game_node_toy != empty_gametoy){
        if (game_field[1][2].game_node_toy == human_gametoy) {

            std::cout << "Human Wins!!!" << std::endl;
        } else {
              std::cout << "Ii Wins!!!" << std::endl;
        }
        win = true;
        game_steps = 0;

    } else if (game_field[0][0].game_node_toy == game_field[1][1].game_node_toy && game_field[1][1].game_node_toy == game_field[2][2].game_node_toy && game_field[1][1].game_node_toy != empty_gametoy) {

        if (game_field[1][1].game_node_toy == human_gametoy) {

            std::cout << "Human Wins!!!" << std::endl;
        } else {
              std::cout << "Ii Wins!!!" << std::endl;
        }
        win = true;
        game_steps = 0;

    }else if (game_field[2][0].game_node_toy == game_field[1][1].game_node_toy && game_field[1][1].game_node_toy == game_field[0][2].game_node_toy && game_field[1][1].game_node_toy != empty_gametoy) {

        if (game_field[1][1].game_node_toy == human_gametoy) {

            std::cout << "Human Wins!!!" << std::endl;
        } else {
              std::cout << "Ii Wins!!!" << std::endl;
        }
        win = true;
        game_steps = 0;

    } else {

        for(uint32_t count1{0}; count1 < size_of_game_filed; ++count1) {

            for (uint32_t count2{0}; count2 < size_of_game_filed; ++count2) {

                if (game_field[count1][count2].game_node_toy == empty_gametoy)
                    ++empty_toy_count;

            }
         }

         if (empty_toy_count == 0) {
          std::cout << "No One Wins!!!" << std::endl;
           win = true;
           game_steps = 0;
         }
    }

return win;
}



void Game::PrintAlarm() {

    if (random_choise) {

        std::cout << "************************************************************************" << std::endl;
        std::cout << "Now Human takes a move" << std::endl;
        std::cout << "************************************************************************" << std::endl;
    } else {
        std::cout << "************************************************************************" << std::endl;
        std::cout << "Now Ii takes a move" << std::endl;
        std::cout << "************************************************************************" << std::endl;

    }

}


uint32_t GetRandomChoise(const uint32_t min, const uint32_t max) {

     auto seed = std::chrono::system_clock::now().time_since_epoch().count();
     std::mt19937_64 rand_gen(seed);
     std::uniform_int_distribution<uint32_t> dis(min,max);
     return  static_cast<uint32_t>(dis(rand_gen));
}
