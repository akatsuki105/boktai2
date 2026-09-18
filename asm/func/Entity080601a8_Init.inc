	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r0, #0
	str r0, [r6, #0x1c]
	adds r4, r6, #0
	adds r4, #0x28
	ldr r1, _080601A0 @ =0x000061F9
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r1, _080601A4 @ =0x000002F6
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	cmp r5, #0
	beq _08060180
	strh r7, [r6, #0x2e]
	str r5, [r6, #0x34]
_08060180:
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_08060186:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805ff04
	adds r4, #1
	adds r5, #0x3c
	cmp r4, #0x1f
	ble _08060186
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080601A0: .4byte 0x000061F9
_080601A4: .4byte 0x000002F6
