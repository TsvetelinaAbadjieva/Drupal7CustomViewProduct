<?php

class view_handler_sort_custom extends views_handler_sort{
  function query(){
    global $user;
    $this->query->add_orderby(null, 'FIELD('.$this->table.'.'.$this->field.','.$user->uid.')', DESC);
    $this->query->add_orderby(Null, $this->table.'.'.$this->field, $this->options['order']);
  }
}
