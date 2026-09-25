	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	ldr r0, _080D8E88 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080D8E78
	ldr r2, [r7, #0x48]
	lsls r1, r5, #1
	adds r0, r7, #0
	adds r0, #0x3e
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bgt _080D8E78
	adds r0, r7, #0
	adds r0, #0x32
	adds r6, r0, r5
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D8E78
	ldr r3, _080D8E8C @ =0x0203B400
	mov ip, r3
	ldr r0, _080D8E90 @ =0x030046B8
	mov sb, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r4, _080D8E94 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	lsls r2, r5, #3
	adds r2, r7, r2
	movs r3, #0xf
	ands r0, r3
	subs r0, #8
	mov sl, r0
	movs r0, #0
	mov r8, r0
	mov r0, sl
	strh r0, [r2, #4]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r3
	strh r0, [r2, #6]
	adds r1, #1
	ands r1, r4
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	ands r0, r3
	subs r0, #8
	strh r0, [r2, #8]
	ldrb r1, [r6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6]
	lsls r1, r5, #2
	adds r0, r7, #0
	adds r0, #0x4c
	adds r0, r0, r1
	mov r1, r8
	str r1, [r0]
_080D8E78:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D8E88: .4byte 0x0300015C
_080D8E8C: .4byte 0x0203B400
_080D8E90: .4byte 0x030046B8
_080D8E94: .4byte 0x000003FF
