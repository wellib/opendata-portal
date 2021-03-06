<?php

/**
 * @file
 * Contains the OdApiData class.
 */

abstract class OdApiDataDefault extends OdApiObject {
  public static $title = 'Набор открытых данных';
  public static $type = self::OBJECT_TYPE_IS_DATA;
  public static $typeCardinality = self::OBJECT_CARDINALITY_IS_MULTIPLE;
  public static $parentType = self::OBJECT_TYPE_IS_DATA_LIST;
  public static $childrenTypes = array(self::OBJECT_TYPE_IS_STRUCTURE);

  // Errors.
  const SITE_OPENDATA_DATA_EXISTS = 51;

  const REGEXP_CSV_DATA = '/^data-(.*)-structure-(.*)$/u';

  protected static $validatorsInfo = array(
    self::SITE_OPENDATA_DATA_EXISTS => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'data exists',
        FALSE => 'data does not exist',
      ),
    ),
  );

  protected function _getAvailableFormats() {
    return array($this->parent->format);
  }
}
