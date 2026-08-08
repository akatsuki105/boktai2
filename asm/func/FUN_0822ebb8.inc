	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	bl FUN_0822e7d8
	cmp r0, #0
	bne _0822EBE0
	bl FUN_0822e7e4
	cmp r0, #0
	blt _0822EC44
_0822EBE0:
	bl FUN_0822e898
	mov r2, sl
	lsls r1, r2, #7
	adds r5, r0, r1
	movs r0, #0
	bl GetTilemapBuffer
	mov sb, r0
	movs r6, #0
_0822EBF4:
	ldr r3, [sp, #8]
	adds r0, r3, r6
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #5
	mov r8, r0
	movs r4, #0
	lsls r7, r6, #1
_0822EC04:
	adds r2, r7, r4
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	mov r1, sl
	ldr r3, [sp, #0xc]
	bl FUN_0822e920
	adds r2, r0, #0
	cmp r2, #0
	blt _0822EC44
	movs r3, #0x80
	lsls r3, r3, #1
	adds r2, r2, r3
	adds r5, #0x20
	ldr r1, [sp, #4]
	adds r0, r1, r4
	movs r3, #0x1f
	ands r0, r3
	add r0, r8
	lsls r0, r0, #1
	add r0, sb
	ldr r3, _0822EC54 @ =0xFFFFF000
	adds r1, r3, #0
	orrs r2, r1
	strh r2, [r0]
	adds r4, #1
	cmp r4, #1
	ble _0822EC04
	adds r6, #1
	cmp r6, #1
	ble _0822EBF4
_0822EC44:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822EC54: .4byte 0xFFFFF000
