<?php

function ais_settings_form() {
  $form = array();

  $form['ais_url'] = array(
    '#type' => 'textfield',
    '#title' => t('AIS url'),
    '#descriptrion' => t('The full url to the AIS feed.'),
    '#default_value' => variable_get('ais_url', ''),
  );

  return system_settings_form($form);
}
