#pragma once
#include<iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "colour.h"
#include "game.h"

class SDL2 {

private:

    enum  SDL2_ERRORS : int32_t {SDL2_INI_ERROR = 1, SDL2_WINDOW_CREATE_ERROR, SDL2_SURFACE_CREATE_ERROR, SDL2_RENDER_CREATE_ERROR};


      uint32_t window_width;
      uint32_t window_heigth;
      std::string window_name;

      SDL_Window* window = nullptr;
      SDL_Surface* screen_surface = nullptr;
      SDL_Renderer* window_render = nullptr;

      SDL_Texture* x_texture = nullptr;
      SDL_Texture* o_texture = nullptr;
      SDL_Texture* hline_texture = nullptr;

      Mix_Music* backgraound_music = nullptr;
      Mix_Chunk* click_music = nullptr;
      Mix_Chunk* ii_click_music = nullptr;

      SDL_Event sdl_event;

      Colour color{0,0,0,0};

public:

    SDL2(uint32_t window_width = 1280, uint32_t window_heigth = 720, std::string window_name = "Крестики-нолики. Powered by [F]renzy");

    //static int32_t EnterWidthHeigthOfWindow(uint32_t& window_width, uint32_t& window_heigth);
    static int32_t SDL2_INIT_EVERYTHING();

    int32_t SDL2_Create_Window();
    int32_t SDL2_Create_Render();
    int32_t SDL2_Create_Music_and_Audio();
    int32_t SDL2_Create_Window_Surface();
    int32_t SDL2_Create_Textures();

    int32_t SDL2UpdateWindowSurface();
    int32_t SDL2ClearWindowSRender();
    int32_t SDL2UpdateWindowSRender();

    int32_t SDL2GetMouseCoords(int32_t &mouse_x, int32_t &mouse_y);
//===================================================================
   inline SDL_Window* GetSDL2_Window () const { return window; }
   inline SDL_Event GetSDL2_Event() const { return sdl_event; }
   inline SDL_Surface* GetSDL2_Surface() const {return screen_surface;}
   inline SDL_Renderer* GetSDL2_Render() const {return window_render;}
   inline Mix_Chunk* GetClickMusic() const {return click_music;}
   inline Mix_Chunk* GetIiClickMusic() const {return ii_click_music;}
   inline Mix_Music* GetBackGroundMisic() const {return backgraound_music;}
   inline SDL_Texture* GetXTexture() const {return x_texture ;}
   inline SDL_Texture* GetOTexture() const {return o_texture ;}
   inline SDL_Texture* GetHLineTexture() const {return hline_texture ;}

//===================================================================
    void SDL2DrawLines(Colour& color);
    int32_t SDL2DrawGameField(Game* game, uint32_t size);
    int32_t SDL2DrawHTextureLine(int32_t x1, int32_t y1, int32_t width, int32_t heigth);

//===================================================================
    void SDL2Quit();




    ~SDL2() {

        if (x_texture) {
            SDL_DestroyTexture(x_texture);
            x_texture = nullptr;
        }

        if (o_texture) {
            SDL_DestroyTexture(o_texture);
            o_texture = nullptr;
        }
          if (hline_texture) {

              SDL_DestroyTexture(hline_texture);
              hline_texture = nullptr;
          }

       if(screen_surface) {
            SDL_FreeSurface(screen_surface);
            screen_surface = nullptr;
       }

       if(window_render) {
            SDL_DestroyRenderer(window_render);
            window_render = nullptr;
        }           

       if (window) {
            SDL_DestroyWindow(window);
            window = nullptr;
        }


       SDL_Quit();
       IMG_Quit();
   }
};



