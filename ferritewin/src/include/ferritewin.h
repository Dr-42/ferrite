#ifndef FERRITEWIN_H
#define FERRITEWIN_H

#include "ferriteinput.h"
#include <stdint.h>
#include <stdbool.h>

#define FERRITE_WIN_FLAG_FULLSCREEN 0x01
#define FERRITE_WIN_FLAG_RESIZABLE 0x02
#define FERRITE_WIN_FLAG_MINIMIZABLE 0x04
#define FERRITE_WIN_FLAG_MAXIMIZABLE 0x08
#define FERRITE_WIN_FLAG_MINIMIZED 0x10
#define FERRITE_WIN_FLAG_MAXIMIZED 0x20
#define FERRITE_WIN_FLAG_CURSOR_GRABBED 0x40
#define FERRITE_WIN_FLAG_CURSOR_HIDDEN 0x80

typedef struct ferrite_win_t {
	int32_t x;
	int32_t y;
	int32_t width;
	int32_t height;
	int8_t flags;
	char* title;
	void *win_handle; // depends on platform
	void *VkSurface; // depends on platform
	ferrite_win_event_t* event_stack;
} ferrite_win_t;

void ferrite_win_init(ferrite_win_t *win, int32_t x, int32_t y, int32_t width, int32_t height, char *title);
void ferrite_win_destroy(ferrite_win_t *win);
void ferrite_win_update(ferrite_win_t *win);
void ferrite_win_set_title(ferrite_win_t *win, char *title);
void ferrite_win_set_position(ferrite_win_t *win, int32_t x, int32_t y);
void ferrite_win_set_size(ferrite_win_t *win, int32_t width, int32_t height);
void ferrite_win_set_fullscreen(ferrite_win_t *win, int8_t fullscreen);
void ferrite_win_set_resizable(ferrite_win_t *win, int8_t resizable);
void ferrite_win_set_minimizable(ferrite_win_t *win, int8_t minimizable);
void ferrite_win_set_maximizable(ferrite_win_t *win, int8_t maximizable);
void ferrite_win_set_minimized(ferrite_win_t *win, int8_t minimized);
void ferrite_win_set_maximized(ferrite_win_t *win, int8_t maximized);

bool ferrite_win_is_fullscreen(ferrite_win_t *win);
bool ferrite_win_is_resizable(ferrite_win_t *win);
bool ferrite_win_is_minimizable(ferrite_win_t *win);
bool ferrite_win_is_maximizable(ferrite_win_t *win);
bool ferrite_win_is_minimized(ferrite_win_t *win);
bool ferrite_win_is_maximized(ferrite_win_t *win);

void* ferrite_win_get_handle(ferrite_win_t *win);
void* ferrite_win_get_VkSurface(ferrite_win_t *win);

void ferrite_win_grab_cursor(ferrite_win_t *win);
void ferrite_win_release_cursor(ferrite_win_t *win);
void ferrite_win_hide_cursor(ferrite_win_t *win);
void ferrite_win_show_cursor(ferrite_win_t *win);

bool ferrite_win_is_cursor_grabbed(ferrite_win_t *win);
bool ferrite_win_is_cursor_hidden(ferrite_win_t *win);

bool ferrite_win_poll_event(ferrite_win_t *win, ferrite_win_event_t *event);
#endif // FERRITEWIN_H
