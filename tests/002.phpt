--TEST--
seasvalid_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('seasvalid')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = seasvalid_test1();

var_dump($ret);
?>
--EXPECT--
The extension seasvalid is loaded and working!
NULL
