<?php

function andromeda_preprocess_page(&$vars, $hook) {
  global $theme;
  global $theme_path;

  // Set variables for the logo and site_name.
  $vars['logo_alt_text'] = (empty($vars['logo_alt_text']) ? variable_get('site_name', '') : $vars['logo_alt_text']);
  $vars['logo'] = '<a id="site-logo" href="'. $vars['front_page'] .'" title="'. t('Home page') .'" rel="home"><img src="/'. $theme_path .'/andromeda_logo.png" alt="'. $vars['logo_alt_text'] .'" /></a>';
}

function andromeda_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    $uri = check_plain(request_uri());
    $uri = split('/', $uri);
    if (!empty($uri) && $uri[1] == 'nyheder') { // Added news to breadcrumb
      if (count($uri) > 2) {
        $breadcrumb[2] = $breadcrumb[1];
        $breadcrumb[1] = l(t('News'), 'nyheder');
      }
      else {
        $breadcrumb[1] = t('News');
      }
    }

    if (!empty($uri) && $uri[1] == 'album') { // Added news to breadcrumb
      if (count($uri) > 2) {
        $breadcrumb[2] = $breadcrumb[1];
        $breadcrumb[1] = l(t('Photoalbum'), 'album');
      }
      else {
        $breadcrumb[1] = t('Photoalbum');
      }
    }

    /** XXX remove extra frontpage link **/
    if (strstr($breadcrumb[0], 'Forsiden') && strstr($breadcrumb[1], 'Forsiden')) {
	unset($breadcrumb[0]);
    }

    return '<div class="breadcrumb">'. implode(' › ', $breadcrumb) .'</div>';
  }
}
