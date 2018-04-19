/*
 * Copyright (c) 2018 Yubico AB. All rights reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include <sys/types.h>
#include <sys/stat.h>

#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/pem.h>

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "fido.h"
#include "compat.h"
#include "extern.h"

int
write_blob(const char *path, const unsigned char *ptr, size_t len)
{
	int fd, ok = -1;
	ssize_t n;

	if ((fd = open(path, O_WRONLY | O_CREAT, 0644)) < 0) {
		warn("open %s", path);
		goto fail;
	}

	if ((n = write(fd, ptr, len)) < 0) {
		warn("write");
		goto fail;
	}
	if ((size_t)n != len) {
		warnx("write");
		goto fail;
	}

	ok = 0;
fail:
	if (fd != -1) {
		close(fd);
	}

	return (ok);
}

int
read_blob(const char *path, unsigned char **ptr, size_t *len)
{
	int fd, ok = -1;
	struct stat st;
	ssize_t n;

	*ptr = NULL;
	*len = 0;

	if ((fd = open(path, O_RDONLY)) < 0) {
		warn("open %s", path);
		goto fail;
	}
	if (fstat(fd, &st) < 0) {
		warn("stat %s", path);
		goto fail;
	}
	if (st.st_size < 0) {
		warnx("stat %s: invalid size", path);
		goto fail;
	}
	*len = (size_t)st.st_size;
	if ((*ptr = malloc(*len)) == NULL) {
		warn("malloc");
		goto fail;
	}
	if ((n = read(fd, *ptr, *len)) < 0) {
		warn("read");
		goto fail;
	}
	if ((size_t)n != *len) {
		warnx("read");
		goto fail;
	}

	ok = 0;
fail:
	if (fd != -1) {
		close(fd);
	}
	if (ok < 0) {
		free(*ptr);
		*ptr = NULL;
		*len = 0;
	}

	return (ok);
}

EC_KEY *
read_ec_pubkey(const char *path)
{
	FILE *fp = NULL;
	EVP_PKEY *pkey = NULL;
	EC_KEY *ec = NULL;

	if ((fp = fopen(path, "r")) == NULL) {
		warn("fopen");
		goto fail;
	}

	if ((pkey = PEM_read_PUBKEY(fp, NULL, NULL, NULL)) == NULL) {
		warnx("PEM_read_PUBKEY");
		goto fail;
	}
	if ((ec = EVP_PKEY_get1_EC_KEY(pkey)) == NULL) {
		warnx("EVP_PKEY_get1_EC_KEY");
		goto fail;
	}

fail:
	if (fp) {
		fclose(fp);
	}
	if (pkey) {
		EVP_PKEY_free(pkey);
	}

	return (ec);
}

int
write_ec_pubkey(const char *path, const es256_pk_t *pk)
{
	FILE *fp = NULL;
	EVP_PKEY *pkey = NULL;
	int fd = -1;
	int ok = -1;

	if ((fd = open(path, O_WRONLY | O_CREAT, 0644)) < 0) {
		warn("open %s", path);
		goto fail;
	}

	if ((fp = fdopen(fd, "w")) == NULL) {
		warn("fdopen");
		goto fail;
	}
	fd = -1; /* owned by fp now */

	if ((pkey = es256_pk_to_EVP_PKEY(pk)) == NULL) {
		warnx("es256_pk_to_EVP_PKEY");
	}

	if (PEM_write_PUBKEY(fp, pkey) == 0) {
		warnx("PEM_write_PUBKEY");
	}

	ok = 0;
fail:
	if (fp != NULL) {
		fclose(fp);
	}
	if (fd != -1) {
		close(fd);
	}
	if (pkey != NULL) {
		EVP_PKEY_free(pkey);
	}

	return (ok);
}