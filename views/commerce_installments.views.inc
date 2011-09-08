<?php

/**
 * @file
 * Providing extra functionality for the Commerce Installment UI via views.
 */


/**
 * Implements hook_views_data()
 */
function commerce_installments_views_data_alter(&$data) { 
  $data['commerce_installments']['link_commerce_installments'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the commerce installments.'),
      'handler' => 'commerce_installments_handler_link_field',
    ),
  );
  $data['commerce_installments']['edit_commerce_installments'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the commerce installments.'),
      'handler' => 'commerce_installments_handler_edit_link_field',
    ),
  );
  $data['commerce_installments']['delete_commerce_installments'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the commerce installments.'),
      'handler' => 'commerce_installments_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows commerce_installments/commerce_installment/%commerce-installment_id/op
  $data['commerce_installments']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this commerce installments.'),
      'handler' => 'commerce_installments_handler_commerce_installments_operations_field',
    ),
  );
  $data['commerce_installments']['initial_order_ref']['field']['handler'] = 'commerce_installments_handler_initial_order_link_field';
  $data['commerce_installments']['initial_line_item_ref']['field']['handler'] = 'commerce_order_handler_field_order_link';
  $data['commerce_installments']['paid_order_ref']['field']['handler'] = 'commerce_installments_handler_paid_order_link_field';
  $data['commerce_installments']['paid_line_item_ref']['field']['handler'] = 'commerce_order_handler_field_order_link';
  $data['commerce_installments']['created']['field']['handler'] = 'views_handler_field_date';
  $data['commerce_installments']['changed']['field']['handler'] = 'views_handler_field_date';
  $data['commerce_installments']['due_date']['field']['handler'] = 'views_handler_field_date';

}


/**
 * Implements hook_views_default_views().
 */
function commerce_installments_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'commerce_installments';
  $view->description = 'A list of all commerce installments';
  $view->tag = 'Commerce Installments';
  $view->base_table = 'commerce_installments';
  $view->human_name = 'Commerce installments';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Commerce installments';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any commerce installments type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'commerce_installments_id' => 'commerce_installments_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'commerce_installments_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No commerce installments have been created yet';
  /* Field: commerce_installments: Commerce Installment ID */
  $handler->display->display_options['fields']['commerce_installments_id']['id'] = 'commerce_installments_id';
  $handler->display->display_options['fields']['commerce_installments_id']['table'] = 'commerce_installments';
  $handler->display->display_options['fields']['commerce_installments_id']['field'] = 'commerce_installments';
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['commerce_installments_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['commerce_installments_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['commerce_installments_id']['empty_zero'] = 0;
  /* Field: commerce_installments: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'commerce_installments';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  /* Field: commerce_installments: Link */
  $handler->display->display_options['fields']['link_commerce_installments']['id'] = 'link_commerce_installments';
  $handler->display->display_options['fields']['link_commerce_installments']['table'] = 'commerce_installments';
  $handler->display->display_options['fields']['link_commerce_installments']['field'] = 'link_commerce_installments';
  $handler->display->display_options['fields']['link_commerce_installments']['label'] = 'View';
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_commerce_installments']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_commerce_installments']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_commerce_installments']['empty_zero'] = 0;
  /* Field: commerce_installments: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'commerce_installments';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'commerce_installments_admin_page');
  $handler->display->display_options['path'] = 'admin/commerce/commerce_installments/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Commerce installments';
  $handler->display->display_options['tab_options']['description'] = 'Manage commerce installments';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['commerce_installmentss'] = array(
    t('Master'),
    t('Commerce installments'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Empty '),
    t('No commerce installments have been created yet'),
    t('Commerce Installment ID'),
    t('.'),
    t(','),
    t('Name'),
    t('View'),
    t('Operations links'),
    t('Page'),
  );
  $views[] = $view;
  return $views;

}
