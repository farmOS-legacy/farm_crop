<?php
/**
 * @file
 * farm_crop.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function farm_crop_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function farm_crop_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_farm_asset_type().
 */
function farm_crop_default_farm_asset_type() {
  $items = array();
  $items['planting'] = entity_import('farm_asset_type', '{
    "type" : "planting",
    "label" : "Planting",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_log_type().
 */
function farm_crop_default_log_type() {
  $items = array();
  $items['farm_planting_location'] = entity_import('log_type', '{
    "type" : "farm_planting_location",
    "label" : "Planting Location",
    "weight" : 0,
    "name_pattern" : "[log:field-farm-planting] [log:field-farm-quantity] [log:field-farm-area]",
    "name_edit" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
