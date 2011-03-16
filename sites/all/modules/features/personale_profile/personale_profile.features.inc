<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function personale_profile_imagecache_default_presets() {
  $items = array(
    'personale_image' => array(
      'presetname' => 'personale_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '200',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function personale_profile_node_info() {
  $items = array(
    'personale' => array(
      'name' => t('Personale profil'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Navn'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function personale_profile_views_api() {
  return array(
    'api' => '2',
  );
}
