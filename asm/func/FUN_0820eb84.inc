	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r1, #0
	ldr r0, _0820EC5C @ =0x00000854
	adds r0, r0, r7
	mov sb, r0
	ldr r3, _0820EC60 @ =0x000005B4
	adds r3, r3, r7
	mov r8, r3
	adds r0, r7, #0
	adds r0, #0x25
	str r0, [sp, #0x18]
	movs r6, #1
_0820EBA8:
	lsls r4, r1, #1
	adds r5, r1, #1
	adds r0, r4, r1
	lsls r0, r0, #6
	mov r3, sb
	adds r2, r0, r3
	movs r3, #1
_0820EBB6:
	ldr r0, [r2]
	orrs r0, r6
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0820EBB6
	adds r1, r4, r1
	lsls r1, r1, #5
	add r1, r8
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	adds r1, r5, #0
	cmp r1, #6
	ble _0820EBA8
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
	bl FUN_0820cbec
	mov sl, r0
	ldr r3, [sp, #0x18]
	ldrb r0, [r3]
	bl FUN_0820cbdc
	adds r0, #1
	str r0, [sp, #0x14]
	movs r0, #0
	mov r8, r0
	cmp r8, sl
	bge _0820EC4A
	ldr r1, _0820EC64 @ =0x000005CC
	adds r4, r7, r1
	mov sb, r0
	movs r6, #0x28
	ldr r3, _0820EC68 @ =0x0000084C
	adds r5, r7, r3
_0820EC00:
	ldr r2, [sp, #0x14]
	add r2, r8
	movs r0, #0
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r1, #0
	str r1, [sp, #0x10]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x4c
	movs r3, #2
	bl FUN_082376a4
	ldr r3, _0820EC60 @ =0x000005B4
	adds r2, r7, r3
	add r2, sb
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0x28
	strh r0, [r4]
	strh r6, [r4, #2]
	adds r4, #0x60
	movs r0, #0x60
	add sb, r0
	adds r6, #0x10
	adds r5, #0xc0
	movs r1, #1
	add r8, r1
	cmp r8, sl
	blt _0820EC00
_0820EC4A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820EC5C: .4byte 0x00000854
_0820EC60: .4byte 0x000005B4
_0820EC64: .4byte 0x000005CC
_0820EC68: .4byte 0x0000084C
