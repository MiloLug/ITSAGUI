#include "common.h"

#include <functional>
#include <xxhash.h>
#include <cstring>

namespace GUI {
	elemId_t strHash(const char* data) {
		/* GUI::elemId_t hash = 0;

		for (; *data; ++data)
		{
			hash += *data;
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}

		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);*/
		return (GUI::elemId_t)XXH64(data, strlen(data), 0);
	}
}