	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _080A7D68 @ =0x00000201
	adds r0, r0, r6
	mov sb, r0
	ldrb r0, [r0]
	adds r0, #1
	mov r1, sb
	strb r0, [r1]
	movs r3, #0xff
	mov r2, sp
	strb r3, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080A7D58
	movs r0, #0x80
	lsls r0, r0, #2
	adds r7, r6, r0
	ldrb r0, [r7]
	movs r4, #0x2c
	muls r0, r4, r0
	adds r1, r6, #0
	adds r1, #0xa0
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldrb r0, [r7]
	muls r0, r4, r0
	adds r2, r6, #0
	adds r2, #0xb8
	adds r2, r2, r0
	adds r0, r6, #0
	adds r0, #0x88
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A7D6C @ =0x0203B400
	mov ip, r1
	ldr r2, _080A7D70 @ =0x030046B8
	mov r8, r2
	ldr r2, [r2]
	adds r2, #1
	ldr r5, _080A7D74 @ =0x000003FF
	ands r2, r5
	lsls r3, r2, #1
	add r3, ip
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xb8
	ldrh r0, [r1]
	subs r0, #0x7f
	ldrb r3, [r3]
	adds r0, r0, r3
	movs r3, #0
	mov sl, r3
	strh r0, [r1]
	adds r2, #1
	ands r2, r5
	lsls r3, r2, #1
	add r3, ip
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xba
	ldrh r0, [r1]
	subs r0, #0x7f
	ldrb r3, [r3]
	adds r0, r0, r3
	strh r0, [r1]
	adds r2, #1
	ands r2, r5
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, ip
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xbc
	ldrh r0, [r1]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r7]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc8
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r7]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc9
	mov r1, sl
	strb r1, [r0]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	mov r2, sp
	ldrb r2, [r2]
	ands r0, r2
	cmp r0, #7
	bls _080A7D52
	strb r1, [r7]
_080A7D52:
	mov r0, sl
	mov r3, sb
	strb r0, [r3]
_080A7D58:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7D68: .4byte 0x00000201
_080A7D6C: .4byte 0x0203B400
_080A7D70: .4byte 0x030046B8
_080A7D74: .4byte 0x000003FF
