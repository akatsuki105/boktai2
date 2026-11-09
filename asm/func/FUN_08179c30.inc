	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r0, #0
	str r0, [sp]
	ldr r1, _08179C80 @ =0x00001012
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp]
	cmp r1, r0
	bge _08179D34
	mov sl, r7
	movs r3, #0
	ldr r0, _08179C84 @ =0x00000734
	adds r6, r7, r0
	ldr r1, _08179C88 @ =0x0000075B
	adds r1, r1, r7
	mov sb, r1
	adds r0, #0x21
	adds r5, r7, r0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
_08179C70:
	ldrb r0, [r5]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08179C8C
	movs r0, #1
	b _08179C8E
	.align 2, 0
_08179C80: .4byte 0x00001012
_08179C84: .4byte 0x00000734
_08179C88: .4byte 0x0000075B
_08179C8C:
	movs r0, #0
_08179C8E:
	cmp r0, #0
	beq _08179CC4
	ldrb r0, [r5, #6]
	adds r4, r0, #0
	cmp r4, #0
	beq _08179CA0
	subs r0, #1
	strb r0, [r5, #6]
	b _08179CC4
_08179CA0:
	adds r0, r3, r7
	ldr r1, _08179CE4 @ =0x00000684
	adds r0, r0, r1
	movs r1, #0xd1
	lsls r1, r1, #1
	str r3, [sp, #4]
	bl Video_SetAuxSpritePltt
	mov r0, sb
	strb r4, [r0]
	ldr r2, _08179CE8 @ =0x00000755
	add r2, sl
	ldrb r1, [r2]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r3, [sp, #4]
_08179CC4:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08179D12
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08179CEC
	mov r1, r8
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08179CF6
	.align 2, 0
_08179CE4: .4byte 0x00000684
_08179CE8: .4byte 0x00000755
_08179CEC:
	mov r1, r8
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08179CF6:
	str r1, [r0]
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08179D12
	mov r1, r8
	adds r0, r1, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_08179D12:
	movs r0, #0x92
	lsls r0, r0, #1
	add sl, r0
	adds r3, r3, r0
	adds r6, r6, r0
	add sb, r0
	adds r5, r5, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	ldr r1, _08179D44 @ =0x00001012
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp]
	cmp r1, r0
	blt _08179C70
_08179D34:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08179D44: .4byte 0x00001012
