	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	mov r7, r8
	adds r7, #0x38
	mov r5, r8
	adds r5, #0x64
	ldr r0, _08055908 @ =0x03002BE0
	ldr r6, [r0]
	add r4, sp, #8
	mov r0, r8
	ldr r3, [r0, #0x18]
	ldr r2, _0805590C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov ip, r4
	cmp r0, #0
	blt _08055910
	asrs r1, r0, #0xc
	b _08055916
	.align 2, 0
_08055908: .4byte 0x03002BE0
_0805590C: .4byte 0x085B0A08
_08055910:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08055916:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _08055936
	asrs r0, r0, #0xc
	b _0805593C
_08055936:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805593C:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	adds r1, r6, #0
	adds r1, #0x2c
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r6, [r6, #0x2c]
	adds r0, r0, r6
	strh r0, [r7, #0x1c]
	mov r3, ip
	ldrh r0, [r3, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	mov r3, ip
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0xff
	mov r2, r8
	ldrb r0, [r2, #0x18]
	adds r0, #0x20
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	add r3, sp, #4
	mov r2, sp
	adds r2, #5
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r2, #0
	cmp r0, #1
	bhi _0805598C
	movs r0, #1
	b _0805598E
_0805598C:
	movs r0, #0
_0805598E:
	strb r0, [r3]
	cmp r1, #1
	bls _08055998
	movs r0, #1
	b _0805599A
_08055998:
	movs r0, #0
_0805599A:
	strb r0, [r2]
	mov r3, r8
	ldr r1, [r3, #0x74]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl AuxAnim_SetAnim
	ldrh r1, [r5, #8]
	lsls r1, r1, #1
	ldr r2, [r5]
	adds r6, r2, r1
	ldrh r1, [r6]
	lsrs r1, r1, #6
	strh r1, [r7, #0x10]
	ldrb r1, [r5, #4]
	movs r4, #1
	adds r2, r4, #0
	ands r2, r1
	ldrh r3, [r6]
	movs r1, #0x30
	ands r1, r3
	lsrs r1, r1, #4
	ands r1, r4
	cmp r2, r1
	beq _080559DC
	ldr r1, [r7]
	movs r2, #4
	orrs r1, r2
	b _080559E4
_080559DC:
	ldr r1, [r7]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080559E4:
	str r1, [r7]
	ldrb r1, [r5, #4]
	movs r4, #2
	adds r2, r4, #0
	ands r2, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrh r3, [r6]
	movs r1, #0x30
	ands r1, r3
	lsrs r1, r1, #4
	ands r1, r4
	cmp r2, r1
	beq _08055A08
	ldr r1, [r7]
	movs r2, #8
	orrs r1, r2
	b _08055A10
_08055A08:
	ldr r1, [r7]
	movs r2, #9
	rsbs r2, r2, #0
	ands r1, r2
_08055A10:
	str r1, [r7]
	ldrh r1, [r5, #0xe]
	adds r1, #1
	strh r1, [r5, #0xe]
	ldr r2, _08055A48 @ =0x0000FFFF
	adds r3, r2, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrb r2, [r5, #7]
	cmp r1, r2
	blo _08055A80
	movs r1, #0
	strh r1, [r5, #0xe]
	ldrb r2, [r5, #4]
	movs r1, #4
	ands r1, r2
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0
	beq _08055A4C
	ldrh r1, [r5, #8]
	cmp r1, #0
	bne _08055A40
	ldrb r1, [r5, #5]
_08055A40:
	subs r1, #1
	strh r1, [r5, #8]
	b _08055A5C
	.align 2, 0
_08055A48: .4byte 0x0000FFFF
_08055A4C:
	ldrh r1, [r5, #8]
	adds r1, #1
	strh r1, [r5, #8]
	ands r1, r3
	ldrb r3, [r5, #5]
	cmp r1, r3
	blo _08055A5C
	strh r2, [r5, #8]
_08055A5C:
	ldrh r1, [r5, #8]
	lsls r1, r1, #1
	ldr r2, [r5]
	adds r6, r2, r1
	ldrh r2, [r6]
	movs r1, #0xf
	ands r1, r2
	strb r1, [r5, #6]
	ldrb r2, [r5, #6]
	ldrh r1, [r5, #0xc]
	muls r1, r2, r1
	asrs r1, r1, #6
	strb r1, [r5, #7]
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _08055A80
	movs r1, #1
	strb r1, [r5, #7]
_08055A80:
	mov r2, r8
	ldr r1, [r2, #0x18]
	adds r1, #1
	str r1, [r2, #0x18]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
