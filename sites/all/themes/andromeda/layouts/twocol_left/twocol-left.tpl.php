  <?php if ($content['left']) { ?>
    <div class="grid-9 alpha panel-col-left <?php if (!$content['right']) { ?>suffix-3 omega<?php } ?>">
      <?php print $content['left']; ?>
    </div>
  <?php } ?>
  
  <?php if ($content['right']) { ?>
  <div class="<?php if (!$content['left']) { ?>prefix-9 alpha <?php } ?> grid-3 omega panel-col-right">
    <?php print $content['right']; ?>
  </div>
  <?php } ?>