<?php
/**
 * @file
 * luggage_question_answer.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function luggage_question_answer_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create qa content'.
  $permissions['create qa content'] = array(
    'name' => 'create qa content',
    'roles' => array(
      'Q&A Moderator' => 'Q&A Moderator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any qa content'.
  $permissions['delete any qa content'] = array(
    'name' => 'delete any qa content',
    'roles' => array(
      'Q&A Moderator' => 'Q&A Moderator',
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own qa content'.
  $permissions['delete own qa content'] = array(
    'name' => 'delete own qa content',
    'roles' => array(
      'Q&A Moderator' => 'Q&A Moderator',
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any qa content'.
  $permissions['edit any qa content'] = array(
    'name' => 'edit any qa content',
    'roles' => array(
      'Q&A Moderator' => 'Q&A Moderator',
      'content editor' => 'content editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own qa content'.
  $permissions['edit own qa content'] = array(
    'name' => 'edit own qa content',
    'roles' => array(
      'Q&A Moderator' => 'Q&A Moderator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'moderate questions and answers'.
  $permissions['moderate questions and answers'] = array(
    'name' => 'moderate questions and answers',
    'roles' => array(
      'Q&A Moderator' => 'Q&A Moderator',
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'luggage_question_answer',
  );

  // Exported permission: 'view any unpublished qa content'.
  $permissions['view any unpublished qa content'] = array(
    'name' => 'view any unpublished qa content',
    'roles' => array(
      'Q&A Moderator' => 'Q&A Moderator',
      'content editor' => 'content editor',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
