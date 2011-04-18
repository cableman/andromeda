<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function openlayers_ais_maps_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer openlayers
  $permissions['administer openlayers'] = array(
    'name' => 'administer openlayers',
    'roles' => array(),
  );

  return $permissions;
}
