/* This is not a gode solution, but it works for now */
$(document).ready(function () {
  // Only fix in ei
  if (!$.browser.msie) { return; }

  // Select all images on the page
  var imgs = $('#content .field-field-content img');
  if (imgs.length == 0) { return; }

  // Run through the images
  for (var i = 0; imgs.length > i; i++) {
    var img = $(imgs[i]);

    // Add class to left float
    if (img.css('float') == 'left') {
      img.addClass('left');
    }

    // Add class to right float
    if (img.css('float') == 'right') {
      img.addClass('right');
    }
  }
});

