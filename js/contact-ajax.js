(function ($) {

  Drupal.behaviors.contactAjax = {
    attach: function (context, settings) {

      $('.open-item', context).click(function () {
        $('#contact-ajax', context).addClass('open');
        $(this).addClass('open');
      });

      $('.close-item', context).click(function () {
        $('#contact-ajax', context).removeClass('open').attr('style', '');
        $('.open-item', context).removeClass('open');
      });

      $('#contact-ajax', context).draggable({
        handle: '.title',
        start: function (event, ui) {
          $(this).css({
            bottom: 'auto',
            right: 'auto'
          });
        }
      });

    }
  };

})(jQuery);