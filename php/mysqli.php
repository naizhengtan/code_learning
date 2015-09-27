<?php
// create a database connection
$mysqli = new mysqli("localhost", "root", "news123", "naivetest");

if (mysqli_connect_errno()) {
  printf("Connect failed: %s\n", mysqli_connect_error());
  exit();
}

/* turn autocommit on */
$mysqli->autocommit(TRUE);
/* set autocommit to off */
//$mysqli->autocommit(FALSE);

if ($result = $mysqli->query("SELECT @@autocommit")) {
  $row = $result->fetch_row();
  printf("Autocommit is %s<br>", $row[0]);
  $result->free();
}

// create whatever
echo "CREATE TABLE ....";
$create = "CREATE TABLE Language (
  id int(6) NOT NULL auto_increment,
  name varchar(15) NOT NULL,
  natioin varchar(15) NOT NULL,
  PRIMARY KEY (id),UNIQUE id (id),KEY id_2 (id))";
//$mysqli->query($create);
echo "DONE<br>";


/* Insert some values */
echo "Insert ....<br>";
//$mysqli->query("INSERT INTO Language VALUES (1, 'chinese', 'china')");
//$result = $mysqli->query("SELECT * FROM Language");
//$ans = $result->fetch_array();
//$ans = $result->fetch_assoc();
//print_r($ans);
echo "<br>DONE<br>";

/* Query */
echo "Query....<br>";
$result = $mysqli->query("SELECT * FROM Language");
if ($result == FALSE) {
  echo "error:";
  echo $mysqli->error;
  exit();
}
$ans = $result->fetch_array();
//$ans = $result2->fetch_assoc();
print_r($ans);
$result->free();
echo "<br>DONE<br>";

/* real query */
echo "Real Query....<br>";
if (!$mysqli->real_query("SELECT * FROM Language")) {
  echo "error:";
  echo $mysqli->error;
  exit();
}
if ($result = $mysqli->store_result()) {
  $ans = $result->fetch_array();
  //$ans = $result2->fetch_assoc();
  print_r($ans);
  $result->free();
} else {
  echo "no result";
}
echo "<br>DONE<br>";

/* Multi query */
echo "Multi Query....<br>";
$mysqli->multi_query("SELECT * FROM Language; SELECT name FROM Language");
do {
  $result = $mysqli->use_result();
  print_r($result->fetch_assoc());
  $result->close();
} while ($mysqli->next_result());
echo "DONE<br>";

/* commit transaction */
if (!$mysqli->commit()) {
  print("Transaction commit failed<br>");
  exit();
} else {
  echo "Transaction commit sucessfully<br>";
}

if (!$mysqli->query("SET a=1")) {
  printf("Errorcode: %d<br>", $mysqli->errno);
}


echo "Client info:";
echo $mysqli->get_client_info();

/* drop table */
//$mysqli->query("DROP TABLE Language");

/* close connection */
$mysqli->close();
?>
