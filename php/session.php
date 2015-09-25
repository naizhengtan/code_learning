<?php

error_reporting(E_STRICT);

echo "REQUEST_METHOD:<br> <- ";
echo $_SERVER['REQUEST_METHOD'];
echo " -><br>";
echo "COOKIE:<br> <- ";
print_r($_COOKIE);
echo " -><br>";
echo "CACHE LIMITER:<br> <- ";
echo session_cache_limiter();
echo " -><br>";
echo "SESSION CONTENT:<br> <- ";
echo $_SESSION["cheng"]; 
echo "->, <-";
$_SESSION["cheng"] = 10;
echo $_SESSION["cheng"]; 
echo " -><br>";

session_id("000000000929");
session_name("WTF:");

echo "SESSION START:<br><br>";
session_start();

echo "BEFORE SESSION CONTENT:<br> <- ";
echo $_SESSION["cheng"]; 
echo " -><br>";
$_SESSION["cheng"] = "TAN4";
echo "AFTER SESSION CONTENT:<br> <- ";
echo $_SESSION["cheng"]; 
echo " -><br>";

echo "SESSION COOKIE:<br> <- ";
print_r(session_get_cookie_params());
echo " -><br>";

echo "SESSION ENCODE:<br> <- ";
$encode = session_encode();
echo $encode;
echo " -><br>";

echo "SESSION ID:<br> <- ";
$id = session_id();
echo $id;
echo " -><br>";

echo "SESSION MODULE:<br> <- ";
echo session_module_name();
echo " -><br>";

echo "SESSION NAME:<br> <- ";
echo session_name();
echo " -><br>";


//session_abort();
//session_write_close();
//session_destroy();
//echo session_cache_expire();
