int strcmp(const char * a, const char * b) {
	uint32_t i = 0;
	while (1) {
		if (a[i] < b[i]) {
			return -1;
		} else if (a[i] > b[i]) {
			return 1;
		} else {
			if (a[i] == '\0') {
				return 0;
			}
			++i;
		}
	}
}

uint32_t strlen(const char *str) {
	int i = 0;
	while (str[i] != (char)0) {
		++i;
	}
	return i;
}

char * strdup(const char *str) {
	int len = strlen(str);
	char * out = malloc(sizeof(char) * (len+1));
	memcpy(out, str, len+1);
	return out;
}

char * strcpy(char * dest, const char * src) {
	int len = strlen(src);
	memcpy(dest, src, len+1);
	return dest;
}

char * strtok_r(char * str, const char * delim, char ** saveptr) {
	char * token;
	if (str == NULL) {
		str = *saveptr;
	}
	str += strspn(str, delim);
	if (*str == '\0') {
		*saveptr = str;
		return NULL;
	}
	token = str;
	str = strpbrk(token, delim);
	if (str == NULL) {
		*saveptr = (char *)lfind(token, '\0');
	} else {
		*str = '\0';
		*saveptr = str + 1;
	}
	return token;
}

size_t lfind(const char * str, const char accept) {
	size_t i = 0;
	while ( str[i] != accept) {
		i++;
	}
	return (size_t)(str) + i;
}

size_t rfind(const char * str, const char accept) {
	size_t i = strlen(str) - 1;
	while (str[i] != accept) {
		if (i == 0) return UINT32_MAX;
		i--;
	}
	return (size_t)(str) + i;
}

char * strstr(const char * haystack, const char * needle) {
	const char * out = NULL;
	const char * ptr;
	const char * acc;
	const char * p;
	size_t s = strlen(needle);
	for (ptr = haystack; *ptr != '\0'; ++ptr) {
		size_t accept = 0;
		out = ptr;
		p = ptr;
		for (acc = needle; (*acc != '\0') && (*p != '\0'); ++acc) {
			if (*p == *acc) {
				accept++;
				p++;
			} else {
				break;
			}
		}
		if (accept == s) {
			return (char *)out;
		}
	}
	return NULL;
}

size_t strspn(const char * str, const char * accept) {
	const char * ptr = str;
	const char * acc;

	while (*str) {
		for (acc = accept; *acc; ++acc) {
			if (*str == *acc) {
				break;
			}
		}
		if (*acc == '\0') {
			break;
		}

		str++;
	}

	return str - ptr;
}

char * strpbrk(const char * str, const char * accept) {
	const char *acc = accept;

	if (!*str) {
		return NULL;
	}

	while (*str) {
		for (acc = accept; *acc; ++acc) {
			if (*str == *acc) {
				break;
			}
		}
		if (*acc) {
			break;
		}
		++str;
	}

	if (*acc == '\0') {
		return NULL;
	}

	return (char *)str;
}
