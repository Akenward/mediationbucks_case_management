<?php

/** function to return definitions of new field instances required by each of the three new nodes
 *  @node_type: is the node type.
 *  @return takes the form af an array of field instance arrays each keyed on the field type name
 */
 
 function _case_management_installed_instances($node_type) {
  switch ($node_type) {
  	// build and return an array with the new fields required for the Event node field instances
  	case 'case_management_event':
      return array(
        // define instance for field Image in the Event node - existing core field reused for this node
        'field_image' => array(
          'field_name' => 'field_image',
          'entity_type' => 'node',
          'bundle' => 'case_management_event',
          'description' => 'A field to include an image of the event.',
          'label' => 'Image',
          'widget' => array (
            'type' => 'image_image',
            'settings' => array (
              'progress_indicator' => 'throbber',
              'preview_image_style' => 'thumbnail',
          ),
            'weight' => 1,
            'module' => 'image',
          ),
            'settings' => array(
            'file_directory' => 'images',
	        'alt_field' => true,
	        'title_field' => true,
	      ),
	      'display' => array(
            'default' => array(
	          'label' => 'hidden',
	          'settings' => array(
		        'image_style' => 'large'
		      ),
		      'weight' => 1
	        ),
	        'teaser' => array(
	          'label' => 'hidden',
	          'settings' => array(
		        'image_style' => 'medium',
		        'image_link' => 'content'
		      ),
		      'weight' => 1,
		    )
		  )
		),
	    // define instance for field Event time in the Event node
	    'field_event_time' => array(
	      'field_name' => 'field_event_time',
          'entity_type' => 'node',
          'bundle' => 'case_management_event',
	      'required' => 1,
          'description' => '',
          'label' => 'Event time',
          'deleted' =>0,
          'widget' => array (
            'weight' => '4',
            'type' => 'date_popup',
            'module' => 'date',
            'active' => 1,
            'settings' => array (
              'input_format' => 'j M Y - H:i:s',
              'input_format_custom' => '',
              'year_range' => '-3:+3',
              'increment' => '15',
              'label_position' => 'none',
              'text_parts' => array (
              ),
            ),
          ),
          'settings' => array (
            'tz_handling' => 'none',
            'default_value' => 'blank',
            'default_value_code' => '',
            'default_value2' => 'same',
            'default_value_code2' => '',
            'user_register_form' => false,
          ),
          'display' => array (
            'default' => array (
              'label' => 'hidden',
              'type' => 'date_default',
              'weight' => '4',
              'settings' => array (
                'format_type' => 'long',
                'multiple_number' => '',
                'multiple_from' => '',
                'multiple_to' => '',
                'fromto' => 'both',
              ),
              'module' => 'date',
            ),
            'teaser' => array (
              'label' => 'hidden',
              'type' => 'date_default',
              'weight' => '4',
              'settings' => array (
                'format_type' => 'long',
                'multiple_number' => '',
                'multiple_from' => '',
                'multiple_to' => '',
                'fromto' => 'both',
              ),
              'module' => 'date',
            ),
          ),
        ),
      );
	// build and return an array with the new fields required for the Meeting node field instances
    case 'case_management_meeting':
	  // set up variables with the tid values for default taxonomy items for meeting_type and meeting_duration 
	  $key_array = array_keys(taxonomy_get_term_by_name('Home visit'));
      $default_type_tid = $key_array[0];
      $key_array = array_keys(taxonomy_get_term_by_name('1 hour'));
      $default_duration_tid = $key_array[0];
	  return array(
	    // define instance for field Meeting date in the Meeting node
	    'field_meeting_date' => array(
	      'field_name' => 'field_meeting_date',
          'entity_type' => 'node',
          'bundle' => 'case_management_meeting',
          'required' => 1,
          'description' => '',
          'label' => 'Meeting date',
          'deleted' => '0',
	      'widget' => array (
            'weight' => '3',
            'type' => 'date_popup',
            'module' => 'date',
            'active' => 1,
            'settings' => array (
              'input_format' => 'j M Y - H:i:s',
              'input_format_custom' => '',
              'year_range' => '-3:+3',
              'increment' => '15',
              'label_position' => 'none',
              'text_parts' => array (
              ),
            ),
          ),
          'settings' => array (
            'tz_handling' => 'none',
            'default_value' => 'blank',
            'default_value_code' => '',
            'default_value2' => 'same',
            'default_value_code2' => '',
            'user_register_form' => false,
          ),
          'display' => array (
            'default' => array (
              'label' => 'above',
              'type' => 'date_default',
              'settings' =>  array (
                'format_type' => 'long',
                'multiple_number' => '',
                'multiple_from' => '',
                'multiple_to' => '',
                'fromto' => 'both',
              ),
              'module' => 'date',
              'weight' => '3',
           ),
            'teaser' => array (
              'type' => 'hidden',
              'label' => 'above',
              'settings' => array (
              ),
              'module' => 'date',
              'weight' => '3',
            ),
          ),
	    ),
	    // define instance for field Meeting type in the Meeting node
	    'field_meeting_type' => array(
	      'field_name' => 'field_meeting_type',
          'entity_type' => 'node',
          'bundle' => 'case_management_meeting',
          'required' => 1,
          'description' => '',
          'deleted' => '0',
	      'label' => 'Meeting type',
	      'default_value' => array (
            0 => array (
            'tid' => $default_type_tid,
            ),
          ),
          'widget' => array (
            'weight' => '4',
            'type' => 'options_select',
            'module' => 'options',
            'active' => 1,
            'settings' => 
            array (
            ),
          ),
          'settings' => 
          array (
            'user_register_form' => false,
          ),
          'display' => array (
            'default' => array (
              'label' => 'above',
              'type' => 'taxonomy_term_reference_link',
              'settings' => array (
              ),
              'module' => 'taxonomy',
              'weight' => 4,
            ),
            'teaser' => array (
              'type' => 'hidden',
              'label' => 'above',
              'settings' => array (
              ),
              'weight' => 4,
              'module' => 'taxonomy',
            ),
          ),
	    ),
	    // define instance for field Duration in the Meeting node
        'field_duration' => array(
	      'field_name' => 'field_duration',
          'entity_type' => 'node',
          'bundle' => 'case_management_meeting',
          'deleted' => '0',
	      'label' => 'Duration',
	      'required' => 1,
          'description' => '',
          'default_value' => array (
            0 => array (
              'tid' => $default_duration_tid,
            ),
          ),
          'widget' => array (
             'weight' => '5',
            'type' => 'options_select',
            'module' => 'options',
            'active' => 1,
            'settings' => array (
            ),
          ),
          'settings' => array (
            'user_register_form' => false,
          ),
          'display' => array (
            'default' => array (
              'label' => 'above',
              'type' => 'taxonomy_term_reference_link',
              'settings' => array (
              ),
              'module' => 'taxonomy',
              'weight' => 5,
            ),
            'teaser' => array (
              'type' => 'hidden',
              'label' => 'above',
              'settings' => array (
              ),
              'weight' => 5,
              'module' => 'taxonomy',
            ),
	      ),
	    ),
	  );
	// build and return an array with the new fields required for the Meeting node field instances
	case 'case_management_case':
	  // set up variables with the tid value for default taxonomy item for Case status 
	  $key_array = array_keys(taxonomy_get_term_by_name('Open'));
      $default_status_tid = $key_array[0];
	  return array(
	    // define instance for Opened date in the Case node
        'field_opened_date' => array(
          'field_name' => 'field_opened_date',
          'entity_type' => 'node',
          'bundle' => 'case_management_case',
          'deleted' => '0',
          'label' => 'Opened date',
          'required' => 1,
          'description' => 'The date the case file was opened',
          'widget' => array (
            'weight' => '2',
            'type' => 'date_popup',
            'module' => 'date',
            'active' => 1,
            'settings' => array (
              'input_format' => 'j M Y - H:i:s',
              'input_format_custom' => '',
              'year_range' => '-3:+3',
              'increment' => '15',
              'label_position' => 'none',
              'text_parts' => array (
              ),
            ),
          ),
          'settings' => array (
            'default_value' => 'now',
            'default_value_code' => '',
            'default_value2' => 'same',
            'default_value_code2' => '',
            'user_register_form' => false,
          ),
          'display' => array (
            'default' => array (
              'label' => 'above',
              'type' => 'date_default',
              'settings' => array (
                'format_type' => 'long',
                'multiple_number' => '',
                'multiple_from' => '',
                'multiple_to' => '',
                'fromto' => 'both',
             ),
              'module' => 'date',
              'weight' => 2,
            ),
           'teaser' => array (
              'type' => 'hidden',
              'label' => 'above',
              'settings' => array (
              ),
              'weight' => 2,
              'module' => 'date',
            ),
          ),
        ),
        // define instance for Reference in the Case node
        'field_reference' => array(
	      'field_name' => 'field_reference',
          'entity_type' => 'node',
          'bundle' => 'case_management_case',
          'deleted' => '0',
          'label' => 'Reference',
          'required' => 1,
          'description' => 'The Mediation Bucks case reference',
          'widget' => array (
            'weight' => '1',
            'type' => 'text_textfield',
            'module' => 'text',
            'active' => 1,
            'settings' => array (
              'size' => '15',
            ),
          ),
          'settings' => array (
            'text_processing' => '0',
            'user_register_form' => false,
          ),
          'display' => array (
            'default' => array (
              'label' => 'above',
              'type' => 'text_default',
              'settings' => array (
              ),
              'module' => 'text',
              'weight' => 1,
            ),
            'teaser' => array (
              'type' => 'hidden',
              'label' => 'above',
              'settings' => array (
              ),
              'module' => 'text',
              'weight' => 1,
            ),
          ),
	    ),
	    // define instance for Mediator in the Case node
	    'field_mediator' => array(
          'field_name' => 'field_mediator',
          'entity_type' => 'node',
          'bundle' => 'case_management_case',
          'deleted' => '0',
	      'label' => 'Mediator',
	      'required' => 0,
          'description' => '',
          'default_value' => NULL,
          'widget' => array (
            'weight' => '5',
            'type' => 'entityreference_autocomplete',
            'module' => 'entityreference',
            'active' => 1,
            'settings' => array (
              'match_operator' => 'STARTS_WITH',
              'size' => '30',
              'path' => '',
            ),
          ),
          'settings' => array (
            'user_register_form' => false,
          ),
          'display' => array (
            'default' => array (
              'label' => 'above',
              'type' => 'entityreference_label',
              'settings' =>  array (
                'link' => false,
              ),
              'module' => 'entityreference',
              'weight' => 5,
            ),
            'teaser' => array (
              'type' => 'hidden',
              'label' => 'above',
              'settings' => array (
              ),
              'weight' => 5,
              'module' => 'entityreference',
            ),
          ),
        ),
	    // define instance for Meeting in the Case node
	    'field_meeting' => array(
	      'field_name' => 'field_meeting',
          'entity_type' => 'node',
          'bundle' => 'case_management_case',
          'deleted' => '0',
	      'label' => 'Meeting',
	      'required' => 0,
          'description' => '',
	      'widget' => array (
            'weight' => '6',
            'type' => 'inline_entity_form',
            'module' => 'inline_entity_form',
            'active' => 1,
            'settings' => array (
              'fields' => array (
              ),
              'type_settings' => array (
                'allow_existing' => 1,
                'match_operator' => 'CONTAINS',
                'delete_references' => 1,
                'override_labels' => 1,
                'label_singular' => 'meeting',
                'label_plural' => 'meetings',
              ),
            ),
          ),
          'settings' => array (
            'user_register_form' => false,
          ),
          'display' => array (
            'default' => array (
              'label' => 'above',
              'type' => 'entityreference_label',
              'settings' => array (
               'link' => false,
              ),
              'module' => 'entityreference',
              'weight' => 6,
            ),
            'teaser' => array (
              'type' => 'hidden',
              'label' => 'above',
              'settings' => array (
              ),
              'module' => 'entityreference',
              'weight' => 6,
            ),
          ),
	    ),
	    // define instance for Case status in the Case node
          'field_case_status' => array(
	      'field_name' => 'field_case_status',
          'entity_type' => 'node',
          'bundle' => 'case_management_case',
          'deleted' => '0',
	      'label' => 'Case status',
	      'type' => 'options_select',
          'module' => 'options',
          'required' => 1,
          'description' => 'Status of the case',
          'active' => 1,
          'widget' => array (
            'weight' => '7',
            'settings' => array (
            ),
          ),
          'settings' => array (
            'user_register_form' => false,
          ),
          'display' => array (
            'default' => array (
              'label' => 'above',
              'type' => 'taxonomy_term_reference_link',
              'settings' => array (
              ),
              'module' => 'taxonomy',
              'weight' => 7,
            ),
            'teaser' => array (
              'type' => 'hidden',
              'label' => 'above',
              'settings' => array (
              ),
              'module' => 'taxonomy',
              'weight' => 7,
            ),
          ),
          'default_value' => array (
            0 => array (
              'tid' => $default_status_tid,
            ),
          ),
	    ),
	  );
  }
}
