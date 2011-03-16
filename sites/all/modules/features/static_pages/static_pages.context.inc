<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function static_pages_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all_pages';
  $context->description = 'Alle sider';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mailchimp-a90470be7f' => array(
          'module' => 'mailchimp',
          'delta' => 'a90470be7f',
          'region' => 'footer_1',
          'weight' => 0,
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'footer_2',
          'weight' => 0,
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'footer_3',
          'weight' => 0,
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'footer_4',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Alle sider');

  $export['all_pages'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontpage';
  $context->description = 'Forsiden';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nodespotbox-2' => array(
          'module' => 'nodespotbox',
          'delta' => '2',
          'region' => 'region_middle_left',
          'weight' => 0,
        ),
        'nodespotbox-14' => array(
          'module' => 'nodespotbox',
          'delta' => '14',
          'region' => 'region_middle_left',
          'weight' => 1,
        ),
        'nodespotbox-12' => array(
          'module' => 'nodespotbox',
          'delta' => '12',
          'region' => 'region_middle_center',
          'weight' => 0,
        ),
        'nodespotbox-10' => array(
          'module' => 'nodespotbox',
          'delta' => '10',
          'region' => 'region_middle_center',
          'weight' => 1,
        ),
        'nodespotbox-1' => array(
          'module' => 'nodespotbox',
          'delta' => '1',
          'region' => 'region_middle_right',
          'weight' => 0,
        ),
        'nodespotbox-11' => array(
          'module' => 'nodespotbox',
          'delta' => '11',
          'region' => 'region_middle_right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Forsiden');

  $export['frontpage'] = $context;
  return $export;
}
