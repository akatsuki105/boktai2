	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	mov r8, r0
	adds r0, r1, #0
	adds r4, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x10
	bl GetTilemapFile
	adds r5, r0, #0
	mov r1, sp
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [sp, #0xc]
	adds r0, r0, r5
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	adds r0, r0, r5
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	adds r0, r0, r5
	str r0, [sp, #0x14]
	cmp r4, #0
	bne _08000ED4
	mov r0, sp
	adds r1, r6, #0
	bl FUN_08000c84
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08000ED4:
	mov r0, r8
	adds r1, r5, #0
	adds r2, r6, #0
	bl Video_SetBGLayer
	adds r0, r6, #0
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
