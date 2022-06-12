#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <thread>
#include <cstdlib>
#include "sdl2.h"
#include "colour.h"
#include "game.h"


//                            ***Работа по крестикам и ноликам ****

/*   Очень много сил ушло на работу с графикой, но все же не всё удалось реализовать из-за малого колличества времени, например хотелось бы целиком отрисовку обьектов вывести в отдельный поток,
 *   но, к сожалению, не хватает времени на разбор, из-за этого на завершающем запросе нажатия клавиши ENTER фризится изображение, потому что в ожидании нажатия клавиши приостанавливается поток выполнения и
 *   и появляются не приятные глазу артефакты из-за отсутвия обновления экрана(перерисовки). Все же очень мало времени дается на реализацию, вот если бы дней 15... Эх.
 *   По той же причине могу не успеть сделать адекватный ии. Очень хотелось не использовать тупой алгоритм блокировки, и я постараюсь до такого не опускаться, будет попытка реализовать ии через алгоритм
 *   поиска ближайшего соседа, но на крайний случай буду реализовавать рандом.
 *   Так же отмечу, что большую часть наработок я не удалю, а закоментирую, так как планирую работать дальше в данном направлении, так что закоментированный код оставлен целенаправленно*
 *   Такие файлы как human.cpp,  human.h, ii.cpp, ii.h так же оставлны, так как хотелось использовать ещё больший уровень декомпозиции, но как обычно времени не хватает.*/

void InitFunc(SDL2* sdl);
void MusicFunc(SDL2* sdl);
void InitTexures(SDL2* sdl);

void GetHumanSelect(SDL2* sdl, Game* game);
void HumanGetAChoise(SDL2* sdl, Game* game);
void IiGetAChoise(SDL2* sdl, Game* game);

//void Rend(SDL2* sdl, Game* game, Colour &color);

int main()
{
    bool SDL_IS_RUN = true;

    SDL2* sdl2 = new SDL2();
    Game* game = new Game();
    Colour color(0,0,0,0);

    std::thread thread1(InitFunc, sdl2);
    thread1.join();

    std::thread thread3(MusicFunc, sdl2);
    thread3.detach();

    SDL_Texture* x_texture = nullptr;
    SDL_Texture* o_texture = nullptr;

    std::thread thread2(InitTexures, sdl2);
    thread2.detach();


    SDL_Event event = sdl2->GetSDL2_Event();

    //==============================================================================================================================================================

    while (SDL_IS_RUN) {

        SDL_SetRenderDrawColor(sdl2->GetSDL2_Render(), 255, 255, 255, 0);
        SDL_RenderClear(sdl2->GetSDL2_Render());
        sdl2->SDL2DrawLines(color);




        while( SDL_PollEvent(&event) != 0) {

                if (event.type == SDL_QUIT) {

                    SDL_IS_RUN = false;

                } else if (event.type == SDL_MOUSEMOTION) {

                     std::thread thread4 (GetHumanSelect,sdl2, game);
                     thread4.detach();
                     //thread4.~thread();
                   // GetHumanSelect(sdl2, game);

     } else if(event.type == SDL_MOUSEBUTTONUP &&  (game->GetChoise() == game->GetHumanChoise())) {

                    /*std::thread thread5 (HumanGetAChoise,sdl2, game);
                    thread5.detach();
                    //thread5.~thread();*/
                    HumanGetAChoise(sdl2, game);
            }
    }

         /* std::thread thread6(IiGetAChoise,sdl2, game);
          thread6.detach();
         thread6.~thread();*/
         IiGetAChoise(sdl2, game);

        sdl2->SDL2DrawGameField(game,game->GetSizeOfGameField());
        sdl2->SDL2UpdateWindowSRender();


        if (game->CalculateWinner() && (event.type != SDL_QUIT)){
          std::cout << "Thank you, Game is Over, Please Enter ENTER_KEY to EXIT" << std::endl;
          std::cin.get();
          SDL_IS_RUN = false;
          event.type = SDL_QUIT;
        }

     }



    return 0;
}


/*void Rend(SDL2* sdl, Game* game, Colour &color){

    SDL_SetRenderDrawColor(sdl->GetSDL2_Render(), 255, 255, 255, 0);
    SDL_RenderClear(sdl->GetSDL2_Render());
    sdl->SDL2DrawLines(color);

    sdl->SDL2DrawGameField(game,game->GetSizeOfGameField());
    sdl->SDL2UpdateWindowSRender();

}*/

void IiGetAChoise(SDL2* sdl, Game* game) {

      if( game->GetChoise() == game->GetIiChoise()){
      game->IiTakeAmove();
      Mix_PlayChannel(-1, sdl->GetIiClickMusic(),0);

      }

}

void HumanGetAChoise(SDL2* sdl, Game* game) {

    if( game->GetChoise() == game->GetHumanChoise()) {
    std::cout << "========================================================================"<< std::endl;
    std::cout <<std::endl<< " Human choosing int new thread : " << std::this_thread::get_id()  << std::endl;
    int32_t mouse_x{0};
    int32_t mouse_y{0};
    sdl->SDL2GetMouseCoords(mouse_x,mouse_y);
    game->HumanTakeAmove(mouse_x, mouse_y);
    Mix_PlayChannel(-1, sdl->GetClickMusic(),0);
}
}

void GetHumanSelect(SDL2* sdl, Game* game) {

    int32_t mouse_x{0};
    int32_t mouse_y{0};
    sdl->SDL2GetMouseCoords(mouse_x,mouse_y);
    game->HumanSelect(mouse_x,mouse_y);
}

void InitTexures(SDL2* sdl){
    std::cout << "========================================================================"<< std::endl;
    std::cout <<std::endl<< "Init SDL2 Textures int new thread : " << std::this_thread::get_id()  << std::endl;
    sdl->SDL2_Create_Textures();

}

void InitFunc(SDL2* sdl) {
    std::cout << "========================================================================"<< std::endl;
    std::cout << "Init SDL2 int new thread : " << std::this_thread::get_id() << std::endl;
    SDL2::SDL2_INIT_EVERYTHING();
    sdl->SDL2_Create_Window();
    sdl->SDL2_Create_Render();

}

void MusicFunc(SDL2* sdl) {
    std::cout << "=========================================================================" << std::endl;
    std::cout << std::endl << "Playng music on  new thread : " << std::this_thread::get_id() << std::endl;
    sdl->SDL2_Create_Music_and_Audio();

}
