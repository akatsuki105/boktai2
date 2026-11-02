	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	bl BlackPanther_FindFreeObj
	adds r4, r0, #0
	cmp r4, #0
	beq _08053D22
	ldr r2, _08053D2C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08053D30 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08053D34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r3, r0, #0
	ldr r2, _08053D38 @ =0x00001E14
	adds r0, r5, r2
	ldr r2, [r0]
	movs r0, #2
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl BlackPantherObj_Init
	adds r1, r4, #0
	adds r1, #0x56
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x64
	ldr r2, _08053D3C @ =0x000017E4
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #1
	str r2, [sp]
	movs r2, #0
	movs r3, #3
	bl AuxAnim_SetAnim
	ldr r1, _08053D40 @ =BlackPantherObj_UpdateBee
	adds r0, r4, #0
	bl BlackPantherObj_SetUpdate
_08053D22:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08053D2C: .4byte 0x030046B8
_08053D30: .4byte 0x000003FF
_08053D34: .4byte 0x0203B400
_08053D38: .4byte 0x00001E14
_08053D3C: .4byte 0x000017E4
_08053D40: .4byte BlackPantherObj_UpdateBee
