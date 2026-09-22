	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	movs r1, #0xff
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0xb
	bhi _080A907C
	adds r0, r5, #0
	adds r0, #0x24
	bl Hitbox_Register
_080A907C:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r2, r2, r5
	mov r8, r2
	movs r7, #0
	adds r6, r5, #0
	adds r6, #0x74
	adds r4, r5, #0
	adds r4, #0x8c
	movs r0, #7
	mov sb, r0
_080A9092:
	mov r1, r8
	ldrh r0, [r1]
	ldrb r2, [r4, #0x15]
	cmp r0, r2
	blo _080A90AC
	adds r0, r5, #0
	adds r0, #0x74
	adds r0, r0, r7
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080A9170
_080A90AC:
	movs r0, #1
	mov sl, r0
	ldrb r0, [r4, #0x14]
	ldrb r1, [r4, #0x10]
	adds r0, r0, r1
	strb r0, [r4, #0x10]
	ldrh r3, [r4, #0x16]
	ldr r2, _080A90D8 @ =0x085B0A08
	ldrb r0, [r4, #0x10]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080A90DC
	asrs r3, r0, #0xc
	b _080A90E2
	.align 2, 0
_080A90D8: .4byte 0x085B0A08
_080A90DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080A90E2:
	ldrh r0, [r5, #0x1c]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r1, [r4, #0x16]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A90FE
	asrs r1, r0, #0xc
	b _080A9104
_080A90FE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A9104:
	ldrh r0, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #4]
	mov r0, r8
	ldrh r1, [r0]
	ldrb r2, [r4, #0x12]
	cmp r1, r2
	blo _080A912E
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080A9126
	ldrb r0, [r4, #0x14]
	cmp r0, #2
	bls _080A9126
	subs r0, #1
	strb r0, [r4, #0x14]
_080A9126:
	ldrh r0, [r4, #2]
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	strh r0, [r4, #2]
_080A912E:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A9146
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #0xc
	bl FUN_0822dafc
	b _080A915E
_080A9146:
	cmp r0, #4
	bne _080A915E
	adds r0, r7, #0
	adds r0, #0x74
	adds r0, r5, r0
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0xd
	bl FUN_0822dafc
_080A915E:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080A9170
	strb r1, [r4, #0x13]
_080A9170:
	adds r7, #0x30
	adds r6, #0x30
	adds r4, #0x30
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _080A9092
	movs r2, #0xff
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	mov r0, sl
	cmp r0, #0
	bne _080A919A
	adds r0, r5, #0
	bl KillEntity
_080A919A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
