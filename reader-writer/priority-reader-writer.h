#ifndef PS1_PRIORITY_HEADER_WRITER_H
#define PS1_PRIORITY_HEADER_WRITER_H

int main(int argc, char **argv);
void *readerMain(void *threadArgument);
void *writerMain(void *threadArgument);

#endif