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
