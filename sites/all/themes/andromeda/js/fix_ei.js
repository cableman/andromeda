/* This is not a gode solution, but it works for now */
$(document).ready(function () {

  // Select all images on the page
  var imgs = $('#content .field-field-content img');
  if (imgs.length == 0) { return; }

  // Run through the images
  for (var i = 0; imgs.length > i; i++) {
    var img = $(imgs[i]);

    // Get style attribute
    var style = img.attr('style');

    // Add class to left float
    if (style.indexOf('float: left;') > -1) {
      img.addClass('left');
    }

    // Add class to right float
    if (style.indexOf('float: right;') > -1) {
      img.addClass('right');
    }

    alert('test');
  }
});

