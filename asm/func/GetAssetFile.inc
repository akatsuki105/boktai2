	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r0, r2, #0
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	adds r1, r4, #0
	ldm r1!, {r5, r6, r7}
	stm r3!, {r5, r6, r7}
	ldr r1, [r1]
	str r1, [r3]
	ldr r1, [sp, #8]
	adds r1, r1, r4
	str r1, [sp, #8]
	ldr r3, [sp, #0xc]
	adds r3, r3, r4
	str r3, [sp, #0xc]
	ldr r3, [sp, #4]
	subs r3, #1
	str r3, [sp]
	movs r3, #0
	bl FindFile
	adds r1, r0, #0
	cmp r1, #0
	blt _0823107E
	ldr r0, [sp, #4]
	cmp r1, r0
	blo _08231082
_0823107E:
	movs r0, #0
	b _0823108C
_08231082:
	ldr r0, [sp, #0xc]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, r0, r4
_0823108C:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
