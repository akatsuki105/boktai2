	push {lr}
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08049D46
	movs r0, #0
	strb r0, [r1]
_08049D46:
	ldr r0, _08049D58 @ =0x03002CE8
	movs r1, #0
	str r1, [r0]
	ldr r0, _08049D5C @ =0x030000C8
	str r1, [r0]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08049D58: .4byte 0x03002CE8
_08049D5C: .4byte 0x030000C8
