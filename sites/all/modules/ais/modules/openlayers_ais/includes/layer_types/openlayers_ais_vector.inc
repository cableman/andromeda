<?php

/**
 * @file
 * OpenLayers AIS Vector Layer Type
 */
class openlayers_layer_type_openlayers_ais_vector extends openlayers_layer_type {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_type' => 'openlayers_layer_type_openlayers_ais_vector',
      'layer_handler' => 'openlayers_ais_vector',
      'vector' => TRUE,
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form() {
    return array(
    );
  }

  /**
   * Get features
   *
   * @return
   *   array of features
   */
  function get_features() {
    // Load laste coordinate form the database.
    $result = db_fetch_object(db_query('SELECT * FROM ais ORDER BY id DESC LIMIT 1'));

    $features = array(
      array(
        'wkt' => 'POINT('.$result->long.' '.$result->lat.')',
        'projection' => 4326,
        'attributes' => array(
          'name' => ucwords($result->name),
          'description' => t('Speed: %speed, Course: %course', array('%speed' => $result->speed, '%course' => $result->course)),
        ),
      ),
    );

    return isset($features) ? $features : array();
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers_ais') .
      '/includes/layer_types/openlayers_ais_vector.js');
    $this->data['features'] = $this->get_features();
    return $this->options;
  }
}
