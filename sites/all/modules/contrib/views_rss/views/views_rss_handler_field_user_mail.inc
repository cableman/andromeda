<?php

/**
 * @file
 * Field handler to provide additional control for the email field.
 */

class views_rss_handler_field_user_mail extends views_handler_field_user_mail {

  function option_definition() {
    $options = parent::option_definition();
    $options['rss_format'] = array('default' => 'default');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['rss_format'] = array(
      '#title' => t('Format'),
      '#type' => 'select',
      '#options' => array(
        'default' => t('Generic email'),
        'with_name' => t('RSS <author> element (with user name)'),
      ),
      '#default_value' => isset($this->options['rss_format']) ? $this->options['rss_format'] : 'default',
    );
  }

  function render($values) {
    parent::render($values);
    if ($this->options['rss_format'] == 'with_name') {
      $account = user_load(array('mail' => $values->{$this->field_alias}));
      return $values->{$this->field_alias} . ' (' . $account->name . ')';
    }
    return $values->{$this->field_alias};
  }

}
