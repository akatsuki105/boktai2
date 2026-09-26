	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	movs r4, #1
	ldr r0, _0820EDDC @ =0x00000E54
	adds r2, r7, r0
	subs r0, #0xc0
	adds r1, r7, r0
	movs r3, #1
_0820ED60:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820ED60
	movs r4, #0
	adds r0, r7, #0
	adds r0, #0x26
	ldrb r0, [r0]
	bl FUN_0820cc8c
	mov r8, r0
	bl FUN_0820d0b8
	adds r2, r0, #0
	ldr r1, _0820EDE0 @ =0x00000D8C
	adds r0, r7, r1
	movs r1, #0x4c
	adds r1, r1, r7
	mov sb, r1
	str r4, [sp]
	movs r1, #0x98
	str r1, [sp, #4]
	movs r6, #0x13
	str r6, [sp, #8]
	movs r5, #8
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	mov r1, sb
	movs r3, #2
	bl FUN_082376a4
	mov r0, r8
	bl FUN_0820cbfc
	adds r2, r0, #0
	ldr r1, _0820EDE4 @ =0x00000E4C
	adds r0, r7, r1
	str r4, [sp]
	movs r1, #0xb0
	str r1, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	mov r1, sb
	movs r3, #2
	bl FUN_082376a4
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820EDDC: .4byte 0x00000E54
_0820EDE0: .4byte 0x00000D8C
_0820EDE4: .4byte 0x00000E4C
