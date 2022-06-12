#include "sdl2.h"
#include "game.h"

SDL2::SDL2(uint32_t window_width, uint32_t window_heigth, std::string window_name): window_width{window_width}, window_heigth{window_heigth}, window_name{window_name} {}

int32_t SDL2:: SDL2_INIT_EVERYTHING() {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        std::cerr << std::endl << "---Sorry, cant init SDL2 : " << SDL_GetError()  <<std::endl;
        return SDL2_INI_ERROR;
    }

    return 0;
}


int32_t SDL2::SDL2_Create_Textures() {

    SDL_Surface* temp_surface = nullptr;
    temp_surface = IMG_Load("x_texture.jpg");

    if (!temp_surface) {

        std::cerr << "Sorry cant create temp surface to textures" << SDL_GetError() << std::endl;
        return 5;
    }

    x_texture = SDL_CreateTextureFromSurface(window_render, temp_surface);

    if (!x_texture) {

        std::cerr << "Sorry cant create texture from surface" << SDL_GetError() <<std::endl;
        return 6;
    }


    temp_surface = IMG_Load("o_texture.jpg");

    if (!temp_surface) {

        std::cerr << "Sorry cant create temp surface to textures" << SDL_GetError() << std::endl;
        return 6;
    }
    o_texture = SDL_CreateTextureFromSurface(window_render, temp_surface);

    if (!o_texture) {

        std::cerr << "Sorry cant create texture from surface" << SDL_GetError() <<std::endl;
        return 6;
    }

    temp_surface = IMG_Load("h_line_texture.jpg");

    if (!temp_surface) {

        std::cerr << "Sorry cant create temp surface to textures" << SDL_GetError() << std::endl;
        return 6;
    }
    hline_texture = SDL_CreateTextureFromSurface(window_render, temp_surface);

    if (!hline_texture) {

        std::cerr << "Sorry cant create texture from surface" << SDL_GetError() <<std::endl;
        return 6;
    }

    return 0;
}


int32_t SDL2::SDL2_Create_Music_and_Audio(){

 Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT,2,2048);

 backgraound_music = Mix_LoadMUS("background.mp3");

 if (!backgraound_music ) {

     std::cerr << "Sorry cant load the music file" << std::endl;
     return 4;
 }

 click_music = Mix_LoadWAV("click.wav");

 if (!click_music) {

     std::cerr << "Sorry cant load the click music file" << std::endl;
     return 4;
 }

 ii_click_music = Mix_LoadWAV("ii_click_music.wav");

 if (!ii_click_music) {

     std::cerr << "Sorry cant load the click music file" << std::endl;
     return 4;
 }

 Mix_PlayMusic(backgraound_music,-1);
 return 0;
}




int32_t SDL2::SDL2_Create_Window() {

    window = SDL_CreateWindow(" Крестики-нолики :D .Powered by Static_Volume(SV) special for [L]inux on X11 server. Work in Progress ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_heigth, SDL_WINDOW_SHOWN);

    if (window == nullptr) {

        std::cerr << std::endl << std::endl << "---Sorry, cant create SDL2 Window : " << SDL_GetError() <<std::endl;
        return SDL2_WINDOW_CREATE_ERROR;

    }

    return 0;
}

int32_t SDL2::SDL2_Create_Window_Surface() {

    screen_surface = SDL_GetWindowSurface(window);

    if(screen_surface == nullptr){

        std::cerr << std::endl << "---Sorry, cant create Screen Surface : " << SDL_GetError() <<std::endl;

        return SDL2_SURFACE_CREATE_ERROR;
    }


    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 255 , 255 , 255));
    SDL_UpdateWindowSurface(window);

 return 0;
}

int32_t SDL2::SDL2_Create_Render() {

    window_render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

    if (window_render == nullptr) {

        std::cerr <<std::endl << " ---Sorry cant Create SDL2 Render : " << SDL_GetError() << std::endl;

        return SDL2_RENDER_CREATE_ERROR;
    }

    SDL_SetRenderDrawColor(window_render, 255, 255, 255, 0);

    return 0;
}

/*int32_t SDL2::EnterWidthHeigthOfWindow(uint32_t& window_width, uint32_t& window_heigth) {

    int64_t w_width {0};
    int64_t w_heigth {0};

    while (true) {

    std::cout << "Please enter window width : ";
    std::cin >> w_width;
    std::cout << "Please enter window heigth : ";
    std::cin >> w_heigth;

        if (std::cin.fail() || w_width <= 0 || w_heigth <= 0) {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        } else {

            break;
        }

    }

    window_width = static_cast<uint32_t>(w_width);
    window_heigth = static_cast<uint32_t>(w_heigth);

    return 0;


}*/

int32_t SDL2::SDL2UpdateWindowSurface() {

    if (! screen_surface) {

            std::cerr <<std::endl << " ---Sorry cant update Screen Surface : " << SDL_GetError() << std::endl;

            return SDL2_SURFACE_CREATE_ERROR;
        }

    SDL_UpdateWindowSurface(window);
    return 0;
}

int32_t SDL2::SDL2ClearWindowSRender() {

    if (!window_render) {

            std::cerr <<std::endl << " ---Sorry cant update render : " << SDL_GetError() << std::endl;

            return SDL2_RENDER_CREATE_ERROR;
        }

    SDL_RenderClear(window_render);
    SDL_RenderPresent(window_render);


    return 0;
}

int32_t SDL2::SDL2UpdateWindowSRender() {

    if (!window_render) {

            std::cerr <<std::endl << " ---Sorry cant update render : " << SDL_GetError() << std::endl;

            return SDL2_RENDER_CREATE_ERROR;
        }


    SDL_RenderPresent(window_render);


    return 0;
}



//=======================================================================================================================



int32_t SDL2::SDL2DrawGameField(Game* game, uint32_t size) {

    if (!game->GetGamefield()) {

        std::cerr << "Sorry, array is empty or not exist" << std::endl;
    }

    if (!*(game->GetGamefield())) {

        std::cerr << "Sorry, sub_array is empty or not exist" << std::endl;
    }


for (uint32_t count1{0}; count1 < size; ++count1) {

 for (uint32_t count2{0}; count2 < size; ++count2) {

   SDL_SetRenderDrawColor(window_render, game->GetGamefield()[count1][count2].color.GetColourR() ,  game->GetGamefield()[count1][count2].color.GetColourG(),  game->GetGamefield()[count1][count2].color.GetColourB(),  game->GetGamefield()[count1][count2].color.GetColourA());
   SDL_Rect rect = {game->GetGamefield()[count1][count2].x, game->GetGamefield()[count1][count2].y, static_cast<int>(game->GetGamefield()[count1][count2].width),static_cast<int>(game->GetGamefield()[count1][count2].heigth)};

            if (game->GetGamefield()[count1][count2].is_image) {

                  SDL_SetRenderDrawBlendMode(window_render,SDL_BLENDMODE_BLEND);

                     if(game->GetGamefield()[count1][count2].game_node_toy == game->GetHumanGameToy()) {

                            SDL_RenderCopy(window_render, x_texture, nullptr, &rect);

                     }

                        if(game->GetGamefield()[count1][count2].game_node_toy == game->GetIiGameToy()) {

                            SDL_RenderCopy(window_render, o_texture, nullptr, &rect);

                          }
             } else {
                SDL_SetRenderDrawBlendMode(window_render,SDL_BLENDMODE_NONE);
                }

           if (game->GetGamefield()[count1][count2].is_fill) {

                    SDL_RenderFillRect(window_render, &rect);

           } else {

               SDL_RenderDrawRect(window_render, &rect);

           }

        }
    }

    return 0;
}


void SDL2::SDL2DrawLines(Colour& color) {

    SDL_SetRenderDrawBlendMode(window_render,SDL_BLENDMODE_NONE);

    SDL_SetRenderDrawColor(window_render, color.GetColourR() , color.GetColourG(), color.GetColourB(), color.GetColourA());

    SDL_RenderDrawLine(window_render, 250 , 275, 1000, 275);
    SDL_RenderDrawLine(window_render, 250 , 405, 1000, 405);

    SDL_RenderDrawLine(window_render, 565 , 100, 565, 600);
    SDL_RenderDrawLine(window_render, 695 , 100, 695, 600);
}


int32_t SDL2::SDL2GetMouseCoords(int32_t &mouse_x, int32_t &mouse_y) {

SDL_GetMouseState(&mouse_x,&mouse_y);

return 0;
}



int32_t SDL2::SDL2DrawHTextureLine(int32_t x1,int32_t y1, int32_t width, int32_t heigth) {

    if (hline_texture) {

        std::cerr << "Sorry cant use texture" << std::endl;
        return 6;
    }
    SDL_SetRenderDrawBlendMode(window_render,SDL_BLENDMODE_BLEND);
    //SDL_SetRenderDrawColor(window_render, color.GetColourR() , color.GetColourG(), color.GetColourB(), color.GetColourA());
    SDL_Rect rect1 = {x1,y1,width,heigth};

    SDL_RenderCopy(window_render, hline_texture, nullptr, &rect1);
    SDL_RenderFillRect(window_render, &rect1);


return 0;
}

//========================================================================================================================
void SDL2::SDL2Quit() {

    SDL2::~SDL2();
}


