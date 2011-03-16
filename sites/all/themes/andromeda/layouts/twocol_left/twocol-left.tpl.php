  <?php if ($content['left']) { ?>
    <div class="grid-8 alpha panel-col-left <?php if (!$content['right']) { ?>suffix-4 omega<?php } ?>">
      <?php print $content['left']; ?>
    </div>
  <?php } ?>
  
  <?php if ($content['right']) { ?>
  <div class="<?php if (!$content['left']) { ?>prefix-8 alpha <?php } ?> grid-4 omega panel-col-right">
    <?php print $content['right']; ?>
  </div>
  <?php } ?>