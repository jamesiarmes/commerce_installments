<?php

/**
 * @file
 * Commerce Installment type editing UI.
 */

/**
 * UI controller.
 */
class CommerceInstallmentsTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage commerce installments entity types, including adding
    and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the commerce installments type editing form.
 */
function commerce_installments_type_form($form, &$form_state, $installment_type, $op = 'edit') {

  if ($op == 'clone') {
    $installment_type->label .= ' (cloned)';
    $installment_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $installment_type->label,
    '#description' => t('The human-readable name of this commerce installments type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($installment_type->type) ? $installment_type->type : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'commerce_installments_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this commerce installments type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save commerce installment type'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function commerce_installments_type_form_submit(&$form, &$form_state) {
  $installment_type = entity_ui_form_submit_build_entity($form, $form_state);
  $installment_type->save();
  $form_state['redirect'] = 'admin/commerce/commerce_installments/commerce_installment_types';
}

/**
 * Form API submit callback for the delete button.
 */
function commerce_installments_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/commerce/commerce_installments/commerce_installment_types/manage/' . $form_state['commerce_installments_type']->type . '/delete';
}
