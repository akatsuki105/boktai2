	push {r4, r5, lr}
	sub sp, #0x14
	adds r5, r1, #0
	cmp r0, #1
	beq _0823CE98
	cmp r0, #1
	bgt _0823CE7C
	cmp r0, #0
	beq _0823CE86
	b _0823CE98
_0823CE7C:
	cmp r0, #2
	beq _0823CE8C
	cmp r0, #3
	beq _0823CE92
	b _0823CE98
_0823CE86:
	movs r1, #2
	movs r4, #1
	b _0823CE9C
_0823CE8C:
	movs r1, #4
	movs r4, #3
	b _0823CE9C
_0823CE92:
	movs r1, #5
	movs r4, #4
	b _0823CE9C
_0823CE98:
	movs r1, #3
	movs r4, #2
_0823CE9C:
	str r5, [sp]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x10]
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl MapPltt_PushCommand
	ldr r0, [sp, #0x28]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #5
	mov r2, sp
	bl FUN_08002800
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
