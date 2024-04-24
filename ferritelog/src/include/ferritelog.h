#ifndef FERRITELOG_H
#define FERRITELOG_H

#include <stdbool.h>

typedef enum FERRITE_LOG_LEVEL {
	FERRITE_LOG_LEVEL_DEBUG,
	FERRITE_LOG_LEVEL_INFO,
	FERRITE_LOG_LEVEL_WARN,
	FERRITE_LOG_LEVEL_ERROR,
	FERRITE_LOG_LEVEL_FATAL
} FERRITE_LOG_LEVEL;

void ferrite_log_set_color(bool enabled);
void ferrite_log_set_level(FERRITE_LOG_LEVEL level);

void ferrite_log_debug(const char *format, ...);
void ferrite_log_info(const char *format, ...);
void ferrite_log_warn(const char *format, ...);
void ferrite_log_error(const char *format, ...);	
void ferrite_log_fatal(const char *format, ...);

void ferrite_log(FERRITE_LOG_LEVEL level, const char *format, ...);

#endif // FERRITELOG_H
