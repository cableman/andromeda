/**
 * @file
 * GMap Shapes
 * GMap API version / Base case
 *
 */

/*global $, Drupal, google.maps, !google.maps.geometry! */

Drupal.gmap.addHandler('gmap', function (elem) {
    var obj = this;

    obj.bind('prepareshape', function (shape) {
        var pa, cargs, style, nofillstyle;
        cargs = {};
        pa = []; // point array (array of LatLng-objects)

        if (shape.type === 'circle') {
            if (Object.prototype.toString.call(shape.center) === '[object Array]') {
                shape.center = new google.maps.LatLng(shape.center[0], shape.center[1]);
            } // otherwise it should be a LatLng already
            if (shape.point2) {
                if (Object.prototype.toString.call(shape.point2) === '[object Array]') {
                    shape.point2 = new google.maps.LatLng(shape.point2[0], shape.point2[1]);
                } // otherwise it should be a LatLng already
                shape.radius = google.maps.geometry.spherical.computeDistanceBetween(shape.center, shape.point2);
            } // if you didn't pass a shape.point2, then you should have passed a shape.radius in meters
        }
        if (shape.type === 'rpolygon') { /* this is deprecated as we have circle now.  It is left for backwards compatibility */
            if (Object.prototype.toString.call(shape.center) === '[object Array]') {
                shape.center = new google.maps.LatLng(shape.center[0], shape.center[1]);
            } // otherwise it should be a LatLng already
            if (Object.prototype.toString.call(shape.point2) === '[object Array]') {
                shape.point2 = new google.maps.LatLng(shape.point2[0], shape.point2[1]);
            } // otherwise it should be a LatLng already
            shape.radius = google.maps.geometry.spherical.computeDistanceBetween(shape.center, shape.point2);
            if (!shape.numpoints) {
                shape.numpoints = 20;
            }
            pa = obj.poly.calcPolyPoints(shape.center, radius, shape.numpoints);
        }
        else if (shape.type === 'polygon') {
            $.each(shape.points, function (i, n) {
                if (Object.prototype.toString.call(n) === '[object Array]') {
                    n = new google.maps.LatLng(n[0], n[1]);
                } // otherwise it should be a LatLng already
                pa.push(n);
            });
        }
        else if (shape.type === 'line') {
            $.each(shape.points, function (i, n) {
                if (Object.prototype.toString.call(n) === '[object Array]') {
                    n = new google.maps.LatLng(n[0], n[1]);
                } // otherwise it should be a LatLng already
                pa.push(n);
            });
            nofillstyle = true;
        }
        else if (shape.type === 'encoded_polygon') {
            pa = google.maps.geometry.encoding.decodePath(shape.path);
        }
        else if (shape.type === 'encoded_line') {
            pa = google.maps.geometry.encoding.decodePath(shape.path);
            nofillstyle = true;
        }

        if (shape.style) {
            if (typeof shape.style === 'string') {
                if (obj.vars.styles[shape.style]) {
                    style = obj.vars.styles[shape.style].slice();
                }
            }
            else {
                style = shape.style.slice();
            }
            style[0] = '#' + style[0];
            style[1] = Number(style[1]);
            style[2] = style[2] / 100;
            if (!nofillstyle) {
                style[3] = '#' + style[3];
                style[4] = style[4] / 100;
            }

            if (shape.type == 'encoded_line') {
                shape.color = style[0];
                shape.weight = style[1];
                shape.opacity = style[2];
            }
            else if (shape.type == 'encoded_polygon') {
                if (shape.polylines) {
                    $.each(shape.polylines, function (i, polyline) {
                        polyline.color = style[0];
                        polyline.weight = style[1];
                        polyline.opacity = style[2];
                    });
                }
                shape.fill = true;
                shape.color = style[3];
                shape.opacity = style[4];
                shape.outline = true;
            }
            else if (shape.type == 'polygon') {
                shape.outline = true;
                shape.strokeColor = style[0];
                shape.strokeOpacity = style[1];
                shape.strokeWeight = style[2];
                shape.fillColor = style[3];
                shape.fillOpacity = style[4];
            }
        }

        if (shape.opts) {
            $.extend(cargs, shape.opts);
        }

        switch (shape.type) {
            case 'circle':
                cargs = {center: shape.center, radius: shape.radius, strokeColor: shape.color }; // required arges
                if (shape.outline) {
                    cargs.strokeColor = shape.color;
                } // outline color
                if (shape.weight) {
                    cargs.strokeWeight = shape.weight;
                } // boundary line weight
                if (shape.fill) {
                    cargs.fillColor = shape.color;
                } // shape fill color
                if (shape.opacity) {
                    cargs.strokeOpacity = shape.color;
                    cargs.fillOpacity = shape.color;
                } // shape opacity
                shape.shape = new google.maps.Circle(cargs);
                break;
            case 'rpolygon':
            case 'encoded_polygon':
            case 'polygon':
                cargs = { path: pa }; // required args
                if (shape.outline) {
                    cargs.strokeColor = shape.strokeColor;
                } // Stroke color
                if (shape.strokeWeight) {
                    cargs.strokeWeight = shape.strokeWeight;
                } // Stroke Weight
                if (shape.strokeOpacity) {
                    cargs.strokeOpacity = shape.strokeOpacity;
                } // Stroke Opacity
                if (shape.fillColor) {
                    cargs.fillColor = shape.fillColor;
                } // Fill Color
                if (shape.fillOpacity) {
                    cargs.fillOpacity = shape.fillOpacity;
                } // Fill Opacity
                shape.shape = new google.maps.Polygon(cargs);
                break;
            case 'line':
            case 'encoded_line':
                cargs = { path: pa }; // required args
                if (shape.color) {
                    cargs.strokeColor = shape.color;
                }
                if (shape.weight) {
                    cargs.strokeWeight = shape.weight;
                }
                if (shape.fill) {
                    cargs.fillColor = shape.color;
                }
                if (shape.opacity) {
                    cargs.strokeOpacity = shape.color;
                    cargs.fillOpacity = shape.color;
                }
                shape.shape = new google.maps.Polyline(cargs);
                break;
        }
    });

    obj.bind('addshape', function (shape) {
        if (!obj.vars.shapes) {
            obj.vars.shapes = [];
        }
        obj.vars.shapes.push(shape);
        shape.shape.setMap(obj.map);

        if (obj.vars.behavior.clickableshapes) {
            google.maps.event.addListener(shape.shape, 'click', function () {
                obj.change('clickshape', -1, shape);
            });
        }
        if (obj.vars.behavior.shapesactions) {
            google.maps.event.addListener(shape.shape, 'dblclick', function () {
                obj.change('dblclickshape', -1, shape);
            });
            google.maps.event.addListener(shape.shape, 'mousedown', function () {
                obj.change('mousedownshape', -1, shape);
            });
            google.maps.event.addListener(shape.shape, 'mouseout', function () {
                obj.change('mouseoutshape', -1, shape);
            });
            google.maps.event.addListener(shape.shape, 'mouseover', function () {
                obj.change('mouseovershape', -1, shape);
            });
            google.maps.event.addListener(shape.shape, 'mouseup', function () {
                obj.change('mouseupshape', -1, shape);
            });
            google.maps.event.addListener(shape.shape, 'mousemove', function () {
                obj.change('mousemoveshape', -1, shape);
            });
            google.maps.event.addListener(shape.shape, 'rightclick', function () {
                obj.change('rightclickshape', -1, shape);
            });
        }
    });

    obj.bind('delshape', function (shape) {
        shape.shape.setMap(null);
    });

    obj.bind('clearshapes', function () {
        if (obj.vars.shapes) {
            $.each(obj.vars.shapes, function (i, n) {
                obj.change('delshape', -1, n);
            });
        }
    });
});
