<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */


class commerce_installments_handler_delete_link_field extends commerce_installments_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy commerce installments to check access against
    $dummy_installment = (object) array('type' => $type);
    if (!commerce_installments_access('edit', $dummy_installment)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $installment_id = $values->{$this->aliases['commerce_installments_id']};
    
    return l($text, 'admin/commerce/commerce_installments/commerce_installment/' . $installment_id . '/delete');
  }
}
