<?php
/**
 * @file
 * luggage_question_answer.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function luggage_question_answer_user_default_roles() {
  $roles = array();

  // Exported role: Q&A Moderator.
  $roles['Q&A Moderator'] = array(
    'name' => 'Q&A Moderator',
    'weight' => 10,
  );

  return $roles;
}
