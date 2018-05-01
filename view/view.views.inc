<?php
/**
* Implements hook_views_data(  )
* for implementation copy/paste node_views_data() method to see the structure
* from node.views.inc
*/
view_views_data(){
  $data = array();
  $data['product']['table']['group'] = t('Product group');
  $data['product']['table']['base'] = array(
    'title' => t('Product info'),
    'help' => t('Store info for products'),
  );
//relationship definition between corresponding tables
// table product will koin to table 'node' and 'users'
  $data['product']['table']['join'] = array(
      'node' => array(
        'left_field' => 'nid',
        'field' => 'nid',
      ),
      'users' => array(
        'left_field' => 'uid',
        'field' => 'uid',
      ),
  );

  $data['product']['nid'] = array(
    'title' => t('Product nid'),
    'help' => t('Store info for product NId'),
    'field' => array(
      'handler'=> 'views_handler_field_node',
      'click sortable' => true,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',//from modules/views/handlers
    ),
    'sort'=> array(
      'handler'=> 'views_handler_sort',
    ),
    //this field could be passed as argument
    'arguments' => array(
      'handler' => 'views_handler_argument_node_nid',
      'name field' => 'NId',
      'numeric' => true,
      'validate type' => 'nid'
    ),

    //foreign keys definition
    'relationship' => array(
      'base' => 'node',// the table to which this field refers
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node')
    )
  );
//user Id definition
  $data['product']['uid'] = array(
    'title' => t('Product Uid'),
    'help' => t('Store info for the user published this product'),
    'field' => array(
      'handler'=> 'views_handler_field_numeric',
    ),
    //this field could be handled as argument by views_handler_argument_user_uid
    'arguments' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'uid',
      'numeric' => true,
      'validate type' => 'uid'
    ),
    'sort'=> array(
      'handler'=> 'view_handler_sort_custom',
      // 'handler'=> 'views_handler_sort',

    ),
    //foreign keys definition
    'relationship' => array(
      'base' => 'users',// the table to which this field refers
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User')
    )
  );
  $data['product']['id'] = array(
    'title' => t('Product id'),
    'help' => t('Store info for product Id'),
    'field' => array(
      'handler'=> 'views_handler_numeric',
      'click sortable' => true,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort'=> array(
      'handler'=> 'views_handler_sort',
    ),
    //this field could be passed as argument
    'arguments' => array(
      'handler' => 'views_handler_argument_node',
      'name field' => 'Id',
      'numeric' => true,
      'validate type' => 'id'
    ),
  );
  $data['product']['title'] = array(
    'title' => t('Product title'),
    'help' => t('Store info for product title'),
    'field' => array(
      'handler'=> 'views_handler_string',
      'click sortable' => true,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort'=> array(
      'handler'=> 'views_handler_sort',
    )
  );
  $data['product']['last_viewed'] = array(
    'title' => t('Product last viewed'),
    'help' => t('Store info forlast viewed product as timestamp'),
    'field' => array(
      'handler'=> 'views_handler_field_date',//standart function from a class views_handler_field_date.inc
      'click sortable' => true,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort'=> array(
      'handler'=> 'views_handler_sort_date',// core function from views_handler_sort_date.inc
      'click sortable' => true,
    )
  );
  $data['product']['view_count'] = array(
    'title' => t('Product count of views'),
    'help' => t('Store info for count of  product been viewed'),
    'field' => array(
    'handler' => 'view_handler_field_percent'// custom handler class extending views handler_field_numeric
      // 'handler'=> 'views_handler_field_numeric',//standart function from a class views_handler_field_numeric.inc
      'click sortable' => true,
    ),
    'filter' => array(
      'handler' => 'view_handler_filter_numeric', // custom handler
      // 'handler' => 'views_handler_filter_numeric',
    ),
    'sort'=> array(
      'handler'=> 'views_handler_sort',// core function from views_handler_sort_date.inc
      'click sortable' => true,
    )
  );

  //definition of area
  $data['product']['product_area'] = array(
    'title' => t('Product area'),
    'help' => t('Display product area'),
    'area' => array(
      'handler' => 'view_handler_area_product'
    )
  );
  return $data;
}
