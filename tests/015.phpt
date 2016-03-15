--TEST--
Test the rsync_generate_signatur (blake2) function
--SKIPIF--
<?php 
if (!extension_loaded("rsync")) print "skip"; ?>
--FILE--
<?php 
$targetMD5 = '131b2b5d9e04442837748177525fd4bb';
$ret = rsync_generate_signature('tests/002test.png','tests/015signatur.sig', 'blake2');
$resultMD5 = md5_file('tests/015signatur.sig');
if ($resultMD5 == $targetMD5 && $ret == RSYNC_DONE) {
	echo "SUCCESS\n";
} else {
	echo "FAILED with Return $ret and MD5 $resultMD5\n";
}	
unlink('tests/015signatur.sig');
?>
--EXPECT--
SUCCESS
