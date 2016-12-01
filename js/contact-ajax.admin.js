(function ($) {

  Drupal.behaviors.contactAjaxAdmin = {
    attach: function (context, settings) {

      var farb = $.farbtastic('#picker');
      $('.colorwell', context)
        .each(function () {
          farb.linkTo(this);
        })
        .focus(function () {
          farb.linkTo(this);
          $('.colorwell', context).unbind('keyup').parent().removeClass('item-selected');
          $(this).keyup().parent().addClass('item-selected');
        })
        .first().focus();

    }
  };

})(jQuery);