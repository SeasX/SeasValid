--TEST--
Check if seasvalid is loaded
--SKIPIF--
<?php
if (!extension_loaded('seasvalid')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "seasvalid" is available';
?>
--EXPECT--
The extension "seasvalid" is available
