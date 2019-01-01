const spriteMap PROGMEM spriteMap3[228] =
{
    0,     0,     0, &s_B6,     0,     0,     0, &s_BV, &s_BA,     0, &s_BB, &s_BU,     0,     0,     0, &s_B6,     0,     0,     0,
    0, &s_B1,     0,     0,     0, &s_B1,     0, &s_B6,     0,     0,     0, &s_B6,     0, &s_B1,     0,     0,     0, &s_B1,     0,
    0,     0,     0, &s_BI,     0,     0,     0,     0,     0, &s_B1,     0,     0,     0,     0,     0, &s_BI,     0,     0,     0,
&s_B2, &s_B2, &s_B2, &s_BS,     0, &s_B3, &s_B2, &s_BP,     0,     0,     0, &s_BO, &s_B2, &s_B4,     0, &s_BR, &s_B2, &s_B2, &s_B2,
    0,     0,     0, &s_B6,     0,     0,     0, &s_B5,     0, &s_BM,     0, &s_B5,     0,     0,     0, &s_B6,     0,     0,     0,
    0, &s_B1,     0,     0,     0, &s_B1,     0, &s_B6,     0,     0,     0, &s_B6,     0, &s_B1,     0,     0,     0, &s_B1,     0,
    0,     0,     0, &s_BI,     0,     0,     0,     0,     0, &s_B1,     0,     0,     0,     0,     0, &s_BI,     0,     0,     0,
&s_B2, &s_B2, &s_B2, &s_BS,     0, &s_B3, &s_B2, &s_BP,     0,     0,     0, &s_BO, &s_B2, &s_B4,     0, &s_BR, &s_B2, &s_B2, &s_B2,
    0,     0,     0, &s_B6,     0,     0,     0, &s_B6,     0, &s_B1,     0, &s_B6,     0,     0,     0, &s_B6,     0,     0,     0,
    0, &s_B1,     0,     0,     0, &s_BI,     0,     0,     0,     0,     0,     0,     0, &s_BI,     0,     0,     0, &s_B1,     0,
    0,     0,     0, &s_BI,     0, &s_B6,     0, &s_B7, &s_B8,     0, &s_B7, &s_B8,     0, &s_B6,     0, &s_BI,     0,     0,     0,
&s_B9, &s_B9, &s_B9, &s_BT,     0,     0,     0, &s_BF, &s_BE,     0, &s_BF, &s_BE,     0,     0,     0, &s_BQ, &s_B9, &s_B9, &s_B9
};

const bool PROGMEM dots3[228] = {
false, false, false,  true, false, false, false,  true,  true,  true,  true,  true, false, false, false,  true, false, false, false,
 true,  true, false, false, false,  true, false,  true, false, false, false,  true, false,  true, false, false, false,  true,  true,
false, false, false,  true, false, false, false, false, false,  true, false, false, false, false, false,  true, false, false, false,
 true,  true,  true,  true, false,  true,  true,  true, false, false, false,  true,  true,  true, false,  true,  true,  true,  true,
false, false, false,  true, false, false, false,  true, false,  true, false,  true, false, false, false,  true, false, false, false,
false,  true, false, false, false,  true, false,  true, false, false, false,  true, false,  true, false, false, false,  true, false,
false, false, false,  true, false, false, false, false, false,  true, false, false, false, false, false,  true, false, false, false,
 true,  true,  true,  true, false,  true,  true,  true, false,  true, false,  true,  true,  true, false,  true,  true,  true,  true,
false, false, false,  true, false, false, false,  true, false,  true, false,  true, false, false, false,  true, false, false, false,
 true,  true, false, false, false,  true, false, false, false, false, false, false, false,  true, false, false, false,  true,  true,
false, false, false,  true, false,  true, false,  true,  true,  true,  true,  true, false,  true, false,  true, false, false, false,
 true,  true,  true,  true, false, false, false,  true,  true,  true,  true,  true, false, false, false,  true,  true,  true,  true
};
const LevelMap PROGMEM map3 = { {{45, -4, 45, 59}, {0, 0, 0, 0}}, 9*5, 7*5, 9*5, 4*5, spriteMap3, dots3, { {0, 1, VIOBYTESTATE_PHASING}, {18, 1, VIOBYTESTATE_PHASING}, {0, 9, VIOBYTESTATE_PHASING}, {18, 9, VIOBYTESTATE_PHASING}} };
