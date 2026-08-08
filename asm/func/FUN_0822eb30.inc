	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r1
	adds r4, r2, #0
	mov sb, r3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	bl FUN_0822e7d8
	cmp r0, #0
	bne _0822EB56
	bl FUN_0822e7e4
	cmp r0, #0
	blt _0822EBA2
_0822EB56:
	bl FUN_0822e87c
	lsls r1, r7, #6
	adds r6, r0, r1
	movs r0, #0
	bl GetTilemapBuffer
	mov r8, r0
	movs r5, #0
_0822EB68:
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	mov r3, sb
	bl FUN_0822e920
	adds r2, r0, #0
	cmp r2, #0
	blt _0822EBA2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r6, #0x20
	lsls r0, r4, #5
	add r0, sl
	lsls r0, r0, #1
	add r0, r8
	ldr r3, _0822EBB4 @ =0xFFFFF000
	adds r1, r3, #0
	orrs r2, r1
	strh r2, [r0]
	adds r4, #1
	movs r0, #0x1f
	ands r4, r0
	adds r5, #1
	cmp r5, #1
	ble _0822EB68
_0822EBA2:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822EBB4: .4byte 0xFFFFF000
