#include "seasvalid_validation.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_seasvalid_validation_execute, 0, 0, 1)
ZEND_END_ARG_INFO()

PHP_METHOD(seasvalid_validation, execute)
{
    zval result;

    php_printf("hello execute function");

    *return_value = result;
}


const zend_function_entry seasvalid_validation_methods[] = 
{
    PHP_ME(seasvalid_validation, execute, arginfo_seasvalid_validation_execute, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

/**
 * Define zend class entry
 */
zend_class_entry seasvalid_validation_ce;
zend_class_entry *seasvalid_validation_ce_ptr;

void seasvalid_validation_init()
{
    INIT_NS_CLASS_ENTRY(seasvalid_validation_ce, "Seasvalid", "Validation", seasvalid_validation_methods);
    seasvalid_validation_ce_ptr = zend_register_internal_class(&seasvalid_validation_ce TSRMLS_CC); // Registered in the Zend Engine
}