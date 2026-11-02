	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081489E4
	ldrb r0, [r1, #4]
	cmp r0, #3
	bhi _081489D8
	ldr r0, _081489DC @ =0x03002BE0
	ldrb r1, [r1, #4]
	lsls r2, r1, #2
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081489E4
	movs r0, #8
	ldr r1, _081489E0 @ =0x03002BC0
	adds r1, r2, r1
	ldr r1, [r1]
	ands r1, r0
	cmp r1, #0
	bne _081489E4
_081489D8:
	movs r0, #0
	b _081489E6
	.align 2, 0
_081489DC: .4byte 0x03002BE0
_081489E0: .4byte 0x03002BC0
_081489E4:
	movs r0, #1
_081489E6:
	pop {r1}
	bx r1
	.align 2, 0
