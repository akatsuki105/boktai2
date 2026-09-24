	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r0, #0xab
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	ldrb r6, [r0]
	cmp r6, #0
	beq _081D627C
	adds r0, r5, #0
	bl FUN_081d6764
	ldr r1, _081D6270 @ =0x0000013D
	adds r6, r5, r1
	ldrb r0, [r6]
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r4, r5, r3
	ldrb r1, [r4]
	subs r0, r0, r1
	cmp r0, #0
	blt _081D6238
	ldr r0, _081D6274 @ =0x000003C7
	bl PlaySound_082406e0
_081D6238:
	ldrb r1, [r6]
	ldrb r0, [r4]
	subs r1, r1, r0
	adds r0, r5, #0
	bl FUN_081d6ae8
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081D6262
	adds r0, r5, #0
	adds r0, #0xa8
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r4]
_081D6262:
	ldr r0, _081D6278 @ =0x000003C6
	bl PlaySound_082406e0
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	b _081D62B4
	.align 2, 0
_081D6270: .4byte 0x0000013D
_081D6274: .4byte 0x000003C7
_081D6278: .4byte 0x000003C6
_081D627C:
	ldr r0, [r5]
	movs r4, #1
	orrs r0, r4
	str r0, [r5]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0x58
	bl Hitbox_Unregister
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r6, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r3, _081D62C0 @ =0x0000057C
	adds r1, r7, r3
	lsls r4, r0
	ldr r0, [r1]
	bics r0, r4
	str r0, [r1]
	ldr r0, _081D62C4 @ =0x0000FFFF
	strh r0, [r2]
_081D62B4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D62C0: .4byte 0x0000057C
_081D62C4: .4byte 0x0000FFFF
