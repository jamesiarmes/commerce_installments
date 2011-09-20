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
  $items['rules_add_installment_payment_to_cart'] = entity_import('rules_config', '{ "rules_add_installment_payment_to_cart" : {
      "LABEL" : "Add Installment Payment To Cart",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "commerce_product" : { "label" : "Product", "type" : "commerce_product" } },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-product:type" ], "value" : "installment_payment" } }
      ],
      "DO" : [
        { "component_rules_add_item_to_cart" : {
            "commerce_product" : [ "commerce_product" ],
            "line_item_type" : "installment"
          }
        }
      ]
    }
  }');
  $items['rules_add_item_to_cart'] = entity_import('rules_config', '{ "rules_add_item_to_cart" : {
      "LABEL" : "Add Item to Cart",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "commerce_installments" ],
      "USES VARIABLES" : {
        "commerce_product" : { "label" : "Product", "type" : "commerce_product" },
        "line_item_type" : { "label" : "Line Item Type", "type" : "text" }
      },
      "ACTION SET" : [
        { "commerce_installments_action_add_to_cart" : {
            "product" : [ "commerce-product" ],
            "line_item_type" : [ "line_item_type" ]
          }
        }
      ]
    }
  }');
  $items['rules_create_installment_payment_product_for_line_item'] = entity_import('rules_config', '{ "rules_create_installment_payment_product_for_line_item" : {
      "LABEL" : "Create Installment Payment Product for Line Item",
      "PLUGIN" : "rule",
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
            "commerce_order" : [ "line-item:order" ],
            "original_product" : [ "line-item:commerce-product" ]
          }
        }
      ]
    }
  }');
  $items['rules_disable_installment_payment_product'] = entity_import('rules_config', '{ "rules_disable_installment_payment_product" : {
      "LABEL" : "Disable Installment Payment Product",
      "PLUGIN" : "rule",
      "TAGS" : [ "commerce_installment" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "line_item" : { "label" : "Line Item", "type" : "commerce_line_item" } },
      "IF" : [
        { "data_is" : { "data" : [ "line-item:type" ], "value" : "installment" } },
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
