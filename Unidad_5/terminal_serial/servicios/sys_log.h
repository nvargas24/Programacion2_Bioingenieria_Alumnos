#ifndef SYS_LOG_H_
#define SYS_LOG_H_

#include <stdbool.h>

void sysLog_Init();
void sysTerminal_write(const char* str);
bool sysTerminal_read(char* buffer, unsigned int buffer_size);
bool readSingleCharLPC(char* out_char);

#endif /* SYS_LOG_H_ */
