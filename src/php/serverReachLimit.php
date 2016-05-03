<?php
/**
 * frequence check certain $id used $chance in $duration(s) peroid
 *
 * @return bool
 */
private function _reachRateLimit($id, $duration, $chance)
{
    $timestamp = time();
    $limitKey = 'RATE_LIMIT_ALANYUAN_' . $id;

    //step1:check if reach limit
    $limitVal = \Yii::app()->redis->get($limitKey);
    if (empty($limitVal))
    {
        $limitVal = $timestamp . '||' . 1;
        \Yii::app()->redis->set($limitKey, $limitVal);
    }

    list($firstTs, $totalNum) = explode('||', $limitVal);

    //step2:if time window not reached,check the total request number
    if (($timestamp-intval($firstTs)) <= $duration)
    {
        if (intval($totalNum) > $chance)
        {
            return true;
        }
        else
        {
            $totalNum += 1;
            \Yii::app()->redis->set($limitKey, $firstTs . '||' . $totalNum);
            return false;
        }
    }
    //step2:if time window reached,initial the key
    else
    {
        \Yii::app()->redis->set($limitKey, $timestamp . '||' . 1);
        return false;
    }
}
