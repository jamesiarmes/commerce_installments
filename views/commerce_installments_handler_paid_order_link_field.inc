<?php

/**
 * Field handler to present a link to an order.
 */
class commerce_installments_handler_paid_order_link_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['paid_order_ref'] = 'paid_order_ref';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $order_id = $this->get_value($values, 'paid_order_ref');

    return l($text, 'admin/commerce/orders/' . $order_id, array('query' => drupal_get_destination()));
  }
}
