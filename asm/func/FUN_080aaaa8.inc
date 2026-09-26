	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x94
	ldr r2, _080AAB08 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _080AAB0C @ =0x00007530
	orrs r0, r3
	ldr r1, _080AAB10 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _080AAB14 @ =0x75300000
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	mov ip, r1
	cmp r0, #0
	bne _080AAB18
	ldr r1, [r4, #0x18]
	adds r0, r1, #0
	adds r0, #0x28
	movs r3, #1
	ldrb r0, [r0]
	lsls r3, r0
	adds r2, #0x1e
	adds r0, r1, r2
	ldrh r2, [r0]
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r5, r2, r0
	b _080AAB4E
	.align 2, 0
_080AAB08: .4byte 0xFFFF0000
_080AAB0C: .4byte 0x00007530
_080AAB10: .4byte 0x0000FFFF
_080AAB14: .4byte 0x75300000
_080AAB18:
	ldr r0, [r4, #0x18]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080AAB40
	ldr r0, _080AAB3C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #0xa
	cmp r0, #0x63
	ble _080AAB4A
	movs r0, #0x63
	b _080AAB4A
	.align 2, 0
_080AAB3C: .4byte 0x030046A0
_080AAB40:
	ldr r0, _080AAB9C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
_080AAB4A:
	movs r3, #0
	lsls r5, r0, #3
_080AAB4E:
	movs r7, #0x80
	lsls r7, r7, #5
	ldr r2, _080AABA0 @ =0x00003001
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	mov r1, ip
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	str r7, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #0
	bl Hitbox_SetAttack
	adds r0, r6, #0
	movs r1, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	ldr r1, [r4, #0x18]
	adds r1, #0x2c
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAB9C: .4byte 0x030046A0
_080AABA0: .4byte 0x00003001
