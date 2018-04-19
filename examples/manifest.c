/*
 * Copyright (c) 2018 Yubico AB. All rights reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include <openssl/ec.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "fido.h"
#include "compat.h"

int
main(void)
{
	fido_dev_info_t	*devlist;
	size_t		 ndevs;
	int		 r;

	fido_init();

	if ((devlist = fido_dev_info_new(64)) == NULL)
		errx(1, "fido_dev_info_new");

	if ((r = fido_dev_info_manifest(devlist, 64, &ndevs)) != FIDO_OK)
		errx(1, "fido_dev_info_manifest: %s (0x%x)", fido_strerr(r), r);

	for (size_t i = 0; i < ndevs; i++) {
		const fido_dev_info_t *di = fido_dev_info_ptr(devlist, i);
		printf("%s: vendor=0x%04x, product=0x%04x (%ls %ls)\n",
		    fido_dev_info_path(di),
		    fido_dev_info_vendor(di),
		    fido_dev_info_product(di),
		    fido_dev_info_manufacturer_string(di),
		    fido_dev_info_product_string(di));
	}

	fido_dev_info_free(&devlist, ndevs);
}