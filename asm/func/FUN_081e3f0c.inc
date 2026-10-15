	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _081E3F9C @ =0x00001594
	adds r2, r7, r0
	movs r0, #0
	str r0, [r2]
	ldr r3, _081E3FA0 @ =0x00001598
	adds r1, r7, r3
	strb r0, [r1]
	ldr r0, _081E3FA4 @ =0x030046A0
	ldr r0, [r0]
	adds r6, r2, #0
	movs r2, #1
	mov sb, r2
	adds r5, r1, #0
	adds r4, r0, #0
	adds r4, #0x60
	movs r3, #0
	mov r8, r3
	movs r0, #3
	mov ip, r0
_081E3F3C:
	ldr r0, _081E3FA8 @ =0x00000868
	add r0, r8
	adds r2, r7, r0
	movs r1, #0
	ldrsh r3, [r4, r1]
	cmp r3, #0
	blt _081E3F74
	movs r1, #3
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r2, #0x20]
	asrs r1, r3, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r2, #0x22]
	mov r1, sb
	lsls r1, r3
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_081E3F74:
	ldr r0, [r2, #8]
	mov r3, sb
	orrs r0, r3
	str r0, [r2, #8]
	adds r4, #2
	movs r0, #0x60
	add r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add ip, r1
	mov r2, ip
	cmp r2, #0
	bge _081E3F3C
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3F9C: .4byte 0x00001594
_081E3FA0: .4byte 0x00001598
_081E3FA4: .4byte 0x030046A0
_081E3FA8: .4byte 0x00000868
