	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	bl BlackPanther_FindFreeObj
	adds r6, r0, #0
	cmp r6, #0
	beq _08053C02
	ldr r2, _08053C0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08053C10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08053C14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r3, r0, #0
	ldr r2, _08053C18 @ =0x00001E0C
	adds r0, r5, r2
	ldr r2, [r0]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl BlackPantherObj_Init
	adds r0, r6, #0
	adds r0, #0x64
	ldr r2, _08053C1C @ =0x000017DC
	adds r1, r5, r2
	ldr r1, [r1]
	str r4, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r1, _08053C20 @ =BlackPantherObj_UpdateBomb
	adds r0, r6, #0
	bl BlackPantherObj_SetUpdate
_08053C02:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053C0C: .4byte 0x030046B8
_08053C10: .4byte 0x000003FF
_08053C14: .4byte 0x0203B400
_08053C18: .4byte 0x00001E0C
_08053C1C: .4byte 0x000017DC
_08053C20: .4byte BlackPantherObj_UpdateBomb
