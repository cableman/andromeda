<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script type="text/javascript"><?php /* Needed to avoid Flash of Unstyled Content in IE */ ?> </script>
</head>
<body class="<?php print $body_classes; ?>">
  <div id="page" class="container-12 clear-fix">

    <!-- header -->
    <div id="header"  class="grid-12">
      <div id="region-secondary-menu">
        <?php print $region_secondary_menu; ?>
      </div>
        
      <?php if (!empty($logo)): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?><!-- /logo -->

      <?php if (!empty($search_box)): ?>
      <div id="search-box"><?php print $search_box; ?></div>
      <?php endif; ?>

      <?php if (!empty($region_header)): ?>
        <div id="header-region">
          <?php print $region_header; ?>
        </div>
      <?php endif; ?>

      <!-- navigation -->
      <?php if ($region_main_menu): ?>
        <div id="region-main-menu">
          <?php print $region_main_menu; ?>
        </div>
      <?php endif; ?>
      <!-- /navigation -->
    </div>
    <!-- /header -->

    <!-- content -->
    <div id="content" class="container-12 clear">
      <!-- top content -->
      <?php if ($region_top): ?>
        <div id="region-top">
          <?php print $region_top; ?>
        </div>
      <?php endif; ?>
      <!-- /top content -->

      <?php print $messages; ?>      
      <?php print $help; ?>
        
        <div id="main-content" class="grid-12 region">
          <?php if ($title): ?>
            <h1><?php print $title; ?></h1>
          <?php endif; ?>
          <?php if ($tabs): ?>
            <div class="tabs"><?php print $tabs; ?></div>
          <?php endif; ?>
          <?php print $content; ?>
        </div>
    
    </div>
    <!-- /content -->

    <!-- Middle content -->
    <?php if ($region_middle_left || $region_middle_center || $region_middle_right || $region_bottom): ?>
    <div id="secondary-content" class="clear">
      <div id="secondary-content-inner" class="container-12">
        <?php if ($region_middle_left): ?>
          <div id="region-middle-left" class="region grid-4">
          <?php print $region_middle_left; ?>
          </div>
        <?php endif; ?>
        <?php if ($region_middle_center): ?>
          <div id="region-middle-center" class="region grid-4">
          <?php print $region_middle_center; ?>
          </div>
        <?php endif; ?>
        <?php if ($region_middle_right): ?>
          <div id="region-middle-right" class="region grid-4">
          <?php print $region_middle_right; ?>
          </div>
        <?php endif; ?>
        <?php if ($region_bottom): ?>
          <div id="region-bottom" class="region grid-12">
          <?php print $region_bottom; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
    <?php endif; ?>
    <!-- /Secondary content -->

  </div> <!-- /page -->
  <div id="footer-outer">
        <!-- footer -->
    <div id="footer" class="clear container-12">
      <?php if ($footer_1): ?>
        <div class="region grid-3">
          <?php print $footer_1; ?>
        </div>
      <?php endif; ?>
      <?php if ($footer_2): ?>
        <div class="region grid-3">
          <?php print $footer_2; ?>
        </div>
      <?php endif; ?>
      <?php if ($footer_3): ?>
        <div class="region grid-3">
          <?php print $footer_3; ?>
        </div>
      <?php endif; ?>
      <?php if ($footer_4): ?>
        <div class="region grid-3">
          <?php print $footer_4; ?>
        </div>
      <?php endif; ?>
    </div>
    <!-- /footer -->
  </div>
  <?php print $closure; ?>
</body>
</html>
