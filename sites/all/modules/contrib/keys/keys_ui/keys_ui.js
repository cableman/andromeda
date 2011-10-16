
Drupal.behaviors.keys = function() {
  if ($("#edit-rule:not('.keys-processed')").size()) {
    $("#edit-rule").focus(function() {
      var ruleField = $(this);
      if (ruleField.val() == Drupal.settings.keys.domain) {
        if (ruleField.css('color') != 'rgb(0, 0, 0)') {
          ruleField.val('');
          ruleField.css('color', '#000000')
        }
      }
    });

    $("#edit-rule").blur(function() {
      var ruleField = $(this);
      if (ruleField.val() == '') {
        ruleField.val(Drupal.settings.keys.domain);
        ruleField.css('color', '#999999');
      }
    });

    $("#edit-rule").addClass('keys-processed');
  }
}
