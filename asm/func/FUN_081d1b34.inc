	push {lr}
	sub sp, #0x30
	adds r1, r0, #0
	adds r0, #0x80
	ldrh r2, [r0]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081D1BA0
	adds r2, r1, #0
	adds r2, #0x4c
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D1BF2
	adds r0, r1, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, [r1, #0x5c]
	str r0, [sp, #4]
	ldr r0, [r1, #0x60]
	str r0, [sp, #8]
	ldr r0, [r1, #0x64]
	str r0, [sp, #0xc]
	ldr r0, [r1, #0x68]
	str r0, [sp, #0x10]
	ldr r0, [r1, #0x6c]
	str r0, [sp, #0x14]
	ldr r0, [r1, #0x70]
	str r0, [sp, #0x18]
	ldr r0, [r1, #0x74]
	str r0, [sp, #0x1c]
	ldr r0, [r1, #0x78]
	str r0, [sp, #0x20]
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, _081D1B9C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
	b _081D1BF2
	.align 2, 0
_081D1B9C: .4byte 0xFFFF0000
_081D1BA0:
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081D1BF2
	adds r2, r1, #0
	adds r2, #0x4e
	ldrh r0, [r2]
	cmp r0, #0
	beq _081D1BF2
	adds r0, r1, #0
	adds r0, #0x48
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, [r1, #0x5c]
	str r0, [sp, #4]
	ldr r0, [r1, #0x60]
	str r0, [sp, #8]
	ldr r0, [r1, #0x64]
	str r0, [sp, #0xc]
	ldr r0, [r1, #0x68]
	str r0, [sp, #0x10]
	ldr r0, [r1, #0x6c]
	str r0, [sp, #0x14]
	ldr r0, [r1, #0x70]
	str r0, [sp, #0x18]
	ldr r0, [r1, #0x74]
	str r0, [sp, #0x1c]
	ldr r0, [r1, #0x78]
	str r0, [sp, #0x20]
	adds r0, r1, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	movs r0, #0xa
	add r1, sp, #0x28
	strh r0, [r1]
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081D1BF2:
	add sp, #0x30
	pop {r0}
	bx r0
