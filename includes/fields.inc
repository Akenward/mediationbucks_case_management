<?php

/** function to return definitions of new field types required by each of the three new nodes
 *  @node_type: is the node type requiring the field type.
 *  the returned data takes the form af an array of field definition arrays keyed on the field type name
 */

function _case_management_installed_fields($node_type) {
  switch ($node_type) {
  	case 'case_management_event':
	  // build and return an array with the new fields required for the Event node
      return array(
        // definition for the field "Event time" based on the date field type from the Date module
        'field_event_time' => array (
          'field_name' => 'field_event_time',
          'type' => 'date',
          'module' => 'date',
          'active' => '1',
          'locked' => '1',
          'cardinality' => '1',
          'deleted' => '0',
          'settings' => array (
            'granularity' => array (
              'month' => 'month',
              'day' => 'day',
              'year' => 'year',
              'hour' => 'hour',
              'minute' => 'minute',
              'second' => 0,
            ),
            'tz_handling' => 'none',
          ),
        ),
      );
  
	case 'case_management_meeting':
	// build and return an array with the new fields required for the Meeting node
    return array(
      // definition for the field "Meeting date" based on the date field type from the Date module
	  'field_meeting_date' => array(
	    'field_name' => 'field_meeting_date',
        'type' => 'date',
        'module' => 'date',
        'active' => '1',
        'locked' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'settings' => array (
          'granularity' => array (
            'month' => 'month',
            'day' => 'day',
            'year' => 'year',
            'hour' => 'hour',
            'minute' => 'minute',
            'second' => 0,
          ),
          'tz_handling' => 'none',
        ),
      ),
      // definition for the field "Meeting type" based on the "Meeting types" vocabulary supported by the taxonomy module
	  'field_meeting_type' => array(
	    'field_name' => 'field_meeting_type',
        'type' => 'taxonomy_term_reference',
        'module' => 'taxonomy',
        'active' => '1',
        'locked' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'settings' => array (
          'allowed_values' =>  array (
            0 => array (
             'vocabulary' => 'meeting_types',
             'parent' => '0',
            ),
          ),
        ),
	  ),
	  // definition for the field "Meeting duration" based on the "Meeting duration" vocabulary supported by the taxonomy module
	  'field_duration' => array(
	    'field_name' => 'field_duration',
        'type' => 'taxonomy_term_reference',
        'module' => 'taxonomy',
        'active' => '1',
        'locked' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'settings' => array (
          'allowed_values' => array (
            0 => array (
              'vocabulary' => 'meeting_duration',
              'parent' => '0',
            ),
          ),
        ),
	  ),
	);
	case 'case_management_case':
	// build and return an array with the new fields required for the Case node
    return array(
      // definition for the field "Opened date" based on the date field type from the Date module
      'field_opened_date' => array(
        'field_name' => 'field_opened_date',
        'type' => 'date',
        'module' => 'date',
        'active' => '1',
        'locked' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'settings' => array (
          'granularity' => array (
            'month' => 'month',
            'day' => 'day',
            'year' => 'year',
            'hour' => 0,
            'minute' => 0,
            'second' => 0,
          ),
          'tz_handling' => 'none',
          'timezone_db' => '',
        ),
      ),
      // definition for the field "Reference" based on the text field type from the Text module
      'field_reference' => array(
        'field_name' => 'field_reference',
        'type' => 'text',
        'module' => 'text',
        'active' => '1',
        'locked' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'settings' => array (
          'max_length' => '15',
        ),
        'columns' => array (
          'value' => array (
            'type' => 'varchar',
            'length' => '15',
            'not null' => false,
          ),
          'format' => array (
            'type' => 'varchar',
            'length' => 255,
            'not null' => false,
          ),
        ),
      ),
      // definition for the field "Mediator" based on the entity reference field type from the Entity reference module
      // referencing the User entity type
	  'field_mediator' => array(
	    'field_name' => 'field_mediator',
	    'type' => 'entityreference',
        'module' => 'entityreference',
        'active' => '1',
        'locked' => '1',
        'cardinality' => '-1',
        'deleted' => '0',
	    'settings' => array (
          'target_type' => 'user',
          'handler' => 'base',
          'handler_settings' => array (
            'target_bundles' => array (
            ),
            'sort' => array (
              'type' => 'none',
            ),
            'behaviors' => array (
              'views-select-list' => array (
                'status' => 0,
              ),
            ),
          ),
        ),
        'columns' => array (
          'target_id' => array (
            'description' => 'The id of the target entity.',
            'type' => 'int',
            'unsigned' => true,
            'not null' => true,
          ),
        ),
	  ),
	  // definition for the field "Meeting" based on the entity reference field type from the Entity reference module
      // referencing the node entity type which in turn includes the Meeting node type
	  'field_meeting' => array(
	    'field_name' => 'field_meeting',
        'type' => 'entityreference',
        'module' => 'entityreference',
        'active' => '1',
        'locked' => '1',
        'cardinality' => '-1',
        'deleted' => '0',
	    'settings' => array (
          'target_type' => 'node',
          'handler' => 'base',
          'handler_settings' => array (
            'target_bundles' => array (
              'meeting' => 'case_management_meeting',
            ),
            'sort' => array (
              'type' => 'none',
            ),
            'behaviors' => array (
              'views-select-list' => array (
                'status' => 0,
              ),
            ),
          ),
        ),
        'columns' => array (
          'target_id' => array (
            'description' => 'The id of the target entity.',
            'type' => 'int',
            'unsigned' => true,
            'not null' => true,
          ),
        ),
	  ),
	  // definition for the field "Case status" based on the "Case status" vocabulary supported by the taxonomy module
	  'field_case_status' => array(
	    'field_name' => 'field_case_status',
        'type' => 'taxonomy_term_reference',
        'module' => 'taxonomy',
        'active' => '1',
        'locked' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'settings' => array (
          'allowed_values' => array (
            0 => array (
              'vocabulary' => 'case_status',
              'parent' => '0',
            ),
          ),
        ),
	  )
    );
  }
}