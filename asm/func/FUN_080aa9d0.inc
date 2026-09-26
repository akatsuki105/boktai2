	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, _080AAA24 @ =0x000024BA
	bl Video_GetAuxSprite
	movs r6, #0
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r7, r5, r0
_080AA9E8:
	movs r0, #0x2c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0xe4
	adds r0, r5, r0
	adds r1, r7, #0
	movs r2, #1
	bl AuxSprite_Add
	adds r0, r7, #0
	ldr r1, _080AAA28 @ =0x0000027D
	bl Video_SetAuxSpritePltt
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	adds r2, r2, r4
	ldr r0, [r5, #0x18]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, #1
	cmp r6, #1
	ble _080AA9E8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAA24: .4byte 0x000024BA
_080AAA28: .4byte 0x0000027D
