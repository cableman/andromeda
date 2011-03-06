<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function fotoalbum_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function fotoalbum_imagecache_default_presets() {
  $items = array(
    'album_listing' => array(
      'presetname' => 'album_listing',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '450',
            'height' => '250',
          ),
        ),
      ),
    ),
    'album_photo' => array(
      'presetname' => 'album_photo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '1024',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'album_thumb' => array(
      'presetname' => 'album_thumb',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '120',
            'height' => '100',
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
function fotoalbum_node_info() {
  $items = array(
    'photo_album' => array(
      'name' => t('Fotoalbum'),
      'module' => 'features',
      'description' => t('Opret et nyt foto album.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
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
function fotoalbum_views_api() {
  return array(
    'api' => '2',
  );
}
