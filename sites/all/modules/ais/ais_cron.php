<?php

// Drupal bootstrap.
require_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);

register_shutdown_function('ais_shutdown');
function ais_shutdown() {
  exit();
}

// Load settings (variable_get dos not work yet).
$url = db_fetch_object(db_query('SELECT value FROM variable WHERE name = \'%s\'', array('ais_url')))->value;
if (!$url) {
  echo "URL was not defined in AIS cron script.";
  exit;
}
$url = unserialize($url);

// Load settings (variable_get dos not work yet).
$call = db_fetch_object(db_query('SELECT value FROM variable WHERE name = \'%s\'', array('ais_call')))->value;
if (!$call) {
  echo "Call sign was not defined in AIS cron script.";
  exit;
}
$call = unserialize($call);

// Load feed.
$xml = simplexml_load_file($url);

// Find ship and store data in the database.
foreach ($xml->marker as $mark) {
  $attributes = $mark->attributes();
  if ($attributes->call == $call) {
    // Store data in db
    $values = array(
      $attributes->lat, $attributes->lon,
      $attributes->name, $attributes->mmsi,
      $attributes->imo, $attributes->call,
      $attributes->speed, $attributes->course,
      $attributes->type,
    );
    db_query("INSERT INTO {ais} VALUES ('', %f, %f, '%s', %d, %d, '%s', %f, %f, %d)", $values);
  }
}

echo "cron";