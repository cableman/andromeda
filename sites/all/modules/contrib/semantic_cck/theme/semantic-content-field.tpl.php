<?php
// $Id: semantic-content-field.tpl.php,v 1.3.2.2 2010/07/19 03:58:16 rjay Exp $

/**
 * @file content-field.tpl.php
 * Default theme implementation to display the value of a field.
 *
 * Available variables:
 * - $node: The node object.
 * - $field: The field array.
 * - $items: An array of values for each item in the field array.
 * - $teaser: Whether this is displayed as a teaser.
 * - $page: Whether this is displayed as a page.
 * - $field_name: The field name.
 * - $field_type: The field type.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $label: The item label.
 * - $label_display: Position of label display, inline, above, or hidden.
 * - $field_empty: Whether the field has any valid value.
 *
 * Semantic HTML variables:
 * - $field_element: The HTML element to surround the entire field with.
 * - $label_element: The HTML element to surround the label text with.
 * - $label_suffix: A character or string displayed directly after the label, eg. a colon.
 * - $items_element: The HTML element to surround all of the field items with.
 * - $item_element: The HTML element to surround each field item with.
 *
 * Each $item in $items contains:
 * - 'view' - the themed view for that item
 *
 * @see template_preprocess_field()
 */
?>
<?php if (!$field_empty) : ?>
  <?php if ($field_element) : ?>
<<?php print $field_element; ?><?php print drupal_attributes($field_attributes); ?>>
  <?php endif; ?>
  <?php if ($label_display == 'above') : ?>
    <<?php print $label_element; ?> class="field-label <?php print $label_class; ?>"><?php print t($label) ?><?php print $label_suffix; ?></<?php print $label_element; ?>>
  <?php endif;?>
  <?php if ($items_element) : ?>
  <<?php print $items_element; ?><?php print drupal_attributes($items_attributes); ?>>
  <?php endif; ?>
    <?php
    foreach ($items as $delta => $item) :
      if (!$item['empty']) : ?>
        <?php if ($item_element) : ?>
        <<?php print $item_element; ?><?php print drupal_attributes($item_attributes[$delta]); ?>>
        <?php endif; ?>
          <?php if ($label_display == 'inline') { ?>
            <<?php print $label_element; ?> class="field-label-inline<?php print($delta ? '' : '-first')?> <?php print $label_class; ?>">
              <?php print t($label) ?><?php print $label_suffix; ?></<?php print $label_element; ?>>
          <?php } ?>
          <?php print $item['view'] ?>
        <?php if ($item_element) : ?>
        </<?php print $item_element; ?>>
        <?php endif; ?>
      <?php
      endif;
    endforeach;?>
  <?php if ($items_element) : ?>
  </<?php print $items_element; ?>>
  <?php endif; ?>
  <?php if ($field_element) : ?>
</<?php print $field_element; ?>>
  <?php endif; ?>
<?php endif; ?>