#include "../include/camera_handler.h"

char *take_picture_house(size_t *img_size) 
{
    if (system(CMD_WEBCAM) < 0) {
        perror("Camera is not working...");
    } else  {
        return process_image(img_size);
    }
}

char *process_image(size_t *img_size) 
{
    size_t size = 0;
    FILE* img_data = fopen("myhouse.jpg", "r");
    char *img_bin = NULL;

    fseek(img_data, 0, SEEK_END);
    size = ftell(img_data);
    rewind(img_data);
    *img_size = b64_encoded_size(size);
    img_bin = malloc((size + 1) * sizeof(*img_bin) );
    fread(img_bin, size, 1, img_data);
    img_bin[size] = '\0';
    
    return b64_encode(img_bin, size);
}

char* b64_encode(const unsigned char *in, size_t len)
{
	char   *out;
	size_t  elen;
	size_t  i;
	size_t  j;
	size_t  v;

	if (in == NULL || len == 0)
		return NULL;

	elen = b64_encoded_size(len);
	out  = malloc(elen+1);
	out[elen] = '\0';

	for (i=0, j=0; i<len; i+=3, j+=4) {
		v = in[i];
		v = i+1 < len ? v << 8 | in[i+1] : v << 8;
		v = i+2 < len ? v << 8 | in[i+2] : v << 8;

		out[j]   = b64chars[(v >> 18) & 0x3F];
		out[j+1] = b64chars[(v >> 12) & 0x3F];
		if (i+1 < len) {
			out[j+2] = b64chars[(v >> 6) & 0x3F];
		} else {
			out[j+2] = '=';
		}
		if (i+2 < len) {
			out[j+3] = b64chars[v & 0x3F];
		} else {
			out[j+3] = '=';
		}
	}
    return out;
}

size_t b64_encoded_size(size_t inlen)
{
	size_t ret;

	ret = inlen;
	if (inlen % 3 != 0)
		ret += 3 - (inlen % 3);
	ret /= 3;
	ret *= 4;

	return ret;
}
