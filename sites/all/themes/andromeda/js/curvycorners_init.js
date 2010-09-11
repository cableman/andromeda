
$(document).ready(function () {
  var all = {
    tl: {radius: 8},
    tr: {radius: 8},
    bl: {radius: 8},
    br: {radius: 8},
    antiAlias: true
  }

  var top_lr = {
    tl: {radius: 8},
    tr: {radius: 8},
    antiAlias: true
  }

  curvyCorners(all, "#page");
  curvyCorners(top_lr, "#site-header");
  curvyCorners({tl: {radius: 8}, antiAlias: true}, "#branding");
});