	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0
	strh r1, [r5, #0x18]
	strh r0, [r5, #0x1a]
	movs r0, #0x6f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800FB8C
	movs r6, #0
	movs r0, #0x1c
	adds r0, r0, r5
	mov sb, r0
	movs r2, #0x1e
	adds r2, r2, r5
	mov r8, r2
	b _0800FB6E
_0800FB62:
	bl Script_GetValue
	lsls r1, r6, #1
	add r1, sp
	strh r0, [r1]
	adds r6, #1
_0800FB6E:
	cmp r6, #5
	bgt _0800FBA6
	bl VM_GetPC
	cmp r0, #0
	bne _0800FB62
	movs r1, #0
	lsls r0, r6, #1
	add r0, sp
_0800FB80:
	strh r1, [r0]
	adds r0, #2
	adds r6, #1
	cmp r6, #5
	ble _0800FB80
	b _0800FBA6
_0800FB8C:
	movs r0, #0x1c
	adds r0, r0, r5
	mov sb, r0
	movs r2, #0x1e
	adds r2, r2, r5
	mov r8, r2
	movs r1, #0
	mov r0, sp
	adds r0, #0xa
_0800FB9E:
	strh r1, [r0]
	subs r0, #2
	cmp r0, sp
	bge _0800FB9E
_0800FBA6:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800FC02
	movs r6, #0
	ldr r0, _0800FBC0 @ =0x03003584
	mov sl, r0
	mov r7, sp
	adds r4, r5, #0
	adds r4, #0x28
	b _0800FBF6
	.align 2, 0
_0800FBC0: .4byte 0x03003584
_0800FBC4:
	bl Script_GetValue
	strh r0, [r4]
	ldrh r0, [r4]
	bl FUN_0823cdf8
	ldrh r1, [r7]
	adds r1, r1, r0
	strh r1, [r4, #2]
	ldrh r1, [r4, #2]
	lsls r1, r1, #5
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r4, #0x24]
	adds r0, #0x20
	str r0, [r4, #0x28]
	adds r0, #0x20
	str r0, [r4, #0x2c]
	ldrh r0, [r5, #0x1a]
	adds r0, #1
	strh r0, [r5, #0x1a]
	adds r7, #2
	adds r4, #0x30
	adds r6, #1
_0800FBF6:
	cmp r6, #5
	bgt _0800FC02
	bl VM_GetPC
	cmp r0, #0
	bne _0800FBC4
_0800FC02:
	mov r0, sb
	mov r1, r8
	bl FUN_0823ce10
	movs r0, #0x40
	strh r0, [r5, #0x20]
	ldr r1, _0800FC48 @ =gClock
	ldrb r0, [r1, #0xf]
	strh r0, [r5, #0x24]
	ldrb r0, [r1, #0xe]
	strh r0, [r5, #0x26]
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _0800FC36
	adds r4, r5, #0
	adds r4, #0x28
_0800FC24:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800f9b4
	adds r4, #0x30
	adds r6, #1
	ldrh r2, [r5, #0x1a]
	cmp r6, r2
	blt _0800FC24
_0800FC36:
	movs r0, #0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FC48: .4byte gClock
