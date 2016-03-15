/*
  +--------------------------------------------------------------------+
  | PECL :: rsync                                                      |
  +--------------------------------------------------------------------+
  | Redistribution and use in source and binary forms, with or without |
  | modification, are permitted provided that the conditions mentioned |
  | in the accompanying LICENSE file are met.                          |
  +--------------------------------------------------------------------+
  | Copyright (c) 2010 Michele Catalano <michele@catalano.de>          |
  |                    Anatoliy Belsky <ab@php.net>                    |
  +--------------------------------------------------------------------+ 
*/

/* $Id: header 252479 2008-02-07 19:39:50Z iliaa $ */

#ifndef PHP_RSYNC_H
#define PHP_RSYNC_H

#define PHP_RSYNC_EXTNAME "rsync"
#define PHP_RSYNC_EXTVER "0.1.0"

extern zend_module_entry rsync_module_entry;
#define phpext_rsync_ptr &rsync_module_entry

#ifdef PHP_WIN32
#	define PHP_RSYNC_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_RSYNC_API __attribute__ ((visibility("default")))
#else
#	define PHP_RSYNC_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#define RSYNC_HAVE_PHP_53 ZEND_MODULE_API_NO >= 20071006

#include "external_libraries.h"

PHP_MINIT_FUNCTION(rsync);
PHP_MSHUTDOWN_FUNCTION(rsync);
PHP_RINIT_FUNCTION(rsync);
PHP_RSHUTDOWN_FUNCTION(rsync);
PHP_MINFO_FUNCTION(rsync);

PHP_FUNCTION(rsync_generate_signature);
PHP_FUNCTION(rsync_generate_delta);
PHP_FUNCTION(rsync_patch_file);
PHP_FUNCTION(rsync_set_log_callback);
PHP_FUNCTION(rsync_set_log_level);
PHP_FUNCTION(rsync_error);

PHP_METHOD(Rsync, __construct);
PHP_METHOD(Rsync, generateSignature);
PHP_METHOD(Rsync, generateDelta);
PHP_METHOD(Rsync, patchFile);
PHP_METHOD(Rsync, setLogCallback);
PHP_METHOD(Rsync, setLogLevel);
PHP_METHOD(Rsync, getError);


ZEND_BEGIN_MODULE_GLOBALS(rsync)
	char *tmp_dir;
	long block_length;
	long strong_length;
	long hash_type;
	rs_stats_t stats;
	rs_result ret;
	struct php_rsync_log_callback {
		zend_fcall_info fci;
		zend_fcall_info_cache fcc;
	} log_cb;
	int error;
	int has_log_cb;
	long log_stats;
ZEND_END_MODULE_GLOBALS(rsync)

struct ze_rsync_main_obj {
	zend_object zo;
	long block_length;
	long strong_length;
	long hash_type;
	rs_stats_t stats;
	rs_result ret;
};
#ifdef ZTS
#define RSYNC_G(v) TSRMG(rsync_globals_id, zend_rsync_globals *, v)
#else
#define RSYNC_G(v) (rsync_globals.v)
#endif

//extern zend_object_value php_rsync_object_init(zend_class_entry *ze TSRMLS_CC);

#endif	/* PHP_RSYNC_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
