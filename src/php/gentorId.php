<?php

/**
 * 生成17位长的id（因为signed int64 大约18位，最高位位9会有溢出风险）
 * 12位长md5 int + 5位定长crc32（截取后五位） unsigned int string（不足10位前导补0）
 */
public function genId($seed, $withValidator=true) {
    if (!$seed)
    {
        return 0;
    }

    //12 length oid str gentor
    //type should be signed int64,if highest number greater than 8 will cause overflow,make shorter, 18 length
    $coverted = base_convert(substr(md5(time() . $seed), 8, -8), 16, 10);
    $oidPart = substr($coverted, 0, 12);

    //replace first position is 0 to nnt zero val
    if (!substr($oidPart, -1))
    {
        $oidPart = mt_rand(1, 9) . substr($oidPart, -11);
    }

    //with validator
    if ($withValidator)
    {
        $validatePart = substr(sprintf("%010u", crc32(self::ORDER_ID_PREFIX . $oidPart)), -5);
        $oidPart = $oidPart . $validatePart;
    }
    return $oidPart;
}

