/* seasvalid extension for PHP */

#include "php_seasvalid.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

PHP_MINIT_FUNCTION(seasvalid)
{
	seasvalid_validation_init();

	return SUCCESS;
}



/* {{{ string seasvalid_hello( [ string $var ] )
 */
PHP_FUNCTION(seasvalid_hello)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(seasvalid)
{
#if defined(ZTS) && defined(COMPILE_DL_SEASVALID)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(seasvalid)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "seasvalid support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_seasvalid_hello, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ seasvalid_functions[]
 */
static const zend_function_entry seasvalid_functions[] = {
	PHP_FE(seasvalid_hello,		arginfo_seasvalid_hello)
	PHP_FE_END
};
/* }}} */

/* {{{ seasvalid_module_entry
 */
zend_module_entry seasvalid_module_entry = {
	STANDARD_MODULE_HEADER,
	"seasvalid",					/* Extension name */
	seasvalid_functions,			/* zend_function_entry */
	PHP_MINIT(seasvalid),							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(seasvalid),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(seasvalid),			/* PHP_MINFO - Module info */
	PHP_SEASVALID_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SEASVALID
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(seasvalid)
#endif
