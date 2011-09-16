<?php
/**
 * @file
 * commerce_installments_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_installments_feature_default_rules_configuration() {
  $items = array();
  $items['commerce_installment_process_checkout'] = entity_import('rules_config', '{ "commerce_installment_process_checkout" : {
      "LABEL" : "Commerce Installment Process Checkout",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "commerce_installments", "entity" ],
      "ON" : [ "commerce_order_update" ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "commerce_installments_action_create_installments" : {
                  "commerce_line_item" : [ "list-item" ],
                  "commerce_order" : [ "commerce_order" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
