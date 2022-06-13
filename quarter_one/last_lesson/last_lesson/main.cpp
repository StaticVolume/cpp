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
 *   но, к сожалению, не хватает времени на разбор, из-за этого на завершающем запросе нажатия клавиши ENTER фризится изображение(ИСПРАВЛЕНО!!!!), потому что в ожидании нажатия клавиши приостанавливается поток выполнения и
 *   и появляются не приятные глазу артефакты из-за отсутвия обновления экрана(перерисовки)(ВНИМАНИЕ ОШИБКА ИСПРАВЛЕНА, НЕОБХОЖИМЫЕ ДАННЫЕ ВЫВЕДЕНЫ В ПОТОК. Все же очень мало времени дается на реализацию, вот если бы дней 15... Эх.
 *   По той же причине могу не успеть сделать адекватный ии. Очень хотелось не использовать тупой алгоритм блокировки, и я постараюсь до такого не опускаться, будет попытка реализовать ии через алгоритм
 *   поиска ближайшего соседа, но на крайний случай буду реализовавать рандом.
 *   Так же отмечу, что большую часть наработок я не удалю, а закоментирую, так как планирую работать дальше в данном направлении, так что закоментированный код оставлен целенаправленно*
 *   Такие файлы как human.cpp,  human.h, ii.cpp, ii.h так же оставлны, так как хотелось использовать ещё больший уровень декомпозиции, но как обычно времени не хватает.
 *   Перед финалом хотел сделать возможность создания линии зачёркивания при выйгрыше для большей наглядности, но времени не хватило    */


                                                   /* На данный момент реализовано :*/

                                                   /* * Все основные механики игры.
                                                      * Изменён алгорит работы ИИ. Но сложно оценить насколько он стал лучше и стал ли.
                                                      * Реализована графическая оболочка игры на базе SDL2 а именно :
                                                           * Полноценное оконное приложение
                                                           * Поддержка текстур, blending
                                                           * Поддержка фоновой музыки
                                                           * Поддержка обработки событий кнопок
                                                           * Поддержка звуков обработки событий кнопок
                                                           * Поддержка обработки звуков событий ИИ
                                                       * Базовая многопоточность (на данный момент в основном многопоточная инициализация, хотя присутствует многопоточный код иных функций)
                                                       * Присутствует основа для создания более гибкого приложения, но понадобится рефакторинг некоторых мест, так как из-за спешки некоторые моменты пришлось програмировать в лоб
                                                         из-за чего используется много лишних переменных, и лобовой просчёт результата*/

void InitFunc(SDL2* sdl);
void MusicFunc(SDL2* sdl);
void InitTexures(SDL2* sdl);

void GetHumanSelect(SDL2* sdl, Game* game);
void HumanGetAChoise(SDL2* sdl, Game* game);
void IiGetAChoise(SDL2* sdl, Game* game);

void CalcWin(Game* game,SDL_Event &event, bool &SDL_IS_RUN, bool &say_final, bool &cout);

int main()
{
    bool SDL_IS_RUN = true;
    bool say_final = false;
    bool cout = true;
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

            std::thread thread10 (CalcWin, game, std::ref(event), std::ref(SDL_IS_RUN), std::ref(say_final), std::ref(cout));
            thread10.detach();
            thread10.~thread();




        while( SDL_PollEvent(&event) != 0) {

                if (event.type == SDL_QUIT) {

                    SDL_IS_RUN = false;

                } else if (event.type == SDL_MOUSEMOTION) {

                     std::thread thread4 (GetHumanSelect,sdl2, game);
                     thread4.detach();
                     thread4.~thread();
                   // GetHumanSelect(sdl2, game);

     } else if(event.type == SDL_MOUSEBUTTONUP &&  (game->GetChoise() == game->GetHumanChoise())) {

                    std::thread thread5 (HumanGetAChoise,sdl2, game);
                    thread5.join();
                    thread5.~thread();
                   // HumanGetAChoise(sdl2, game);
            }
   }

         std::thread thread6(IiGetAChoise,sdl2, game);
          thread6.join();
          thread6.~thread();
        // IiGetAChoise(sdl2, game);



        sdl2->SDL2DrawGameField(game,game->GetSizeOfGameField());
        sdl2->SDL2UpdateWindowSRender();



     }



    return 0;
}


void CalcWin(Game* game, SDL_Event &event, bool &SDL_IS_RUN, bool &say_final, bool & cout){

   if (!say_final && (event.type != SDL_QUIT )){

                say_final = game->CalculateWinner();

    }else if (say_final) {
       if (cout){
       std::cout << std::endl << "Thank you, Game is Over, Please Enter ENTER_KE to EXIT" << std::endl;
       cout = false;
       }
       std::cin.get();
       SDL_IS_RUN = false;
       event.type = SDL_QUIT;

   }

 }



void IiGetAChoise(SDL2* sdl, Game* game) {

      if( game->GetChoise() == game->GetIiChoise() && game->GetGameSteps() >0 ){
      game->IiTakeAmove();
      Mix_PlayChannel(-1, sdl->GetIiClickMusic(),0);

      }

}

void HumanGetAChoise(SDL2* sdl, Game* game) {

    if( game->GetChoise() == game->GetHumanChoise() && game->GetGameSteps() >0 ) {
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
