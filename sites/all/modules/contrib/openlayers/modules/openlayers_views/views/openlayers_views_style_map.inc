<?php

/**
 * @file
 * This file holds style plugin for OpenLayers Views
 *
 * @ingroup openlayers
 */

/**
 * @class
 * Extension of the Views Plugin Syle for OpenLayers
 *
 * This class extended the default views plugin class to provide
 * a style plugin for the Open Layers module.
 */
class openlayers_views_style_map extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['preset'] = array('default' => variable_get('openlayers_default_preset', 'default'));
    return $options;
  }

  /**
   * Options form
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Map Preset
    $form['preset'] = array(
      '#type' => 'select',
      '#title' => t('Map preset'),
      '#description' => t('This is map that will be used to render the view.'),
      '#options' => openlayers_preset_options(),
      '#default_value' => $this->options['preset'] ?
        $this->options['preset'] : variable_get('openlayers_default_preset', 'default'),
    );
  }
  
  /**
   * Query - override to make sure this doesn't get run
   */
  function query() {
    $this->view->built = TRUE;
  }

  /**
   * Renders views (map)
   */
  function render() {
    $output = '';

    // Check for live preview.
    if (!empty($this->view->live_preview)) {
      return t('OpenLayers views are not compatible with live preview.');
    }

    // Get selected preset
    $preset = openlayers_preset_load($this->options['preset']);

    $map = openlayers_render_map($preset->data, $preset->name);
    return theme($this->theme_functions(), $this->view, $this->options, $map);
  }
}
