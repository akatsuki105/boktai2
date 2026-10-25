	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0x3c
	mov r8, r0
	movs r1, #1
	mov sb, r1
_0805983A:
	mov r1, sb
	mov r2, r8
	lsls r1, r2
	ldr r0, [r7, #0x1c]
	ands r0, r1
	cmp r0, #0
	bne _0805984A
	b _08059956
_0805984A:
	ldr r1, _08059890 @ =0x085AB9DC
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r3
	adds r6, r4, #0
	adds r6, #0x34
	adds r3, r4, #0
	adds r3, #0x60
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x60]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sb
	ands r0, r1
	cmp r2, r0
	beq _08059894
	ldr r0, [r4, #0x34]
	movs r1, #4
	orrs r0, r1
	b _0805989C
	.align 2, 0
_08059890: .4byte 0x085AB9DC
_08059894:
	ldr r0, [r4, #0x34]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805989C:
	str r0, [r4, #0x34]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _080598C0
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080598C8
_080598C0:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080598C8:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r5, _08059900 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _08059938
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08059904
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _080598F8
	ldrb r0, [r3, #5]
_080598F8:
	subs r0, #1
	strh r0, [r3, #8]
	b _08059914
	.align 2, 0
_08059900: .4byte 0x0000FFFF
_08059904:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _08059914
	strh r1, [r3, #8]
_08059914:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08059938
	mov r5, sb
	strb r5, [r3, #7]
_08059938:
	adds r0, r4, #0
	adds r0, #0x70
	adds r1, r4, #0
	adds r1, #0x50
	movs r2, #0
	bl Hitbox_SetPos
	ldrb r0, [r4, #2]
	cmp r0, #1
	bne _08059950
	movs r0, #1
	add sl, r0
_08059950:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_08059956:
	movs r1, #1
	add r8, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r4, r4, r2
	mov r5, r8
	cmp r5, #7
	bgt _08059968
	b _0805983A
_08059968:
	mov r0, sl
	str r0, [r7, #0x2c]
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
