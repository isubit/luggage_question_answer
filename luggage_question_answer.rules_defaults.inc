<?php
/**
 * @file
 * luggage_question_answer.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function luggage_question_answer_default_rules_configuration() {
  $items = array();
  $items['rules_q_a_question_answered'] = entity_import('rules_config', '{ "rules_q_a_question_answered" : {
      "LABEL" : "Q\\u0026A Question Answered",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--qa" : { "bundle" : "qa" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "node:field-qa-email" ] } },
        { "data_is" : { "data" : [ "node:status" ], "value" : "1" } },
        { "data_is" : { "data" : [ "node-unchanged:status" ], "value" : "0" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:field-qa-email]",
            "subject" : "Your question has been answered on [site:name]",
            "message" : "[node:field-qa-name],\\r\\n\\r\\nYour question has been answered and has been published. See it at [node:url]",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
