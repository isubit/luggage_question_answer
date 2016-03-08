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
  $items['rules_q_a_new_question_asker'] = entity_import('rules_config', '{ "rules_q_a_new_question_asker" : {
      "LABEL" : "Q\\u0026A New Question Mail Asker",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--qa" : { "bundle" : "qa" } },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "node:field-qa-email" ] } } ],
      "DO" : [
        { "mail" : {
            "to" : "[node:field-qa-email]",
            "subject" : "Your question at [site:name]",
            "message" : "Thank you for asking a question. We\\u2019ll attempt to make our best effort to answer reasonable questions that could be interesting and informative to a wide range of people. Questions and answers will be posted on our website. Questions can be edited or adapted from their original form, and not all are guaranteed to be answered. (Note: We do not do homework, give financial advice, or provide research support.)\\r\\n\\r\\nYour Question:\\r\\n[node:field-qa-question-short]\\r\\n\\r\\n[node:field-qa-question]\\r\\n\\r\\n",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_q_a_new_question_mail_moderators'] = entity_import('rules_config', '{ "rules_q_a_new_question_mail_moderators" : {
      "LABEL" : "Q\\u0026A New Question Mail Moderators",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--qa" : { "bundle" : "qa" } },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "10" : "10" } },
            "subject" : "New question for [site:name]",
            "message" : "A new question has been submitted to [site:name]. A Q\\u0026A moderator can log into the site and answer the question on the site at [node:url]\\r\\n\\r\\nFrom: [node:field-qa-name] [node:field-qa-email]\\r\\n\\r\\n[node:field-qa-question-short]\\r\\n\\r\\n[node:field-qa-question]\\r\\n",
            "from" : "[site:mail]"
          }
        }
      ]
    }
  }');
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
