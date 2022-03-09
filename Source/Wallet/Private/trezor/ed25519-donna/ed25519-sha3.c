#include <stddef.h>

#include <trezor/ed25519-donna/ed25519-sha3.h>
#include <trezor/ed25519-donna/ed25519-hash-custom-sha3.h>

#define ED25519_SUFFIX _sha3

#include "ed25519.c"
