	push {r4, r5, lr}
	sub sp, #0x24
	adds r5, r0, #0
	ldr r1, _080B69E0 @ =0x00001429
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080B69E8
	ldr r2, _080B69E4 @ =0x0000142B
	adds r0, r5, r2
	adds r2, #0x2d
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl GetWeaponData
	b _080B69EE
	.align 2, 0
_080B69E0: .4byte 0x00001429
_080B69E4: .4byte 0x0000142B
_080B69E8:
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
_080B69EE:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B6A0E
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl MessageWindow_Close
	bl Marquee_Clear
	b _080B6A60
_080B6A0E:
	mov r0, sp
	bl GetWeaponWearPose
	adds r2, r0, #0
	movs r0, #0xf2
	lsls r0, r0, #4
	adds r3, r5, r0
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	ldr r1, _080B6A68 @ =0x00000F18
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x38
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
	ldr r2, _080B6A6C @ =0x000013F8
	adds r4, r5, r2
	ldr r0, [r4]
	bl MessageWindow_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl MessageWindow_SetRect
	ldr r0, _080B6A70 @ =0x00001404
	adds r1, r5, r0
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r4]
	mov r0, sp
	bl FUN_08094d48
_080B6A60:
	add sp, #0x24
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B6A68: .4byte 0x00000F18
_080B6A6C: .4byte 0x000013F8
_080B6A70: .4byte 0x00001404
