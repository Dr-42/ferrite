#include "ferritewin.h"
#ifdef __linux__
#include <wayland-client-protocol.h>
#include "xdg-client-shell-protocol.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <assert.h>

#define TODO() assert(0 && "TODO" && __FILE__ && __LINE__)

typedef struct _ferrite_wayland_elements_t {
	struct wl_compositor* comp;
	struct wl_surface* srfc;
	struct wl_buffer* bfr;
	struct wl_shm* shm;
	struct xdg_wm_base* sh;
	struct xdg_toplevel* top;
	struct wl_seat* seat;
	struct wl_keyboard* kb;
	struct wl_pointer* mouse;
	struct wl_display *display;
} ferrite_wayland_elements_t;

static ferrite_wayland_elements_t wle;

void ferrite_win_init(ferrite_win_t *win, int32_t x, int32_t y, int32_t width, int32_t height, char *title){
	wle.display = wl_display_connect(NULL);
}

void ferrite_win_destroy(ferrite_win_t *win){
	TODO();
}

void ferrite_win_update(ferrite_win_t *win){
	TODO();
}

void ferrite_win_set_title(ferrite_win_t *win, char *title){
	TODO();
}

void ferrite_win_set_position(ferrite_win_t *win, int32_t x, int32_t y){
	TODO();
}

void ferrite_win_set_size(ferrite_win_t *win, int32_t width, int32_t height){
	TODO();
}

void ferrite_win_set_fullscreen(ferrite_win_t *win, int8_t fullscreen){
	TODO();
}

void ferrite_win_set_resizable(ferrite_win_t *win, int8_t resizable){
	TODO();
}

void ferrite_win_set_minimizable(ferrite_win_t *win, int8_t minimizable){
	TODO();
}

void ferrite_win_set_maximizable(ferrite_win_t *win, int8_t maximizable){
	TODO();
}

void ferrite_win_set_minimized(ferrite_win_t *win, int8_t minimized){
	TODO();
}

void ferrite_win_set_maximized(ferrite_win_t *win, int8_t maximized){
	TODO();
}


bool ferrite_win_is_fullscreen(ferrite_win_t *win){
	TODO();
}

bool ferrite_win_is_resizable(ferrite_win_t *win){
	TODO();
}

bool ferrite_win_is_minimizable(ferrite_win_t *win){
	TODO();
}

bool ferrite_win_is_maximizable(ferrite_win_t *win){
	TODO();
}

bool ferrite_win_is_minimized(ferrite_win_t *win){
	TODO();
}

bool ferrite_win_is_maximized(ferrite_win_t *win){
	TODO();
}


void* ferrite_win_get_handle(ferrite_win_t *win){
	TODO();
}

void* ferrite_win_get_VkSurface(ferrite_win_t *win){
	TODO();
}


void ferrite_win_grab_cursor(ferrite_win_t *win){
	TODO();
}

void ferrite_win_release_cursor(ferrite_win_t *win){
	TODO();
}

void ferrite_win_hide_cursor(ferrite_win_t *win){
	TODO();
}

void ferrite_win_show_cursor(ferrite_win_t *win){
	TODO();
}


bool ferrite_win_is_cursor_grabbed(ferrite_win_t *win){
	TODO();
}

bool ferrite_win_is_cursor_hidden(ferrite_win_t *win){
	TODO();
}


bool ferrite_win_poll_event(ferrite_win_t *win, ferrite_win_event_t *event){
	TODO();
}

#endif
