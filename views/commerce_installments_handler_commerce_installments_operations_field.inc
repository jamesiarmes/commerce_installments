<?php

/**
 * This field handler aggregates operations that can be done on a commerce installments
 * under a single field providing a more flexible way to present them in a view
 */
class commerce_installments_handler_commerce_installments_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['commerce_installments_id'] = 'commerce_installments_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('commerce installments', 'admin/commerce/commerce_installments/commerce_installment', array($this->get_value($values, 'commerce_installments_id')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
