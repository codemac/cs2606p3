#include "BufferPool.h"


int BufferPool::write(char* towrite, int fileOffset) {
	for( int i = 0; i < total ; i++) {
		if (memory[i]->inRange(fileOffset)) {
			return memory[i]->write(towrite, fileOffset);
		}
	}
}
bool BufferPool::read(char* tostore, int fileOffset, int length) {

}
