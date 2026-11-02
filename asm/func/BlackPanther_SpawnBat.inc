	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	bl BlackPanther_FindFreeObj
	adds r5, r0, #0
	cmp r5, #0
	beq _08053C9A
	ldr r2, _08053CA4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08053CA8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08053CAC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r3, r0, #0
	ldr r2, _08053CB0 @ =0x00001E10
	adds r0, r6, r2
	ldr r2, [r0]
	movs r4, #1
	str r4, [sp]
	adds r0, r6, #0
	adds r1, r5, #0
	bl BlackPantherObj_Init
	adds r0, r5, #0
	adds r0, #0x1c
	ldr r1, _08053CB4 @ =0x00000269
	bl Video_SetAuxSpritePltt
	adds r0, r5, #0
	adds r0, #0x64
	movs r2, #0xbf
	lsls r2, r2, #5
	adds r1, r6, r2
	ldr r1, [r1]
	str r4, [sp]
	movs r2, #0
	movs r3, #1
	bl AuxAnim_SetAnim
	ldrb r0, [r5, #3]
	strb r0, [r5, #0x14]
	ldrb r0, [r5, #3]
	adds r0, #2
	movs r1, #3
	bl Mod
	strb r0, [r5, #0x15]
	ldr r1, _08053CB8 @ =BlackPantherObj_UpdateBat
	adds r0, r5, #0
	bl BlackPantherObj_SetUpdate
_08053C9A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053CA4: .4byte 0x030046B8
_08053CA8: .4byte 0x000003FF
_08053CAC: .4byte 0x0203B400
_08053CB0: .4byte 0x00001E10
_08053CB4: .4byte 0x00000269
_08053CB8: .4byte BlackPantherObj_UpdateBat
