<?php

interface MediationTaxonomyInterface {
	
  public function deleteVocab();
	
  public function setTerm($name, $description = NULL, $weight = NULL);
  
  public function getTerm($name);
  
  public function setDescription($vocab_description);
  
}

/**
 * A class implementing MediationTaxonomyInterface to provide a wrapper for a taxonomy vocabulary.
 * @constructor: finds the vocabulary referenced by $vocab_name.  This is the visible name.
 * The constructor looks first to see if there is a variable for the vid, set by a previous
 * instance of the class and referenced by the name converted to lower case and with spaces replaced
 * by underscores.  If not, it looks for a vocabulary with the right machine name and,
 * as a last resort, creates a new vocabulary.
 */
class MediationTaxonomyHandler implements MediationTaxonomyInterface {
  // protected variable for the vocabulary object
  protected $vocab;
  // protected variable for the vocabulary vid
  protected $vid;
  // constructor function.
  function __construct($vocab_name) {
  	// constructor function
  	if (variable_get('taxonomy_vocab_' . strtolower(str_replace(' ', '_', $vocab_name)))) {
      $this->vid = variable_get('taxonomy_vocab_' . strtolower(str_replace(' ', '_', $vocab_name)));
	  $this->vocab = taxonomy_vocabulary_load($this->vid);
	}
	else if ((taxonomy_vocabulary_machine_name_load(strtolower(str_replace(' ', '_', $vocab_name))))) {
	  $this->vocab = taxonomy_vocabulary_machine_name_load(strtolower(str_replace(' ', '_', $vocab_name)));
	  $this->vid = $this->vocab->vid;
	  variable_set('taxonomy_vocab_' . strtolower(str_replace(' ', '_', $vocab_name)), $this->vid);
	}
	else {
	  $new_vocab = (object) array(
        'name' => $vocab_name,
        'description' => '',
        'machine_name' => strtolower(str_replace(' ', '_' , $vocab_name)),
      );
	  $result = taxonomy_vocabulary_save($new_vocab);
	  $this->vocab = taxonomy_vocabulary_machine_name_load(strtolower(str_replace(' ', '_' , $vocab_name)));
	  $this->vid = $this->vocab->vid;
	  variable_set('taxonomy_vocab_' . strtolower(str_replace(' ', '_', $vocab_name)), $this->vid);
	}
  }
  
  public function deleteVocab() {
  	variable_del('taxonomy_vocab_' . $this->vocab->machine_name);
  	taxonomy_vocabulary_delete($this->vid);
  }
  
  public function setTerm($name, $description = NULL, $weight = NULL) {
  	$term = taxonomy_get_term_by_name($name);
  	if (empty(array_filter($term, function($a) { return $a->vid == $this->vid; }))) {
  	  $term = (object) array(
	    'name' => $name,
	    'vid' => $this->vid,
	  );
	}
	else {
	  $term = current($term);
	}
	if ($description) {
	  $term->description = $description;
	}
	if ($weight) {
	  $term->weight = $weight;
	}
	taxonomy_term_save($term);
    return $term;
  }
  
  public function getTerm($name) {
  	$terms = taxonomy_get_term_by_name($name);
	$our_terms = array();
	foreach ($terms as $term) {
	  if ($term->vid == $this->vid) {
	    $our_terms[] = $term;
	  }
    } 
    return (empty($our_terms)) ? FALSE : current($our_terms);
  }
  
   public function setDescription($vocab_description) {
  	 $this->vocab->description = $vocab_description;
	 $result = taxonomy_vocabulary_save($this->vocab);
	 return $this->vocab;
   }
  
}


