<?php
/**
 * @author neeke@php.net
 * Date: 2020-11-16 下午6:16
 */

class SeasValid
{
    public function __construct()
    {
        #SeasValid init
    }
    /**
     * 获取本次请求标识
     * @return string
     */
    static public function getRequestID()
    {
        return uniqid();
    }

    /**
     * 获得当前日志buffer中的内容
     *
     * @return array
     */
    static public function getBuffer()
    {
        return array();
    }

    static public function log($level, $message, array $context = array(), $module = '')
    {
        return true;
    }

}

