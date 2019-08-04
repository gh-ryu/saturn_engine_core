#ifndef SATURN_ENGINE_CORE
#define SATURN_ENGINE_CORE

#ifdef _WIN32
//#define SATEN_PATH_SEP "\\" 
#define SATEN_ERROR_LOG "error.txt"
#else
//#define SATEN_PATH_SEP "/"
#define SATEN_ERROR_LOG "error.log"
#endif
#define SATEN_PATH_SEP "/"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
//#include <SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32
#include <io.h>
#endif
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "saturn_engine_core_config.h" // defines mruby locations
// path to mruby.h
#include SATEN_MRB_HEADER_LOCATION
// path to mruby/compile.h
#include SATEN_MRB_COMPILE_HEADER_LOCATION
#include "saturn_engine_core_structs.h"
#include "saturn_engine_core_declarations.h"
#include "saturn_engine_core_list.h"
#include "saturn_engine_core_darray.h"
#include "saturn_engine_core_framerate.h"
#include "saturn_engine_core_main.h"
#include "saturn_engine_core_getset.h"
#include "saturn_engine_core_flag.h"
#include "saturn_engine_core_util.h"
#include "saturn_engine_core_error.h"
#include "saturn_engine_core_input.h"
#include "saturn_engine_core_haptic.h"
#include "saturn_engine_core_draw.h"
#include "saturn_engine_core_layer.h"
#include "saturn_engine_core_sprite.h"
#include "saturn_engine_core_pixel.h"
#include "saturn_engine_core_surface.h"
#include "saturn_engine_core_mruby.h"
#include "saturn_engine_core_text.h"
#include "saturn_engine_core_audio.h"


#endif /* SATURN_ENGINE_CORE */
