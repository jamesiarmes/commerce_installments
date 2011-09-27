<?php
/**
 * @file
 * commerce_installments_feature.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function commerce_installments_feature_commerce_product_default_types() {
  $items = array(
    'installment_payment' => array(
      'type' => 'installment_payment',
      'name' => 'Installment Payment',
      'description' => 'Installment payment type. ',
      'help' => '',
      'module' => 'commerce_product_ui',
    ),
    'master_installment' => array(
      'type' => 'master_installment',
      'name' => 'Master Installment',
      'description' => '',
      'help' => '',
      'module' => 'commerce_product_ui',
    ),
  );
  return $items;
}

/**
 * Implements hook_views_api().
 */
function commerce_installments_feature_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
