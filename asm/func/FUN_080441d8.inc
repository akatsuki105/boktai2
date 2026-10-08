	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r4
	mov r8, r0
	movs r3, #0
	ldr r0, _08044284 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r3, r0
	bge _080442BE
	adds r6, r4, #0
	adds r6, #0x54
	str r6, [sp, #4]
	movs r7, #0
	movs r0, #1
	mov sl, r0
	movs r1, #0x64
	adds r1, r1, r4
	mov sb, r1
_08044218:
	ldr r0, _08044284 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, r8
	adds r0, #8
	adds r0, r0, r1
	ldr r5, [r0]
	ldrb r1, [r5, #6]
	cmp r1, #2
	beq _08044288
	cmp r1, #3
	bne _0804429C
	ldrh r0, [r5, #8]
	ldr r2, [sp, #4]
	strh r0, [r2]
	ldrh r0, [r5, #0xa]
	adds r1, r4, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r5, #0xc]
	adds r0, r4, #0
	adds r0, #0x58
	strh r1, [r0]
	movs r6, #0
	ldrsh r0, [r2, r6]
	mov r2, sb
	movs r6, #0
	ldrsh r1, [r2, r6]
	subs r0, r0, r1
	ldr r2, [sp, #4]
	movs r6, #4
	ldrsh r1, [r2, r6]
	mov r2, sb
	movs r6, #4
	ldrsh r2, [r2, r6]
	subs r1, r1, r2
	str r3, [sp]
	bl ArcTan2_8
	strb r0, [r4, #0x1b]
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	mov r1, sl
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r3, [sp]
	b _0804429C
	.align 2, 0
_08044284: .4byte 0x03002B4C
_08044288:
	ldrb r0, [r5, #8]
	adds r0, #5
	lsls r0, r0, #5
	strb r0, [r4, #0x1b]
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	mov r2, sl
	strb r2, [r4, #8]
_0804429C:
	mov r0, r8
	adds r1, r5, #0
	str r3, [sp]
	bl MsgQueue_BeginWait
	ldr r3, [sp]
	adds r3, #1
	ldr r0, _080442D0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, r8
	adds r0, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r3, r0
	blt _08044218
_080442BE:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080442D0: .4byte 0x03002B4C
