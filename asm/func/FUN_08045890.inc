	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r4, r1, #0
	str r2, [sp, #4]
	adds r0, r4, #0
	adds r0, #0xc4
	str r0, [sp, #8]
	ldrb r5, [r4, #5]
	cmp r5, #0
	beq _08045968
	movs r5, #0
	strb r5, [r4, #5]
	ldrb r0, [r4, #7]
	ldr r2, _0804590C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r2, r8
	adds r7, r0, r2
	ldr r3, _08045910 @ =0x0000192C
	adds r7, r7, r3
	ldrh r1, [r1]
	mov ip, r1
	movs r0, #1
	mov sl, r0
	adds r2, r4, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r3, r1, #0
	ands r3, r0
	adds r1, r3, #0
	strb r3, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r2
	cmp r0, #2
	bhi _08045914
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, sl
	strb r2, [r0]
	b _08045920
	.align 2, 0
_0804590C: .4byte 0x085AB404
_08045910: .4byte 0x0000192C
_08045914:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
_08045920:
	adds r5, r0, #0
	ldrb r0, [r1]
	add r0, ip
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	mov r3, sl
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _08045946
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _0804594E
_08045946:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0804594E:
	str r1, [r6, #8]
	movs r1, #0
	strb r1, [r4, #8]
	adds r1, r4, #0
	adds r1, #0x23
	ldrb r1, [r1]
	adds r1, #5
	lsls r1, r1, #5
	adds r2, r4, #0
	adds r2, #0x22
	strb r1, [r2]
	adds r1, r2, #0
	b _08045A08
_08045968:
	ldrb r0, [r4, #7]
	ldr r2, _080459C0 @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r6, r4, #0
	adds r6, #0xa4
	lsls r0, r0, #5
	mov r3, r8
	adds r7, r0, r3
	ldr r0, _080459C4 @ =0x0000192C
	adds r7, r7, r0
	ldrh r1, [r1]
	mov ip, r1
	movs r1, #1
	mov sl, r1
	adds r2, r4, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r3, r1, #0
	ands r3, r0
	adds r1, r3, #0
	strb r3, [r4, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r2
	cmp r0, #2
	bhi _080459C8
	movs r0, #8
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	mov r2, sl
	strb r2, [r0]
	b _080459D4
	.align 2, 0
_080459C0: .4byte 0x085AB404
_080459C4: .4byte 0x0000192C
_080459C8:
	adds r1, r4, #0
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r4, #0
	adds r0, #0x2d
	strb r5, [r0]
_080459D4:
	adds r5, r0, #0
	ldrb r0, [r1]
	add r0, ip
	strh r0, [r4, #0x2e]
	ldrh r2, [r4, #0x2e]
	movs r3, #1
	mov r0, sl
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_SetAnim
	ldrb r1, [r5]
	cmp r1, #0
	beq _080459FA
	ldr r1, [r6, #8]
	movs r2, #4
	orrs r1, r2
	b _08045A02
_080459FA:
	ldr r1, [r6, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08045A02:
	str r1, [r6, #8]
	adds r1, r4, #0
	adds r1, #0x22
_08045A08:
	ldrb r1, [r1]
	mov r3, sb
	ldrb r2, [r3]
	subs r1, r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r5, r1, #0
	lsls r1, r5, #0x18
	asrs r3, r1, #0x18
	cmp r3, #8
	ble _08045A28
	adds r1, r2, #0
	adds r1, #8
	mov r6, sb
	strb r1, [r6]
	b _08045A40
_08045A28:
	movs r1, #8
	rsbs r1, r1, #0
	cmp r3, r1
	bge _08045A3A
	adds r1, r2, #0
	subs r1, #8
	mov r7, sb
	strb r1, [r7]
	b _08045A40
_08045A3A:
	adds r1, r2, r5
	mov r2, sb
	strb r1, [r2]
_08045A40:
	mov r3, r8
	ldr r1, [r3, #0x28]
	movs r2, #0xf
	ands r1, r2
	ldr r6, [sp, #4]
	cmp r1, r6
	bne _08045AD4
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _08045A7C
	mov r1, r8
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _08045A7C
	movs r0, #5
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	movs r0, #0
	str r0, [r4, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	movs r0, #0
	b _08045B5A
_08045A7C:
	ldrb r1, [r4, #0x1f]
	cmp r1, #0
	beq _08045AD4
	mov r7, r8
	ldrb r1, [r7, #0x1e]
	cmp r1, #0
	beq _08045AD4
	mov r3, r8
	adds r3, #0x20
	adds r5, r4, #0
	adds r5, #0x26
	ldrb r1, [r3]
	ldrb r2, [r5]
	cmp r1, r2
	bne _08045AAA
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _08045AC4
_08045AAA:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r5, [r5]
	cmp r1, r5
	bne _08045AD4
	mov r1, r8
	adds r1, #0x21
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhi _08045AD4
_08045AC4:
	movs r0, #0
	strb r0, [r4, #0x1e]
	movs r1, #6
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _08045B5A
_08045AD4:
	mov r6, r8
	ldr r3, [r6, #0x18]
	ldr r5, [r4, #0x3c]
	movs r7, #0
	ldrsh r2, [r3, r7]
	ldr r6, [sp, #8]
	movs r7, #0
	ldrsh r1, [r6, r7]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045AEC
	rsbs r2, r2, #0
_08045AEC:
	cmp r2, r5
	bge _08045B1E
	movs r1, #2
	ldrsh r2, [r3, r1]
	ldr r6, [sp, #8]
	movs r7, #2
	ldrsh r1, [r6, r7]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045B02
	rsbs r2, r2, #0
_08045B02:
	cmp r2, #0xff
	bgt _08045B1E
	movs r1, #4
	ldrsh r2, [r3, r1]
	ldr r3, [sp, #8]
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r2, r2, r1
	cmp r2, #0
	bge _08045B18
	rsbs r2, r2, #0
_08045B18:
	movs r3, #1
	cmp r2, r5
	blt _08045B20
_08045B1E:
	movs r3, #0
_08045B20:
	cmp r3, #0
	beq _08045B34
	movs r0, #0
	strb r0, [r4, #0xc]
	movs r1, #3
	strb r1, [r4, #4]
	movs r1, #1
	strb r1, [r4, #5]
	str r0, [r4, #0x10]
	b _08045B5A
_08045B34:
	mov r7, sb
	ldrb r1, [r7]
	adds r1, #0x10
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r1, r2
	adds r2, r4, #0
	adds r2, #0x23
	ldrb r2, [r2]
	cmp r1, r2
	bne _08045B5A
	strb r3, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r3, [r4, #0x10]
	movs r0, #0
_08045B5A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
