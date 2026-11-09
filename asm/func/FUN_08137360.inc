	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	movs r6, #0
	ldr r0, _081373AC @ =0x00000B3A
	adds r4, r3, r0
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r6, r0
	bge _081373A2
	ldr r2, [r1, #4]
	ldr r1, [r1]
	mov ip, r4
	ldr r5, _081373B0 @ =0x00000764
	adds r4, r3, r5
	ldr r7, _081373B4 @ =0x00000674
	adds r3, r3, r7
	movs r0, #0x90
	lsls r0, r0, #1
	mov r8, r0
_0813738A:
	str r1, [r3]
	str r2, [r3, #4]
	str r1, [r4]
	str r2, [r4, #4]
	add r4, r8
	add r3, r8
	adds r6, #1
	mov r5, ip
	movs r7, #0
	ldrsh r0, [r5, r7]
	cmp r6, r0
	blt _0813738A
_081373A2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081373AC: .4byte 0x00000B3A
_081373B0: .4byte 0x00000764
_081373B4: .4byte 0x00000674
