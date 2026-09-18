	push {r4, lr}
	sub sp, #4
	bl FUN_0823cd38
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r2, _0823CD98 @ =0x05000004
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0823CD9C
	bl VM_GetPC
	bl VM_GetValueAtSafe_Proxy
	adds r1, r0, #0
	cmp r1, #0
	beq _0823CDB6
	movs r3, #0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0823CDB6
	adds r2, r1, #0
_0823CD82:
	adds r0, r4, r3
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _0823CDB6
	cmp r3, #0xf
	ble _0823CD82
	b _0823CDB6
	.align 2, 0
_0823CD98: .4byte 0x05000004
_0823CD9C:
	movs r1, #0x80
	strb r1, [r4]
	movs r0, #0xa2
	strb r0, [r4, #1]
	strb r1, [r4, #2]
	movs r0, #0x98
	strb r0, [r4, #3]
	strb r1, [r4, #4]
	movs r0, #0x91
	strb r0, [r4, #5]
	strb r1, [r4, #6]
	movs r0, #0x9f
	strb r0, [r4, #7]
_0823CDB6:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
