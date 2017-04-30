#include <stdarg.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void
err_sys(const char *fmt, ...)
{
	va_list		ap;
	va_start(ap, fmt);

	char buff[1024];
	vsnprintf(buff, 1024, fmt, ap);
	strcat(buff, "\n");
	printf("%s",buff);
	va_end(ap);
	exit(1);
}