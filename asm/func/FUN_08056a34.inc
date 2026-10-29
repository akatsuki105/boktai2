	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r2, r0, #0
	adds r7, r1, #0
	ldr r1, _08056AD0 @ =0x00000EBC
	adds r2, r2, r1
	ldr r2, [r2]
	mov r8, r2
	movs r4, #0x2c
	add r4, r8
	mov ip, r4
	adds r6, r7, #0
	adds r6, #0x4c
	ldrh r4, [r6, #0x1c]
	ldr r5, _08056AD4 @ =0xFFFFFC00
	adds r3, r5, #0
	adds r2, r4, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r5, _08056AD8 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r5
	orrs r1, r2
	str r1, [sp]
	ldrh r2, [r6, #0x20]
	adds r3, r2, r3
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r6, sp
	ldr r1, [sp, #4]
	ands r1, r5
	orrs r1, r3
	str r1, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r3, r1, #0
	adds r4, r4, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, [sp, #8]
	ands r1, r5
	orrs r1, r4
	str r1, [sp, #8]
	adds r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #8
	ldr r1, [r3, #4]
	ands r1, r5
	orrs r1, r2
	str r1, [r3, #4]
	mov r1, sp
	mov r4, r8
	movs r5, #0x2c
	ldrsh r2, [r4, r5]
	movs r4, #0
	ldrsh r1, [r1, r4]
	cmp r2, r1
	blt _08056ADC
	movs r5, #0
	ldrsh r1, [r3, r5]
	cmp r2, r1
	bgt _08056ADC
	mov r1, ip
	movs r4, #4
	ldrsh r2, [r1, r4]
	movs r5, #4
	ldrsh r1, [r6, r5]
	cmp r2, r1
	blt _08056ADC
	movs r4, #4
	ldrsh r1, [r3, r4]
	cmp r2, r1
	bgt _08056ADC
	movs r1, #1
	b _08056ADE
	.align 2, 0
_08056AD0: .4byte 0x00000EBC
_08056AD4: .4byte 0xFFFFFC00
_08056AD8: .4byte 0xFFFF0000
_08056ADC:
	movs r1, #0
_08056ADE:
	adds r2, r1, #0
	cmp r2, #0
	beq _08056AEA
	movs r0, #0
	strb r0, [r7, #0xc]
	b _08056AFC
_08056AEA:
	ldrb r1, [r7, #0xc]
	adds r1, #1
	strb r1, [r7, #0xc]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x1f
	bls _08056AFC
	strb r2, [r7, #0xc]
	movs r0, #1
_08056AFC:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
