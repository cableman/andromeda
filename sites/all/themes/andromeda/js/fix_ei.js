$(document).ready(function () {
  /* This is not a gode solution, but it works for now */
  var img = $('.field-field-content img');
  var style = img.attr('style');  
  if (style.indexOf('float: left;') > -1) {
    img.addClass('left');
  }

  if (style.indexOf('float: right;') > -1) {
    img.addClass('right');
  }
});

