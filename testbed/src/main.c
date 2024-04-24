#include <ferritelog.h>

int main() {
	ferrite_log_info("Hello, World!");
	ferrite_log_debug("Hello, World!");
	ferrite_log_warn("Hello, World!");
	ferrite_log_error("Hello, World!");
	ferrite_log_fatal("Hello, World!");
	return 0;
}
