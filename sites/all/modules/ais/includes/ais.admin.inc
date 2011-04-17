<?php

function ais_settings_form() {
  $form = array();

  $form['ais_url'] = array(
    '#type' => 'textfield',
    '#title' => t('AIS url'),
    '#descriptrion' => t('The full url to the AIS feed.'),
    '#default_value' => variable_get('ais_url', ''),
  );

  $form['ais_call'] = array(
    '#type' => 'textfield',
    '#title' => t('Ship call sign'),
    '#descriptrion' => t('The call sign of the ship you want to track.'),
    '#default_value' => variable_get('ais_call', ''),
  );

  return system_settings_form($form);
}
