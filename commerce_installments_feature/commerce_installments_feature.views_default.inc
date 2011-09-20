<?php
/**
 * @file
 * commerce_installments_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_installments_feature_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'commerce_installment_payment';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_product';
  $view->human_name = 'Commerce Installment Payment';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Installments';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'product_id_1' => 'product_id_1',
    'title' => 'title',
    'product_id' => 'product_id',
    'commerce_price' => 'commerce_price',
    'field_amount_paid' => 'field_amount_paid',
    'add_to_cart_form' => 'add_to_cart_form',
    'sku' => 'sku',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = 'commerce_price';
  $handler->display->display_options['style_options']['info'] = array(
    'product_id_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'product_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'commerce_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_amount_paid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'add_to_cart_form' => array(
      'align' => '',
      'separator' => '',
    ),
    'sku' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Commerce Product: Creator */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'User';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_original_order_target_id']['id'] = 'field_original_order_target_id';
  $handler->display->display_options['relationships']['field_original_order_target_id']['table'] = 'field_data_field_original_order';
  $handler->display->display_options['relationships']['field_original_order_target_id']['field'] = 'field_original_order_target_id';
  $handler->display->display_options['relationships']['field_original_order_target_id']['required'] = 1;
  /* Field: Commerce Product: Product ID */
  $handler->display->display_options['fields']['product_id_1']['id'] = 'product_id_1';
  $handler->display->display_options['fields']['product_id_1']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['product_id_1']['field'] = 'product_id';
  $handler->display->display_options['fields']['product_id_1']['label'] = 'Payment ID';
  $handler->display->display_options['fields']['product_id_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['product_id_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['product_id_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['product_id_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['product_id_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['product_id_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['product_id_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['product_id_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['product_id_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['product_id_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['product_id_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['product_id_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['product_id_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['product_id_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['product_id_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['product_id_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['product_id_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['product_id_1']['link_to_product'] = 1;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Field: Commerce Product: Product ID */
  $handler->display->display_options['fields']['product_id']['id'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['product_id']['field'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['product_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['product_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['product_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['product_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['product_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['product_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['product_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['product_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['product_id']['link_to_product'] = 0;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['label'] = 'Payment Due Amount';
  $handler->display->display_options['fields']['commerce_price']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['commerce_price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['commerce_price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['commerce_price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['commerce_price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['commerce_price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['commerce_price']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  $handler->display->display_options['fields']['commerce_price']['field_api_classes'] = 0;
  /* Field: Commerce Product: Amount Paid */
  $handler->display->display_options['fields']['field_amount_paid']['id'] = 'field_amount_paid';
  $handler->display->display_options['fields']['field_amount_paid']['table'] = 'field_data_field_amount_paid';
  $handler->display->display_options['fields']['field_amount_paid']['field'] = 'field_amount_paid';
  $handler->display->display_options['fields']['field_amount_paid']['label'] = 'Amount Already Paid';
  $handler->display->display_options['fields']['field_amount_paid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_amount_paid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_amount_paid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_amount_paid']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['field_amount_paid']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['field_amount_paid']['field_api_classes'] = 0;
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = '';
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['external'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['alter']['html'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['hide_empty'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['empty_zero'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'installment';
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['label'] = '';
  $handler->display->display_options['fields']['sku']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sku']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sku']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sku']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sku']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sku']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sku']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sku']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sku']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Filter criterion: Commerce Product: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'installment_payment' => 'installment_payment',
  );
  /* Filter criterion: Commerce Product: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = 1;
  $handler->display->display_options['filters']['status']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_original_order_target_id';
  $handler->display->display_options['filters']['status_1']['value'] = array(
    'completed' => 'completed',
  );

  /* Display: My Installments */
  $handler = $view->new_display('page', 'My Installments', 'page');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Product: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'installment_payment' => 'installment_payment',
  );
  /* Filter criterion: Commerce Product: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = 1;
  $handler->display->display_options['filters']['status']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['path'] = 'user/%/installments';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My Installments';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'devel';

  /* Display: Installments Admin */
  $handler = $view->new_display('page', 'Installments Admin', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_product'] = 1;
  /* Field: Commerce Product: Product ID */
  $handler->display->display_options['fields']['product_id']['id'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['product_id']['field'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['product_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['product_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['product_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['product_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['product_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['product_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['product_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['product_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['product_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['product_id']['link_to_product'] = 0;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['label'] = 'Payment Due Amount';
  $handler->display->display_options['fields']['commerce_price']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['commerce_price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['commerce_price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['commerce_price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['commerce_price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['commerce_price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['commerce_price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['commerce_price']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  $handler->display->display_options['fields']['commerce_price']['field_api_classes'] = 0;
  /* Field: Commerce Product: Due Date */
  $handler->display->display_options['fields']['field_due_date']['id'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['table'] = 'field_data_field_due_date';
  $handler->display->display_options['fields']['field_due_date']['field'] = 'field_due_date';
  $handler->display->display_options['fields']['field_due_date']['label'] = 'Payment Due Date';
  $handler->display->display_options['fields']['field_due_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_due_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_due_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_due_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_due_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_due_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_due_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_due_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_due_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_due_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_due_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_due_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_due_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_due_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_due_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_due_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_due_date']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_due_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_due_date']['field_api_classes'] = 0;
  /* Field: Commerce Product: Amount Paid */
  $handler->display->display_options['fields']['field_amount_paid']['id'] = 'field_amount_paid';
  $handler->display->display_options['fields']['field_amount_paid']['table'] = 'field_data_field_amount_paid';
  $handler->display->display_options['fields']['field_amount_paid']['field'] = 'field_amount_paid';
  $handler->display->display_options['fields']['field_amount_paid']['label'] = 'Amount Already Paid';
  $handler->display->display_options['fields']['field_amount_paid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_amount_paid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_amount_paid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_amount_paid']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_amount_paid']['type'] = 'commerce_price_formatted_amount';
  $handler->display->display_options['fields']['field_amount_paid']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['field_amount_paid']['field_api_classes'] = 0;
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['label'] = '';
  $handler->display->display_options['fields']['sku']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sku']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sku']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sku']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sku']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sku']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sku']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sku']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sku']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sku']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Commerce Product: Original Order */
  $handler->display->display_options['fields']['field_original_order']['id'] = 'field_original_order';
  $handler->display->display_options['fields']['field_original_order']['table'] = 'field_data_field_original_order';
  $handler->display->display_options['fields']['field_original_order']['field'] = 'field_original_order';
  $handler->display->display_options['fields']['field_original_order']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_original_order']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_original_order']['alter']['path'] = 'admin/commerce/orders/[field_original_order-target_id]';
  $handler->display->display_options['fields']['field_original_order']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_original_order']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_original_order']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_original_order']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_original_order']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_original_order']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_original_order']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_original_order']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_original_order']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_original_order']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_original_order']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_original_order']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_original_order']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_original_order']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_original_order']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_original_order']['click_sort_column'] = 'target_id';
  $handler->display->display_options['fields']['field_original_order']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_original_order']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'admin/commerce/installments';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Installment Payments';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['commerce_installment_payment'] = $view;

  return $export;
}
