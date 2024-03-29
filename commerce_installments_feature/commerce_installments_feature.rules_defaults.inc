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
  $items['commerce_installments_process_checkout'] = entity_import('rules_config', '{ "commerce_installments_process_checkout" : {
      "LABEL" : "Commerce Installments Create Installments",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "commerce_installments" ],
      "REQUIRES" : [ "rules", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "line_item" : "Line Item" },
            "DO" : [
              { "component_rules_create_installment_payment_product_for_line_item" : { "line_item" : [ "line_item" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_add_item_to_cart'] = entity_import('rules_config', '{ "rules_add_item_to_cart" : {
      "LABEL" : "Add item to cart",
      "PLUGIN" : "action set",
      "TAGS" : [ "commerce_installments" ],
      "REQUIRES" : [ "commerce_installments" ],
      "USES VARIABLES" : { "commerce_product" : { "label" : "Product", "type" : "commerce_product" } },
      "ACTION SET" : [
        { "commerce_installments_action_add_to_cart" : { "product" : [ "commerce-product" ] } }
      ]
    }
  }');
  $items['rules_create_installment_payment_product_for_line_item'] = entity_import('rules_config', '{ "rules_create_installment_payment_product_for_line_item" : {
      "LABEL" : "Create Installment Payment Product for Line Item",
      "PLUGIN" : "rule",
      "TAGS" : [ "commerce_installments" ],
      "REQUIRES" : [ "rules", "commerce_installments" ],
      "USES VARIABLES" : { "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "line-item" ], "field" : "commerce_product" } },
        { "data_is" : {
            "data" : [ "line-item:commerce-product:type" ],
            "value" : "master_installment"
          }
        }
      ],
      "DO" : [
        { "commerce_installments_action_create_installments" : {
            "commerce_line_item" : [ "line-item" ],
            "commerce_order" : [ "line-item:order" ]
          }
        }
      ]
    }
  }');
  $items['rules_disable_installment_payment_product'] = entity_import('rules_config', '{ "rules_disable_installment_payment_product" : {
      "LABEL" : "Disable Installment Payment Product",
      "PLUGIN" : "rule",
      "TAGS" : [ "commerce_installments" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "line-item" ], "field" : "commerce_product" } },
        { "data_is" : {
            "data" : [ "line-item:commerce-product:type" ],
            "value" : "installment_payment"
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "line-item:commerce-product:status" ], "value" : "0" } }
      ]
    }
  }');
  $items['rules_disable_installment_payment_product_when_it_s_been_paid'] = entity_import('rules_config', '{ "rules_disable_installment_payment_product_when_it_s_been_paid" : {
      "LABEL" : "Disable Installment Payment Product When It\'s Been Paid",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "commerce_installments" ],
      "REQUIRES" : [ "rules", "commerce_payment" ],
      "ON" : [ "commerce_payment_order_paid_in_full" ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-order:commerce-line-items" ] },
            "ITEM" : { "line_item" : "Line Item" },
            "DO" : [
              { "component_rules_disable_installment_payment_product" : { "line_item" : [ "line_item" ] } }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
