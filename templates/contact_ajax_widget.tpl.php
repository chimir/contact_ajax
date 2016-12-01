<span class="open-item <?php print $element['#position'] ?>" <?php print $element['#button_style'] ?>>
  <?php print t('Contact us') ?>
</span>
<div id="contact-ajax" class="<?php print $element['#position'] ?>">
  <section class="contact-ajax">
    <span class="close-item">&#215;</span>
    <span class="title" <?php print $element['#title_style'] ?>><?php print t('Contact us') ?></span>
    <div class="wrap" <?php print $element['#border_bottom'] ?>>
      <?php print $element['#form'] ?>
    </div>
  </section>
</div>
