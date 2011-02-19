<?php

/**
 * Implementation of hook_preproces_node
 *
 * @param array $vars
 */
function andromeda_preprocess_node(&$vars) {
  $node = $vars['node'];

  // Submitted for news
  if ($node->type == 'news') {
    $date = andromeda_date_format($vars['created'], 'd. F Y');
    $vars['submitted'] = t('Written d. !date by !author', array('!date' => $date, '!author' => $node->name));
  }
}

/**
 * Theme override for theme_menu_item(). To add active-trail to search menu links.
 */
function andromeda_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) {
  $class = ($menu ? 'expanded' : ($has_children ? 'collapsed' : 'leaf'));
  if (!empty($extra_class)) {
    $class .= ' '. $extra_class;
  }
  if ($in_active_trail) {
    $class .= ' active-trail';
  }

  $url = $_GET['q'];
  if (strstr($url, 'apachesolr_search')) {
    $class .= ' active-trail';
  }
 
  // Add unique identifier
  static $item_id = 0;
  $item_id += 1;
  $id .= 'menu-item-custom-id-' . $item_id;
  // Add semi-unique class
  $class .= ' ' . preg_replace("/[^a-zA-Z0-9]/", "", strip_tags($link));
 
  return '<li class="'. $class .'" id="' . $id . '">'. $link . $menu ."</li>\n";
}

/**
 * Theme override for theme_menu_item_link(). To add active-trail to search menu links.
 */
function andromeda_menu_item_link($link) {
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }

  $url = $_GET['q'];
  if ($link['href'] == 'search/apachesolr_search' && strstr($url, 'apachesolr_search')) {
    $link['localized_options']['attributes'] =  array('title' => t('Search'), 'class' => 'active-trail');
  }
  return l($link['title'], $link['href'], $link['localized_options']);
}

/**
 * Format an date in respect to the language code given.
 *
 * @param date object $date
 * @param string $format
 * @param string $lang
 * @return string
 */
function andromeda_date_format($date, $format, $lang = 'da') {
  $date = date_make_date($date, NULL, DATE_UNIX);
  return date_format_date($date, 'custom', $format, $lang);
}
