<?php

/**
 * Find distance between to geo points.
 */
function ais_distance($lat1, $lon1, $lat2, $lon2) {
  $theta = $lon1 - $lon2;
  $dist = sin(deg2rad($lat1)) * sin(deg2rad($lat2)) +  cos(deg2rad($lat1)) * cos(deg2rad($lat2)) * cos(deg2rad($theta));
  $dist = acos($dist);
  $dist = rad2deg($dist);
  $miles = $dist * 60 * 1.1515;
  $unit = strtoupper($unit);

  return $miles * 0.8684;
}

/**
 * Insert new AIS point into the database.
 */
function ais_insert($values) {
  db_query("INSERT INTO {ais} VALUES ('', %f, %f, '%s', %d, %d, '%s', %f, %f, %d, %d)", $values);
}

/**
 * Update AIS point in the database.
 */
function ais_update($id, $values) {
  db_query('UPDATE {ais} SET timestamp = %d', array(time()));
}

// Drupal bootstrap.
require_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE);

register_shutdown_function('ais_shutdown');
function ais_shutdown() {
  exit();
}

// Load settings (variable_get dos not work yet).
$url = db_fetch_object(db_query('SELECT value FROM {variable} WHERE name = \'%s\'', array('ais_url')))->value;
if (!$url) {
  echo "URL was not defined in AIS cron script.";
  exit;
}
$url = unserialize($url);

// Load settings (variable_get dos not work yet).
$call = db_fetch_object(db_query('SELECT value FROM {variable} WHERE name = \'%s\'', array('ais_call')))->value;
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
    // Build values that should be stored.
    $values = array(
      $attributes->lat, $attributes->lon,
      $attributes->name, $attributes->mmsi,
      $attributes->imo, $attributes->call,
      $attributes->speed, $attributes->course,
      $attributes->type, time(),
    );

    // Check if the position have moved since laste time
    $new_pos = FALSE;
    $result = db_fetch_object(db_query('SELECT * FROM {ais} ORDER BY id DESC LIMIT 1'));
    if ($result) {
      $distance = round(ais_distance((float)$result->long, (float)$result->lat,
                                     (float)$attributes->lon, (float)$attributes->lat), 5);
      // Check if lat have changed.
      if ((float)$distance > 0.25) {
        // Insert new record.
        ais_insert($values);
      }
      else {
        // Update record.
        ais_update($result->id, $values);
      }
    }
    else {
      // Insert new record.
      ais_insert($values);
    }

    // End loop
    break;
  }
}
