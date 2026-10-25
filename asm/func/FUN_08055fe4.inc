	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r6, r1, #0
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #6]
	cmp r0, #0xf
	bls _0805606A
	ldrb r1, [r6, #5]
	mov sb, r1
	ldrb r5, [r6, #8]
	adds r4, r6, #0
	adds r4, #0x4c
	ldr r3, _080560C4 @ =0x00000DAC
	adds r0, r7, r3
	ldr r3, [r0]
	movs r0, #0x2c
	adds r0, r0, r3
	mov r8, r0
	ldr r1, _080560C8 @ =0x085AB990
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrh r1, [r7, #0x24]
	ldrh r0, [r0]
	cmp r1, r0
	bhs _0805606A
	ldr r0, [r7, #0x20]
	movs r1, #3
	ands r0, r1
	ands r2, r1
	cmp r0, r2
	bne _0805606A
	movs r2, #0x2c
	ldrsh r1, [r3, r2]
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _0805603E
	rsbs r0, r0, #0
_0805603E:
	cmp r0, #0x7f
	bgt _0805606A
	mov r0, r8
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08056054
	rsbs r1, r1, #0
_08056054:
	cmp r1, #0x7f
	bgt _0805606A
	adds r0, r7, #0
	adds r0, #0x2a
	strb r5, [r0]
	ldrh r0, [r7, #0x24]
	adds r0, #1
	strh r0, [r7, #0x24]
	ldrh r0, [r7, #0x28]
	add r0, sb
	strh r0, [r7, #0x28]
_0805606A:
	mov r1, ip
	adds r1, #0x1c
	adds r2, r6, #0
	adds r2, #0xc
	ldrh r0, [r6, #0xc]
	mov r4, ip
	ldrh r4, [r4, #0x1c]
	adds r0, r0, r4
	mov r3, ip
	strh r0, [r3, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r4, r6, #0
	adds r4, #0x5c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x5c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r3, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _080560CC
	mov r3, ip
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _080560DA
	.align 2, 0
_080560C4: .4byte 0x00000DAC
_080560C8: .4byte 0x085AB990
_080560CC:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080560DA:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08056100
	mov r3, ip
	ldr r0, [r3]
	movs r1, #8
	orrs r0, r1
	str r0, [r3]
	b _0805610E
_08056100:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_0805610E:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08056144 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0805618A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805614E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08056148
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08056164
	.align 2, 0
_08056144: .4byte 0x0000FFFF
_08056148:
	subs r0, #1
	strh r0, [r4, #8]
	b _08056162
_0805614E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08056162
	strh r1, [r4, #8]
	movs r2, #1
	b _08056164
_08056162:
	movs r2, #0
_08056164:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805618C
	movs r0, #1
	strb r0, [r4, #7]
	b _0805618C
_0805618A:
	movs r2, #0
_0805618C:
	cmp r2, #0
	beq _080561A8
	ldrb r0, [r6, #2]
	adds r0, #1
	movs r3, #0
	strb r0, [r6, #2]
	strh r3, [r6, #6]
	ldr r1, [r7, #0x18]
	ldrb r2, [r6, #2]
	adds r2, #3
	str r3, [sp]
	mov r0, r8
	bl AuxAnim_SetAnim
_080561A8:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
