	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r0, _08061DAC @ =0x0000071D
	adds r7, r5, r0
	ldrb r1, [r7]
	movs r0, #0x34
	adds r4, r1, #0
	muls r4, r0, r4
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r4, r1
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r3, r3, #1
	adds r3, #2
	adds r2, r4, #0
	adds r2, #0x32
	movs r0, #0
	mov sb, r0
	strb r3, [r2]
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	ldrb r2, [r2]
	adds r0, r4, #0
	bl FUN_0822dafc
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x31
	mov r1, sb
	strb r1, [r0]
	adds r4, #0x30
	movs r0, #1
	strb r0, [r4]
	ldr r2, _08061DB0 @ =0x0000071C
	adds r5, r5, r2
	strb r0, [r5]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _08061DA0
	strb r1, [r7]
_08061DA0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061DAC: .4byte 0x0000071D
_08061DB0: .4byte 0x0000071C
