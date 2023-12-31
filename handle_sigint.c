#include "main.h"


/**
 * handle_sigint - Handle Ctrl + C signal.
 *
 * @signum: Signal number obtained.
 */

void handle_sigint(int signum __attribute__((unused)))
{
	signal_received = CTRL_C_SIGNAL_CODE;
	write(STDOUT_FILENO, "\n$ ", 3);
}
