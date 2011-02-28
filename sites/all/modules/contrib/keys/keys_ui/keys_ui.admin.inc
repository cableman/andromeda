<?php
// $Id: keys_ui.admin.inc,v 1.2.2.4 2010/01/06 16:25:21 greenskin Exp $

/**
 * @file
 * Provides the Keys API's administrative interface.
 */

/*******************************************************************************
 * Callback Functions, Forms, and Tables
 ******************************************************************************/

/**
 * Keys API List.
 */
function keys_ui_list() {
  $keys = keys_get_keys();

  return theme('keys_ui_list', $keys);
}

/**
 * Keys API add key form.
 */
function keys_ui_key_form($form_state, $key = array()) {
  if (empty($key)) {
    $key = new stdClass();
    $key->kid = 0;
    $key->service = $key->rule = $key->api_key = '';
  }

  $form = keys_settings_form($key);

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t("Save"),
  );
  $form['#submit'][] = 'keys_ui_key_form_submit';
  $form['#redirect'] = 'admin/settings/keys';

  return $form;
}

function keys_ui_key_form_submit($form, &$form_state) {
  $message = t('Key successfully saved.');
  drupal_set_message($message);
}

function keys_ui_key_delete_form($form_state, $key) {
  $form['kid'] = array(
    '#type' => 'value',
    '#value' => $key->kid
  );

  return confirm_form($form,
    t("Are you sure you want to delete key for '%service' @ '%rule'?", array('%service' => $key->service, '%rule' => $key->rule)),
    'admin/build/share',
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

function keys_ui_key_delete_form_submit($form, &$form_state) {
  db_query("DELETE FROM {keys_api} WHERE kid = %d", $form_state['values']['kid']);
  drupal_set_message(t('Key deleted successfully.'));
  $form_state['redirect'] = 'admin/settings/keys';
}

/*******************************************************************************
 * Module and Helper Functions
 ******************************************************************************/

function keys_ui_delete_key() {
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    db_query("DELETE FROM {keys_api} WHERE rule = '%s' AND service = '%s'", $_POST['name'], $_POST['service']);
    print keys_ui_get_keys();
  }
  exit();
}

/*******************************************************************************
 * Theme Functions
 ******************************************************************************/

function theme_keys_ui_list($keys) {
  if (empty($keys)) {
    return t("No keys have been saved.");
  }

  $list = keys_get_services();

  $headers = array(
    array('data' => t('Service')),
    array('data' => t('Rule')),
    array('data' => t('API Key')),
    array('data' => '')
  );
  $rows = array();

  $links = array(
    'edit' => array('title' => 'Edit'),
    'delete' => array('title' => 'Delete')
  );

  foreach ($keys as $key) {
    $links['edit']['href'] = 'admin/settings/keys/'. $key->kid .'/edit';
    $links['delete']['href'] = 'admin/settings/keys/'. $key->kid .'/delete';
    $rows[] = array(
      array('data' => $list[$key->service]['name']),
      array('data' => $key->rule),
      array('data' => $key->api_key),
      array('data' => theme('links', $links))
    );
  }

  return theme('table', $headers, $rows);
}

function theme_keys_ui_key_form($form) {
  drupal_add_js(array('keys' => array('domain' => keys_get_domain())), 'setting');
  drupal_add_js(drupal_get_path('module', 'keys_ui') .'/keys_ui.js');
  return drupal_render($form);
}
