/**
 * OpenLayers AIS Vector Layer Handler
 */
Drupal.openlayers.layer.openlayers_ais_vector = function(title, map, options) {
  // Note, so that we do not pass all the features along to the Layer
  // options, we use the options.options to give to Layer
  options.options.drupalID = options.drupalID;

  // Create projection
  options.projection = new OpenLayers.Projection('EPSG:'+options.projection);

  // Get style map
  options.options.styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);

  // Create layer object
  var layer = new OpenLayers.Layer.Vector(title, options.options);

  // Center map to the first point in the feature.
  map.center.initial['centerpoint'] = '' + options.features[0].center;

  // Add fetures if there are any
  if (options.features) {
    Drupal.openlayers.addFeatures(map, layer, options.features);
  }

  return layer;
};
