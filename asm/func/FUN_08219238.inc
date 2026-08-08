	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0
	bl FUN_0822b644
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #2
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r0, #3
	bl FUN_0822b644
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	ldr r0, _082192DC @ =0x000012F0
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _082192E0 @ =0x00001350
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #1
	ldr r0, _082192E4 @ =0x000013B0
	adds r1, r5, r0
	movs r2, #4
_0821929A:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0821929A
	movs r3, #1
	ldr r0, _082192E8 @ =0x00001590
	adds r1, r5, r0
	movs r2, #1
_082192B0:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _082192B0
	ldr r1, _082192EC @ =0x00001648
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _082192F0 @ =0x0000164C
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082192DC: .4byte 0x000012F0
_082192E0: .4byte 0x00001350
_082192E4: .4byte 0x000013B0
_082192E8: .4byte 0x00001590
_082192EC: .4byte 0x00001648
_082192F0: .4byte 0x0000164C
