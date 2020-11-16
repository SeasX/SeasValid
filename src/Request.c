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

#include "Request.h"
#include "Common.h"

void seasvalid_init_request_id(TSRMLS_D)
{
    SEASVALID_G(request_id) = get_uniqid();
    SEASVALID_G(request_id_len) = strlen(SEASVALID_G(request_id));
}

void seasvalid_clear_request_id(TSRMLS_D)
{
    if (SEASVALID_G(request_id))
    {
        efree(SEASVALID_G(request_id));
    }
}

