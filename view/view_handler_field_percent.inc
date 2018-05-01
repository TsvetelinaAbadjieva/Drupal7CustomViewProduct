<?php

class view_handler_field_percent extends view_handler_field_numeric{

  function construct(){
    parent::construct;
    $this->additional_fields['nid'] = 'nid';
    $this->definition['float'] = TRUE;
  }

  function query(){
    parent::query();
    if($this->options['percent']){
      $this->add_additional_fields();
    }
  }
  //we want to add % symbol to the end of the form field on display
  public function options_form(&$form, &$form_state){
    parent::options_form($form, $form_state);
    $form['percent'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display as percent'),
      '#description' => t('Display value as percent'),
      '#default_value' => $this->options['percent'],
    );
  }

  public function option_definition(){
    $options = parent::option_definition();
    $options['percent'] = array('default' => FALSE);

    return $options;
  }
  public function pre_render(&$values){
    parent::pre_render($values);
    dsm($values);
    if($this->options['percent']){
      foreach($values as $key =>$row){
        $nid = $row->{$this->aliases['nid']};
        //to be accessible this $nid we need to add it tricky in the constructor and in the add_field method
        $total = db_query("SELECT SUM(view_count) FROM {product} WHERE nid = :nid", array(':nid'=> $nid))
        ->fetchField();
        $count = $row->get_value($row);// get the valued of the field this handler is created for - view_count
        $percent = ($count/$total)*100;
        $values[$key]->{$this->field_alias} = $percent;
      }

    }
  }
}
