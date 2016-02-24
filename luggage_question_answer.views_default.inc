<?php
/**
 * @file
 * luggage_question_answer.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function luggage_question_answer_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'questions_and_answers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Questions and Answers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Questions and Answers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['style_options']['disableifone'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Have a question that needs answered? <a href="node/add/qa">Ask it</a>.';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Question */
  $handler->display->display_options['fields']['field_qa_question']['id'] = 'field_qa_question';
  $handler->display->display_options['fields']['field_qa_question']['table'] = 'field_data_field_qa_question';
  $handler->display->display_options['fields']['field_qa_question']['field'] = 'field_qa_question';
  $handler->display->display_options['fields']['field_qa_question']['alter']['nl2br'] = TRUE;
  /* Field: Content: Answer */
  $handler->display->display_options['fields']['field_qa_answer']['id'] = 'field_qa_answer';
  $handler->display->display_options['fields']['field_qa_answer']['table'] = 'field_data_field_qa_answer';
  $handler->display->display_options['fields']['field_qa_answer']['field'] = 'field_qa_answer';
  $handler->display->display_options['fields']['field_qa_answer']['alter']['max_length'] = '250';
  $handler->display->display_options['fields']['field_qa_answer']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['field_qa_answer']['alter']['more_link_text'] = 'Continue Reading Answer';
  $handler->display->display_options['fields']['field_qa_answer']['alter']['more_link_path'] = '[path]';
  $handler->display->display_options['fields']['field_qa_answer']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_qa_answer']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_qa_answer']['settings'] = array(
    'trim_length' => '250',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'qa' => 'qa',
  );
  /* Filter criterion: Content: Answer (field_qa_answer) */
  $handler->display->display_options['filters']['field_qa_answer_value']['id'] = 'field_qa_answer_value';
  $handler->display->display_options['filters']['field_qa_answer_value']['table'] = 'field_data_field_qa_answer';
  $handler->display->display_options['filters']['field_qa_answer_value']['field'] = 'field_qa_answer_value';
  $handler->display->display_options['filters']['field_qa_answer_value']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'qa';
  $export['questions_and_answers'] = $view;

  return $export;
}
