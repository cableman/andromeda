<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function static_pages_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "page_manager" && $api == "pages_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function static_pages_imagecache_default_presets() {
  $items = array(
    'frontpage_slider' => array(
      'presetname' => 'frontpage_slider',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '940',
            'height' => '330',
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
function static_pages_node_info() {
  $items = array(
    'static_page' => array(
      'name' => t('Statisk side'),
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
function static_pages_views_api() {
  return array(
    'api' => '2',
  );
}
