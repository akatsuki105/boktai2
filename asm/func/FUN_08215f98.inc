	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08215FF4 @ =0x00000E8C
	adds r5, r4, r0
	ldr r0, [r5, #8]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r5, #8]
	adds r6, r4, #0
	adds r6, #0x18
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #7
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08215FF8 @ =0x00000EEC
	adds r0, r4, r1
	ldr r1, _08215FFC @ =0x000012B0
	adds r4, r4, r1
	ldr r2, [r4]
	adds r2, #0x4b
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r6, #0
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, [r5, #0x68]
	mov r1, r8
	ands r0, r1
	str r0, [r5, #0x68]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08215FF4: .4byte 0x00000E8C
_08215FF8: .4byte 0x00000EEC
_08215FFC: .4byte 0x000012B0
