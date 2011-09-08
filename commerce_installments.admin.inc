<?php

/**
 * @file
 * Commerce Installment editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class CommerceInstallmentsUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'Commerce installments',
      'description' => 'Add edit and update commerce installments.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );

    // Change the overview menu type for the list of commerce installments.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a commerce installment',
      'description' => 'Add a new commerce installment',
      'page callback'  => 'commerce_installments_add_page',
      'access callback'  => 'commerce_installments_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'commerce_installments.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Add menu items to add each different type of entity.
    foreach (commerce_installments_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 'commerce_installments_form_wrapper',
        'page arguments' => array(commerce_installments_create(array('type' => $type->type))),
        'access callback' => 'commerce_installments_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'commerce_installments.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }

    // Loading and editing commerce installments entities
    $items[$this->path . '/commerce_installment/' . $wildcard] = array(
      'page callback' => 'commerce_installments_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'commerce_installments_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'commerce_installments.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    $items[$this->path . '/commerce_installment/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/commerce_installment/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'commerce_installments_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'commerce_installments_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'commerce_installments.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Menu item for viewing commerce installments
    $items['commerce_installment/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'commerce_installments_page_title',
      'title arguments' => array(1),
      'page callback' => 'commerce_installments_page_view',
      'page arguments' => array(1),
      'access callback' => 'commerce_installments_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }
  
  
  /**
   * Create the markup for the add Commerce Installment Entities page within the class
   * so it can easily be extended/overridden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('commerce_installments_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a commerce installments.
 *
 * @param $installment
 *   The commerce installments object being edited by this form.
 *
 * @see commerce_installments_edit_form()
 */
function commerce_installments_form_wrapper($installment) {
  // Add the breadcrumb for the form's location.
  commerce_installments_set_breadcrumb();
  return drupal_get_form('commerce_installments_edit_form', $installment);
}


/**
 * Form callback wrapper: delete a commerce installments.
 *
 * @param $installment
 *   The commerce installments object being edited by this form.
 *
 * @see commerce_installments_edit_form()
 */
function commerce_installments_delete_form_wrapper($installment) {
  // Add the breadcrumb for the form's location.
  //commerce_installments_set_breadcrumb();
  return drupal_get_form('commerce_installments_delete_form', $installment);
}


/**
 * Form callback: create or edit a commerce installments.
 *
 * @param $installment
 *   The commerce installments object to edit or for a create form an empty commerce installments object
 *     with only a commerce installments type defined.
 */
function commerce_installments_edit_form($form, &$form_state, $installment) {
  // Add the default field elements.
  $form['due_date'] = array(
    '#type' => 'date',
    '#title' => t('Payment due date'),
    '#default_value' => isset($installment->due_date) ? commerce_installments_date_transform($installment->due_date) : commerce_installments_date_transform(strtotime('NOW')),
    '#description' => t('The due date for the installment payment.'),
  );

  $form['total_amount_due'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount Due'),
    '#size' => 6,
    '#default_value' => number_format($installment->total_amount_due / 100, 2),
    '#description' => t('The total amount due'),
  );

  $form['data']['#tree'] = TRUE;

  // Add the field related form elements.
  $form_state['commerce_installments'] = $installment;
  field_attach_form('commerce_installments', $installment, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save commerce installment'),
    '#submit' => $submit + array('commerce_installments_edit_form_submit'),
  );
  
  if (!empty($installment->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete commerce installment'),
      '#suffix' => l(t('Cancel'), 'admin/commerce/commerce_installments'),
      '#submit' => $submit + array('commerce_installments_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'commerce_installments_edit_form_validate';
  return $form;
}

/**
 * Form API validate callback for the commerce installments form
 */
function commerce_installments_edit_form_validate(&$form, &$form_state) {
  $installment = $form_state['commerce_installments'];

  form_set_value($form['total_amount_due'], round($form_state['values']['total_amount_due'] * 100, 2), $form_state);
  form_set_value($form['due_date'], mktime(0,0,0, $form_state['values']['due_date']['month'], $form_state['values']['due_date']['day'], $form_state['values']['due_date']['year']), $form_state);
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('commerce_installments', $installment, $form, $form_state);
}


/**
 * Form API submit callback for the commerce installments form.
 * 
 */
function commerce_installments_edit_form_submit(&$form, &$form_state) {
  
  $installment = entity_ui_controller('commerce_installments')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the commerce installments and go back to the list of commerce installments.
  
  // Add in created and changed times.
  if ($installment->is_new = isset($installment->is_new) ? $installment->is_new : 0){
    $installment->created = time();
  }

  $installment->changed = time();
  
  $installment->save();
  $form_state['redirect'] = 'admin/commerce/commerce_installments';
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function commerce_installments_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/commerce/commerce_installments/commerce_installment/' . $form_state['commerce_installments']->commerce_installments_id . '/delete';
}

/**
 * Form callback: confirmation form for deleting a commerce installments.
 *
 * @param $installment
 *   The commerce installment to delete
 *
 * @see confirm_form()
 */
function commerce_installments_delete_form($form, &$form_state, $installment) {
  $form_state['commerce_installments'] = $installment;

  $form['#submit'][] = 'commerce_installments_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete commerce installments %name?', array('%name' => $installment->name)),
    'admin/commerce/commerce_installments/commerce_installment',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for commerce_installments_delete_form
 */
function commerce_installments_delete_form_submit($form, &$form_state) {
  $installment = $form_state['commerce_installments'];

  commerce_installments_delete($installment);

  drupal_set_message(t('The commerce installments %name has been deleted.', array('%name' => $installment->name)));
  watchdog('commerce_installments', 'Deleted commerce installments %name.', array('%name' => $installment->name));

  $form_state['redirect'] = 'admin/commerce/commerce_installments';
}



/**
 * Page to add Commerce Installment Entities.
 *
 * @todo Pass this through a proper theme function
 */
function commerce_installments_add_page() {
  $controller = entity_ui_controller('commerce_installments');
  return $controller->addPage();
}


/**
 * Displays the list of available commerce installments types for commerce installments creation.
 *
 * @ingroup themeable
 */
function theme_commerce_installments_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="commerce-installments-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer commerce installment types')) {
      $output = '<p>' . t('Commerce Installment Entities cannot be added because you have not created any commerce installments types yet. Go to the <a href="@create-commerce-installments-type">commerce installments type creation page</a> to add a new commerce installments type.', array('@create-commerce-installments-type' => url('admin/commerce/commerce_installment_type/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No commerce installments types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative commerce installments pages.
 */
function commerce_installments_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Commerce installments'), 'admin/commerce/commerce_installments'),
  );

  drupal_set_breadcrumb($breadcrumb);
}
