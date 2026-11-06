	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	movs r6, #0
	mov r8, r6
	ldr r7, _080ACAD4 @ =0x030046B8
_080ACA70:
	movs r0, #0x5c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #0x40
	add r4, sb
	adds r5, r4, #0
	adds r5, #0x2c
	adds r0, r5, #0
	ldr r1, _080ACAD8 @ =0x0000CC88
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r0, r8
	strh r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080ACADC @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080ACAE0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r0, #5
	adds r1, r4, #0
	adds r1, #0x5a
	strh r0, [r1]
	adds r4, #0x50
	mov r0, r8
	strb r0, [r4]
	adds r6, #1
	cmp r6, #0x17
	ble _080ACA70
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ACAD4: .4byte 0x030046B8
_080ACAD8: .4byte 0x0000CC88
_080ACADC: .4byte 0x000003FF
_080ACAE0: .4byte 0x0203B400
