	push {r4, lr}
	ldr r0, _08047B44 @ =0x030000C4
	ldr r4, [r0]
	cmp r4, #0
	beq _08047B3A
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08047B3A
	bl Script_GetValue
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
_08047B3A:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08047B44: .4byte 0x030000C4
