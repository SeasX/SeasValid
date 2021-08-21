/* seasvalid extension for PHP */

#ifndef PHP_SEASVALID_H
# define PHP_SEASVALID_H

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#include "seasvalid.h"

extern zend_module_entry seasvalid_module_entry;
# define phpext_seasvalid_ptr &seasvalid_module_entry

# define PHP_SEASVALID_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_SEASVALID)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_SEASVALID_H */
