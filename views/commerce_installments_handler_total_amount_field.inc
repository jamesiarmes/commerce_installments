<?php
/**
 * Render a field as a numeric value
 *
 * Definition terms:
 * - float: If true this field contains a decimal value. If unset this field
 *          will be assumed to be integer.
 *
 * @ingroup views_field_handlers
 */
class commerce_installments_handler_total_amount_field extends views_handler_field_numeric {
  function construct() {
    parent::construct();

    $this->additional_fields['total_amount_due'] = 'total_amount_due';
  }

  function render($values) {
    $amount = $this->get_value($values, 'total_amount_due');

    return '$ '.number_format(($amount / 100), 2);
  }
}
