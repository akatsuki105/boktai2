	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08044DFC
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	strh r4, [r5, #0x20]
_08044DFC:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08044E62
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08044E62
	ldrh r0, [r5, #0x20]
	cmp r0, #1
	beq _08044E46
	cmp r0, #1
	bgt _08044E2E
	cmp r0, #0
	beq _08044E34
	b _08044E62
_08044E2E:
	cmp r0, #2
	beq _08044E58
	b _08044E62
_08044E34:
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	b _08044E5C
_08044E46:
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	b _08044E5C
_08044E58:
	movs r0, #1
	strb r0, [r5, #7]
_08044E5C:
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
_08044E62:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
