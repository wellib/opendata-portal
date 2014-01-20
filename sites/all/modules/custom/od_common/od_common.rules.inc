<?php
/*
 * @file
 */

function od_common_rules_action_info() {
  return array(
//    'generate_password' => array(
//      'label' => t('Generate password'),
//      'parameter' => array(
//        'length' => array(
//          'type' => 'integer',
//          'label' => t('Length'),
//        ),
//      ),
//      'group' => t('Gosbook'),
//      'base' => 'common_rules_actions_generate_pass',
//      'provides' => array(
//        'password_generated' => array(
//          'type' => 'text',
//          'label' => t('Generated password'),
//        ),
//      ),
//    ),
//    'set_users_password' => array(
//      'label' => t('Set users password'),
//      'parameter' => array(
//        'account' => array(
//          'type' => 'user',
//          'label' => t('User'),
//        ),
//        'password' => array(
//          'type' => 'text',
//          'label' => t('Password'),
//        ),
//      ),
//      'group' => t('User'),
//      'base' => 'common_rules_actions_set_user_password',
//    ),
//    'get_ulogin_data' => array(
//      'label' => t('Get uLogin data'),
//      'provides' => array(
//        'ulogin_data' => array(
//          'type' => 'ulogin_data',
//          'label' => t('uLogin data'),
//        ),
//      ),
//      'group' => t('uLogin'),
//      'base' => 'common_rules_actions_get_ulogin_data',
//    ),
    'copy_entity_form_to_node' => array(
      'label' => t('Copy entity form type to node (Deprecated)'),
      'parameter' => array(
        'ef' => array(
          'type' => 'entityform',
          'label' => t('Entity form type to copy'),
        ),
        'node_type' => array(
          'type' => 'text',
          'label' => t('Node type name to create'),
        ),
        'save_node' => array(
          'type' => 'boolean',
          'label' => t('Save created node'),
        ),
      ),
      'provides' => array(
        'node_created' => array(
          'type' => 'node',
          'label' => t('Created node'),
          'save' => TRUE,
        ),
//        'node_type_created' => array(
//          'type' => 'boolean',
//          'label' => t('Returns true if new node type has been created'),
//        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'common_rules_actions_copy_entity_form_to_node_deprecated',
    ),
    'copy_entity_form_to_node_safe' => array(
      'label' => t('Safely copy entity form type to node'),
      'parameter' => array(
        'ef' => array(
          'type' => 'entityform',
          'label' => t('Entity form type to copy'),
        ),
        'node_type' => array(
          'type' => 'text',
          'label' => t('Node type name to create'),
        ),
        'create_fields' => array(
          'type' => 'boolean',
          'label' => t('Create fields'),
          'default value' => TRUE,
        ),
        'save_node' => array(
          'type' => 'boolean',
          'label' => t('Save created node'),
        ),
      ),
      'provides' => array(
        'node_created' => array(
          'type' => 'node',
          'label' => t('Created node'),
          'save' => TRUE,
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'common_rules_actions_copy_entity_form_to_node',
    ),
    'od_common_format_date' => array(
      'label' => t('Format timestamp to appropriate format'),
      'parameter' => array(
        'timestamp' => array(
          'type' => 'date',
          'label' => t('Valid unix timestamp'),
        ),
        'format' => array(
          'label' => t('Select date format'),
          'type' => 'text',
          'options list' => '_od_common_callbacks_date_formats',
        ),
      ),
      'provides' => array(
        'date_formated' => array(
          'type' => 'text',
          'label' => t('Formated date string'),
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'od_common_rules_actions_od_common_format_date',
    ),
  );
}


function _od_common_callbacks_date_formats() {
  module_load_include('admin.inc', 'system');
  $formats_trash = system_date_time_settings();

  $options = array();
  foreach ($formats_trash['formats']['format'] as $format_name => $element) {
    $options[$format_name] = $element['#title'] . '('. date($element['#default_value']). ')';
  }

  return $options;
}

function od_common_rules_actions_od_common_format_date($timestamp, $format_name) {
  return array('date_formated' => format_date($timestamp, str_replace('date_format_', '', $format_name)));
}


/**
 * Callback for "copy_entity_form_to_node" action.
 * @param $ef
 * @param $node_type
 * @param bool $save_node
 * @return array
 * @deprecated
 *  An old version without field create disabling support
 */
function common_rules_actions_copy_entity_form_to_node_deprecated($ef, $node_type, $save_node = FALSE) {
  module_load_include('core.inc', 'od_common');
  $node = common_copy_ef_to_node($ef, $node_type, array('save_node' => $save_node));
  return array('node_created' => $node);
}

/**
 * Callback for "copy_entity_form_to_node" action.
 * @param $ef
 * @param $node_type
 * @param bool $save_node
 * @return array
 */
function common_rules_actions_copy_entity_form_to_node($ef, $node_type, $create_fields = TRUE, $save_node = FALSE) {
  module_load_include('core.inc', 'od_common');
  $node = common_copy_ef_to_node($ef, $node_type, array('create_fields' => $create_fields, 'save_node' => $save_node));
  return array('node_created' => $node);
}

function common_rules_actions_generate_pass($length = 10) {
  $info = array();
  $info['password_generated'] = user_password($length);

  return $info;
}

function common_rules_actions_set_user_password($account, $password) {
  $edit = array(
    'pass' => $password,
  );
  user_save($account, $edit);
}

function common_rules_actions_get_ulogin_data() {
  //if ()
}
