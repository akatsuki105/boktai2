	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x24
	mov r8, r1
	mov sb, r2
	ldr r6, _08240258 @ =gClock
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	str r2, [r6, #0x20]
	bl __floatsidf
	ldr r4, _0824025C @ =0x3EF00000
	ldr r5, _08240260 @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	mov r0, r8
	bl __floatsidf
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	adds r5, r1, #0
	adds r4, r0, #0
	add r1, sp, #0x14
	add r2, sp, #0x18
	ldr r3, [r6]
	add r0, sp, #0x10
	bl FUN_0823db08
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	str r4, [sp, #4]
	str r5, [sp, #8]
	mov r3, sb
	str r3, [sp, #0xc]
	ldr r3, [sp, #0x20]
	str r3, [sp]
	ldr r3, [sp, #0x1c]
	bl FUN_0823fb90
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08240258: .4byte gClock
_0824025C: .4byte 0x3EF00000
_08240260: .4byte 0x00000000
