  <?php if ($content['left']) { ?>
    <div class="grid-3 alpha panel-col-left <?php if (!$content['right']) { ?>suffix-9 omega<?php } ?>">
      <?php print $content['left']; ?>
    </div>
  <?php } ?>
  
  <?php if ($content['right']) { ?>
  <div class="<?php if (!$content['left']) { ?>prefix-3 alpha <?php } ?> grid-9 omega panel-col-right">
    <?php print $content['right']; ?>
  </div>
  <?php } ?>