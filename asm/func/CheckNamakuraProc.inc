	push {lr}
	ldr r2, _0806400C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08064010 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08064014 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, #0xa
	ble _08064018
	movs r0, #0
	b _0806401C
	.align 2, 0
_0806400C: .4byte 0x030046B8
_08064010: .4byte 0x000003FF
_08064014: .4byte 0x0203B400
_08064018:
	movs r0, #0x80
	lsls r0, r0, #5
_0806401C:
	pop {r1}
	bx r1
