	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	cmp r4, #0
	beq _0823BDF0
	movs r5, #1
	strh r5, [r4, #0x1e]
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823BDCC
	bl VM_GetPC
	add r2, sp, #4
	mov r1, sp
	bl VM_DecodeValue
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [sp, #4]
	str r0, [r1]
	subs r1, #2
	movs r0, #0
	strh r0, [r1]
	b _0823BDF0
_0823BDCC:
	movs r0, #0x52
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0823BDEA
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x98
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x96
	strh r5, [r0]
	b _0823BDF0
_0823BDEA:
	adds r0, r4, #0
	adds r0, #0x98
	str r1, [r0]
_0823BDF0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
