	.include "asm/macros.inc"
	.syntax unified
	.text

	thumb_func_start Sensor_DoDisableIO
Sensor_DoDisableIO: @ 0x08247604
  .include "asm/func/Sensor_DoDisableIO.inc"

	thumb_func_start Sensor_Tick
Sensor_Tick: @ 0x08247650
  .include "asm/func/Sensor_Tick.inc"

	thumb_func_start Sensor_EnableIO
Sensor_EnableIO: @ 0x08247738
  .include "asm/func/Sensor_EnableIO.inc"

	thumb_func_start Sensor_DisableIO
Sensor_DisableIO: @ 0x08247758
  .include "asm/func/Sensor_DisableIO.inc"

	thumb_func_start Sensor_Enable
Sensor_Enable: @ 0x08247774
  .include "asm/func/Sensor_Enable.inc"

	thumb_func_start Sensor_Disable
Sensor_Disable: @ 0x082477B4
  .include "asm/func/Sensor_Disable.inc"

	thumb_func_start Sensor_GetRawLevel
Sensor_GetRawLevel: @ 0x082477E0
  .include "asm/func/Sensor_GetRawLevel.inc"

	thumb_func_start FUN_08247800
FUN_08247800: @ 0x08247800
  .include "asm/func/FUN_08247800.inc"

	thumb_func_start FUN_0824780c
FUN_0824780c: @ 0x0824780C
  .include "asm/func/FUN_0824780c.inc"

