	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r2, #0
	mov r8, r3
	ldr r7, [sp, #0x30]
	cmp r0, #0
	beq _0805EF58
	bl Entity0805ee80_FindFreeElem
	adds r6, r0, #0
	cmp r6, #0
	beq _0805EF58
	adds r0, #0x20
	movs r4, #1
	movs r1, #0
	strb r4, [r6, #1]
	strb r4, [r6, #2]
	str r1, [r6, #0x14]
	movs r1, #2
	movs r2, #0
	mov sb, r2
	strh r1, [r0, #0x10]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	str r1, [r6, #0x18]
	str r2, [r6, #0x1c]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	str r1, [r6, #0x3c]
	str r2, [r6, #0x40]
	ldr r1, [r6, #0x20]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r6, #0x20]
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	strh r5, [r6, #6]
	mov r0, r8
	strh r0, [r6, #4]
	ldr r0, [sp, #0x1c]
	strh r0, [r6, #8]
	ldr r0, [sp, #0x20]
	strh r0, [r6, #0xa]
	ldr r0, [sp, #0x24]
	strh r0, [r6, #0xc]
	ldr r0, [sp, #0x28]
	strb r0, [r6, #0x10]
	ldr r0, [sp, #0x2c]
	strb r0, [r6, #0xf]
	mov r2, sb
	strb r2, [r6, #0xe]
	strb r4, [r6]
	movs r0, #0
	b _0805EF5C
_0805EF58:
	movs r0, #1
	rsbs r0, r0, #0
_0805EF5C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
