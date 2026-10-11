	push {lr}
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _0809F900 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0809F904 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809F908
	movs r0, #1
	b _0809F90A
	.align 2, 0
_0809F900: .4byte 0x030046A0
_0809F904: .4byte 0x00000934
_0809F908:
	movs r0, #0
_0809F90A:
	cmp r0, #0
	beq _0809F92A
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _0809F930 @ =0x012B0000
	cmp r1, r0
	ble _0809F92A
	ldr r2, _0809F934 @ =FUN_0809fa80
	adds r0, r3, #0
	movs r1, #0
	bl Entity1DBEElem_SetState
_0809F92A:
	pop {r0}
	bx r0
	.align 2, 0
_0809F930: .4byte 0x012B0000
_0809F934: .4byte FUN_0809fa80
