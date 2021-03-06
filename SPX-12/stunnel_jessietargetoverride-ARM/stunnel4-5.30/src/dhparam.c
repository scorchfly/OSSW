#include "common.h"
#ifndef OPENSSL_NO_DH
#define DN_new DH_new
#ifndef HEADER_DH_H
# include <openssl/dh.h>
#endif

DH *get_dh2048()
{
    static unsigned char dhp_2048[] = {
	0xCB, 0x35, 0x0E, 0x68, 0xA7, 0x31, 0xA6, 0x99, 0x92, 0x3E, 
	0x1B, 0x41, 0x32, 0xE0, 0xD9, 0x4D, 0x96, 0x27, 0xD0, 0xE6, 
	0x77, 0x2B, 0x5C, 0xAB, 0xF5, 0xF4, 0x0A, 0x79, 0xF4, 0x7E, 
	0x7F, 0xC8, 0x8D, 0x44, 0x6B, 0xCC, 0x57, 0x6D, 0xF8, 0x5A, 
	0x31, 0x2D, 0x6B, 0x38, 0x2A, 0x91, 0x9E, 0x02, 0x8D, 0x99, 
	0x65, 0x14, 0x05, 0x68, 0x79, 0x58, 0xA3, 0x9A, 0xF8, 0xF7, 
	0x1B, 0x51, 0x55, 0x1C, 0xEE, 0x5E, 0x28, 0x86, 0x02, 0xD4, 
	0xFD, 0x9D, 0x8F, 0x62, 0x92, 0x98, 0x5D, 0x4F, 0x04, 0xB4, 
	0x77, 0xA8, 0x86, 0xD5, 0x34, 0xB9, 0x6B, 0x6C, 0xFD, 0x0B, 
	0x85, 0x3F, 0x70, 0x86, 0x67, 0xB8, 0x47, 0xBA, 0x62, 0xF3, 
	0x1F, 0x8C, 0x91, 0x84, 0x03, 0xD9, 0xD0, 0x94, 0xCC, 0xAD, 
	0x31, 0x41, 0x83, 0x50, 0x1E, 0x11, 0xD7, 0x09, 0x53, 0x3A, 
	0x5B, 0x11, 0xC1, 0x46, 0x19, 0xF1, 0x4D, 0x9A, 0x2A, 0x10, 
	0x3B, 0xE6, 0x47, 0xD4, 0x19, 0x63, 0xFF, 0x6D, 0x70, 0x40, 
	0xEA, 0xFA, 0x66, 0x43, 0xFB, 0xB8, 0xDB, 0xFE, 0xCE, 0xC5, 
	0x53, 0xAB, 0x22, 0xD7, 0x30, 0xDD, 0x55, 0xD0, 0xF2, 0x5D, 
	0xF8, 0x84, 0x50, 0xC7, 0x28, 0xDC, 0x5F, 0x5C, 0xF7, 0xED, 
	0x67, 0xE9, 0x0B, 0xAA, 0xD7, 0x63, 0xCC, 0xC5, 0x70, 0x49, 
	0xDA, 0x68, 0x94, 0xF0, 0x66, 0x5D, 0xB7, 0x9E, 0xE1, 0xD8, 
	0x47, 0xF6, 0x87, 0x54, 0xA5, 0x9B, 0x20, 0x0F, 0x26, 0x77, 
	0xCC, 0x67, 0xFB, 0xFB, 0x5B, 0x9F, 0x1F, 0x90, 0x53, 0x90, 
	0x99, 0x83, 0x4F, 0xC2, 0x1D, 0x86, 0x98, 0x51, 0x78, 0x62, 
	0x5B, 0x9C, 0x04, 0xCE, 0x3F, 0x46, 0x5F, 0xC7, 0xF0, 0xE7, 
	0x26, 0x47, 0x28, 0xC0, 0xC0, 0x6D, 0xDA, 0x87, 0xA4, 0x54, 
	0xDE, 0xD8, 0x53, 0x1C, 0xF9, 0xC0, 0xC5, 0x93, 0xAD, 0x84, 
	0x11, 0x92, 0x3C, 0x1C, 0x31, 0x23
    };
    static unsigned char dhg_2048[] = {
	0x02
    };
    DH *dh = DN_new();

    if (dh == NULL)
        return NULL;
    dh->p = BN_bin2bn(dhp_2048, sizeof (dhp_2048), NULL);
    dh->g = BN_bin2bn(dhg_2048, sizeof (dhg_2048), NULL);
    if (!dh->p || !dh->g) {
        DH_free(dh);
        return NULL;
    }
    return dh;
}
#endif /* OPENSSL_NO_DH */
