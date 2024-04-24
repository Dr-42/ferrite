#include "ferritelog.h"

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

#define TODO() assert(0 && "TODO" && __FILE__ && __LINE__)

typedef struct FERRITE_LOG_DATA{
	FERRITE_LOG_LEVEL level;
	bool color;
} FERRITE_LOG_DATA;

static FERRITE_LOG_DATA log_data = {
	.level = FERRITE_LOG_LEVEL_INFO,
	.color = true
};

const char* ANSI_COLOR_RESET = "\x1b[0m";
const char* ANSI_COLOR_RED = "\x1b[31m";
const char* ANSI_COLOR_GREEN = "\x1b[32m";
const char* ANSI_COLOR_YELLOW = "\x1b[33m";
const char* ANSI_COLOR_BLUE = "\x1b[34m";
const char* ANSI_COLOR_IRED = "\x1b[1;30;41m";

void ferrite_log_set_color(bool enabled){
	log_data.color = enabled;
}

void ferrite_log_set_level(FERRITE_LOG_LEVEL level){
	log_data.level = level;
}

void ferrite_log(FERRITE_LOG_LEVEL level, const char *format, ...){
	const char *color = "";
	const char *preface = "";
	switch(level){
		case FERRITE_LOG_LEVEL_DEBUG:
			if (log_data.level > FERRITE_LOG_LEVEL_DEBUG) return;
			if (log_data.color) color = ANSI_COLOR_BLUE;
			preface = "DEBUG: ";
			break;
		case FERRITE_LOG_LEVEL_INFO:
			if (log_data.level > FERRITE_LOG_LEVEL_INFO) return;
			if (log_data.color) color = ANSI_COLOR_GREEN;
			preface = "INFO: ";
			break;
		case FERRITE_LOG_LEVEL_WARN:
			if (log_data.level > FERRITE_LOG_LEVEL_WARN) return;
			if (log_data.color) color = ANSI_COLOR_YELLOW;
			preface = "WARN: ";
			break;
		case FERRITE_LOG_LEVEL_ERROR:
			if (log_data.level > FERRITE_LOG_LEVEL_ERROR) return;
			if (log_data.color) color = ANSI_COLOR_RED;
			preface = "ERROR: ";
			break;
		case FERRITE_LOG_LEVEL_FATAL:
			if (log_data.color) color = ANSI_COLOR_IRED;
			preface = "FATAL: ";
			break;
		default:
			assert(0 && "Invalid log level");
	}

	va_list args;
	va_start(args, format);
	fprintf(stderr, "%s", color);
	fprintf(stderr, "%s", preface);
	if (level != FERRITE_LOG_LEVEL_FATAL) {
		fprintf(stderr, "%s", ANSI_COLOR_RESET);
	}
	vfprintf(stderr, format, args);
	if (level == FERRITE_LOG_LEVEL_FATAL) {
		fprintf(stderr, "%s", ANSI_COLOR_RESET);
	}
	fprintf(stderr, "\n");
	va_end(args);
}

void ferrite_log_debug(const char *format, ...){
	ferrite_log(FERRITE_LOG_LEVEL_DEBUG, format);
}

void ferrite_log_info(const char *format, ...){
	ferrite_log(FERRITE_LOG_LEVEL_INFO, format);
}

void ferrite_log_warn(const char *format, ...){
	ferrite_log(FERRITE_LOG_LEVEL_WARN, format);
}

void ferrite_log_error(const char *format, ...){
	ferrite_log(FERRITE_LOG_LEVEL_ERROR, format);
}
	
void ferrite_log_fatal(const char *format, ...){
	ferrite_log(FERRITE_LOG_LEVEL_FATAL, format);
}
