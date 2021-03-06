<?php
/*
 * @file
 */

function od_common_rules_action_info() {
  return array(
    'generate_password' => array(
      'label' => t('Generate password'),
      'parameter' => array(
        'length' => array(
          'type' => 'integer',
          'label' => t('Length'),
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'common_rules_actions_generate_pass',
      'provides' => array(
        'password_generated' => array(
          'type' => 'text',
          'label' => t('Generated password'),
        ),
      ),
    ),
    'set_users_password' => array(
      'label' => t('Set users password'),
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
        ),
        'password' => array(
          'type' => 'text',
          'label' => t('Password'),
        ),
      ),
      'group' => t('User'),
      'base' => 'common_rules_actions_set_user_password',
    ),
    'get_ulogin_data' => array(
      'label' => t('Get uLogin data'),
      'provides' => array(
        'ulogin_data' => array(
          'type' => 'ulogin_data',
          'label' => t('uLogin data'),
        ),
      ),
      'group' => t('uLogin'),
      'base' => 'common_rules_actions_get_ulogin_data',
    ),
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
        'config' => array(
          'type' => 'struct',
          'label' => t('Copy config'),
          'optional' => TRUE,
          'ui class' => 'ODCommonRulesUI_ef_node_config',
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
    'copy_entity_form_to_existing_node_safe' => array(
      'label' => t('Safely copy entity form type to existing node'),
      'parameter' => array(
        'ef' => array(
          'type' => 'entityform',
          'label' => t('Entity form type to copy'),
        ),
        'node' => array(
          'type' => 'node',
          'label' => t('Node to copy to'),
        ),
        'config' => array(
          'type' => 'struct',
          'label' => t('Copy config'),
          'optional' => TRUE,
          'ui class' => 'ODCommonRulesUI_ef_node_config',
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'common_rules_actions_copy_entity_form_to_existing_node',
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
    'od_common_file_get_extension_term' => array(
      'label' => t('Gets taxonomy term that represents file extension'),
      'parameter' => array(
        'file' => array(
          'type' => 'file',
          'label' => t('File'),
        ),
        'vocabulary' => array(
          'label' => t('Select vocabulary that contains term as extensions'),
          'type' => 'taxonomy_vocabulary',
        ),
      ),
      'provides' => array(
        'extension_term' => array(
          'type' => 'taxonomy_term',
          'label' => t('Formated date string'),
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'od_common_rules_actions_od_common_file_get_extension_term',
    ),
    'od_common_entity_list_get_element_by_index' => array(
      'label' => t('Gets an element from list<node> by index'),
      'parameter' => array(
        'list' => array(
          'type' => 'list<node>',
          'label' => t('A list of entities'),
        ),
        'index' => array(
          'label' => t('An index to return an element'),
          'type' => 'integer',
        ),
      ),
      'provides' => array(
        'entity' => array(
          'type' => 'list_element',
          'label' => t('List element'),
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'od_common_rules_actions_od_common_entity_list_get_element_by_index',
    ),
    'od_common_convert_geolocation_to_geofield' => array(
      'label' => t('Converts geolocation spatial code into geofield'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('A node with geolocation data'),
        ),
        'geolocation' => array(
          'type' => 'text',
          'label' => t('Full geolocation field machine-name'),
        ),
        'geofield' => array(
          'type' => 'text',
          'label' => t('Full geofield field machine-name'),
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'od_common_rules_actions_od_common_convert_geolocation_to_geofield',
    ),
    'generate_api_key' => array(
      'label' => t('Generate key to api'),
      'parameter' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('For which user generate a key'),
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'od_common_rules_actions_generate_api_key',
      'provides' => array(
        'api_key_generated' => array(
          'type' => 'text',
          'label' => t('Generated key'),
        ),
      ),
    ),
  );
}

function od_common_rules_actions_od_common_entity_list_get_element_by_index($entities, $index) {
  $ret = array(
    'list_element' => NULL,
  );

  if (isset($entities[$index])) {
    $ret['list_element'] = $entities[$index];
  }

  return $ret;
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
  od_common_module('core');
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
function common_rules_actions_copy_entity_form_to_node($ef, $config, $save_node = FALSE) {
  od_common_module('core');

  $options = array(
    'create_fields' => FALSE,
    'save_node' => $save_node,
    'field_mappings' => $config['field_mappings'],
  );

  $node = common_copy_ef_to_node($ef, $config['node_type'], $options);
  return array('node_created' => $node);
}


/**
 * Callback for "copy_entity_form_to_node" action.
 * @param $ef
 * @param $node_type
 * @param bool $save_node
 * @return array
 */
function common_rules_actions_copy_entity_form_to_existing_node($ef, $node, $config) {
  od_common_module('core');

  $options = array(
    'create_fields' => FALSE,
    'save_node' => FALSE,
    'field_mappings' => $config['field_mappings'],
    'node' => $node,
  );

  $node = common_copy_ef_to_node($ef, $config['node_type'], $options);
}


function common_rules_actions_generate_pass($length = 10) {
  $info = array();
  $info['password_generated'] = user_password($length);

  return $info;
}

function od_common_rules_actions_generate_api_key($user) {
  $info = array();
  $string = $user->uid . 'key' . time() . 'api';
  $info['api_key_generated'] = md5($string);
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

/**
 * Rule callback.
 */
function od_common_rules_actions_od_common_file_get_extension_term($file, $vocabulary) {
  $term = NULL;
  try {
    if ($ext = pathinfo($file->filename, PATHINFO_EXTENSION)) {
      od_common_module('core');
      if ($term = od_common_file_get_extension_term($ext, $vocabulary)) {
        $term = entity_load_single('taxonomy_term', $term->tid);
      }
    }
  }
  catch (Exception $e) {
    watchdog_exception('od_common', $e);
    $term = NULL;
  }

  return array('extension_term' => $term);
}

/**
 * Rule callback.
 */
function od_common_rules_actions_od_common_convert_geolocation_to_geofield($node, $geolocation, $geofield) {
  $wrapper = entity_metadata_wrapper('node', $node);
  $geolocation = $node->$geolocation;
  $data = array(
    'lat' => $geolocation['und'][0]['lat'],
    'lon' => $geolocation['und'][0]['lng'],
  );

  $wrapper->$geofield->set($data);
  $wrapper->save();
}

