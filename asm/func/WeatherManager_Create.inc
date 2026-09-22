	push {r4, lr}
	ldr r0, _08018918 @ =0x03000084
	ldr r0, [r0]
	cmp r0, #0
	bne _0801892A
	ldr r1, _0801891C @ =0x000008E8
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08018928
	ldr r1, _08018920 @ =WeatherManager_Update
	ldr r2, _08018924 @ =WeatherManager_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl WeatherManager_Init
	cmp r0, #0
	bge _08018928
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801892A
	.align 2, 0
_08018918: .4byte 0x03000084
_0801891C: .4byte 0x000008E8
_08018920: .4byte WeatherManager_Update
_08018924: .4byte WeatherManager_Destroy
_08018928:
	adds r0, r4, #0
_0801892A:
	pop {r4}
	pop {r1}
	bx r1
