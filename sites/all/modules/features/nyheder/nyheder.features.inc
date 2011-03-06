<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function nyheder_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function nyheder_imagecache_default_presets() {
  $items = array(
    'news' => array(
      'presetname' => 'news',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '690',
            'height' => '250',
          ),
        ),
      ),
    ),
    'news_listing' => array(
      'presetname' => 'news_listing',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '268',
            'height' => '150',
          ),
        ),
      ),
    ),
    'static_pages_image' => array(
      'presetname' => 'static_pages_image',
      'actions' => array(
        '0' => array(
          'weight' => '-8',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '320px',
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
function nyheder_node_info() {
  $items = array(
    'news' => array(
      'name' => t('Nyheder'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
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
function nyheder_views_api() {
  return array(
    'api' => '2',
  );
}
