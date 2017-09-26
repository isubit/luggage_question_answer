<?php
/**
 * @file
 * luggage_question_answer.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function luggage_question_answer_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:announcement.
  $config['node:qa'] = array(
    'instance' => 'node:qa',
    'config' => array(
      'description' => array(
        'value' => '[node:field-qa-answer:value]',
      ),
    ),
  );

  return $config;
}
