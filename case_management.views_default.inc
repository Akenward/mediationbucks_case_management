<?php
  
/**
 *  Implements hook_views_default_views to load views code held as .inc files in views sub-folder
 */
function case_management_views_default_views() {
  // Check for all view files in views directory
  $files = file_scan_directory(drupal_get_path('module', 'case_management') . '/views', '/.*\.inc$/');
  $views = array();
  // Add each view to list of views
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }

  // Return array of default views.
  return $views;
}




