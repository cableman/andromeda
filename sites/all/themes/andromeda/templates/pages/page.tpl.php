<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>

<body class="<?php print $body_classes; ?> show-grid">
  <div id="page" class="container-12 clear-block">

    <!-- Header -->
    <div id="site-header" class="clear-block">
      <div id="branding" class="grid-12 alpha clear-block">
	<?php print $logo; ?>
      </div>
    </div>

    <!-- Menu -->
    <?php if ($menu): ?>
    <div id="site-menu">
      <?php print $menu; ?>
    </div>
    <?php endif; ?>

    <!-- Main content -->
    <div id="main" class="clear-block">      
      <div id="left" class="grid-3 alpha omega">
        &nbsp;
        <?php print $left; ?>
      </div>
      <div id="main-content">
        <?php if ($tabs): ?>
        <div class="tabs"><?php print $tabs; ?></div>
        <?php endif; ?>
        <?php print $breadcrumb; ?>
        <?php print $messages; ?>
        <?php print $content; ?>
      </div>

      <?php print $feed_icons; ?>
    </div>

  <div id="footer" class="clear-block">
    <?php if ($footer): ?>
        <?php print $footer; ?>
      </div>
    <?php endif; ?>

    <?php if ($footer_message): ?>
      <div id="footer-message" class="grid-12">
        <?php print $footer_message; ?>
      </div>
    <?php endif; ?>
  </div>
  
  <?php print $closure; ?>
</body>
</html>
