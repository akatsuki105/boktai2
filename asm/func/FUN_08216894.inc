	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _082168BC @ =0x00000E8C
	adds r0, r0, r7
	mov r8, r0
	movs r2, #0
	ldr r1, _082168C0 @ =0x00000F54
	adds r4, r7, r1
	ldr r3, _082168C4 @ =0x00000F4C
	adds r5, r7, r3
_082168AE:
	cmp r2, #1
	beq _082168DC
	cmp r2, #1
	bgt _082168C8
	cmp r2, #0
	beq _082168CE
	b _0821695C
	.align 2, 0
_082168BC: .4byte 0x00000E8C
_082168C0: .4byte 0x00000F54
_082168C4: .4byte 0x00000F4C
_082168C8:
	cmp r2, #2
	beq _082168EC
	b _0821695C
_082168CE:
	ldr r1, _082168D4 @ =0x085AFA30
	ldr r0, _082168D8 @ =0x00000434
	b _082168F2
	.align 2, 0
_082168D4: .4byte 0x085AFA30
_082168D8: .4byte 0x00000434
_082168DC:
	ldr r1, _082168E4 @ =0x085AFAEE
	ldr r0, _082168E8 @ =0x00000436
	b _082168F2
	.align 2, 0
_082168E4: .4byte 0x085AFAEE
_082168E8: .4byte 0x00000436
_082168EC:
	ldr r1, _08216928 @ =0x085AFEB2
	movs r0, #0x87
	lsls r0, r0, #3
_082168F2:
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r2, [sp]
	bl sound_08240960
	ldr r2, [sp]
	cmp r0, #0
	beq _0821692C
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x18
	str r2, [sp]
	bl FUN_082372cc
	ldr r2, [sp]
	b _08216952
	.align 2, 0
_08216928: .4byte 0x085AFEB2
_0821692C:
	ldr r0, [r4]
	movs r6, #1
	ands r0, r6
	cmp r0, #0
	bne _08216952
	movs r0, #2
	strb r0, [r4, #0x13]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x18
	str r2, [sp]
	bl FUN_082372cc
	ldr r2, [sp]
	cmp r0, #0
	beq _08216952
	ldr r0, [r4]
	orrs r0, r6
	str r0, [r4]
_08216952:
	adds r4, #0x60
	adds r5, #0x60
	adds r2, #1
	cmp r2, #2
	ble _082168AE
_0821695C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
