<?php
// $Id: cufon.admin.inc,v 1.4 2009/08/26 21:33:54 eads Exp $
/**
 * @file
 * Provides the administration page for Cufon.
 */
DEFINE('CUFON_ADDITIONAL_FORM_ELEMENTS', 3);

/**
 * Administration settings page
 */
function cufon_admin() {
  drupal_add_css(drupal_get_path('module', 'cufon') .'/cufon-admin.css');

  $selectors = variable_get('cufon_selectors', array());

  $fonts = array('------');
  foreach (_cufon_discover_fonts() as $font) {
    $fonts[$font] = $font;
  }

  $form = array(
    'cufon_selectors' =>  array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#description' => t('You may add as many selector / font combinations as you would like.  To add additional input fields, save to add @count more.', array('@count' => CUFON_ADDITIONAL_FORM_ELEMENTS)),
    ),
  );
  $i = 0;
  while ($i < (count($selectors) + CUFON_ADDITIONAL_FORM_ELEMENTS)) { 
    $form['cufon_selectors'][$i] = array(
      'selector' => array(
        '#type' => 'textarea',
        '#title' => t('Selector'),
        '#cols' => 40,
        '#rows' => 3,
        '#prefix' => '<div class="cufon-selector">',
        '#suffix' => '</div>',
      ),
      'options' => array(
        '#tree' => TRUE,
        'fontFamily' => array(
          '#type' => 'select',
          '#title' => t('Font family'),
          '#options' => $fonts,
          '#prefix' => '<div class="cufon-font-family">',
          '#suffix' => '</div>',
        ),
        'hover' => array(
          '#type' => 'checkbox',
          '#title' => t('Enable hover state support'),
          '#default_value' => 0,
          '#description' => t('Adds support for <code>:hover</code> states.  For performance reasons, this is disabled by default.'),
          '#prefix' => '<div class="cufon-hover">',
          '#suffix' => '</div>',
        ),
        '#prefix' => '<div class="cufon-options">',
        '#suffix' => '</div>',
      ),
      '#prefix' => '<div class="cufon-settings-row clear-block">',
      '#suffix' => '</div>',
    );
    // Slightly hoary use of position
    if (($s = $selectors[$i])) {
      $form['cufon_selectors'][$i]['selector']['#default_value'] = $s['selector'];
      $form['cufon_selectors'][$i]['options']['fontFamily']['#default_value'] = $s['options']['fontFamily'];
      $form['cufon_selectors'][$i]['options']['hover']['#default_value'] = $s['options']['hover'];
    }
    $i++;
  }
  $form['#submit'][] = 'cufon_admin_submit';
  return system_settings_form($form);
}

/**
 * Submit callback for cufon administrative settings
 *
 * Filters out empty form elements.
 */
function cufon_admin_submit($form, &$form_state) {
  foreach ($form_state['values']['cufon_selectors'] as $row => $options) {
    if (empty($options['selector']) && empty($options['options']['fontFamily'])) {
      unset($form_state['values']['cufon_selectors'][$row]);
    }
  }
}
