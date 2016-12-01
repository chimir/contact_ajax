<?php
/**
 * @file
 * Administration pages for the Contact Ajax module.
 */

/**
 * Returns settings form.
 */
function contact_ajax_admin_settings() {
  $form['contact_ajax_position'] = array(
    '#type' => 'radios',
    '#title' => t('Position'),
    '#description' => t('Position.'),
    '#options' => array(
      'right' => t('Right'),
      'left' => t('Left'),
      'bottom' => t('Bottom'),
    ),
    '#default_value' => variable_get('contact_ajax_position', 'bottom'),
  );

  $path = drupal_get_path('module', 'contact_ajax');
  $form['color'] = array(
    '#type' => 'fieldset',
    '#title' => t('Color scheme'),
    '#attached' => array(
      'library' => array(
        array('system', 'farbtastic'),
      ),
      'js' => array($path . '/js/contact-ajax.admin.js'),
      'css' => array($path . '/css/contact-ajax.admin.css'),
    ),
  );

  $form['color']['contact_ajax_farbtastic'] = array(
    '#type' => 'markup',
    '#markup' => '<div id="picker"></div>',
  );

  $form['color']['palette'] = array(
    '#type' => 'container',
  );

  $form['color']['palette']['contact_ajax_title_bg'] = array(
    '#type' => 'textfield',
    '#title' => t('Title background'),
    '#size'   => 8,
    '#attributes' => array(
      'class' => array('colorwell')
    ),
    '#element_validate' => array('contact_ajax_color_validate'),
    '#default_value' => variable_get('contact_ajax_title_bg', '#C2C6E2'),
  );

  $form['color']['palette']['contact_ajax_title_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Title color'),
    '#size'   => 8,
    '#attributes' => array(
      'class' => array('colorwell')
    ),
    '#element_validate' => array('contact_ajax_color_validate'),
    '#default_value' => variable_get('contact_ajax_title_color', '#FFFFFF'),
  );

  $form['color']['palette']['contact_ajax_border_bottom'] = array(
    '#type' => 'textfield',
    '#title' => t('Border bottom color'),
    '#size'   => 8,
    '#attributes' => array(
      'class' => array('colorwell')
    ),
    '#element_validate' => array('contact_ajax_color_validate'),
    '#default_value' => variable_get('contact_ajax_border_bottom', '#A7ABC6'),
  );

  $form['color']['palette']['contact_ajax_button_bg'] = array(
    '#type' => 'textfield',
    '#title' => t('Buttot background'),
    '#size'   => 8,
    '#attributes' => array(
      'class' => array('colorwell')
    ),
    '#element_validate' => array('contact_ajax_color_validate'),
    '#default_value' => variable_get('contact_ajax_button_bg', '#C2C6E2'),
  );

  $form['color']['palette']['contact_ajax_button_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Buttot color'),
    '#size'   => 8,
    '#attributes' => array(
      'class' => array('colorwell')
    ),
    '#element_validate' => array('contact_ajax_color_validate'),
    '#default_value' => variable_get('contact_ajax_button_color', '#FFFFFF'),
  );

  return system_settings_form($form);
}

/**
 * Validate color.
 */
function contact_ajax_color_validate($element) {
  $value = $element['#value'];
  $title = $element['#title'];
  preg_match('/^#([a-f0-9]{3}){1,2}$/iD', $value, $match);

  if (empty($match[0])) {
    form_error($element, t('%name must be a valid hexadecimal CSS color value.', array('%name' => $title)));
  }
}
