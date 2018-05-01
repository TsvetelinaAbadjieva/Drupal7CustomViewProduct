<?php

class view_handler_filter_numeric extends views_handler_filter_numeric{
//will create new operation 'even'
  function operators(){
    parent::operators();
    $operators['even'] = array(
        'title' => t('Even operation'),
        'method' => 'op_even',// existing method from parent class
        'short' => t('even'),
        'values' => 0,
    );
    return $operators;
  }
  //define op_even function for the current field which this class is called for
  function op_even($field){
    $this->query->add_where_expression($this->options['group'],'MOD('.$field.', 2)=0');
  }
}
