/*
  +----------------------------------------------------------------------+
  | SeasLog                                                              |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Chitao Gao  <neeke@php.net>                                  |
  +----------------------------------------------------------------------+
*/

#include "php_seasValid.h"
#include "Request.h"

ZEND_DECLARE_MODULE_GLOBALS(seasvalid);
static PHP_GINIT_FUNCTION(seasvalid);
static PHP_GSHUTDOWN_FUNCTION(seasvalid);

#ifdef COMPILE_DL_SEASVALID
ZEND_GET_MODULE(seasvalid)
#endif

#include "Datetime.h"
#include "Common.h"
#include "php7_wrapper.h"

zend_class_entry *seasvalid_ce;

const zend_function_entry seasvalid_functions[] =
{
    PHP_FE(seasvalid_get_author,  NULL)
    {
        NULL, NULL, NULL
    }
};

#if ZEND_MODULE_API_NO >= 20050922
zend_module_dep seasvalid_deps[] =
{
    {
        NULL, NULL, NULL
    }
};
#endif

ZEND_BEGIN_ARG_INFO_EX(seasvalid_setRequestID_arginfo, 0, 0, 1)
ZEND_ARG_INFO(0, request_id)
ZEND_END_ARG_INFO()

const zend_function_entry seasvalid_methods[] =
{
    PHP_ME(SEASVALID_RES_NAME, __construct,   NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(SEASVALID_RES_NAME, getRequestID,  NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(SEASVALID_RES_NAME, getBuffer,     NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    {
        NULL, NULL, NULL
    }
};

PHP_INI_BEGIN()
//STD_PHP_INI_ENTRY("seasvalid.trace_performance_min_wall_time", "1000", PHP_INI_ALL, OnUpdateLongGEZero, trace_performance_min_wall_time, zend_seasvalid_globals, seasvaild_globals)

PHP_INI_END()

static PHP_GINIT_FUNCTION(seasvalid)
{
    memset(seasvalid_globals, 0, sizeof(zend_seasvalid_globals));
    //seasvalid_globals->performance_frames = NULL;
}

static PHP_GSHUTDOWN_FUNCTION(seasvalid)
{

}

PHP_MINIT_FUNCTION(seasvalid)
{
    zend_class_entry seasvalid;

    REGISTER_INI_ENTRIES();

    REGISTER_STRINGL_CONSTANT("SEASVALID_AUTHOR",    SEASVALID_AUTHOR,    sizeof(SEASVALID_AUTHOR) - 1,   CONST_PERSISTENT | CONST_CS);

    INIT_CLASS_ENTRY(seasvalid, SEASVALID_RES_NAME, seasvalid_methods);

#if PHP_VERSION_ID >= 70000
    seasvalid_ce = zend_register_internal_class_ex(&seasvalid, NULL);
#else
    seasvalid_ce = zend_register_internal_class_ex(&seasvalid, NULL, NULL TSRMLS_CC);
#endif

    seasvalid_ce->ce_flags |= ZEND_ACC_FINAL;

    /*init_error_hooks(TSRMLS_C);
    init_exception_hooks(TSRMLS_C);
    init_buffer_switch(TSRMLS_C);
    init_remote_timeout(TSRMLS_C);
    init_zend_hooks(TSRMLS_C);*/

    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(seasvalid)
{
    /*recovery_error_hooks(TSRMLS_C);
    recovery_exception_hooks(TSRMLS_C);
    recovery_zend_hooks(TSRMLS_C);

    UNREGISTER_INI_ENTRIES();*/

    return SUCCESS;
}

PHP_RINIT_FUNCTION(seasvalid)
{
    //SEASVALID_G(error_loop) = 0;

    //seasvalid_init_request_id(TSRMLS_C);
    //SEASVALID_G(initRComplete) = SEASVALID_INITR_COMPLETE_YES;
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(seasvalid)
{
    seasvalid_clear_request_id(TSRMLS_C);
    return SUCCESS;
}

PHP_MINFO_FUNCTION(seasvalid)
{
    /*php_info_print_table_start();

    if (PG(expose_php) && !sapi_module.phpinfo_as_text)
    {
        php_info_print_table_header(2, "SeasLog support", SEASVALID_LOGO_IMG"enabled");
    }
    else
    {
        php_info_print_table_header(2, "SeasLog support", "Enabled");
    }

    php_info_print_table_row(2, "SeasLog Author", SEASVALIDAUTHOR);
    php_info_print_table_end();

    DISPLAY_INI_ENTRIES();*/
}

zend_module_entry seasvalid_module_entry =
{
#if ZEND_MODULE_API_NO >= 20050922
    STANDARD_MODULE_HEADER_EX, NULL,
    seasvalid_deps,
#else
    STANDARD_MODULE_HEADER,
#endif
    SEASVALID_RES_NAME,
    seasvalid_functions,
    PHP_MINIT(seasvalid),
    PHP_MSHUTDOWN(seasvalid),
    PHP_RINIT(seasvalid),
    PHP_RSHUTDOWN(seasvalid),
    PHP_MINFO(seasvalid),
    SEASVALID_VERSION,
    PHP_MODULE_GLOBALS(seasvalid),
    PHP_GINIT(seasvalid),
    PHP_GSHUTDOWN(seasvalid),
    NULL,
    STANDARD_MODULE_PROPERTIES_EX
};

/* {{{ proto string seasvaild_get_author()
   Return SeasLog author */
PHP_FUNCTION(seasvalid_get_author)
{
    SEASVALID_RETURN_STRINGL(SEASVALID_AUTHOR, strlen(SEASVALID_AUTHOR));
}
/* }}} */

PHP_METHOD(SEASVALID_RES_NAME, __construct)
{
    RETURN_TRUE;
}

/* {{{ proto string getRequestID()
   Get SeasLog request_id differentiated requests */
PHP_METHOD(SEASVALID_RES_NAME, getRequestID)
{
    SEASVALID_RETURN_STRINGL(SEASVALID_G(request_id), strlen(SEASVALID_G(request_id)));
}
/* }}} */

/* {{{ proto array getBuffer()
   Get the logs buffer in memory as array */
PHP_METHOD(SEASVALID_RES_NAME, getBuffer)
{
    //if (seasvalid_check_buffer_enable(TSRMLS_C))
    //{
#if PHP_VERSION_ID >= 70000
        //RETURN_ZVAL(&SEASVALID_G(buffer), 1, 0);
#else
        //RETURN_ZVAL(SEASVALID_G(buffer), 1, 0);
#endif
    //}

    RETURN_FALSE;
}
/* }}} */

